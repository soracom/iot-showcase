# SORACOM LTE-M Button と Microsoft Azure で簡単IoTを実現

SORACOM LTE-M Button for Enterprise (以下 SORACOM LTE-M Button) を使った自習形式ハンズオンです。  
作業時間の目安は作業Ａで 30分～45分、作業Ｂのそれぞれの作業で15分～30分となります。

<h2 id="prepare">必要なもの</h2>

* パソコン / 1 台
    * タブレットは不可
    * Wi-Fi でインターネットに接続できる環境
    * ブラウザ
        * Google Chrome 最新版をお使いください。それ以外はサポート致しかねます
        * OS は不問ですが、できる限り最新の OS の利用を強く推奨します
        * プロキシー設定やアクセス制限などの社内システム設定がある場合は受講できない場合があります
* SORACOM LTE-M Button for Enterprise / 1 個
    * 会場によっては貸出いたします。また、すでにお持ちの場合は持ち込み可です
    * SORACOM LTE-M Button Plus でもお使いいただけます
* 有効なクレジットカード / 1 つ
    * SORAOCM アカウントを作成いただくのに必要となります
    * 「非通知」からの電話に対する着信拒否設定の解除が必要となります
* 会場で確認可能なメールアドレス / 1 つ
    * SORACOM アカウント作成時を行う際に必要となります
* Azure アカウント
    * [Azure アカウントを作成する(外部リンク)](https://docs.microsoft.com/ja-jp/learn/modules/create-an-azure-account/5-exercise-create-an-azure-account){:target="_blank"} を参考に作成してください


<h2 id="standby">作業前の準備</h2>

* Wi-Fi に接続してください (接続情報は別途お知らせします)
* 「進ちょく表」を開いてください (URL は別途お知らせします。完全に自習の場合は不要です)

<h2 id="overview">全体像</h2>

- 作業A: ボタンのクリックイベントを SORACOM Harvest を使って可視化
- 作業B: ボタンのクリックイベントを Slack に送信します
- 作業C: ボタンのクリックイベントをきっかけに、Azure IoT Hub で接続されたデバイスを制御します

![全体像](https://docs.google.com/drawings/d/e/2PACX-1vSZM2kNBWqLmSPzAlCE6Z1A8gN9Kzmh4YCxF0BLK3PjIjKyPnq8d2Ydgf0Ac1Uod93iOr_Dwb7OUOk3/pub?w=928&h=523)

必要な作業は以下の通りとなります。

<h2 id="workflow">進め方</h2>
作業A → 作業B → 作業C の順番で実施してください

<h2 id="work-a">作業A: Harvest を使ったボタンの動作確認</h2>

1. [SORACOM LTE-M Button for Enterprise を SORACOM アカウントに登録する](register){:target="_blank"}
    - **貸し出されたボタンを利用する場合には必要ありません**
2. [ボタンのクリックイベントを SORACOM Harvest で確認する](harvest){:target="_blank"}

<h2 id="work-b">作業B: Slack を使ったクリックイベント通知</h2>

1. [ Azure Functions で Function App を作成 ](work-b-azure)
2. [ SORACOM Beam から Function App を呼び出し、Slack に通知を行う ](work-b-soracom)

<h2 id="work-c">作業C: ボタンと Azure IoT Hub を連携させてデバイス制御</h2>

1. [ Azure Functions で Function App を作成 ](work-c-azure)
2. [ SORACOM Beam から Function App を呼び出し、デバイスを制御する ](work-c-soracom)

<h2 id="closing">作業: あとかたづけ</h2> TODO

<h3 id="fee">料金について</h3>

#### Azure 各種サービスの利用料金の目安 TODO

* [Azure Functions の価格(外部リンク)](https://azure.microsoft.com/ja-jp/pricing/details/functions/){:target="_blank"}
    * 1 か月あたりの要求数　1,000,000 が無料枠に含まれます

#### SORACOM LTE-M Button for Enterprise

販売価格 5980 円 に加えて、ご利用にあたっては plan-KM1 の基本料金(月額100円)、データ通信量に応じたデータ通信料(*)が発生します。
plan-KM1の料金は[ご利用料金 - 日本向け Air SIM](https://soracom.jp/services/air/cellular/price/#plan-km1)をご確認ください。

(*) 目安として、１クリックあたり約 0.5 円程度

※ 料金は全て送料や税抜きです。

<!--

### 資料集

<h2 id="appendix">おまけコンテンツ</h2>


-->
