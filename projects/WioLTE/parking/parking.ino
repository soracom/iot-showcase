#include <stdio.h>
#include <WioLTEforArduino.h>
#include <Ultrasonic.h>      // https://github.com/Seeed-Studio/Grove_Ultrasonic_Ranger

#define ULTRASONIC_PIN  (WIOLTE_A6)
#define INTERVAL        (1000)
#define REPORT_INTERVAL (10)
#define THRESHOLD       (3)
#define WAIT            (3)
#define LED             (16)
#define RECEIVE_TIMEOUT (10000)

WioLTE Wio;
Ultrasonic UltrasonicRanger(ULTRASONIC_PIN);

bool IsParked;
unsigned long StateChangedAt;
unsigned long TotalParkedSeconds;
unsigned long LastSentAt;

void setup()
{
  delay(200);

  SerialUSB.println("");
  SerialUSB.println("--- START ---------------------------------------------------");

  SerialUSB.println("### I/O Initialize.");
  Wio.Init();
  SerialUSB.println("### Power supply ON.");
  Wio.PowerSupplyGrove(true);
  Wio.PowerSupplyLTE(true);
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
  SerialUSB.println("### Setup completed.");
  
  IsParked=(UltrasonicRanger.MeasureInCentimeters() <= THRESHOLD);
  StateChangedAt=millis();
  TotalParkedSeconds=0;
  LastSentAt=0;
  delay(100);
}

void report()
{
  char data[256];

  if(IsParked)
  {
    
    sprintf(data, "{\"IsParked\":%s, \"TotalParkedSeconds\":%d, \"CurrentParkedSeconds\":%d}", IsParked? "true":"false", TotalParkedSeconds + (millis() - StateChangedAt)/1000, (millis() - StateChangedAt)/1000);  
  }
  else
  {
    sprintf(data, "{\"IsParked\":%s, \"TotalParkedSeconds\":%d, \"CurrentParkedSeconds\":0}", IsParked? "true":"false", TotalParkedSeconds);  
  }
  SerialUSB.println("### Open.");
  int connectId;
  connectId = Wio.SocketOpen("harvest.soracom.io", 8514, WIOLTE_UDP);
  if (connectId < 0) {
    SerialUSB.println("### ERROR! ###");
    goto err;
  }

  SerialUSB.println("### Send.");
  SerialUSB.print("Send:");
  SerialUSB.print(data);
  SerialUSB.println("");
  if (!Wio.SocketSend(connectId, data)) {
    SerialUSB.println("### ERROR! ###");
    goto err_close;
  }

  SerialUSB.println("### Receive.");
  int length;
  length = Wio.SocketReceive(connectId, data, sizeof (data), RECEIVE_TIMEOUT);
  if (length < 0) {
    SerialUSB.println("### ERROR! ###");
    goto err_close;
  }
  if (length == 0) {
    SerialUSB.println("### RECEIVE TIMEOUT! ###");
    goto err_close;
  }
  SerialUSB.print("Receive:");
  SerialUSB.print(data);
  SerialUSB.println("");

err_close:
  SerialUSB.println("### Close.");
  if (!Wio.SocketClose(connectId)) {
    SerialUSB.println("### ERROR! ###");
    goto err;
  }  
err:
  delay(INTERVAL);
}

void loop()
{
  unsigned long next = millis() + INTERVAL;
  unsigned long wait_until;
  long distance;
  char message[256];
  
  distance = UltrasonicRanger.MeasureInCentimeters();
  delay(100);
  
  if(distance <= THRESHOLD)
  {
    if(IsParked)
    {
      Wio.LedSetRGB(LED, 0, 0);
      if(LastSentAt < millis()-REPORT_INTERVAL * INTERVAL)
      {
        report();
        LastSentAt = millis();
      }
    }
    else
    {
      Wio.LedSetRGB(LED/2, LED/2, 0);
      wait_until = millis() + WAIT * INTERVAL;
      while(millis() < wait_until)
      {
        if( UltrasonicRanger.MeasureInCentimeters() > THRESHOLD)
        {
          break;
        }
        delay(100);
      }
      IsParked = true;
      StateChangedAt = millis();
      report();
      LastSentAt = millis();
      return;
    }
  }
  else
  {
    if(IsParked)
    {
      Wio.LedSetRGB(LED/2, LED/2, 0);
      wait_until = millis() + WAIT * INTERVAL;
      while(millis() < wait_until)
      {
        if( UltrasonicRanger.MeasureInCentimeters() <= THRESHOLD)
        {
          break;
        }
        delay(100);
      }
      TotalParkedSeconds = TotalParkedSeconds + (millis() - StateChangedAt)/1000;
      IsParked = false;
      StateChangedAt = millis();
      report();
      LastSentAt = millis();
      return;
    }
    else
    {
      Wio.LedSetRGB(0, LED/2, 0);
    }
  }
  sprintf(message, "IsParked: %s for %d seconds.", (IsParked)? "true":"false", (millis() - StateChangedAt)/1000); 
  SerialUSB.println(message);

  // sleep until next loop
  if(next > millis())
  {
    delay(next - millis());
  }
}

