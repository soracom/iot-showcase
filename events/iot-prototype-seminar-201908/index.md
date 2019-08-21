# Let's IoT プロトタイピング！ オンライン講座 〜雨雲レーダー表示デバイスを M5Stack で作ってみよう〜

### イベントページ

* [Day1](https://pages.soracom.jp/20190829_IoT_Prototype_seminar.html)
* [Day2](https://pages.soracom.jp/20190830_IoT_Prototype_seminar.html)

## セミナー中で使用するプログラムの配布や設定方法

### Day 1

#### Arduino IDE

Arduino IDEは[Arduinoのサイトからダウンロード](https://www.arduino.cc/en/Main/software)をし、インストールを行います。

注: Windowsの場合はWindows Installer版、Windows app版の２つがありますが、**Windows Installer**版での動作を確認しています。

#### ESP32用ボード定義

M5StackはマイコンにESP32を使用しています。Arduino IDEは標準ではESP32の開発環境が入っていませんが、環境設定から追加することができるため、その設定をおこないます。

手順は以下の通りです。

* Arduino IDEのメニューから [ファイル] > [環境設定] で表示されるダイアログ上で **追加のボードマネージャのURL** に、以下のURLを記載します。

```
https://dl.espressif.com/dl/package_esp32_index.json
```

* Arduino IDEのメニューから [ツール] > [ボード: ...] > [ボードマネージャ] で表示されるダイアログ上で `esp32 by Espressif Systems` をインストールします。
    * ※ TIPS: `esp32` で検索すると見つけやすいです

#### M5Stack用ライブラリ

M5Stack用のライブラリをインストールします。

手順は以下の通りです。

* Arduino IDEのメニューから [ツール] > [ライブラリを管理] で表示されるダイアログ上で `M5Stack by M5Stack` をインストールします。
    * ※ TIPS: `m5stack` で検索すると見つけやすいです

### CP210X Driver (仮想シリアルポートドライバ)

M5Stackへスケッチ（Arduino IDEではプログラムを「スケッチ」と称しています）を転送したり、M5Stackのデバッグ出力を受け取るための仮想シリアルポートドライバをインストールします。

[M5Stack公式サイトのDownloadページ](https://m5stack.com/pages/download)の **CP210X Driver** をお使いのOSに合わせてダウンロード、インストールします。

### 3G拡張ボードを利用するための追加ライブラリ

M5Stack用3G拡張ボードを利用するためのライブラリをセットアップします。今回はTinyGSMというオープンソースライブラリを利用します。

手順は以下の通りです。

* Arduino IDEのメニューから [ツール] > [ライブラリを管理] で表示されるダイアログ上で `TinyGSM by Volodymyr Shymanskyy` をインストールします。
    * ※ TIPS: `tinygsm` で検索すると見つけやすいです

### World Time API (m5stack_3gextboard_worldclock.ino)

```c++
/*
 * Copyright (c) 2019 Kohei "Max" MATSUSHITA
 * Released under the MIT license
 * https://opensource.org/licenses/mit-license.php
*/
#include <M5Stack.h>

#define TINY_GSM_MODEM_UBLOX
#include <TinyGsmClient.h>

TinyGsm modem(Serial2); /* 3G board modem */
TinyGsmClient ctx(modem);

void setup() {
  Serial.begin(115200);
  M5.begin();
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.println(F("M5Stack + 3G Module"));

  M5.Lcd.print(F("modem.restart()"));
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
  modem.restart();
  M5.Lcd.println(F("done"));

  M5.Lcd.print(F("getModemInfo:"));
  String modemInfo = modem.getModemInfo();
  M5.Lcd.println(modemInfo);

  M5.Lcd.print(F("waitForNetwork()"));
  while (!modem.waitForNetwork()) M5.Lcd.print(".");
  M5.Lcd.println(F("Ok"));

  M5.Lcd.print(F("gprsConnect(soracom.io)"));
  modem.gprsConnect("soracom.io", "sora", "sora");
  M5.Lcd.println(F("done"));

  M5.Lcd.print(F("isNetworkConnected()"));
  while (!modem.isNetworkConnected()) M5.Lcd.print(".");
  M5.Lcd.println(F("Ok"));

  M5.Lcd.print(F("My IP addr: "));
  IPAddress ipaddr = modem.localIP();
  M5.Lcd.print(ipaddr);
  delay(2000);
}

void loop() {
  M5.update();

  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println(F("World Clock from worldtimeapi.org"));

  /* HTTP GET example */
  if (!ctx.connect("worldtimeapi.org", 80)) {
    Serial.println(F("Connect failed."));
    return;
  }
  Serial.println(F("connected."));

  /* send request */
  ctx.println("GET /api/timezone/Asia/Tokyo.txt HTTP/1.0");
  ctx.println("Host: worldtimeapi.org");
  ctx.println();
  Serial.println("sent.");

  /* receive response */
  while (ctx.connected()) {
    String line = ctx.readStringUntil('\n');
    Serial.println(line);
    if (line == "\r") {
      Serial.println("headers received.");
      break;
    }
  }
  char buf[1 * 1024] = {0};
  ctx.readBytes(buf, sizeof(buf)); /* body */
  ctx.stop();
  M5.Lcd.println(buf);

  delay(1000 * 10);
}
```

### Day 2

#### Yahoo! デベロッパーネットワーク ― YOLP(地図) / アプリケーションIDの登録

雨雲レーダーを利用するためにはYahoo! JAPAN IDとは別に「アプリケーションID」の登録が必要です。 (YOLPの利用にはYahoo! JAPAN ID（無償）が必要となります。)

手順は以下の通りです。

1. [アプリケーション管理](https://e.developer.yahoo.co.jp/dashboard/) > [新しいアプリケーションを開発] に進みます
    * ログインが必要な場合はYahoo! JAPAN IDでログインしてください
2. **アプリケーション情報の入力** では、以下のようにしてから [確認] に進みます
    * アプリケーションの種類: *サーバーサイド（Yahoo! ID連携 v2）*
    * アプリケーション名: `M5Stack RainRadar app` (任意で構いません)
    * サイトURL: (ご自分のブログや会社のURLを記入ください)
    * ガイドラインの同意へのチェック
3. **入力内容の確認** では、内容を確認して [登録] に進みます。

以上で **Client ID** と **シークレット** が発行されます。

##### ブラウザでテスト

先ほど入手した **Client ID** を使って、まずはブラウザで雨雲レーダーを表示してみます。以下のURLをブラウザのアドレスバーに入力してください。

その際、 `<YOUR_CLIENT_ID>` を先ほどの **Client ID** に置き換えてください。

```
https://map.yahooapis.jp/map/V1/static?appid=<YOUR_CLIENT_ID>&output=jpg&quality=50&width=320&height=208&overlay=type:rainfall%7Cdatelabel:off&mode=map&style=base:simple&z=8&lat=35.6313456&lon=139.7312189
```

#### 雨雲レーダー表示 (m5stack_rainradar.ino)

```c++
/*
 * Copyright (c) 2019 Kohei "Max" MATSUSHITA
 * Released under the MIT license
 * https://opensource.org/licenses/mit-license.php
*/
#include <M5Stack.h>
#define CONSOLE Serial
#define MODEM Serial2 /* Serial2 is Modem of 3G Module */
#include <string.h>

#define TINY_GSM_MODEM_UBLOX
#include <TinyGsmClient.h>
TinyGsm modem(MODEM);
TinyGsmClientSecure ctx(modem);

void modem_enabler();
void render_rain_radar();
void print_top();
void print_bottom();
uint16_t getColor(uint8_t red, uint8_t green, uint8_t blue);

void setup() {
  M5.begin();
  CONSOLE.begin(115200);
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextSize(2);
  
  print_top();
  print_bottom();
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(0, 16);
  M5.Lcd.println("## Congrats,");
  M5.Lcd.println("## Boot successfuly!");
}

void loop() {
  if (M5.BtnA.wasReleased()) {
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(218, 0);
    M5.Lcd.print(F("(prog..."));
    modem_enabler();
    get_and_render_rain_radar();
    print_top();
    print_bottom();
    modem.gprsDisconnect();
  }
  M5.update();
}

/* ------------------------------------------------------------*/

void modem_enabler() {
  M5.Lcd.setTextColor(WHITE);
  MODEM.begin(115200, SERIAL_8N1, 16, 17);

  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.println(F("modem.restart()"));
  CONSOLE.println(F("modem.restart()"));
  modem.restart();
  
  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.println(F("waitForNetwork()"));
  CONSOLE.println(F("waitForNetwork()"));
  while (!modem.waitForNetwork()) M5.Lcd.print(".");

  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.println(F("gprsConnect(soracom.io)"));
  CONSOLE.println(F("gprsConnect(soracom.io)"));
  modem.gprsConnect("soracom.io", "sora", "sora");

  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.println(F("isNetworkConnected()"));
  CONSOLE.println(F("isNetworkConnected()"));
  while (!modem.isNetworkConnected()) M5.Lcd.print(".");

  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.print(F("MyIP:"));
  CONSOLE.print(F("MyIP: "));
  IPAddress ipaddr = modem.localIP();
  M5.Lcd.println(ipaddr);
  CONSOLE.println(ipaddr);
}

char _buf[32*1024] = {0}; /* store for JPG image data */
void get_and_render_rain_radar() {
  /* connect to host */
  const char *host = "map.yahooapis.jp";
  const int port = 443;
  int timeout_s = 60;
  CONSOLE.print("Connecting:");
  CONSOLE.println(host);
  if (!ctx.connect(host, port, timeout_s)) {
    CONSOLE.println("fail");
    return;
  }

  /* send request */
  const char *path = "GET /map/V1/static?appid=<YOUR_CLIENT_ID>&output=jpg&quality=50&width=320&height=208&overlay=type:rainfall%7Cdatelabel:off&mode=map&style=base:simple&z=8&lat=35.6313456&lon=139.7312189 HTTP/1.0";
  CONSOLE.println(path);
  ctx.println(path);
  ctx.print("Host: ");
  ctx.println(host);
  ctx.println();
  Serial.println("sent.");

  /* receive response */
  while (ctx.connected()) {
    String line = ctx.readStringUntil('\n');
    CONSOLE.println(line);
    if (line == "\r") {
      CONSOLE.println("headers received.");
      break;
    }
  }
  ctx.readBytes(_buf, sizeof(_buf)); /* body */
  ctx.stop();
  
  /* rendering */
  size_t _buf_s = strlen(_buf);
  CONSOLE.println(_buf_s);
  CONSOLE.println(_buf);
  M5.Lcd.drawJpg((const unsigned char *)_buf, _buf_s, 0, 16);
  _buf[0] = '\0'; /* cleanup */
  CONSOLE.println("done.");
}

void print_top() {
  M5.Lcd.fillRect(0, 0, 320, 16, getColor(51, 244, 204));
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(F("RainRadar by YOLP"));
}

void print_bottom() {
  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.print(F("Btn => Retreve RainRadar"));
}

uint16_t getColor(uint8_t red, uint8_t green, uint8_t blue) {
  return ((red>>3)<<11) | ((green>>2)<<5) | (blue>>3);
}
```

#### SORACOM Beam 設定

まず、SORACOM Beam 上に「 `/rainradar` のアクセスを `map.yahooapis.jp/map/V1/static?....` に転送する」設定を行います。

手順は以下の通りです。

1. [SORACOM ユーザコンソール](https://console.soracom.io) > [(左上の) Menu] > [SIM 管理] に進みます (すでにSIM一覧が表示されている場合は遷移しないので、左上の "SORACOMロゴ" をクリックしてください)
2. SIM一覧から、M5Stackに取り付けているSIMの「チェックボックス」にチェックを付けた後、[操作] > [所属グループ変更] に進みます
3. "SIM の所属グループ変更" ダイアログでは、 **新しい所属グループ** のプルダウンをクリックし、 [新しいグループを作成] に進みます
4. "グループ作成" ダイアログでは、**グループ名** に `yahooapis-for-m5stack` (任意の文字列でも可) を入力して [グループ作成] に進みます
5. すると "SIM の所属グループ変更" ダイアログに戻ります。 **新しい所属グループ** に *yahooapis-for-m5stack* が設定されている事を確認して [グループ変更] に進みます
6. SIM一覧の **グループ** 列に表示されている *yahooapis-for-m5stack* のリンクをクリックします
7. "SIM グループ" で [SORACOM Beam 設定] をクリックしてから [＋] > [HTTP エントリポイント] に進みます
8. "SORACOM Beam - HTTP 設定" ダイアログでは、以下のように入力してから [保存] に進みます
    * パス: `/rainradar`
    * プロトコル: *HTTPS*
    * ホスト名: `map.yahooapis.jp`
    * ポート番号: (なにも入力しません)
    * パス: `/map/V1/static?appid=<YOUR_CLIENT_ID>&output=jpg&quality=50&width=320&height=208&overlay=type:rainfall%7Cdatelabel:off&mode=map&style=base:simple&z=8&lat=35.6313456&lon=139.7312189`
        * **注意:** パスの `<YOUR_CLIENT_ID>` を **Client ID** に置き換えてください

以上で SORACOM Beam の設定は終了です。

#### 雨雲レーダー表示 / SORACOM Beam 対応版 (m5stack_rainradar_with_soracom_beam.ino)

```c++
/*
 * Copyright (c) 2019 Kohei "Max" MATSUSHITA
 * Released under the MIT license
 * https://opensource.org/licenses/mit-license.php
*/
#include <M5Stack.h>
#define CONSOLE Serial
#define MODEM Serial2 /* Serial2 is Modem of 3G Module */
#include <string.h>

#define TINY_GSM_MODEM_UBLOX
#include <TinyGsmClient.h>
TinyGsm modem(MODEM);
TinyGsmClient ctx(modem);

void modem_enabler();
void render_rain_radar();
void print_top();
void print_bottom();
uint16_t getColor(uint8_t red, uint8_t green, uint8_t blue);

void setup() {
  M5.begin();
  CONSOLE.begin(115200);
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextSize(2);
  
  print_top();
  print_bottom();
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(0, 16);
  M5.Lcd.println("## Congrats,");
  M5.Lcd.println("## Boot successfuly!");
}

void loop() {
  if (M5.BtnA.wasReleased()) {
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(218, 0);
    M5.Lcd.print(F("(prog..."));
    modem_enabler();
    get_and_render_rain_radar();
    print_top();
    print_bottom();
    modem.gprsDisconnect();
  }
  M5.update();
}

/* ------------------------------------------------------------*/

void modem_enabler() {
  M5.Lcd.setTextColor(WHITE);
  MODEM.begin(115200, SERIAL_8N1, 16, 17);

  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.println(F("modem.restart()"));
  CONSOLE.println(F("modem.restart()"));
  modem.restart();
  
  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.println(F("waitForNetwork()"));
  CONSOLE.println(F("waitForNetwork()"));
  while (!modem.waitForNetwork()) M5.Lcd.print(".");

  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.println(F("gprsConnect(soracom.io)"));
  CONSOLE.println(F("gprsConnect(soracom.io)"));
  modem.gprsConnect("soracom.io", "sora", "sora");

  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.println(F("isNetworkConnected()"));
  CONSOLE.println(F("isNetworkConnected()"));
  while (!modem.isNetworkConnected()) M5.Lcd.print(".");

  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.print(F("MyIP:"));
  CONSOLE.print(F("MyIP: "));
  IPAddress ipaddr = modem.localIP();
  M5.Lcd.println(ipaddr);
  CONSOLE.println(ipaddr);
}

char _buf[32*1024] = {0}; /* store for JPG image data */
void get_and_render_rain_radar() {
  /* connect to host */
  const char *host = "beam.soracom.io";
  const int port = 8888;
  int timeout_s = 60;
  CONSOLE.print("Connecting:");
  CONSOLE.println(host);
  if (!ctx.connect(host, port, timeout_s)) {
    CONSOLE.println("fail");
    return;
  }

  /* send request */
  const char *path = "GET /rainradar HTTP/1.0";
  CONSOLE.println(path);
  ctx.println(path);
  ctx.print("Host: ");
  ctx.println(host);
  ctx.println();
  Serial.println("sent.");

  /* receive response */
  while (ctx.connected()) {
    String line = ctx.readStringUntil('\n');
    CONSOLE.println(line);
    if (line == "\r") {
      CONSOLE.println("headers received.");
      break;
    }
  }
  ctx.readBytes(_buf, sizeof(_buf)); /* body */
  ctx.stop();
  
  /* rendering */
  size_t _buf_s = strlen(_buf);
  CONSOLE.println(_buf_s);
  CONSOLE.println(_buf);
  M5.Lcd.drawJpg((const unsigned char *)_buf, _buf_s, 0, 16);
  _buf[0] = '\0'; /* cleanup */
  CONSOLE.println("done.");
}

void print_top() {
  M5.Lcd.fillRect(0, 0, 320, 16, getColor(51, 244, 204));
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(F("RainRadar by YOLP"));
}

void print_bottom() {
  M5.Lcd.fillRect(0, 224, 320, 16, BLACK); /* clean up */
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(0, 224);
  M5.Lcd.print(F("Btn => Retreve RainRadar"));
}

uint16_t getColor(uint8_t red, uint8_t green, uint8_t blue) {
  return ((red>>3)<<11) | ((green>>2)<<5) | (blue>>3);
}
```

##### 差分

```diff
--- m5stack_rainradar.ino       2019-08-21 08:43:01.819963700 +0900
+++ m5stack_rainradar_with_soracom_beam.ino     2019-08-21 08:42:25.247913200 +0900
@@ -11,7 +11,7 @@
 #define TINY_GSM_MODEM_UBLOX
 #include <TinyGsmClient.h>
 TinyGsm modem(MODEM);
-TinyGsmClientSecure ctx(modem);
+TinyGsmClient ctx(modem);

 void modem_enabler();
 void render_rain_radar();
@@ -89,8 +89,8 @@
 char _buf[32*1024] = {0}; /* store for JPG image data */
 void get_and_render_rain_radar() {
   /* connect to host */
-  const char *host = "map.yahooapis.jp";
-  const int port = 443;
+  const char *host = "beam.soracom.io";
+  const int port = 8888;
   int timeout_s = 60;
   CONSOLE.print("Connecting:");
   CONSOLE.println(host);
@@ -100,7 +100,7 @@
   }

   /* send request */
-  const char *path = "GET /map/V1/static?appid=<YOUR_CLIENT_ID>&output=jpg&quality=50&width=320&height=208&overlay=type:rainfall%7Cdatelabel:off&mode=map&style=base:simple&z=8&lat=35.6313456&lon=139.7312189 HTTP/1.0";
+  const char *path = "GET /rainradar HTTP/1.0";
   CONSOLE.println(path);
   ctx.println(path);
   ctx.print("Host: ");
```
