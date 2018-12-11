<h1>SORACOM LTE-M Button を AWS IoT 1-Click に登録して、メールを使い動作確認</h1>

[目次に戻る](index#work-a)

SORACOM LTE-M Button が使えるように AWS IoT 1-Click に登録した後、動作確認のためにメールを送ってみましょう。

![button-mkmk / Email 全体像](https://docs.google.com/drawings/d/e/2PACX-1vQcTupxolXoBHeRzGr_UBp3TIZbV1nniNrINjKl16fwh4Kddle8zG9I5kaJp0SwuZCfjUAxAiKHNTV8/pub?w=721&h=406)

## 準備

* SORACOM LTE-M Button を手元に用意してください

<h2 id="claim">作業1: AWS IoT 1-Click へ SORACOM LTE-M Button を登録する</h2>

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home) を開きログインしたあと、リージョンを "オレゴン" に変更し、 AWS IoT 1-Click のコンソールを開きます。

![mkmk-button / 1-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vSzawNDQ3RDZ0RiN6lu1nv5Y57aUOlSuYoK47BZIs72nt6bHnlbhHf6QAn4bxmJQnZHmQES6gAAn-j5/pub?w=927&h=284)

![mkmk-button / 1-2 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vTprwdD-l_uDEZbhNugIaePDUv9MYWYkXfxHFq4IA4fVNKfZFNrTqCWpDGMksArW7HhN7TtMWK_TKGF/pub?w=612&h=276)

AWS IoT 1-Click のコンソールから [デバイスの登録] をクリックします。

![mkmk-button / 1-3 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vRZ_OiMuE0UPvKG2QxIBfA1OP0laZJiDG4gWa-zwfcOqW6B82I3T0uCxasen8uCh_ttXJuHKBoye_q4/pub?w=752&h=216)

SORACOM LTE-M Button の電池カバーを開けて DSN を AWS IoT 1-Click に入力し [登録] をクリックします。

* DSN は文字が非常に小さいですが、頑張って読み取ってください (助け合ってください...)
    * `オー` と 数字の０ 、 `アイ` と 数字の１ などが間違えやすい文字です
* スマートフォン向けアプリであれば QR コードを読み取ることで登録も可能です。その方法は [Getting Started with SORACOM LTE-M Button](https://dev.soracom.io/jp/start/aws_button_slack/#registration) をご覧ください

![mkmk-button / 1-4 dsn](https://docs.google.com/drawings/d/e/2PACX-1vT5pWHfUR5phIDYUL0NdfyqZc5_fg3LxgomOqOSSvh6nDriZzSxMWNvRkBo8Hyl_CH9XBgKpJ9-t_iT/pub?w=532&h=352)

![mkmk-button / 1-5 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vR0FV0g7ywhbb7-02pDvuB-ZB3oiwfomAyUur4Lfx0pLKXQT2EcaSv6tK8RKDVg6GeDoLNG8Vk0j8W1/pub?w=578&h=516)

SORACOM LTE-M Button からのボタン押下を待ち受ける状態になります。このタイミングで SORACOM LTE-M Button のボタンを１回押してください。

* LED が赤点灯 (= データ送信失敗) だった場合は、再度ボタンを１回押してください

登録済みになりましたら [完了] をクリックします。

![mkmk-button / 1-6 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vSKoIzpJwqKkSXsDLEGAbdO4a6tKHx5-PKpSVv7KBWgY5_4wcZS3rhLZ_CSUlZ-Eqv6O4GsJFdPjAub/pub?w=499&h=726)

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
    * *有効* もしくは *無効* です。初期状態は *無効* です。 *有効* は課金対象デバイスです。 *無効* にする方法は [SORACOM LTE-M Button を無効化する](closing/disable) をご覧ください。
* プロジェクト、配置
    * ボタンに紐づいた機能(Lambda 関数)の状況です。初期状態は双方とも _未割り当て_ です。
* ヘルス
    * ボタンの寿命です。詳しくは後述する [ボタンの「ヘルス」について](#life) をご覧ください。

![mkmk-button / 1-7 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vQXuiKDLSeAUC9TbELS5yzMgC-_Ndl7KRuXcWScAYI_hu4t0xqK85Jn_qpGNSWwlxTdKCRTWqhdMd90/pub?w=929&h=315)

### ボタンを登録解除したい場合

登録したボタンは解除することができます。主に別の AWS アカウントへ再登録する際に利用する機能です。

登録解除方法は [SORACOM LTE-M Button を AWS IoT 1-Click から解除](closing/unclaim) をご覧ください。

AWS IoT 1-Click の費用を抑えたい場合は解除ではなく "無効" にすることで実現できます。詳しくは [料金について](index#fee) をご覧ください。

<h3 id="life">ボタンの「ヘルス」について</h3>

**ヘルス** に表示されている % は `1 - 押下回数 / 1500` もしくは `1 - 開始日からの経過日数 / 365` のどちらかで小さいほうが表示されます。

SORACOM LTE-M Button においての *ヘルス* は電池残量ではありません。（他のモデルでは電池残量である場合がありますが異なりますのでご注意ください）

押下回数、開始日からの経過日数、電池残量を具体的に管理したい場合は SORACOM LTE-M Button を SORACOM に登録することで SORACOM ユーザーコンソールおよび API で確認することができます。

SORACOM への登録の方法は [SORACOM LTE-M Button を SORACOM へ登録する](closing/add-to-soracom) をご覧ください。  
**注意：貸し出しの方は SORACOM への登録しないでください！**

## 作業2: AWS IoT 1-Click で Email 送信設定を行う

AWS マネジメントコンソールのリージョンが **オレゴン** (us-west-2) になっている事を確認します。  
なっていなければ **オレゴン** に切り替えてください。

![mkmk-button / 2-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vSgprF60wQZHq5nvPUcueml_-wNwuVn3EWx9FqRV73-7mxS0bapShs6fPVD2LMV-Lrr6GLlb-aEhjIr/pub?w=928&h=189)
AWS マネジメントコンソールのリージョンが **オレゴン** (us-west-2) になっている事を確認します。

AWS IoT 1-Click コンソールから [管理] > [プロジェクト] を開いた後 [プロジェクトの作成] をクリックします。

![mkmk-button / 2-2 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vSQtO8MYnq7k9drY2LWfYrhuWNmjZ16USKNslZr0L6mGvOET8KPYkePkvI3Sq8s3-HCelF3tfeFB5Vz/pub?w=897&h=473)

プロジェクト情報の指定で以下のように入力した後 [次へ] をクリックします。

* プロジェクト名: `TestEmail` (任意の文字列)

![mkmk-button / 2-3 project](https://docs.google.com/drawings/d/e/2PACX-1vSOzmOCZiQg7eXh1pBAy_51zVEpmI9Qg8ApzlMeF1LIWcxOOvpG3_wZNRrNeiKVh4eS0zxE_Nhclbps/pub?w=765&h=451)

プロジェクトのプレイスメントのテンプレートの定義では以下のように設定した後 [プロジェクトの作成] をクリックします。

1. **デバイステンプレートの定義** の [開始] をクリックします
2. **テンプレートのデバイスタイプを選択する** 一覧で _すべてのボタンタイプ_ をクリックします
3. 表示されたフォームを下記のように設定します
    * デバイステンプレート名: `Email` (任意の文字列)
    * アクション: _E メールの送信_
4. **プレイスメントの属性** を以下のように設定します
    * 必須の E メールのデフォルト値: {ボタンで送信したい先の E メールアドレス}
    * 必須の件名のデフォルト値: `テスト送信` (任意の文字列)
    * 必須の本文のデフォルト値: `SORACOM LTE-M Button のテスト送信` (任意の文字列)

![mkmk-button / 2-4 placement](https://docs.google.com/drawings/d/e/2PACX-1vSBzdRl0kI1SI42nj_NnEIBvMOw5snK82NfOq009BKfXjEVTxcdlc6AW79DwdmYd8udtoqahtTGF4vT/pub?w=598&h=842)

プロジェクトとテンプレートが正常に作成されたら [プレイスメントの作成] をクリックします。

![mkmk-button / 2-5 placement](https://docs.google.com/drawings/d/e/2PACX-1vQ2UY0jIXKzzKf5hSu9a5RVxgsgARi3vGzN_BEfX5o_6E_US3Ky8WeSHOY72x2-ELlJbv7srJnKUq-L/pub?w=765&h=446)

プロジェクトの新しいプレイスメントでは以下のように設定した後 [プレイスメントの作成] をクリックします。

* デバイスのプレイスメント名: `button1` (任意の文字列)
* [デバイスの選択] をクリック
    * ボタンの一覧が表示されます。結び付けたいボタンをクリックします。
* プレイスメントの属性は特に編集することはありません
    * 先に作成した「テンプレート」で設定した内容が引き継がれています
    * 逆にここでテンプレートから引き継がれた内容を上書きすることも可能です

![mkmk-button / 2-6 placement](https://docs.google.com/drawings/d/e/2PACX-1vQGcMIdUNmqnbc1iY9q75kSZRUmj6NT7GScR-5Ld1Ta9KH0xH8IRNnjTwEegvOQsRqij_p3lhiSmOCE/pub?w=649&h=793)

以下のような画面になれば完了です。  
バックボタン (←) をクリックして AWS IoT 1-Click コンソールに戻ります。

![mkmk-button / 2-7 placement](https://docs.google.com/drawings/d/e/2PACX-1vR33NlAAkYpwifDiTx1wAMyy6NnGNeBYABdJS3AvlI0V4U3vKhJafNsXgSrrahs1P-FyTUkHTZxEXzL/pub?w=927&h=349)

## 作業3: Amazon SES で送信先 Email の認証を行う

Amazon SES (Simple Email Service) のコンソールを開きます。

[サービス] をクリックした後、検索窓に `ses` と入れるか、 "カスタマーエンゲージメント" カテゴリの中の Simple Email Service をクリックしてください。

![mkmk-button / 3-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vRlCqRPj4jRjUwRkiB9FqvGEyGZP8BpRZuDBMjFqLKCI2_NbP_kowp3fOgcghVN1LAL2nI6l6c5l1hK/pub?w=678&h=232)

AWS マネジメントコンソールのリージョンが **オレゴン** (us-west-2) になっている事を確認します。  
なっていなければ **オレゴン** に切り替えてください。

![mkmk-button / 2-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vSgprF60wQZHq5nvPUcueml_-wNwuVn3EWx9FqRV73-7mxS0bapShs6fPVD2LMV-Lrr6GLlb-aEhjIr/pub?w=928&h=189)

[Email Addresses] をクリックした後、[Verify a New Email Address] をクリックします。

![mkmk-button / 3-2 ses](https://docs.google.com/drawings/d/e/2PACX-1vShW6Y3eJLbvu3UzCfFC7e90OFrsck7D4W10T7l2B02RiY3NMlJKKkkYywd46eOqoW8PwrWPQ9dEdYK/pub?w=552&h=331)

フォームに以下のように入力して [Verify This Email Address] をクリックします。  
その後表示されたダイアログは [Close] をクリックします。

* Email Address: {ボタンで送信したい先の E メールアドレス}

![mkmk-button / 3-3 ses](https://docs.google.com/drawings/d/e/2PACX-1vSrCb0jqeMBwmFsQ6xau8kXkEJlC2WNnbtbi8gBxokO6hPu-wgtDib3kax75EykDnn1Nsb4sAAe1_4o/pub?w=662&h=259)

直後の状態は以下の通りです。pending verification と表示されている事を確認してください。

![mkmk-button / 3-4 ses sent](https://docs.google.com/drawings/d/e/2PACX-1vQ6LLE8QfqqsmHzW7VjUXxhH6zOGzpoxrt7Vj7mAG7gx9OfUf6mXsisZeEitoL6q0zZ038XduxGr4KV/pub?w=928&h=156)

メールソフトを開き、下記のようなメールが届いている事を確認したら、メール本文内の URL をクリックしてください。 (クリックした後は削除してしまって構いません)  
クリックすると「検証に成功しました」というページが表示されます。

![mkmk-button / 3-5 email](https://docs.google.com/drawings/d/e/2PACX-1vRhBENOTyD9iW8fJo5ly_S71nMJC4FqxZvRB6NycGwliB8fFN0Zr8i0SdPgQwy5eOC03pk_2J3G88CT/pub?w=258&h=438)

Amazon SES コンソールに戻り [リロードボタン] で表示を更新した後に verified と表示されている事を確認してください。  
そうでない場合は *resend* をしてメールを再送するか、もしくは別のメールアドレスで再度同じ手順を行ってください。  
(もしメールアドレスを変更する場合は、ステップ３が終わったら再度 AWS IoT 1-Click コンソールからテンプレートに設定したメールアドレスを変更する必要があります。)

![mkmk-button / 3-6 ses verified](https://docs.google.com/drawings/d/e/2PACX-1vTgN6ur9EWU6-lQ913PWOKHUBi2I7cTYTr9c_ucQsqbj33QiHZoRG5eARmUZwzm8Nd15NRKYyObPiCo/pub?w=928&h=170)

## 作業4: SORACOM LTE-M Button からメールを送信してみる

ここまでの作業で AWS IoT 1-Click を通じて Amazon SES 経由でメールが送信されるようになりました。

実際に SORACOM LTE-M Button を押してみてください。  
以下のようなメールが届いたら成功です。

![mkmk-button / 4-1 mail](https://docs.google.com/drawings/d/e/2PACX-1vSXsDZ8opJBE0Vllxt-cbbPEbj00UWvCJhv5eYiGX0csnP0yY860DgKKbY85PS2tChueI70mCPvpG2c/pub?w=316&h=204)

ボタン押下の内容に応じて `SINGLE` の部分が `DOUBLE` や `LONG` に変わりますので試してみてください。

## メールが届いたらこの章は終了です

### まとめ

* AWS マネジメントコンソールを通して AWS IoT 1-Click へのボタンの登録方法
* テスト環境としての Email の設定

### 次へ進む

* [メールの内容を変えてみる](customize-lambda-function) へ進む
* [目次に戻る](index#work-a)

## トラブルシューティング

### メールが届かない

* 原因: Amazon SES での認証メール、もしくは SORACOM LTE-M Button を押した時のメールが迷惑メール扱いになっている可能性があります
* 対策: 以下を確認してください
    * 送信先メールアドレスが verified になっている (Amazon SES コンソールで確認できます)
        * これでも届かない場合は Amazon SES 上で *Send a Test Email* をしてみてください

