# Maker Faire Tokyo 2018 
## 地震測定計を作ってみよう！ IoT ハンズオン

## 本日の機材
各自の机の上に、本日必要な機材を用意しています。
* パソコン
* 有効なSORACOMアカウント（すでにソラコム側でアカウントを作成済みです）
* SORACOMアカウントに登録済みの SORACOM Air SIM （すでにWio LTEの中に入っています）
* [Grove IoT スターターキット for SORACOM](https://soracom.jp/products/#grovestarter_kit)

![機材](https://docs.google.com/drawings/d/e/2PACX-1vQDtAOALHo8MhG_Hr1LUfVJvOfrVJjOslUvKhTvGKmcQ1KH849J-RsXl3VXsuTCytJJceyVkG3Rjlbl/pub?w=757&h=540)

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

外観からはどちらのモードで動いているのか判別できません。

![DFUモードへの移行](http://drive.google.com/uc?export=view&id=1447mCTbYS7iMTtVWaTkXJzHD8vJ8lprJ)
![Wio LTE を横からみた図](https://docs.google.com/drawings/d/e/2PACX-1vRnhRiZC7-jRCqLaxJO6E7Bmq0_8BxornXgP1y6UHdYXhr6iBm_RNoV148oSzJKeHBYXRjYai9msQoz/pub?w=480&h=249)

<h2 id="handson1">1. LEDの色を変えてみよう！</h3>

1. 配線
D20端子にボタンセンサーを取り付けます。

写真

2. 赤色のデバイスにスケッチ例を書き込む

Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。

「対応デバイスが見つかりませんでした」 が一覧に表示された場合は Wio LTE が DFU モードになっていません。 DFU モードへの移行操作をしてください。



「【LEDの色を変えてみよう】を書き込む」をクリックして、スケッチ例を書き込みます。


<h2 id="handson1">2. 超音波センサーでLEDの色を変えてみよう！</h3>

1. 配線
A6端子に超音波センサーを取り付けます。

写真

2. 赤色のデバイスにスケッチ例を書き込む

Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。

「対応デバイスが見つかりませんでした」 が一覧に表示された場合は Wio LTE が DFU モードになっていません。 DFU モードへの移行操作をしてください。



「【超音波センサーでLEDの色を変えてみよう】を書き込む」をクリックして、スケッチ例を書き込みます。



3. LEDの色を確認
超音波センサーに手を近づけてみてください。超音波センサーの距離に応じて、LEDの色が変化します。


<h2 id="handson2">3. 地震測定計を作ってみよう！</h3>

1. 配線
A4端子にブザーと、I2C端子に3軸デジタル加速度センサーを取り付けます。

写真

2. 赤色のデバイスにスケッチ例を書き込む

Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。
「対応デバイスが見つかりませんでした」 が一覧に表示された場合は Wio LTE が DFU モードになっていません。 DFU モードへの移行操作をしてください。


「【地震測定計を作ってみよう】を書き込む」をクリックして、スケッチ例を書き込みます。


3. 震度を測ってみよう

センサーを家に取り付けてお家を揺らしてみましょう。

震度の大きさによりLEDの色が変化します。




4. SORACOM  Harvestで地震測定状況を可視化します。
どれくらいの震度の地震が発生したかを、グラフで表示します。

ソラコムのアカウントにログインします。

[アカウントログインページ](https://console.soracom.io/#/?coverage_type=jp)  
[https://console.soracom.io/#/?coverage_type=jp](https://console.soracom.io/#/?coverage_type=jp)

ログイン情報はPC横の紙をご覧ください。
メールアドレス、パスワードを入力し、ログインをクリックします。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTy5KORqQjieOg-ijF5CLyfhALMq-CmE8G9822NahydZSw5zIYqcz4efiru6R5n1RjAEaotdmfNmXsN/pub?w=444&h=250)

SIMを選択し、「操作」からデータを確認を選びます。

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTyI9zm46Q4RYmDi6wYD0_Q0sFUfmJu-XH_KYR_eDmR7u0ydc1nqIj0jhV_bf1fB5NNn2N_OUEcYHY-/pub?w=455&h=522)

SORACOM Harvest のグラフで下記のように表示されたら成功です。
5秒間のうちに一番大きなデータが送信されます。



## SORACOM Lagoonで可視化する
SORACOM Harvestで収集したデータを利用して、ダッシュボードを作成することができます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vS-bFScvPoTOptNh5O2sJb1dMtwEunlQ7MadcTuIj9JtLXWmD7knnpKx5SDe1NE-TSkbRdqj8KgWvRq/pub?w=932&amp;h=433">
