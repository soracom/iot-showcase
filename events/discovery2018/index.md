# SORACOM Conference "Discovery" 2018
## 今すぐ始めよう SORACOM ”自習”コーナー Wio LTE ハンズオン

## 目的
LTEモジュールが搭載された[Wio LTEデバイス](https://soracom.jp/products/wio_lte/)、様々なGroveセンサー、SORACOM SIMカードを使い、簡単なIoTシステムを体感いただきます。

## 本日の前提
こちらのハンズオンでは、既に SORACOM アカウントとそれに紐づくSIMカードに加え、Wio LTEデバイスを利用するために必要な環境のセットアップを今回は用意しています。
また、本ハンズオンはご自身でテキストに沿って進めていただく形式です。スタッフはおりませんので、自力で対応いただける方にご参加いただいてます。

## 本日の機材
各自の机の上に、本日必要な機材を用意しています。
* パソコン
* 有効なSORACOMアカウント
* SORACOMアカウントに登録済みの SORACOM Air SIM （すでにWio LTEの中に入っています）
* [Grove IoT スターターキット for SORACOM](https://soracom.jp/products/#grovestarter_kit)

## DFUモードへの切り替え方
Wio LTE は２つのモードを持っています
**この操作は Wio LTE の開発で何度も行うことになりますので、必ず覚えてください**

* 書き込まれたプログラムを実行する「通常モード」
* プログラムを書き込むことができる「DFUモード」

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vQAcnymqWTTneRwnc9EFz21YvrmfCsIuV33yfqf1ODC_LKQR-6762CJDMclRIWC8BfUeDDLpC6KKs-2/pub?w=581&h=253)

「通常モード」の Wio LTE に対して、下記操作を行います

1. *BOOTボタン* を押し、 **押し続けてください**
2. *RSTボタン* を押し、離します
3. 押し続けていた *BOOTボタン* を離します

DFUモードへの移行方法  
※動画ではmicroUSB接続をしていませんが、実際は接続した状態で行ってください

![DFUモードへの移行](http://drive.google.com/uc?export=view&id=1447mCTbYS7iMTtVWaTkXJzHD8vJ8lprJ)
![Wio LTE を横からみた図](https://docs.google.com/drawings/d/e/2PACX-1vRnhRiZC7-jRCqLaxJO6E7Bmq0_8BxornXgP1y6UHdYXhr6iBm_RNoV148oSzJKeHBYXRjYai9msQoz/pub?w=480&h=249)


## Wio LTE ハンズオンでできること
本 Wio LTE ハンズオンは、3種類の簡単なIoTの仕組みを体験いただきます。
1. 室内環境センシングシステムを作ってみよう！
2. 駐車場管理システムを作ってみよう！
3. GPSトラッカーを作ってみよう！


## スケッチ例を書き込んでみよう
<h3 id="handson1">1. 室内環境センシングシステムを作ってみよう！</h3>

1-1. 配線
D38 に「GROVE - デジタル温度・湿度センサ」を接続します。 Wio LTEをPCにつなげてください。
![配線](../../images/projects/WioLTE/air-condition/sensor.jpg)

1-2. Wio LTEにスケッチ例を書き込む
[こちら](https://soracom.github.io/iot-showcase/events/discovery2018/webdfu/)のページをクリックし、手順に沿って書き込みを行ってください。

1-2-1. Connect ボタンを押し、**STM32 BOOTLOADER**を選択して接続します。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vSLU7C6SEV16bra_ko2xoBdlNYC64JaSbK06EZ7YG0-tkYS7nwk5EWGzJTPkLwFcdBTkApn7E08d3_U/pub?w=480&h=360)

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vRqDKcttYBSi-f9uHFkOa5f-DKWIwafpvZExjS_SKInhhK4L4Rv3cHmwuHtZAZoeKfGn9iD-NzYm1mg/pub?w=480&h=360)

1-2-2. 「【室内環境センシング】を書き込む」をクリックして、スケッチ例を書き込みます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vRyhUTHrXJXJ7jT6RWL25Dv4ZzuGTmoLGa37ypqUqg2AsCqIfYtB1oE3EzRfm_ykYV6cX1j5NwbRroL/pub?w=480&h=360)

1-3. SORACOM Harvestでデータを可視化しよう
ソラコムのアカウントにログインします。ログイン情報はPC横の紙をご覧ください。
SIMを選択し、「操作」からデータを確認を選びます。

![フロー](https://docs.google.com/presentation/d/e/2PACX-1vSu5rC9tWnoJWSPlp38m5cgOGwU_qGw9X5fc9o4Xs_CwHCb5-BfkruMPcXndIRWynkclRyD5B26QUxl/pub?start=false&loop=false&delayms=3000)

Harvestのグラフで下記のように表示されたら成功です。
涼しい時には青色、ちょうどいい時には緑色、暑い時には赤色と、不快指数に応じて LED の色を変更します。
![グラフ例](../../images/projects/WioLTE/air-condition/harvest.png)

<h3 id="handson2">2. 駐車場管理システムを作ってみよう！/h3>

2-1. 配線
A6 端子に 超音波センサーを取りつけます。

![配線](../../images/projects/WioLTE/parking/parking.jpg)

2-2. Wio LTEにスケッチ例を書き込む
[こちら](https://soracom.github.io/iot-showcase/events/discovery2018/webdfu/)のページをクリックし、手順に沿って書き込みを行ってください。

2-2-1. Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vSLU7C6SEV16bra_ko2xoBdlNYC64JaSbK06EZ7YG0-tkYS7nwk5EWGzJTPkLwFcdBTkApn7E08d3_U/pub?w=480&h=360)

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vRqDKcttYBSi-f9uHFkOa5f-DKWIwafpvZExjS_SKInhhK4L4Rv3cHmwuHtZAZoeKfGn9iD-NzYm1mg/pub?w=480&h=360)

2-2-2. 「【駐車場管理】を書き込む」をクリックして、スケッチ例を書き込みます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTkEx3-P_uEmgUsz08BlOswjE0thl1TfmkKGmm85hRxfIe_SPVxtyP7sLZsidhff-3L2ZicRCpsMbKJ/pub?w=480&h=360)

<h3 id="handson2">3. GPSトラッカーを作ってみよう！/h3>

3-1. 配線
UART 端子に GPS モジュールを接続します。
D20 端子にボタンを接続しておくと、ボタンを押した時にすぐデータを送信します。
![配線](../../images/projects/WioLTE/gps-tracker/gps-tracker.jpg)

3-2. Wio LTEにスケッチ例を書き込む
[こちら](https://soracom.github.io/iot-showcase/events/discovery2018/webdfu/)のページをクリックし、手順に沿って書き込みを行ってください。

3-2-1. Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vSLU7C6SEV16bra_ko2xoBdlNYC64JaSbK06EZ7YG0-tkYS7nwk5EWGzJTPkLwFcdBTkApn7E08d3_U/pub?w=480&h=360)

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vRqDKcttYBSi-f9uHFkOa5f-DKWIwafpvZExjS_SKInhhK4L4Rv3cHmwuHtZAZoeKfGn9iD-NzYm1mg/pub?w=480&h=360)

3-2-2. GPSトラッカーをクリックし書き込みます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vQv9l2M5ylFyVP1rdZw97NPg_U4W3KtPGBi-MMp3tDArwztb9gjuh8H4AjifPhqIt8FCC7sEgDv-JwF/pub?w=468&h=201)

3-3. 
