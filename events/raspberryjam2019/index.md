# Raspberry Jam Big Birthday Weekend 2019 in TOKYO
## Raspberry Pi x SORACOM x 超音波センサーのデータを可視化しよう！

## 本日の機材
* Raspberry Pi
* 超音波センサー
* ドングル
* ブレットボード
* 有効なSORACOMアカウント（すでにソラコム側でアカウントを作成済みです）

機材の写真

## 参加者の持ち物
* wifiに繋がるPC（最新のGoogle Chromeが利用可能なこと）

## 本日のハンズオンでできること
画像

## 手順
1. [Raspberry Pi のセットアップをしよう](#handson1)
2. [SORACOM Harvest でデータを可視化しよう](#handson2)
3. [SORACOM Lagoon でダッシュボードを作成しよう](#handson3)

<h2 id="handson1">1. Raspberry Pi のセットアップをしよう</h2>

1. ジャンパーワイヤーの配線

ブレッドボードを下記のように配線します。配線を間違えないようご注意ください。

2. ドングルを配置

白色のドングルをRaspberry Piに差し込みます。どこのUSBポートを使っていただいても構いません。

3. Raspberry Piに電源を入れます。



<h2 id="handson2">2. SORACOM Harvest でデータを可視化しよう</h2>

1. SORACOM のアカウントにログイン

[ログインURL](https://console.soracom.io/#/login?coverage_type=jp)をクリックします。
今回は、事前にソラコム側でアカウントを作成していますので、そちらをご利用いただき「メールアドレス」「パスワード」を入力します。
アカウント情報は机の上にご用意しています。
![フロー](https://docs.google.com/drawings/d/e/2PACX-1vTy5KORqQjieOg-ijF5CLyfhALMq-CmE8G9822NahydZSw5zIYqcz4efiru6R5n1RjAEaotdmfNmXsN/pub?w=444&h=250)

2. SORACOM Harvestの設定

SORACOM Webコンソール で 左上[Menu] > [SIM グループ] を選択します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSn0Zi77g_YUfJPD4SMgpspn-sCiShXibex_Bd288IC5d8-TfFPfCxanjfTdza-7OT5FgQNCuU8UPls/pub?w=691&amp;h=397">

[追加] で、SIMグループを作成します (グループ名は、他の参加者と被らない独自の名前をつけてください。ここではharvestとしています。)

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSPANZwqx8KjZsVl_gzqv09OKc-i4-CJb1SjrlCiNj6zFN0XM-4ialXN270wHaIgBqYApUjcH1BaUwH/pub?w=639&amp;h=625">

先ほど作成した SIMグループ をクリックし、 SORACOM Harvest の設定を ON にして保存をクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ3JxlDr0DwQ3D_4RNWiMYPBwW3Z-OyftYaNmuM-NIZ0grqn5qgnZvO_gAhCkcQs8nBA7RZ1qeyPlCT/pub?w=867&amp;h=681">

SORACOM Webコンソール で 左上[Menu] > [SIM 管理]を選択します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vR1p_9PqCjBoB3xh_nEta2grhXZlJI3zyrXOjXjH59Vgq69cD5XbVA3PIppl0X6sNYqM538K8G2iK4U/pub?w=704&amp;h=393">

すでに登録されているSIM を選択 > [操作] > [所属グループ変更]をクリックし、先ほど追加したグループ名を選択します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vR9udoWlimJIJv51_uvGoJ2SxIiOga1VQS09JnCr1gjUXg9LxmDoMH33mAagYZQDDCIUm-9Fn3K8TzB/pub?w=544&amp;h=506">

SIMグループ に所属させます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSlVDzWGlXw6w6CpMhGG5weDgJYzcr2Uo7bXXpMfOG5ZfGX53y7yLVfTBY7DvSvFrm0yL5L_HJlYU2L/pub?w=650&amp;h=336">

以上で SORACOM Web コンソール上での作業は終了です
SIM の “グループ” が、先ほど作った SIM グループ名になっていれば成功です。


3. SORACOM Harvest を見てみよう



<h2 id="handson3">3. SORACOM Lagoon でダッシュボードを作成しよう</h2>

1.  SORACOM Lagoon ログイン

SORACOM Lagoon のコンソールログインします。URは[こちら](https://jp.lagoon.soracom.io/login)をクリックしてください。
ログインメールアドレスとパスワードは事前にソラコム側で準備をしています。机の上の紙をご確認ください。

[https://jp.lagoon.soracom.io/login](https://jp.lagoon.soracom.io/login)

2. SORACOM Lagoon でダッシュボードを作成

左側の「＋」>「ダッシュボード」をクリックします。

Graph を選択します。


「Panel Title」>「編集」をクリックします。

複数のSIMをお持ちの場合は、メトリックスから該当するSIMを選択します。（今日は1アカウントにSIMが1つ登録されているだけなので選択する必要はありません）

右上の時刻設定から、画面に表示するデータの時間と自動更新の頻度を設定し、適用をクリックします。

右上の保存ボタンをクリックします。名前をつけて保存をいうポップアップが表示されるので、任意の名前をつけて保存します。


新たにパネルを追加します。
右上の「パネルの追加」をクリックします。

Singlestat を選択、「Panel Title」>「編集」をクリックします。


オプションで、下記のように設定を変更します

- 値 > 表示 > 「現在値」に変更
- 色 > しきい値 > 10, 50 （ここでは10, 50をしきい値にしてますが、しきい値を変更したい場合は変えていただいて構いません）
- 色 > 色 > 反転をクリック
- ゲージ：表示にチェックを入れます。

ダッシュボードを保存し、ダッシュボードに戻るをクリックします。


ダッシュボードにこのように表示されたら成功です。
超音波センサーに手を近づけて変化を確認してください。


## 片付け

Raspberry Pi の電源を落とし、白色のドングルを抜いてください。

こちらで全てのコンテンツは終了です。


