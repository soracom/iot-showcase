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
    * SORACOM アカウント、および Azure アカウントを作成いただくのに必要となります
* 会場で確認可能なメールアドレス / 1 つ
    * SORACOM アカウント作成時を行う際に必要となります（すでに SORACOM アカウントをお持ちの方、もしくは、貸出の方は不要です）
* Azure アカウント
    * [Azure アカウントを作成する(外部リンク)](https://docs.microsoft.com/ja-jp/learn/modules/create-an-azure-account/5-exercise-create-an-azure-account){:target="_blank"} を参考に作成してください
        * Azure アカウント作成時に電話音声もしくはテキストメッセージによる認証が必要となるため、携帯電話をご用意ください
        * 「非通知」からの電話に対する着信拒否設定の解除が必要となります

<h2 id="standby">作業前の準備</h2>

* Wi-Fi に接続してください (接続情報は別途お知らせします)
* 「進ちょく表」を開いてください (URL は別途お知らせします。完全に自習の場合は不要です)

<h2 id="overview">全体像</h2>

- 作業A: ボタンのクリックイベントを SORACOM Harvest を使って可視化
- 作業B: ボタンのクリックイベントを Slack に送信します
- 作業C: ボタンのクリックイベントをきっかけに、Azure IoT Hub で接続されたデバイスを制御します

![全体像](overview.png)

必要な作業は以下の通りとなります。

<h2 id="workflow">進め方</h2>
作業A → 作業B → 作業C の順番で実施してください

<h2 id="work-a">作業A: Harvest を使ったボタンの動作確認</h2>

1. [SORACOM ユーザコンソール](https://console.soracom.io){:target="_blank"} で SORACOM LTE-M Button for Enterprise を 受け取る
    - **貸し出されたボタンを利用する場合には必要ありません**
2. [ボタンのクリックイベントを SORACOM Harvest で確認する](../common/harvest){:target="_blank"}

<h2 id="work-b">作業B: Slack を使ったクリックイベント通知</h2>

1. [ Azure Functions で Slack 通知用 Function を作成 ](work-b/azure)
2. [ SORACOM Beam から Function App を呼び出す ](work-b/soracom)

<h2 id="work-c">作業C: ボタンと Azure IoT Hub を連携させてデバイス制御</h2>

1. [ Azure Functions で デバイス制御用 Function を作成 ](work-c/azure)
2. [ SORACOM Funk から Function App を呼び出し、デバイスを制御する ](work-c/soracom)

<h2 id="closing">作業: あとかたづけ</h2>

<h3 id="cleanup-azure">Azure リソース</h3>

* 本ハンズオンで利用したリソースの削除を「リソースグループ」から削除する
    * [リソース グループ](https://portal.azure.com/#blade/HubsExtension/BrowseResourceGroupBlade/resourceType/Microsoft.Resources%2Fsubscriptions%2FresourceGroups) の一覧から、本ハンズオンで使用した Function App が含まれるリソースグループの削除を行います
    * リソースグループは、関連する Azure リソースを一括で操作する時に利用できます。削除を行うと、含まれるすべてのリソースが削除されるため便利な反面、**内包されているリソースがすべて削除されるため注意が必要です**。

<h3 id="cleanup-soracom">SORACOM リソース</h3>

* 本ハンズオンで利用した SIM グループの削除
    * SORACOM LTE-M Button for Enterprise をグループから解除してください
    * グループ解除後、SIM グループの削除をしてください (SIM グループ設定の "高度な設定" から削除ができます)
* SORACOM Harvest のデータ削除
    * データを表示した後、対象データのチェックボックスを付けて [削除] をします
* 認証情報の削除
    * もし認証情報を削除しておきたい場合は、ユーザーコンソール右上にある青色のプルダウンメニューより [セキュリティ] を選択し、[認証情報ストア] タブから削除します (一番右の [操作] という列に [削除] というボタンがあります)

<h3 id="fee">料金について</h3>

#### Azure 各種サービスの利用料金の目安

* [Azure Functions の価格(外部リンク)](https://azure.microsoft.com/ja-jp/pricing/details/functions/){:target="_blank"}
    *  1 か月あたりの要求数　1,000,000 が[無料枠](https://azure.microsoft.com/ja-jp/free/){:target="_blank"}に含まれます (アカウント作成後 12 ヵ月以内)
* [Azure ストレージアカウントの価格(外部リンク)](https://azure.microsoft.com/ja-jp/pricing/details/storage/page-blobs/){:target="_blank"}
    * LRS File Storage 5 GB が[無料枠](https://azure.microsoft.com/ja-jp/free/){:target="_blank"}に含まれます (アカウント作成後 12 ヵ月以内)

#### SORACOM LTE-M Button for Enterprise

販売価格 5980 円 に加えてご利用にあたっては plan-KM1 の基本料金(月額100円)、データ通信量に応じたデータ通信料(*)が発生します。  
plan-KM1の料金は[ご利用料金 - 日本向け Air SIM](https://soracom.jp/services/air/cellular/price/#plan-km1)をご確認ください。  
SORACOM Harvest 、 SORACOM Beam 、SORACOM Funk 等、 SORACOM サービス利用の費用は別途かかります。

(*) 目安として、１クリックあたり約 0.25 円程度

#### SORACOM サービスの利用料金の目安

* [SORACOM Harvest 料金](https://soracom.jp/services/harvest/price/)
    * Harvest を有効にしたグループに所属する 1 SIM カードまたは 1 デバイスあたり 1 日 5 円 (2000リクエスト/日/SIM あたりのリクエスト含む)
    * 1 アカウントあたり毎月 31 日分の (もしくは 2000リクエスト/日以内)の無料枠があります
* [SORACOM Beam 料金](https://soracom.jp/services/beam/price/)
    * SORACOM Beam への IN/OUT それぞれに 0.0009 円/リクエスト
        * 例) UDP → HTTPS をおこなった場合: SORACOM Beam への UDP/IN で 0.0009 円、HTTPS/OUT で 0.0009 円の計 0.0018 円がかかります
    * 1 アカウントあたり 100,000リクエスト/月の無料枠があります

* [SORACOM Funk 料金](https://soracom.jp/services/funk/price/)
    * SORACOM Funk へのリクエスト毎に 0.0018 円/リクエスト
        * Funk から転送先クラウドサービスへのリクエスト毎に 1 リクエストとカウントします。
    * 1 アカウントあたり 50,000リクエスト/月の無料枠があります

※ 料金は全て送料や税抜きです。

<!--

### 資料集

<h2 id="appendix">おまけコンテンツ</h2>


-->
