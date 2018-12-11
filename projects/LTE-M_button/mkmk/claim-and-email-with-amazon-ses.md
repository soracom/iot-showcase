<h1>SORACOM LTE-M Button を AWS IoT 1-Click に登録し<br>メールを使い動作確認</h1>

SORACOM LTE-M Button が使えるように AWS IoT 1-Click に登録した後、動作確認のためにメールを送ってみましょう。

![button-mkmk / Email 全体像](https://docs.google.com/drawings/d/e/2PACX-1vQcTupxolXoBHeRzGr_UBp3TIZbV1nniNrINjKl16fwh4Kddle8zG9I5kaJp0SwuZCfjUAxAiKHNTV8/pub?w=721&h=406)

## 準備

* SORACOM LTE-M Button を手元に用意してください

## 作業1: AWS IoT 1-Click へ SORACOM LTE-M Button を登録する

### 1: AWS マネジメントコンソール へログインし、AWS IoT 1-Click のコンソールを表示してください

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home) を開きログインしたあと、リージョンを "オレゴン" に変更し、 AWS IoT 1-Click の管理画面を開きます。

![mkmk-button / 1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vSzawNDQ3RDZ0RiN6lu1nv5Y57aUOlSuYoK47BZIs72nt6bHnlbhHf6QAn4bxmJQnZHmQES6gAAn-j5/pub?w=927&h=284)

![mkmk-button / 2 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vTprwdD-l_uDEZbhNugIaePDUv9MYWYkXfxHFq4IA4fVNKfZFNrTqCWpDGMksArW7HhN7TtMWK_TKGF/pub?w=612&h=276)

AWS IoT 1-Click の管理画面から [デバイスの登録] をクリックします。

![mkmk-button / 1 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vRZ_OiMuE0UPvKG2QxIBfA1OP0laZJiDG4gWa-zwfcOqW6B82I3T0uCxasen8uCh_ttXJuHKBoye_q4/pub?w=752&h=216)

SORACOM LTE-M Button の電池カバーを開けて DSN を AWS IoT 1-Click に入力し [登録] をクリックします。

* DSN は文字が非常に小さいですが、頑張って読み取ってください (助け合ってください...)
    * `オー` と 数字の０ 、 `アイ` と 数字の１ などが間違えやすい文字です
* スマートフォン向けアプリであれば QR コードを読み取ることで登録も可能です。その方法は [Getting Started with SORACOM LTE-M Button](https://dev.soracom.io/jp/start/aws_button_slack/#registration) をご覧ください

![mkmk-button / 2 dsn](https://docs.google.com/drawings/d/e/2PACX-1vT5pWHfUR5phIDYUL0NdfyqZc5_fg3LxgomOqOSSvh6nDriZzSxMWNvRkBo8Hyl_CH9XBgKpJ9-t_iT/pub?w=532&h=352)

![mkmk-button / 3 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vR0FV0g7ywhbb7-02pDvuB-ZB3oiwfomAyUur4Lfx0pLKXQT2EcaSv6tK8RKDVg6GeDoLNG8Vk0j8W1/pub?w=578&h=516)

SORACOM LTE-M Button からのボタン押下を待ち受ける状態になります。このタイミングで SORACOM LTE-M Button のボタンを１回押してください。

* LED が赤点灯 (= データ送信失敗) だった場合は、再度ボタンを１回押してください

登録済みになりましたら [完了] をクリックします。

![mkmk-button / 4 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vSKoIzpJwqKkSXsDLEGAbdO4a6tKHx5-PKpSVv7KBWgY5_4wcZS3rhLZ_CSUlZ-Eqv6O4GsJFdPjAub/pub?w=499&h=726)

以下のようにデバイス一覧が表示されていれば登録成功です。
この時点では `無効` と表示されていますが、この後の作業で有効にしていきます。この時点ではこれでＯＫとなります。

一覧に表示されている意味は以下の通りです

* デバイス ID
    * DSN と呼ばれる一意の番号です。 AWS IoT 1-Click 対応デバイスには SORACOM LTE-M Button の他に AWS IoT エンタープライズボタンといったものがありますが、それら全てにおいて一意になる番号です。
* タイプ
    * デバイスの形状を表します。現在は `button` のみです。
* デバイスリージョン
    * デバイスが管理されているリージョンです。現在のところ利用者はリージョンを選ぶことができず、オレゴン(us-west-2) 固定となります。
* 有効
    * *有効* もしくは *無効* です。初期状態は *無効* です。 *有効* は課金対象デバイスです。 *無効* にする方法は [SORACOM LTE-M Button を無効化する](../closing/disable) をご覧ください。
* プロジェクト、配置
    * ボタンに紐づいた機能(Lambda 関数)の状況です。初期状態は双方とも _未割り当て_ です。
* ヘルス
    * ボタンの寿命です。詳しくは後述する [ボタンの「ヘルス」について](#life) をご覧ください。

![mkmk-button / 5 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vQXuiKDLSeAUC9TbELS5yzMgC-_Ndl7KRuXcWScAYI_hu4t0xqK85Jn_qpGNSWwlxTdKCRTWqhdMd90/pub?w=929&h=315)

#### ボタンを登録解除したい場合

登録したボタンは解除することができます。主に別の AWS アカウントへ再登録する際に利用する機能です。

登録解除方法は [SORACOM LTE-M Button を AWS IoT 1-Click から解除](../closing/unclaim) をご覧ください。

AWS IoT 1-Click の費用を抑えたい場合は解除ではなく "無効" にすることで実現できます。詳しくは [料金について](../#fee) をご覧ください。

<h4 id="life">ボタンの「ヘルス」について</h4>

**ヘルス** に表示されている % は `1 - 押下回数 / 1500` もしくは `1 - 開始日からの経過日数 / 365` のどちらかで小さいほうが表示されます。

SORACOM LTE-M Button においての *ヘルス* は電池残量ではありません。（他のモデルでは電池残量である場合がありますが異なりますのでご注意ください）

押下回数、開始日からの経過日数、電池残量を具体的に管理したい場合は SORACOM LTE-M Button を SORACOM に登録することで SORACOM ユーザーコンソールおよび API で確認することができます。

登録の方法は [SORACOM LTE-M Button を SORACOM へ登録する](../closing/add-to-soracom) をご覧ください。（**貸し出しの方は登録しないでください！**）

## 作業2: AWS IoT 1-Click で Email 送信設定を行う













