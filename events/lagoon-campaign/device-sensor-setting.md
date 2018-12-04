## デバイス、センサーのセッティング
### Wio LTE にアンテナを取り付ける
Wio LTE にアンテナを取り付けます。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTMptz_qwXc27oSJPqtl3it_L4DYQITUVsmrzA11MqHhwzWwoTUAB71xXS9HQ1F5_tZ9-iljiLr52Ms/pub?w=641&amp;h=477">

### Wio LTE に SIM を取り付ける
Wio LTE に SIM (nanoサイズ) を取り付けます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vT6x0wd4fSqcZnKijvDDbS54P4kPt_5UqZJ6JY6L5Z-WmjH5KAVpsG8sTRn7kJj_f3f_LMuPuwyjFxC/pub?w=498&amp;h=606">

#### SIM の失敗例
以下のように、SIM 取り付けの「窓」に SIM が見えている場合は 取り付けに失敗 しています。引き抜いてから再度取り付けてください。
また、奥まで入れてしまった場合は、ピンのようなもので少しずつ押し出してください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQhaeNqR7GkWrXitsxlRPKVtXQSzs-UKlSuOELy2ihdJNWwMduIme_dvRDyIu61sSZRz6krdIuSfxMz/pub?w=424&amp;h=321">
 
#### SIM の取り出し
抜く際フックを引っ張りすぎると金具が取れてしまうため、図示されている程度まで引っ張り出したらSIMを取り出し、金具を元に戻してください

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSjFtHLe1w7RS7KgECUq55icvRf9sLf7KZH6pPIVNVUKSobIC4YXZ1oSa6fFYfxXptueKaAqo9b5Vk2/pub?w=689&amp;h=687">

### センサーを取り付ける
Wio LTE のD38 端子に「GROVE - デジタル温度・湿度センサ」を接続、D20 端子にボタンを接続し、Wio LTEをPCにつなげてください。



### スケッチを作成し、書き込む
Arduinoを立ち上げます。
[ファイル]>[新規ファイル]をクリックします。

Wio LTE と PC を接続して DFUモード にし、マイコンボードに書き込むをクリックします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSAT_XAOAaE00Ex43eItitVxM_eH_OLdhbDINq0PK7yS0WmvP0ITen77WlAOHxb03zbKebw6fNusnCS/pub?w=825&amp;h=695">

![https://github.com/soracom/iot-showcase/blob/master/events/lagoon-campaign/fridge_monitoring.gif](https://github.com/soracom/iot-showcase/blob/master/events/lagoon-campaign/fridge_monitoring.gif)

下記がコードです。

```
#include <WioLTEforArduino.h>
#include <stdio.h>

#define INTERVAL        (5000)
#define RECEIVE_TIMEOUT (10000)

// uncomment following line to use Temperature & Humidity sensor
#define SENSOR_PIN    (WIOLTE_D38)
#define MAGNETIC_SWITCH_PIN (WIOLTE_D20)

WioLTE Wio;

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

#ifdef SENSOR_PIN
  TemperatureAndHumidityBegin(SENSOR_PIN);
#endif // SENSOR_PIN
  
  pinMode(MAGNETIC_SWITCH_PIN, INPUT);

  SerialUSB.println("### Setup completed.");
}

void loop() {
  char data[100];

#ifdef SENSOR_PIN
  float temp;
  float humi;
  int door;

  door = digitalRead(MAGNETIC_SWITCH_PIN)? 0:1;
  
  if (!TemperatureAndHumidityRead(&temp, &humi)) {
    SerialUSB.println("ERROR!");
    goto err;
  }

  SerialUSB.print("Current humidity = ");
  SerialUSB.print(humi);
  SerialUSB.print("%  ");
  SerialUSB.print("temperature = ");
  SerialUSB.print(temp);
  SerialUSB.print("C / Door: ");
  SerialUSB.println(door);

  sprintf(data,"{\"temp\":%.1f,\"humi\":%.1f,\"door\":%d}", temp, humi,door);
#else
  sprintf(data, "{\"uptime\":%lu}", millis() / 1000);
#endif // SENSOR_PIN

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

////////////////////////////////////////////////////////////////////////////////////////
//

#ifdef SENSOR_PIN

int TemperatureAndHumidityPin;

void TemperatureAndHumidityBegin(int pin)
{
  TemperatureAndHumidityPin = pin;
  DHT11Init(TemperatureAndHumidityPin);
}

bool TemperatureAndHumidityRead(float* temperature, float* humidity)
{
  byte data[5];

  DHT11Start(TemperatureAndHumidityPin);
  for (int i = 0; i < 5; i++) data[i] = DHT11ReadByte(TemperatureAndHumidityPin);
  DHT11Finish(TemperatureAndHumidityPin);

  if(!DHT11Check(data, sizeof (data))) return false;
  if (data[1] >= 10) return false;
  if (data[3] >= 10) return false;

  *humidity = (float)data[0] + (float)data[1] / 10.0f;
  *temperature = (float)data[2] + (float)data[3] / 10.0f;

  return true;
}

#endif // SENSOR_PIN

////////////////////////////////////////////////////////////////////////////////////////
//

#ifdef SENSOR_PIN

void DHT11Init(int pin)
{
  digitalWrite(pin, HIGH);
  pinMode(pin, OUTPUT);
}

void DHT11Start(int pin)
{
  // Host the start of signal
  digitalWrite(pin, LOW);
  delay(18);

  // Pulled up to wait for
  pinMode(pin, INPUT);
  while (!digitalRead(pin)) ;

  // Response signal
  while (digitalRead(pin)) ;

  // Pulled ready to output
  while (!digitalRead(pin)) ;
}

byte DHT11ReadByte(int pin)
{
  byte data = 0;

  for (int i = 0; i < 8; i++) {
    while (digitalRead(pin)) ;

    while (!digitalRead(pin)) ;
    unsigned long start = micros();

    while (digitalRead(pin)) ;
    unsigned long finish = micros();

    if ((unsigned long)(finish - start) > 50) data |= 1 << (7 - i);
  }

  return data;
}

void DHT11Finish(int pin)
{
  // Releases the bus
  while (!digitalRead(pin)) ;
  digitalWrite(pin, HIGH);
  pinMode(pin, OUTPUT);
}

bool DHT11Check(const byte* data, int dataSize)
{
  if (dataSize != 5) return false;

  byte sum = 0;
  for (int i = 0; i < dataSize - 1; i++) {
    sum += data[i];
  }

  return data[dataSize - 1] == sum;
}

#endif // SENSOR_PIN

////////////////////////////////////////////////////////////////////////////////////////
```

### 通常モードに変更
書き込みが終了後、RSTボタンを押します。
