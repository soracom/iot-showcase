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

<h2 id="handson1">1. LEDの色を変えてみよう！</h2>

- 配線

D20端子にボタンセンサーを取り付けます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ3pNyAow0Q7A7POrhHF6X7fPOzTd9QywxTHXWVTiXVzuSs_0snALgZYHuVjQ5pqTr33_J5ezkae3y5/pub?w=845&amp;h=567">

- 赤色のデバイスにスケッチ例を書き込む

Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。

「対応デバイスが見つかりませんでした」 が一覧に表示された場合は Wio LTE が DFU モードになっていません。 DFU モードへの移行操作をしてください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSQr_8ZmzQnIGhIHvBEB4mBulseWBDbftprJUcPTL8nhTHSS1OA1xe946KaS0fsVpRHN8aElixD1V2z/pub?w=965&amp;h=455">

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ-XijjLxTrEF-rBCw90vMEb9NbGukflIj3CaNWlIckzY6vQnti8pQVGMA_MEMcr2vnq4mbJ80fVv5F/pub?w=715&amp;h=456">

「【ボタンでLEDの色を変えてみよう】を書き込む」をクリックして、スケッチ例を書き込みます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vStGWiiB8GMC7lJwWCaun3sLyJTwkD0JkhjWRYnk_4wJra6LjfkV-zqJkmoIRuB1N7iZdKv_EN42uev/pub?w=922&amp;h=389">

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRSXSCsMq8nWcRY-ev-JcWex8b-Xql14NjTroVok9R07kO5Jwp0JS4hGsjeyBqydqfspFhaBWeW_81L/pub?w=934&amp;h=430">

<h2 id="handson2">2. 超音波センサーでLEDの色を変えてみよう！</h2>

- 配線

A6端子に超音波センサーを取り付けます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRbHNbn3um_R6Y6HydoY5Hn2E__ggjxtuy5qKGan5wy5TvZNmyYZwZGVnfl3PH_OS-8IK13bao9Thz4/pub?w=831&amp;h=474">

- 赤色のデバイスにスケッチ例を書き込む

Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。

「対応デバイスが見つかりませんでした」 が一覧に表示された場合は Wio LTE が DFU モードになっていません。 DFU モードへの移行操作をしてください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSQr_8ZmzQnIGhIHvBEB4mBulseWBDbftprJUcPTL8nhTHSS1OA1xe946KaS0fsVpRHN8aElixD1V2z/pub?w=965&amp;h=455">

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ-XijjLxTrEF-rBCw90vMEb9NbGukflIj3CaNWlIckzY6vQnti8pQVGMA_MEMcr2vnq4mbJ80fVv5F/pub?w=715&amp;h=456">


「【超音波センサーでLEDの色を変えてみよう】を書き込む」をクリックして、スケッチ例を書き込みます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQzArbiqjaFa0_s5BqQXlK8OkG9lWnlkkV9Umh83IRXi7QKlry1eOGe4RDKulcus0eLlwjUZ2CU4AqC/pub?w=922&amp;h=389">


- LEDの色を確認
超音波センサーに手を近づけてみてください。超音波センサーの距離に応じて、LEDの色が変化します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vT2dgUscWaw_DO_rCqYiujKWt6kyEylUOR4Dl4HWevogxEGQM97A-5-AYfuoHQvr5aU66bY41x8Mkl6/pub?w=927&amp;h=537">

<h2 id="handson3">3. 地震測定計を作ってみよう！</h2>

- 配線

A4端子にブザーと、I2C端子に3軸デジタル加速度センサーを取り付けます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSovCwPE9qSJI2KD9Y2gWxExarpw03r4wa-ubcju3mB7YirJEt0ux9oBmN8x4TXVCRxAOrD9Xd69ffS/pub?w=930&amp;h=617">

- 赤色のデバイスにスケッチ例を書き込む

Connect ボタンを押し、**STM32 BOOTLOADER**を選択して「接続」をクリックします。
「対応デバイスが見つかりませんでした」 が一覧に表示された場合は Wio LTE が DFU モードになっていません。 DFU モードへの移行操作をしてください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSQr_8ZmzQnIGhIHvBEB4mBulseWBDbftprJUcPTL8nhTHSS1OA1xe946KaS0fsVpRHN8aElixD1V2z/pub?w=965&amp;h=455">

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ-XijjLxTrEF-rBCw90vMEb9NbGukflIj3CaNWlIckzY6vQnti8pQVGMA_MEMcr2vnq4mbJ80fVv5F/pub?w=715&amp;h=456">

「【地震測定計を作ってみよう】を書き込む」をクリックして、スケッチ例を書き込みます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vR0CIpQNXC6KD7uqai2uIWHg4H1HORx7XLeBZsj0dxUOQOaX04dMQbgUJa1Clf7aYkpnpJylwFdVXwN/pub?w=927&amp;h=379">

- 震度を測ってみよう

センサーを家に取り付けてお家を揺らしてみましょう。

震度の大きさによりLEDの色が変化します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQYoOyTs5UtUSI-ulTIqYZZLSbD9DYLDHUzGQQ92zy1fMkyElb_LJAZrvq05IPwDrJmwS5cS7palURS/pub?w=615&amp;h=504">

<img src="https://docs.google.com/drawings/d/e/2PACX-1vR5T24WqRus8i7PnA-qpGjZP_4XwRaKfGtNdB16ol0Uwa4uHZwiE0M8MTBR7cvKhqsen5whtj25Lhfl/pub?w=925&amp;h=599">


- SORACOM  Harvestで地震測定状況を可視化します。
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

<img src="https://docs.google.com/drawings/d/e/2PACX-1vR5T24WqRus8i7PnA-qpGjZP_4XwRaKfGtNdB16ol0Uwa4uHZwiE0M8MTBR7cvKhqsen5whtj25Lhfl/pub?w=925&amp;h=599">


## SORACOM Lagoonで可視化する
SORACOM Harvestで収集したデータを利用して、ダッシュボードを作成することができます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vS-bFScvPoTOptNh5O2sJb1dMtwEunlQ7MadcTuIj9JtLXWmD7knnpKx5SDe1NE-TSkbRdqj8KgWvRq/pub?w=932&amp;h=433">

## 片付け
これでハンズオンは終了です。センサーを元の位置にお戻しください。
