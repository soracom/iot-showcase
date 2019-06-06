# SORACOM Discovery 2019

## このハンズオンで体験いただくこと
SORACOM SIM を搭載した Wio LTE に温湿度センサーを取り付け、温湿度データを可視化サービス SORACOM Harvestと、ダッシュボード作成・共有サービス SORACOM Lagoon を使って表示します。

## 持ち物
* パソコン / 1台
（Wi-Fi 接続可能、USB Type-A ポートあり、電力供給が1A以上であること、Google Chromeがインストールされていること）
※USB Type-C のみの機種につきましては、Type-A への変換アダプタのご用意をお願いいたします
* 有効なクレジットカード
* その場で確認可能なメールアドレス

## SORACOM アカウントの登録
#### SORACOM アカウントの作成
SORACOM Webコンソール ( https://console.soracom.io/#/signup) にアクセスします。
使用する SIM の種類を選択します。日本向けの SORACOM Air SIM を利用する場合は、カバレッジタイプ Japan を選択します。

「アカウント作成」画面が表示されますのでメールアドレスおよびパスワードを入力します。 また、契約者が個人であるか法人であるかを選び、法人の場合はさらに契約者の情報を入力します。 最後に規約に同意するためのチェックボックスを入れ、「アカウントを作成」ボタンを押します。
[アカウントを作成] ボタンをクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ4DASGMTLNPl-Sg-ahUzbyTAA0myBP7HFEr-MK34ceojFV8UuMvCxJuLBcJ8er5rTBl504DWNNQrRc/pub?w=507&amp;h=376">
<img src="https://docs.google.com/drawings/d/e/2PACX-1vS3dyhOb1qgivxXcJA0qzFv5Yi30WTh2IQvml_z56Vc1KOQDgGd3dydcofBThP-Mogn77E8ych6qWr3/pub?w=677&amp;h=331">
下記の画面が表示されるので、メールを確認してください。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vRViuOVoavgIQYMAu8M7EbmB_wGSkIZR4H4HJhvAggsGHSF1-tKIc05w0BT7HluGn5G6NlAo_NUnJQi/pub?w=906&amp;h=353">

メールが届いたらリンクをクリックしてください。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTtTUbK_YMzCQ2N5DUG02KH8RD-Mht0ncpMQJRTebwJQLN2Lq4m0-YQ0e3YRlxssXx18ye-jA-_QZdO/pub?w=632&amp;h=407">
自動的にログイン画面に遷移しますので、メールアドレスとパスワードを入力してログインしてください。

#### 支払情報の設定
通信料の支払い方法はクレジットカードになります。クレジットカードの情報を登録するには、メイン画面上部のユーザー名から[お支払い方法設定]を開きます。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQn89lYNnM9WbIctZm8wrO-PNbIWfuHBgmdS8U5A4SYEYgr5-AwkFTK2UxIBJUemu7OJDB9vZzw1_1B/pub?w=760&amp;h=428">

お支払方法で各情報を入力し、支払い方法を登録します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vRE8Z9iNQS_Fhvw5BUXFUOkM50LKAhjOhv45w2F74sLWtHQyRUIBGsaZI48AspQgC8onCAahJaKLRGu/pub?w=726&amp;h=614">

### SORACOM Air SIMの登録
#### ユーザーコンソールでの Air SIM の登録
ユーザーコンソールにログインして、Air SIM の登録を行います。左上の [SIM登録] ボタンをクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQpZOpHAwdD_3J2yfOjcdJOJZy5kek1DbLxeJHK2k3NzXvo3yUIv8RQ8isIWO6VqpiUmGzyLy7kdeCk/pub?w=765&amp;h=313">

「SIM登録」画面で、Air SIM の台紙の裏面に貼ってある IMSI と PASSCODE を入力してください。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQiSc6juh7h3S5METhxHaGK8c_qjwGFpBf7YJNKCXIkOPMcNYOg3Tk9j7eFhFCrx0kCp3kLjZFasrwy/pub?w=508&amp;h=385">

名前、グループは空欄のままでも構いません。 「技術基準適合証明等について確認しました」チェックボックスを付けてください。 [登録] を押して SIM 登録を完了してください。（複数の Air SIM を続けて登録することも可能です。）
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQYUYZfipB6wYUIqHWE6RfhmzTpo_DSxnbZNUdumBP1jykYXFWnhyNhm0QDlia0UQ07Ptv_twce2R84/pub?w=793&amp;h=625">

Air SIM を登録した直後の状態は「準備完了」と表示され、通信可能な状態になっています。ただし、まだセッションは確立されていないので、セッション状態は「オフライン」になっていることを確認してください。


## Wio LTE のセットアップを行う
#### Wio LTE とは？
Wio LTE は Seeed Studio が開発・販売しているマイコンモジュールです
Grove コネクタと STM32F4 マイコン、LTE Cat.1 モジュールが搭載されており、 Arduino IDE で素早くプロトタイピングができます

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTNBiOHulMBdVKNNr5ivZeA1dY1lSsC2UuzrxvklMqSInJSyY-Z701p4-ljXMNEakc8MpHXkkvQxH60/pub?w=610&amp;h=474">

* Wio LTE 各部の名称
※この項は知識として知っておいてください
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTmoM1gureGc4imjM4mpmrktfJRWKYUnoWDtrd0xkahiRc8zJsUdR5vh9ZABcVUMA-YVMDaDaWswoN5/pub?w=800&amp;h=379">

#### アンテナの取り付け
アンテナの取り付けはかなり力を要しますが、無理をしないようお願いいたします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSfQ5makGsxiXX44supzOjMeSaBkoZFYYsSY9O-3EN5kYaQpCi7ObkeuWEKidM9oJ0y41J-H_1cM5qy/pub?w=682&amp;h=518">

#### SIM の取り付け方、外し方
取付け方
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTnQSrwriGobpTV35Gob6rR8eAfmBO8DQjGb9Tf96rsXrDEDT7yRUH2h1xQpPEkzb0pZcCVEYMCgRaZ/pub?w=850&amp;h=403">

外し方
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQBysS_e_sCpcS4wm9pPk92t6EL_YoP48WuHWdqHDFdFe7uANU1zBVRdXG4mBvDcpyj0uSQubLgyfvH/pub?w=906&amp;h=297">

#### 温湿度センサーの取り付け
温度センサー (DHT11) 付属の 「Grove コネクタケーブル」を使ってWio LTE の「D38」へ取り付けます
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSki1-b73Z79lYhCOHIXbO9qHjBd0kgsikC4k3hB0VTtPuARWO0QeE5O4A1nLspURfIM7FQ0YZu5-Hw/pub?w=792&amp;h=592">

## 温湿度センサーの値を SORACOM Harvest で可視化
クラウド側のシステムを用意せず、まずデバイスとセルラー通信の稼働を確認するために、SORACOM Harvest による可視化を行います
構築対象システムを減少することができるため、コンポーネントの動作確認を一つづつ確認していく事ができることを学びます
<img src="https://docs.google.com/drawings/d/e/2PACX-1vRMhYvENXGmvbZWMT0cXv74h62I0Papgp_QH5d5zgZ5LJV1S0bHm7chH_sZQwi-ogKQjHidJg5VXjSB/pub?w=892&amp;h=367">

#### SORACOM Harvest の設定
SORACOM Webコンソール ( https://console.soracom.io ) で 左上[Menu] > [SIM グループ]
[追加] で、SIMグループを作成します
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTf3xF7KMHLVCYK-K60D7ePZF5_NSURFn0DZGYf8hQ49-EbP3-SF1cy51103GE_qqZKrg6gjGdODxXV/pub?w=876&amp;h=724">

グループ名 harvest もしくは 任意 でかまいません
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTNlQ1c7PrpgZ0tHMXd5IHrPIUe_aST-iT-gjhzOaD2YnxOIQzZVtaO01RgKQQ5yRldEh3rt6SJjDAT/pub?w=787&amp;h=425">

先ほど作成した SIMグループ をクリックすると、グループの詳細が開きます
SIM グループの詳細で SORACOM Harvest の設定 開き、SORACOM Harvest を ON にし、保存をクリックします

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSlf4hxEqJzmGDIY7bV0edY7yeWIsaCaNFdOlXejaLh3UBxC_I2mYRj--7ib8IAXQK_kC9vejyZE09R/pub?w=839&amp;h=680">

先ほど設定した SIM グループへ、 Wio LTE に挿している SIM を所属させます
左上[Menu] > [SIM 管理]

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRpLdUVrbLhOoeQ26uoYXS9z-hvfmirP2R-XaIQrPh-_k5TvQ3l-WH_DMpw8wQZIAkaYx59J1sjsDI1/pub?w=692&amp;h=404">

Wio LTE に取り付けている SIM を選択 > [操作] > [所属グループ変更]
先ほど作成した SIMグループ に所属させる
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTnIaV_8SHw918zxurqj5ZZ6STDT5RBsI4sfhdeNrDAbCyQDJ7-T8HjFHGzAjkCkHOzyCgR9deJbRoX/pub?w=502&amp;h=712">

以下のように SIM がさきほど登録した SIMグループ になっていることが確認できます
この状態で “Wio LTE” と書かれている SIM は SORACOM Harvest が使用可能な状態になりました
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSBLqovlcUNH1nUyf2S_07_pvRDp4RBp2UMHqrbXxzJRPNcwS9xphqca5prWxDR-J1emEE2uWORpreb/pub?w=541&amp;h=468">

#### Wio LTE の電源を ON にする
Wio LTE と PC を microUSB ケーブルで接続してください

Wio LTE に電源が供給されると Wio LTE にあらかじめ書き込まれたプログラムが開始されます
※お配りした Wio LTE には「D38 に接続されたデジタル温湿度センサーを SORACOM Harvest に送信する」プログラムが書き込まれています

<img src="https://docs.google.com/drawings/d/e/2PACX-1vR8sydyJ_2h_B_dOEpazJOHjuSU50qXIpk0F55y9CdYBsWoIldHxHGXFqwd7X9v4lOpJzvWDt6Sb_vw/pub?w=696&amp;h=518">

#### データの確認
送信されたデータを SORACOM Harvest で確認してみましょう
左上[Menu] > [SIM 管理]

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQWBdzfKyvYRijHcnzkZuWNnMtcHphbdQ-tQNwXG1fhrJcv29fEs4WlStoTDlvDw5CGDnvs6Ax9Jyyg/pub?w=546&amp;h=499">

以下のように、温度・湿度のデータが、それぞれ temp humi として SORACOM Harvest 上で可視化されています
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQy3C9K_3UEewbdK7nGfm5Ii0ACKQA2Hr8NrAUKybWOCBvsFfppQHqHfDuer9eSgQ1_WdS_AL2aCfJj/pub?w=842&amp;h=560">

※自動更新を ON にすることで、半リアルタイムにグラフが描画されます

**SORACOM Harvest の見方、機能**
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSf2W7ezqhDnmnG80-5shbWV2_kvhfdYPb0LwcY-V_XTXe_Lr1OiMfn5SfXGl9458Ws9PJ1Wm5Que1E/pub?w=910&amp;h=612">

## SORACOM Lagoon を活用したデータ共有
SORACOM Harvest は SORACOM アカウント内でデバイスからのデータをいち早く確認するためのツールですが、ビジネスで活用しようとした場合はデータの活用が必須となります。
具体的には「データの共有」と「条件によるアラート」です。
SORACOM Lagoon はその二つを備えており、SORACOM Harvest に蓄積されたデータを即座に活用することが可能です。

**SORACOM Lagoonとは**
SORACOM Lagoon はダッシュボードを作成し、”SORACOM Lagoon ユーザー” と共有できるサービスです。SORACOM Lagoon ユーザーは SORACOM アカウントを持っていれば自由に作成・管理可能で、だれと共有するかを決めることができます。
その他、条件を設定し、Email や Slack、LINEといったメッセージングツールへのアラート送信も可能です。

