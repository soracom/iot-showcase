<h1>IoT もくもく会 <br> (SORACOM LTE-M Button powered by AWS 編)</h1>

<h2 id="prepare">必要なもの</h2>

* パソコン / 1 台
    * タブレットは不可
    * Wi-Fi でインターネットに接続できる環境
    * ブラウザ
        * Google Chrome 最新版をお使いください。それ以外はサポート致しかねます
        * OS は不問ですが、できる限り最新の OS の利用を強く推奨します
        * プロキシー設定やアクセス制限などの社内システム設定がある場合は受講できない場合があります
* SORACOM LTE-M Button powered by AWS / 1 個
* 会場によっては貸出いたします。また、すでにお持ちの場合は持ち込み可です
    * 本ドキュメント内では SORACOM LTE-M Button と省略表記します
* 有効なクレジットカード / 1 つ
    * AWS アカウントならびに SORAOCM アカウントを作成いただくのに必要となります
* 会場で着信可能な電話 (携帯電話) / 1 つ
    * AWS アカウント作成時に電話音声による認証が必要となります
    * 「非通知」からの電話に対する着信拒否設定の解除が必要となります
* 会場で確認可能なメールアドレス / 1 つ
    * SORACOM LTE-M Button の動作確認に使用します
    * SORACOM アカウント作成時を行う場合 (オプション) で必要となります

<h2 id="standby">作業前の準備</h2>

* Wi-Fi に接続してください (接続情報は別途お知らせします)
* 「進ちょく表」を開いてください (URL は別途お知らせします。完全に自習の場合は不要です)

<h2 id="overview">全体像</h2>

SORACOM LTE-M Button はボタンをきっかけに AWS IoT 1-Click を通じて AWS Lambda (= あらかじめ作成しておいたプログラム)を実行できます。

![mkmk-button / 全体像](https://docs.google.com/drawings/d/e/2PACX-1vQWfrmF_w_-tmW6ztypukUXverP4_WS_ECeDmGe9ibqVYilMxP0kWPr6arvFE6oWyypQkAH9SNzjZ6s/pub?w=927&h=521)

必要な作業は以下の通りとなります。

1. AWS での作業
    1. AWS IoT 1-Click への登録
    2. AWS Lambda 関数の作成
2. 連携先サービスでの作業
    * (連携先サービスで異なります)
3. SORACOM への登録

<h2 id="workflow">作業の進め方</h2>

作業は以下のように進めていきます。

![mkmk-button / 作業の進め方](https://docs.google.com/drawings/d/e/2PACX-1vQQcIicnB1MaVrvyJQAZLl9dX581hPE3W6VSTZlgNlwQ8I58HjYsishVw_JFjllk27ajG2ZJhfH_E9d/pub?w=607&h=453)

<h2 id="work-a">作業: Ａ</h2>

1. [AWS アカウントの作成](create-aws-account)
    * [すでに AWS アカウント持っている場合の確認事項](aws-account-available)
2. [SORACOM LTE-M Button を AWS IoT 1-Click に登録し、メールを使い動作確認](claim-and-email-with-amazon-ses)
3. [メールの内容を変えてみる](customize-lambda-function)

<h2 id="work-b">作業: Ｂ</h2>

これより先は、どの手順から開始しても構いません。それぞれで追加で必要なものがあります。

1. [AWS IoT Core を使って会場にあるデバイスを制御](b-work/device-control-with-awsiotcore-shadow)
    * **追加で必要なもの**: とくに無し
    * デバイス側も作ってみたい方は[おまけコンテンツ](#appendix)を見てください
2. [IFTTT を使って LINE に送信](b-work/line-notify-with-ifttt)
    * **追加で必要なもの**: LINE アカウント

<h2 id="closing">作業: あとかたづけ</h2>

* (貸し出しの方のみ) [SORACOM LTE-M Button を AWS IoT 1-Click から解除](closing/unclaim)
* (持ち込みの方のみ) [SORACOM LTE-M Button を SORACOM へ登録する](closing/add-to-soracom)

<h3 id="fee">料金について</h3>



### 資料集

<h2 id="appendix">おまけコンテンツ</h2>

* [AWS IoT Core の Device Shadow を使ったデバイス制御](appendix/awsiotcore-device-shadow)
    * [AWS IoT Core を使って会場にあるデバイスを制御](b-work/device-control-with-awsiotcore-shadow) で使用したデバイス側の開発について解説しています
