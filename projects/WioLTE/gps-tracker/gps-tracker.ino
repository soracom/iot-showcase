#include <WioLTEforArduino.h>
#include <TinyGPS++.h>
#include <stdio.h>
#include <string.h>

#define BUTTON_PIN      (WIOLTE_D20)
#define INTERVAL        (60000)
#define RECEIVE_TIMEOUT (10000)

WioLTE Wio;

HardwareSerial* GpsSerial;
char GpsDataLength;
TinyGPSPlus gps;

void setup() {
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
  pinMode(BUTTON_PIN, INPUT);
  SerialUSB.println("### Setup completed.");
  GpsBegin(&Serial);
}

void loop() {
  unsigned long next = millis() + INTERVAL;
  
  GpsReadWithTinyGPS();
  if(gps.location.isValid())
  {
    Wio.LedSetRGB(0, 100, 100);
    const char* dataByGPS = SendDataCreatorViaGPS();
    SerialUSB.print("INFO : Send SORACOM to : "); SerialUSB.println(dataByGPS);
    Wio.LedSetRGB(0, 100, 0);
    SendDataToSoracom(dataByGPS);
  } else {
    Wio.LedSetRGB(0, 100, 100);
    const char* dataByLTEbase = SendDataCreatorViaLTE();
    SerialUSB.print("INFO : Send SORACOM to : "); SerialUSB.println(dataByLTEbase);
    Wio.LedSetRGB(0, 0, 100);
    SendDataToSoracom(dataByLTEbase);
  }
  
  while(millis() < next)
  {
    if(digitalRead(BUTTON_PIN))
    {
      SerialUSB.println("exit delay loop.");
      break;
    }
    delay(100);
  }
}

void GpsBegin(HardwareSerial* serial)
{
    GpsSerial = serial;
    GpsSerial->begin(9600);
    GpsDataLength = 0;
}

void GpsReadWithTinyGPS()
{
    while (GpsSerial->available()) {
        if(gps.encode(GpsSerial->read())){
            displayGPSInfo();
        }
    }
}

void displayGPSInfo(){
    SerialUSB.println("");
    SerialUSB.print("LAT= "); SerialUSB.println(gps.location.lat(), 6);
    SerialUSB.print("LON= "); SerialUSB.println(gps.location.lng(), 6);
}

const char* SendDataCreatorViaGPS()
{
    return SendDataCreator(gps.location.lat(), gps.location.lng(), "GPS");
}

const char* SendDataCreatorViaLTE()
{
    double baseLatitude;
    double baseLongitude;
    if(!Wio.GetLocation(&baseLongitude, &baseLatitude))
    {
        baseLatitude = 00.0000;
        baseLongitude = 000.000;
    }
    SerialUSB.print("LTE-Base_LAT= "); SerialUSB.println(baseLatitude);
    SerialUSB.print("LTE-Base_LON= "); SerialUSB.println(baseLongitude);

    return SendDataCreator(baseLatitude, baseLongitude, "LTE");
}

const char* SendDataCreator(double argLatitude, double argLongtitude, char *source)
{
    // Return values format is follows as JSON
    // {\"lat\":*,\"lng\:*"}

    char* returnPointer;
    char workBuffer[200] = "{\"lat\":\0";

    char latitude[32];
    snprintf(latitude, 16, "%f", argLatitude);

    returnPointer = strcat(workBuffer, latitude);
    returnPointer = strcat(workBuffer, ",\"lng\":");

    char longitude[32];
    snprintf(longitude, 16, "%f", argLongtitude);

    returnPointer = strcat(workBuffer, longitude);
    returnPointer = strcat(workBuffer, ", \"source\":\"");

    returnPointer = strcat(workBuffer, source);
    returnPointer = strcat(workBuffer, "\"}");

    return returnPointer;
}

bool SendDataToSoracom(const char* dataToSend)
{
  int connectId;
  connectId = Wio.SocketOpen("harvest.soracom.io", 8514, WIOLTE_UDP);
  if (connectId < 0)
  {
      SerialUSB.println("### ERROR : Fail socket open ###");
      goto err;
  }

  if (!Wio.SocketSend(connectId, dataToSend))
  {
      SerialUSB.println("### ERROR : Fail data send ###");
      goto err_close;
  }

  int length;
  char receiveData[100];
  length = Wio.SocketReceive(connectId, receiveData, sizeof (receiveData), RECEIVE_TIMEOUT);


  if (length < 0)
  {
      SerialUSB.println("### ERROR! ###");
      goto err_close;
  }

  if (length == 0)
  {
      SerialUSB.println("### RECEIVE TIMEOUT! ###");
      goto err_close;
  }

err_close:
  SerialUSB.println("### Close.");
  if (!Wio.SocketClose(connectId))
  {
      SerialUSB.println("### ERROR! ###");
      goto err;
  }

err:
  delay(1000);
}

