#include <WioLTEforArduino.h>
#include <ADXL345.h>          // https://github.com/Seeed-Studio/Accelerometer_ADXL345
#include <math.h>
#include <stdio.h>

#define INTERVAL    (10)
#define FPS         (100)
#define DURATION    (5)
#define FRAMES      (500)
#define CHECK_FRAME (30)
#define WARN_LEVEL  (2)
#define CRITICAL_LEVEL (3)
#define SEND_INTERVAL (5000)
#define RECEIVE_TIMEOUT (10000)

#define GAIN  (3.8245935) // sensor value to Gal (100 m^2/s)
#define BUZZER_PIN      (WIOLTE_A4)

WioLTE Wio;
ADXL345 Accel;
unsigned long count=0, last_sent=0;
int xyz[3][FPS];
double rc[3];
double buf[FPS * DURATION];
double tmp[FPS * DURATION];
int connectId;

int sort_desc(const void *cmp1, const void *cmp2)
{
  // Need to cast the void * to int *
  double a = *((double *)cmp1);
  double b = *((double *)cmp2);
  return a > b ? -1 : (a < b ? 1 : 0);
}

void caribration(){
  int i,j,x,y,z;
  double s[3], g;
  for(j=0;j<FPS;j++)
  {
    Accel.readXYZ(&xyz[0][j], &xyz[1][j], &xyz[2][j]);
    delay(INTERVAL);
  }
  
  for(i=0;i<3;i++)
  {
    rc[i] = 0;
    s[i]=0;
    for(j=0;j<FPS;j++)
    {
      s[i]+=xyz[i][j];
      rc[i] = rc[i] * 0.94 + xyz[i][j]*0.06;
    }
  }
  
  SerialUSB.print("avg = [");  
  SerialUSB.print(s[0]/FPS);    
  SerialUSB.print(",");  
  SerialUSB.print(s[1]/FPS);    
  SerialUSB.print(",");
  SerialUSB.print(s[2]/FPS);    
  SerialUSB.print("] = ");
  g=sqrt(s[0]*s[0]+s[1]*s[1]+s[2]*s[2])/FPS;
  SerialUSB.print(g*3.9/1000);
  SerialUSB.println(" G");
  SerialUSB.print("rc = [");  
  SerialUSB.print(rc[0]);    
  SerialUSB.print(",");  
  SerialUSB.print(rc[1]);    
  SerialUSB.print(",");
  SerialUSB.print(rc[2]);    
  SerialUSB.print("] = ");
  g=sqrt(rc[0]*rc[0]+rc[1]*rc[1]+rc[2]*rc[2]);
  SerialUSB.print(g*3.9/1000);
  SerialUSB.println(" G");
}

void setup()
{
  delay(200);

  SerialUSB.println("");
  SerialUSB.println("--- START ---------------------------------------------------");
  
  SerialUSB.println("### I/O Initialize.");
  Wio.Init();
  Wio.LedSetRGB(50,205,215);
  
  SerialUSB.println("### Power supply ON.");
  Wio.PowerSupplyLTE(true);
  Wio.PowerSupplyGrove(true);
  delay(500);

  SerialUSB.println("### Turn on or reset.");
  if (!Wio.TurnOnOrReset()) {
    SerialUSB.println("### ERROR! ###");
    return;
  }

  SerialUSB.println("### Connecting to \"soracom.io\".");
  if (!Wio.Activate("soracom.io", "sora", "sora")) {
    SerialUSB.println("### ERROR! ###");
    return;
  }
  connectId = Wio.SocketOpen("harvest.soracom.io", 8514, WIOLTE_UDP);
  
  pinMode(BUZZER_PIN, OUTPUT);
  Accel.powerOn();
  
  SerialUSB.println("### Calibration.");  
  caribration();
  SerialUSB.println("### Setup completed.");  
}

void loop()
{
  char data[100];
  unsigned long start = millis(), wait;
  int i,j,x,y,z, buf_index, xyz_index;
  double s[3],gal_xyz[3],offset,gal,seismic_scale;
  
  xyz_index = count % (FPS);
  Accel.readXYZ(&xyz[0][xyz_index], &xyz[1][xyz_index], &xyz[2][xyz_index]);
  for(i=0;i<3;i++)
  {
    s[i]=0;
    for(j=0;j<FPS;j++)
    {
      s[i]+=xyz[i][j];
    }
    offset = s[i]/FPS;
    rc[i] = rc[i]*0.94 + xyz[i][xyz_index]*0.06;
    gal_xyz[i] = (rc[i] - offset) * GAIN;
  }  
  gal = sqrt( gal_xyz[0]*gal_xyz[0] + gal_xyz[1]*gal_xyz[1] + gal_xyz[2]*gal_xyz[2]);

  buf_index = count % (FRAMES);
  buf[buf_index] = gal;

  if(count > FRAMES)
  {
    SerialUSB.print(gal); 
    for(i = 0; i < FRAMES ; i++)
    {
      tmp[i]=buf[i];
    }
    qsort(tmp, FRAMES, sizeof(tmp[0]), sort_desc); 
    SerialUSB.print(",1,"); 
    SerialUSB.print(tmp[CHECK_FRAME]);
    SerialUSB.print(","); 
    seismic_scale = 2 * log10(tmp[CHECK_FRAME])+0.94;
    SerialUSB.println(seismic_scale);

    if(millis() > last_sent + SEND_INTERVAL)
    {
      sprintf(data, "{\"seismic_scale\":%f, \"gal\":%f}", seismic_scale, tmp[CHECK_FRAME]);
      Wio.SocketSend(connectId, data);
      last_sent = millis();
      return;
    }
    
    if(seismic_scale > CRITICAL_LEVEL)
    {
      digitalWrite(BUZZER_PIN, HIGH);
      Wio.LedSetRGB(128,0,0);
    }
    else if (seismic_scale > WARN_LEVEL)
    {
      digitalWrite(BUZZER_PIN, LOW);
      Wio.LedSetRGB(64,64,0);
    }
    else
    {
      digitalWrite(BUZZER_PIN, LOW);
      Wio.LedSetRGB(0,128,0);
    }
  }
  
  if(start + INTERVAL < millis())
  {
    delay(millis() - (start + INTERVAL));
  }
  count++; 
}
