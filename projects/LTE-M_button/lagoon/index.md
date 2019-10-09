# SORACOM LTE-M Button と SORACOM Lagoon で簡単IoTを実現

<!--
Google Drive Images: https://drive.google.com/open?id=14yESi7Uem0lpooGA9_QXZ1CmxNT5xl9C
-->

SORACOM LTE-M Button for Enterprise (以下 SORACOM LTE-M Button) を使った自習形式ハンズオンです。  
作業時間の目安は作業Ａで 15分、作業Ｂで20分となります。

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
    * SORACOM アカウントを作成いただくのに必要となります（すでに SORACOM アカウントをお持ちの方、もしくは、貸出の方は不要です）
* 会場で確認可能なメールアドレス / 1 つ
    * SORACOM アカウント作成時を行う際に必要となります（すでに SORACOM アカウントをお持ちの方、もしくは、貸出の方は不要です）
    * SORACOM Lagoon の通知を受け取る際にも利用します

<h2 id="standby">作業前の準備</h2>

* Wi-Fi に接続してください (接続情報は別途お知らせします)
* 「進ちょく表」を開いてください (URL は別途お知らせします／完全に自習の場合は不要です)

<h2 id="overview">全体像</h2>

- 作業A: ボタンのクリックイベントを SORACOM Harvest Data を使って可視化
- 作業B: ボタンのクリックイベントを SORACOM Lagoon のアラート機能を利用して通知します

![overview.png](https://docs.google.com/drawings/d/e/2PACX-1vS-3EnPq0oOCPQgcPK4CDXHGYX76iE_TGR8fqo3zxbMSdiqobdpuDyZgbAsXUfBEdoCkO654KqtKSNF/pub?w=744&h=213)

<h2 id="workflow">進め方</h2>

作業A → 作業B の順番で実施してください

<h2 id="work-a">作業A: SORACOM Harvest Data を使ったボタンの動作確認</h2>

1. [SORACOM ユーザコンソール](https://console.soracom.io){:target="_blank"} で SORACOM LTE-M Button for Enterprise を 受け取る  
   **貸し出されたボタンを利用する場合には必要ありません**
2. [ボタンのクリックイベントを SORACOM Harvest Data で確認する](../common/harvest){:target="_blank"}

<h2 id="work-b">作業B: SORACOM Lagoon のアラート機能を利用して通知を送る</h2>

1. [ SORACOM Lagoon の設定を行う ](work-b/soracom){:target="_blank"}

<h2 id="closing">作業: あとかたづけ</h2>

<h3 id="cleanup-button-rent">ボタンを借りた方</h3>

#### ボタンの片付け

SORACO LTE-M Button は運営にお返しください。

<h3 id="cleanup-button-self">ボタンを持ち込まれた方</h3>

後述の [料金について](#fee) をご確認の上、不要な SORACOM リソースを削除してください。

<h3 id="cleanup-soracom">SORACOM リソース</h3>

* 本ハンズオンで利用した SIM グループの削除
    * SORACOM LTE-M Button for Enterprise をグループから解除してください
    * グループ解除後、SIM グループの削除をしてください (SIM グループ設定の "高度な設定" から削除ができます)
* SORACOM Lagoon の利用の終了 （必要に応じて）
    * [SORACOM Lagoon の管理画面](https://console.soracom.io/#/lagoon){:target="_blank"} の [プラン変更] から [利用を終了する] を選ぶことで、SORACOM Lagoon の利用を終了することができます。
    * 終了時のダイアログに記載されている通り、すべての Lagoon ユーザー、ダッシュボード、アラートが削除されます（SORACOM Harvest Data のデータは削除されません）
* SORACOM Harvest Data のデータ削除 （必要に応じて）
    * データを表示した後、対象データのチェックボックスを付けて [削除] をします

<h3 id="fee">料金について</h3>

#### SORACOM LTE-M Button for Enterprise

販売価格 5980 円 に加えてご利用にあたっては plan-KM1 の基本料金(月額100円)、データ通信量に応じたデータ通信料(*)が発生します。  
plan-KM1の料金は[ご利用料金 - 特定地域向け IoT SIM (plan-KM1)](https://soracom.jp/services/air/cellular/price_specific_area_sim/#plan-km1){:target="_blank"} をご確認ください。  
SORACOM Harvest Data 、 SORACOM Lagoon 等、 SORACOM サービス利用の費用は別途かかります。

(*) 目安として、１クリックあたり約 0.25 ~ 0.3 円程度

#### SORACOM サービスの利用料金の目安

* [SORACOM Harvest Data 料金](https://soracom.jp/services/harvest/price/){:target="_blank"}
    * SORACOM Harvest Data を有効にしたグループに所属する 1 SIM カードまたは 1 デバイスあたり 1 日 5 円 (2000リクエスト/日/SIM あたりのリクエスト含む)
    * 1 アカウントあたり毎月 31 日分の (もしくは 2000リクエスト/日以内)の無料枠があります
* [SORACOM Lagoon 料金](https://soracom.jp/services/lagoon/price/){:target="_blank"}
    * 本テキストにおいては "Free プラン" を利用しています
* [簡易位置測位機能](https://dev.soracom.io/jp/docs/location_service/){:target="_blank"}
    * 1SIM/1ボタンあたり : 月額 50円（月間750リクエスト含む）
    * 750回を越したリクエストについては リクエストあたり : 0.15円　となります。

※ 料金は全て送料や税抜きです。
