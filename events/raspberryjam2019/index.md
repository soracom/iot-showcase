# Raspberry Jam Big Birthday Weekend 2019 in TOKYO
## Raspberry Pi x SORACOM x 超音波センサーのデータを可視化しよう！

## 本日の機材
* Raspberry Pi
* 超音波センサー
* ドングル
* ブレットボード
* 有効なSORACOMアカウント（すでにソラコム側でアカウントを作成済みです）
* SIM カード（ドングルの中にすでに入った状態です）

機材の写真

## 参加者の持ち物
* wifiに繋がるPC（最新のGoogle Chromeが利用可能なこと）

## 本日のハンズオンでできること
Raspberry pi に超音波センサーを取り付け、SORACOM のネットワークを通じて、SORACOM Harvest というデータ蓄積サービスにデータを溜めます。
溜めたデータを、SORACOM Harvest, SORACOM Lagoon を利用し簡単にデータの可視化、ダッシュボードのの作成を行います。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQd9mqUF2oEUjMWNT8QHnVes4ZbgW8lUnKQw0jFsaHjqhMsJ3ZQlS2w9h-eGLdchtRm3NFFjRUDKnNv/pub?w=754&amp;h=206">

## 手順
1. [Raspberry Pi のセットアップをしよう](#handson1)
2. [SORACOM Harvest でデータを可視化しよう](#handson2)
3. [SORACOM Lagoon でダッシュボードを作成しよう](#handson3)

<h2 id="handson1">1. Raspberry Pi のセットアップをしよう</h2>

1. ジャンパーワイヤーの配線

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSISfzAOhFFCChRHmMp9r8Pq8xmzhVpIG4tVTcOS0N4OTX68Ikayzqnq0G3QNxfQiii8k47UWf8CgzB/pub?w=564&amp;h=599">

ブレッドボードを下記のように配線します。配線を間違えないようご注意ください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSXjAe5AyzwIMR70av_F04xp5TzxHuJPrNs6XvOv3GWrCWf205ZQJQRqcueUYxPkc88LUSjMhNL1LF9/pub?w=882&amp;h=664">

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQfBmQsDKwOH6bGQxSMJFb5Krh69Yz2qZsKMLiAbYAoo9RqlRxBtDpe1Atjlkdd1MIef2cN6R-CEe5k/pub?w=842&amp;h=636">

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

SORACOM Harvestの設定をしたSIMを選択し、「操作」からデータを確認を選びます。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQxHPmjEN5pewXexVuFcfkue4qwxG0fxYbLEdpRpOAeBxIUN8_F-5fFP0iI6WcpaZDL9dLXk74Wi85K/pub?w=932&amp;h=483">

右上の自動更新（5秒）をONにします。前にハンズオンをした方のデータが残っているのが気になる方は、時刻を変更していただくことで、ご自身のデータのみをご覧いただけます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSYWVlDGdxtdbWqPrup7KjoO-Rl97fhd6NRE_er3xxNBh3thdIXb5AQiJcEocyyvJcymEF6Cy96UbNC/pub?w=931&amp;h=454">

<h2 id="handson3">3. SORACOM Lagoon でダッシュボードを作成しよう</h2>

1.  SORACOM Lagoon ログイン

SORACOM Lagoon のコンソールログインします。URは[こちら](https://jp.lagoon.soracom.io/login)をクリックしてください。
ログインメールアドレスとパスワードは事前にソラコム側で準備をしています。机の上の紙をご確認ください。

[https://jp.lagoon.soracom.io/login](https://jp.lagoon.soracom.io/login)

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRlp1wuAgkuzhIS1FzMoLD-Hx70WuWTxTMxkGx4A_ymzlwYD0xGAhk04X8j3XOGLwYqTHBtIorlh4Jc/pub?w=925&amp;h=498">

ログイン後の画面は下記のようになってます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQKJ9qiFNrBBVS2jbv1o7TIIzpcLG8AYVe3VA2aLuAZxdP5rYm24YqU6AOOMq8lZ2N_Mtp0m7QmWi8r/pub?w=932&amp;h=396">

2. SORACOM Lagoon でダッシュボードを作成

左側の「＋」>「ダッシュボード」をクリックします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ7PBYFSgwxUavkgHxKMnY0IdlpHGoGozBjCxgofJewfSDrOl-BlzIQxln8vpDsgDuFR1blqF5U5Xkl/pub?w=550&amp;h=468">

Graph を選択します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTI7gkqYnvGg2zEypONVJ5ra4n68LO2APBovo4eMbC8SBqQ7chGAz3VahAkoQsMueuu_z4ZToheUfna/pub?w=931&amp;h=450">

「Panel Title」>「編集」をクリックします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQJdKY68TSAb8I8ksHNhxiyTdjvppKmrAZdZmUVPgMvAZ8x0nVDUI6CmBm_oJRRgVwVyq76huZw6RR1/pub?w=931&amp;h=478">

複数のSIMをお持ちの場合は、メトリックスから該当するSIMを選択します。（今日は1アカウントにSIMが1つ登録されているだけなので選択する必要はありません）

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ9J2fu0tvKOFRsKO8O2UslNp-NYK8RNEM_rwe3oeTNmBIgtGzxVEeFayHP_jDqUxHG4KdCfKgDjrB3/pub?w=930&amp;h=584">

右上の時刻設定から、画面に表示するデータの時間と自動更新の頻度を設定し、適用をクリックします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vT0Eaex8TcO6xVTNduPyoqXym_BqLPWPpK-3vEfbgkzStXqFaHIPngXW0-ASZhC7MuZKJ62jYxVU0uP/pub?w=930&amp;h=359">

右上の保存ボタンをクリックします。名前をつけて保存をするのポップアップが表示されるので、任意の名前をつけて保存します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQNVwaUywETqEWCDuCxGP0CD8wwjmzr-FouJtFGaElfGHQmbJkYQ43o22hiXvAbuHP3fxiF6px6s3I4/pub?w=930&amp;h=285">

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSzW0jl7QrOILaj7Q8wRDd5v8KKdkMGxljMJswxhjrT9ogvAHp-NiYTYSIjSaPtnqHXjqN-9KxWb42y/pub?w=822&amp;h=459">

新たにパネルを追加します。
右上の「パネルの追加」をクリックします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSYh6WhDrL6tB4AUtjJRiBzVjguKJTgnIzSQqZLqs6JJrhTrLaY6n7_Y7tb5PsceaUQBvsOCuEtD-Y9/pub?w=930&amp;h=297">

Singlestat を選択、「Panel Title」>「編集」をクリックします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ3PCE_b10lF8egnRyUCawgHB_Zjg5Va81Yu21hAH0EJrrwOJ0o_Vo2WcxJDKCUrW7_J_pxow_vRyrw/pub?w=930&amp;h=420">

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRwUpdsALE4GvIv7jPFtumqNCHZV0nenVSTYMwRAuUEHfPOP7xkwo48UywOHf_h6hr-AkdJPMBEJinG/pub?w=930&amp;h=469">

オプションで、下記のように設定を変更します

- 値 > 表示 > 「現在値」に変更
- 色 > しきい値 > 10, 50 （ここでは10, 50をしきい値にしてますが、しきい値を変更したい場合は変えていただいて構いません）
- 色 > 色 > 反転をクリック
- ゲージ：表示にチェックを入れます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQjRN2wAwFMMWpCnoAtKM31xvOY-uV0kq8ToWxzhQvodVH2F0Nc5Q5VhzuECGNGhhz9TGec5LdPvZDT/pub?w=931&amp;h=280">

右上の時刻設定から、画面に表示するデータの時間と自動更新の頻度を設定し、適用をクリックします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vT0Eaex8TcO6xVTNduPyoqXym_BqLPWPpK-3vEfbgkzStXqFaHIPngXW0-ASZhC7MuZKJ62jYxVU0uP/pub?w=930&amp;h=359">

ダッシュボードを保存し、ダッシュボードに戻るをクリックします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTVmtEpCD0e73N0uwjnljZxbOOgloYqvwVsT3o4rX1xtC70mgOLdw4v8QdtbrL1UyfdE670NH-sun3u/pub?w=877&amp;h=565">

ダッシュボードにこのように表示されたら成功です。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSAhqtmAH_r8RnR1XrbcfjkoX6Wdrqn-PNIWdL0Nd_Tgw5l4q5mSY5rtlKJXYp6_yTtj5PfDOkRYFA3/pub?w=933&amp;h=270">

超音波センサーに手を近づけて変化を確認してください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQPF8yA8I4QymkXuliO5rI5VYho8-2ySBFCqbqQ5ZE9VdJD8qTjDurm2jszWJMQP8i5WPOOYA-LlpuV/pub?w=917&amp;h=682">

## 片付け

Raspberry Pi の電源を落とし、白色のドングルを抜いてください。

こちらで全てのコンテンツは終了です。


