# SORACOM Conference "Discovery" 2018
## 今すぐ始めよう SORACOM ”自習”コーナー Wio LTE ハンズオン

## 目的
LTEモジュールが搭載された[Wio LTEデバイス](https://soracom.jp/products/wio_lte/)、様々なGroveセンサー、SORACOM SIMカードを使い、簡単なIoTシステムを体感いただきます。

## 本日の前提
こちらのハンズオンでは、既に PC、SORACOM アカウントとそれに紐づくSIMカードに加え、Wio LTEデバイスを利用するために必要な環境のセットアップを用意しています。
また、本ハンズオンはご自身でテキストに沿って進めていただく形式です。スタッフはおりませんので、自力で対応いただける方にご参加いただいてます。

## 本日の機材
各自の机の上に、本日必要な機材を用意しています。
* パソコン
* 有効なSORACOMアカウント（すでにソラコム側でアカウントを作成済みです）
* SORACOMアカウントに登録済みの SORACOM Air SIM （すでにWio LTEの中に入っています）
* [Grove IoT スターターキット for SORACOM](https://soracom.jp/products/#grovestarter_kit)

![機材](https://docs.google.com/drawings/d/e/2PACX-1vQDtAOALHo8MhG_Hr1LUfVJvOfrVJjOslUvKhTvGKmcQ1KH849J-RsXl3VXsuTCytJJceyVkG3Rjlbl/pub?w=376&h=304)

## DFUモードへの切り替え方
Wio LTE は２つのモードを持っています
**この操作は Wio LTE の開発で何度も行うことになりますので、必ず覚えてください**

* 書き込まれたプログラムを実行する「通常モード」
* プログラムを書き込むことができる「DFUモード」（Device Firmware Upgradeモード）

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
1. [室内環境センシングシステムを作ってみよう！](#handson1)
2. [駐車場管理システムを作ってみよう！](#handson2)
3. [GPSトラッカーを作ってみよう！](#handson3)


## スケッチ例を書き込んでみよう
<h3 id="handson1">1. 室内環境センシングシステムを作ってみよう！</h3>

1-1. 配線
D38 に「GROVE - デジタル温度・湿度センサ」を接続、D20 端子にボタンを接続します。 Wio LTEをPCにつなげてください。

![配線](https://docs.google.com/drawings/d/e/2PACX-1vRGopQ9w7dm2zPRSmiQJ4ybo0J9vJTxeovG0Ch2ZR27xewwxm8KIcHOyT5p1gZ2Rz2ScE0IYr_-X6YC/pub?w=392&h=271)

1-2. Wio LTEにスケッチ例を書き込む

下記の「スケッチ書き込みページをページをクリックし、手順に沿って書き込みを行ってください。

[スケッチ書き込みページ](https://soracom.github.io/iot-showcase/events/discovery2018/webdfu/)

1-2-1. Connect ボタンを押し、**STM32 BOOTLOADER**を選択して接続します。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vSLU7C6SEV16bra_ko2xoBdlNYC64JaSbK06EZ7YG0-tkYS7nwk5EWGzJTPkLwFcdBTkApn7E08d3_U/pub?w=480&h=360)

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vRqDKcttYBSi-f9uHFkOa5f-DKWIwafpvZExjS_SKInhhK4L4Rv3cHmwuHtZAZoeKfGn9iD-NzYm1mg/pub?w=480&h=360)

1-2-2. 「【室内環境センシング】を書き込む」をクリックして、スケッチ例を書き込みます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vRyhUTHrXJXJ7jT6RWL25Dv4ZzuGTmoLGa37ypqUqg2AsCqIfYtB1oE3EzRfm_ykYV6cX1j5NwbRroL/pub?w=480&h=360)

書き込んだコードを知りたい方はこちらをクリックください。

[室内環境センシングコード](https://github.com/soracom/iot-showcase/tree/master/projects/WioLTE/air-condition)

1-3. SORACOM Harvestでデータを可視化しよう

ソラコムのアカウントにログインします。

[アカウントログインページ](https://console.soracom.io/#/?coverage_type=jp)

ログイン情報はPC横の紙をご覧ください。
メールアドレス、パスワードを入力し、ログインをクリックします。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTy5KORqQjieOg-ijF5CLyfhALMq-CmE8G9822NahydZSw5zIYqcz4efiru6R5n1RjAEaotdmfNmXsN/pub?w=444&h=250)

SIMを選択し、「操作」からデータを確認を選びます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTyI9zm46Q4RYmDi6wYD0_Q0sFUfmJu-XH_KYR_eDmR7u0ydc1nqIj0jhV_bf1fB5NNn2N_OUEcYHY-/pub?w=455&h=522)

Harvestのグラフで下記のように表示されたら成功です。
tempは気温、humiは湿度、heatは不快進数を表示しています。

涼しい時には青色、ちょうどいい時には緑色、暑い時には赤色と、不快指数に応じて LED の色が変更します。

![グラフ例](https://docs.google.com/drawings/d/e/2PACX-1vQTyEmgPl4GJGw-FmHeM6KaDzDaapLHAjM8jytT3UuIv4vuCU-TE2CQ5oli_7mtIh6Evy4FHfWt87of/pub?w=923&h=425)

<h3 id="handson2">2. 駐車場管理システムを作ってみよう！</h3>

2-1. 配線
A6 端子に 超音波センサーを取りつけます。

![配線](https://docs.google.com/drawings/d/e/2PACX-1vTaIKS1s_HP3ygPyJGBq6sqSsSjgr15Hqw5fDn7K_VHK5xC0LbaCgqSybqM7bgw7uioixlYGVCfkGo7/pub?w=892&h=543)

2-2. Wio LTEにスケッチ例を書き込む

下記の「スケッチ書き込みページをページをクリックし、手順に沿って書き込みを行ってください。

[スケッチ書き込みページ](https://soracom.github.io/iot-showcase/events/discovery2018/webdfu/)

2-2-1. Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vSLU7C6SEV16bra_ko2xoBdlNYC64JaSbK06EZ7YG0-tkYS7nwk5EWGzJTPkLwFcdBTkApn7E08d3_U/pub?w=480&h=360)

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vRqDKcttYBSi-f9uHFkOa5f-DKWIwafpvZExjS_SKInhhK4L4Rv3cHmwuHtZAZoeKfGn9iD-NzYm1mg/pub?w=480&h=360)

2-2-2. 「【駐車場管理】を書き込む」をクリックして、スケッチ例を書き込みます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTkEx3-P_uEmgUsz08BlOswjE0thl1TfmkKGmm85hRxfIe_SPVxtyP7sLZsidhff-3L2ZicRCpsMbKJ/pub?w=480&h=360)

書き込んだコードを知りたい方はこちらをクリックください。

[駐車場管理コード](https://github.com/soracom/iot-showcase/tree/master/projects/WioLTE/parking)

2-3. SORACOM Harvest で駐車時間を可視化します。

ソラコムのアカウントにログインします。

[アカウントログインページ](https://console.soracom.io/#/?coverage_type=jp)

ログイン情報はPC横の紙をご覧ください。
メールアドレス、パスワードを入力し、ログインをクリックします。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTy5KORqQjieOg-ijF5CLyfhALMq-CmE8G9822NahydZSw5zIYqcz4efiru6R5n1RjAEaotdmfNmXsN/pub?w=444&h=250)

SIMを選択し、「操作」からデータを確認を選びます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTyI9zm46Q4RYmDi6wYD0_Q0sFUfmJu-XH_KYR_eDmR7u0ydc1nqIj0jhV_bf1fB5NNn2N_OUEcYHY-/pub?w=455&h=522)

WioLTE で 駐車場の管理を行うスケッチです。超音波距離センサーを使って車がとの距離を計測し、一定の距離以下であった時は駐車しているとみなします。
超音波センサーに机の上にある車を近づけ、パーキングをしてみてください。

現在の車が駐車している時間（CurrentParkingSeconds)と、のべ駐車時間(TotalParkingSeconds)を Harvest に送信し、グラフにします。

![地図](https://docs.google.com/drawings/d/e/2PACX-1vTaIKS1s_HP3ygPyJGBq6sqSsSjgr15Hqw5fDn7K_VHK5xC0LbaCgqSybqM7bgw7uioixlYGVCfkGo7/pub?w=892&h=543)


<h3 id="handson3">3. GPSトラッカーを作ってみよう！</h3>

3-1. 配線

UART 端子に GPS モジュールを、接続します。
D20 端子にボタンを接続しておくと、ボタンを押した時にすぐデータを送信します。
![配線](https://docs.google.com/drawings/d/e/2PACX-1vSZbjBxW4XHm6QnbbuXIRQ28jxqqzU4WbkF6BAwXi_3m9aN9Y5fR-1Ir8EHSsK4tP9VAPWWKjxP-84H/pub?w=869&h=466)

3-2. Wio LTEにスケッチ例を書き込む


下記の「スケッチ書き込みページをページをクリックし、手順に沿って書き込みを行ってください。

[スケッチ書き込みページ](https://soracom.github.io/iot-showcase/events/discovery2018/webdfu/)


3-2-1. Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vSLU7C6SEV16bra_ko2xoBdlNYC64JaSbK06EZ7YG0-tkYS7nwk5EWGzJTPkLwFcdBTkApn7E08d3_U/pub?w=480&h=360)

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vRqDKcttYBSi-f9uHFkOa5f-DKWIwafpvZExjS_SKInhhK4L4Rv3cHmwuHtZAZoeKfGn9iD-NzYm1mg/pub?w=480&h=360)

3-2-2. GPSトラッカーをクリックし書き込みます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vQv9l2M5ylFyVP1rdZw97NPg_U4W3KtPGBi-MMp3tDArwztb9gjuh8H4AjifPhqIt8FCC7sEgDv-JwF/pub?w=468&h=201)

下記のように表示されたら書き込み終了です。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vS6GCEu22XTTC6XkXAie1VA935XZZ8eglrArgIi6Hephf7N4CZpVakGiwXpyfn3dd7eB_bw4LlGOaQN/pub?w=458&h=181)

書き込んだコードを知りたい方はこちらをクリックください。

[GPSトラッカーコード](https://github.com/soracom/iot-showcase/tree/master/projects/WioLTE/parking)


3-3. SORACOM Harvestでデータを位置情報をマッピングしよう

ソラコムのアカウントにログインします。

[アカウントログインページ](https://console.soracom.io/#/?coverage_type=jp)

ログイン情報はPC横の紙をご覧ください。
メールアドレス、パスワードを入力し、ログインをクリックします。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTy5KORqQjieOg-ijF5CLyfhALMq-CmE8G9822NahydZSw5zIYqcz4efiru6R5n1RjAEaotdmfNmXsN/pub?w=444&h=250)

SIMを選択し、「操作」からデータを確認を選びます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTyI9zm46Q4RYmDi6wYD0_Q0sFUfmJu-XH_KYR_eDmR7u0ydc1nqIj0jhV_bf1fB5NNn2N_OUEcYHY-/pub?w=455&h=522)

GPSの座標を SORACOM Harvest に送信します。SORACOM Harvest の位置情報データ表示モードを使うことで、簡単に GPS データの可視化が行えます。

GPSモジュールが接続されていない場合や、GPS モジュールの測位が出来ていない場合には、LTE の基地局情報を元に大雑把な位置を求めることが出来ます。

![地図](https://docs.google.com/drawings/d/e/2PACX-1vRZxVF2mgqfq0FAcUfojE6ARSAHIW0Wl7FMNQ7CEZTPHtsSkR2z4MiwrYpx6LHZ0DJ76h14cvbtB6UQ/pub?w=902&h=693)

