# SORACOM UG 信州 #6 2019/3/30

## ハンズオンの内容
SORACOM LTE-M Button powered by AWS を使い、ボタンを押したらTwilio経由で電話が掛かってくるようにする仕組みを作成します  
（参考：[SORACOM Buttonで会議脱出ボタンをつくる](https://kizawa.info/soracombutton-escape)）

### ハンズオンの構成
![soracomug_shinshu6 / Twilio全体像](https://kizawa.info/wp-content/uploads/2018/11/soracombutton-arch3.png)

## 本日の貸し出し機材
* SORACOM LTE-M Button powered by AWS（※あのボタン貸出枠で参加の方）

## お客様の持ち物
* Wifi に繋がるPC
* クレジットカード（AWSアカウント作成に必要になります）
* 会場で着信可能な携帯電話
   * AWSのアカウント作成時に電話音声による認証が必要となります(非通知からの電話に対する着信拒否設定の解除が必要)
   * Twilioのアカウント作成時にSMSによる認証が必要となります
   * ボタンを押したら電話がかかってくる宛先となります

## 参加費用
無料（ただしAWSの利用料金、数円が発生します）

## 目次
1. [AWS アカウントの作成](#content1)
2. [SORACOM LTE-M Button を AWS IoT 1-Click に登録する](#content2)
3. [Twilio アカウントの作成](#content3)
4. [Twilio セットアップ](#content4)
5. [Twilio Studio Flowの作成](#content5)
6. [AWS Lambda関数の設置](#content6)
7. [AWS IoT 1-Clickのプロジェクト/プレイスメント設定](#content7)
8. [動作確認](#content8)
9. [お片付け](#contentE)

## プログラム
<h3 id="content1">1. AWS アカウントの作成</h3>
(※既にアカウントをお持ちの方は読み飛ばして下さい)  
<a href="https://aws.amazon.com/jp/register-flow/" target="_blank">AWS アカウント作成の流れ (AWS のページに飛びます)</a> から進み作成してください。  

**アカウント作成時のポイント**  
電話音声による認証が必要となります
「非通知」からの着信となるため、必要ならば非通知着信が可能になるようにしてください

**AWSサポートプランについて**  
理由がない限り「ベーシックプラン」を選択してください。それ以外のプランは費用がかかります

<h3 id="content2">2. SORACOM LTE-M Button を AWS IoT 1-Click に登録する</h3>
AWS IoT 1-Click ではボタンと Lambda 関数を結びつける概念として「プレイスメント」と「テンプレート」そして「プロジェクト」が存在します。これらを全て作成したうえで、それぞれボタンと Lambda 関数に結び付けていきます。

![soracomug_shinshu6 / AWSIoT1Click概念図](https://docs.google.com/drawings/d/e/2PACX-1vRNsm3bCso3sEDoLqx0F7ReWgvOUvpyxAxbIkRDHHhhhTCkIbc8xuLW2zwsfSFIkHntgxUSaXCoHC0B/pub?w=927&h=520)

**AWS IoT 1-Click へ LTE-M Button を登録する**  
[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home)を開きログインした後、リージョンをオレゴンに変更し、AWS IoT 1-Clickのコンソールを開きます。

![soracomug_shinshu6 / 2-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vSzawNDQ3RDZ0RiN6lu1nv5Y57aUOlSuYoK47BZIs72nt6bHnlbhHf6QAn4bxmJQnZHmQES6gAAn-j5/pub?w=927&h=284)

![soracomug_shinshu6 / 2-2 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vTprwdD-l_uDEZbhNugIaePDUv9MYWYkXfxHFq4IA4fVNKfZFNrTqCWpDGMksArW7HhN7TtMWK_TKGF/pub?w=612&h=276)

AWS IoT 1-Click のコンソールから [デバイスの登録] をクリックします。  
![soracomug_shinshu6 / 2-3 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vRZ_OiMuE0UPvKG2QxIBfA1OP0laZJiDG4gWa-zwfcOqW6B82I3T0uCxasen8uCh_ttXJuHKBoye_q4/pub?w=752&h=216)

LTE-M Button の電池カバーを開けて DSN を AWS IoT 1-Click に入力し [登録] をクリックします。  
![soracomug_shinshu6 / 2-4 dsn](https://docs.google.com/drawings/d/e/2PACX-1vT5pWHfUR5phIDYUL0NdfyqZc5_fg3LxgomOqOSSvh6nDriZzSxMWNvRkBo8Hyl_CH9XBgKpJ9-t_iT/pub?w=532&h=352)

![soracomug_shinshu6 / 2-5 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vR0FV0g7ywhbb7-02pDvuB-ZB3oiwfomAyUur4Lfx0pLKXQT2EcaSv6tK8RKDVg6GeDoLNG8Vk0j8W1/pub?w=578&h=516)

LTE-M Button からのボタン押下を待ち受ける状態になります。  
このタイミングで LTE-M Button のボタンを１回押してください。  
(LED が赤点灯(= データ送信失敗)となった場合は、再度ボタンを押して下さい)

登録済みになりましたら [完了] をクリックします。  
![soracomug_shinshu6 / 2-6 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vSKoIzpJwqKkSXsDLEGAbdO4a6tKHx5-PKpSVv7KBWgY5_4wcZS3rhLZ_CSUlZ-Eqv6O4GsJFdPjAub/pub?w=499&h=726)

以下のようにデバイス一覧が表示されていれば登録成功です。  
![soracomug_shinshu6 / 2-7 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vQXuiKDLSeAUC9TbELS5yzMgC-_Ndl7KRuXcWScAYI_hu4t0xqK85Jn_qpGNSWwlxTdKCRTWqhdMd90/pub?w=929&h=315)

一覧に表示されている意味は以下の通りです。

* デバイス ID
    * DSN と呼ばれる一意の番号です。 AWS IoT 1-Click 対応デバイスには SORACOM LTE-M Button の他に AWS IoT エンタープライズボタンといったものがありますが、それら全てにおいて一意になる番号です。
* タイプ
    * デバイスの形状を表します。現在は `button` のみです。
* デバイスリージョン
    * デバイスが管理されているリージョンです。現在のところ利用者はリージョンを選ぶことができず、オレゴン(us-west-2) 固定となります。
* 有効
    * *有効* もしくは *無効* です。初期状態は *無効* です。 *有効* は課金対象デバイスです。 
* プロジェクト、配置
    * ボタンに紐づいた機能(Lambda 関数)の状況です。初期状態は双方とも _未割り当て_ です。
* ヘルス
    * ボタンの寿命です。

登録したボタンの右にある [...] をクリックした後、[デバイスの有効化] をクリックします。  
![soracomug_shinshu6 / 2-8 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vRZvuTrcEL7gn72cEFK11VO1HZticJRaUUgt0_znxQOX0MORBdVup1GDCdH32Rq1o_vLNqxP-Wm9p3c/pub?w=926&h=298)  
これでボタンが利用可能な状態になりました。

<h3 id="content3">3. Twilio アカウントの作成</h3> (※既にアカウントをお持ちの方は読み飛ばして下さい)

TwilioはAPIによってコントロールできる電話サービスです。  
登録することで電話番号を取得でき、その電話番号での受発信がAPIでコントロールできます。今回は発信のコントロールを行います。

**アカウントの取得**  
[Twilioのページ](https://twilio.kddi-web.com/)を開き、無料サインアップのアイコンをクリックします。  
![soracomug_shinshu6 / 3-1 Twilio-Top](https://kizawa.info/wp-content/uploads/2018/11/twilio-1-768x377.png)

利用規約に同意します。  
![soracomug_shinshu6 / 3-2 Twilio-signup1](https://kizawa.info/wp-content/uploads/2019/03/twilio-1.png)

氏名・メールアドレス・パスワードの情報を入力します。  
パスワードは14桁以上必要となります。  
![soracomug_shinshu6 / 3-3 Twilio-signup2](https://kizawa.info/wp-content/uploads/2019/03/twilio-2.png)

身元検証用に携帯電話の電話番号の入力を行います。  
携帯電話番号は最初のゼロを取り、80xxxxxxxx のように入力して下さい。  
なお、トライアル（無料）アカウントではここで登録した電話番号のみに発信が可能であるため、今回のハンズオンで電話を着信したい携帯電話の番号を入力して下さい。  
（有料アカウントにアップグレードすることで任意の番号に発信可能となります）  
![soracomug_shinshu6 / 3-4 Twilio-signup3](https://kizawa.info/wp-content/uploads/2019/03/twilio-3.png)

入力した携帯電話に対してSMSで検証コードが送信され認証が完了です。  
![soracomug_shinshu6 / 3-5 Twilio-Validate1](https://kizawa.info/wp-content/uploads/2018/11/twilio-2.png)

チュートリアル画面が出ます。今回は「Skip to dashboard」をクリックしてください。  
![soracomug_shinshu6 / 3-6 Twilio-Validate2](https://kizawa.info/wp-content/uploads/2019/03/twilio-4.png)

トップ画面が表示されます。  
![soracomug_shinshu6 / 3-7 Twilio-Validate3](https://kizawa.info/wp-content/uploads/2019/03/twilio-5.png)

<h3 id="content4">4. Twilio セットアップ</h3>

**電話番号の取得**  
Twilioで利用できる電話番号を取得します。  
[電話番号の取得画面](https://jp.twilio.com/console/phone-numbers/getting-started)にアクセスします。  
![soracomug_shinshu6 / 4-1 Twilio-GetNumber1](https://kizawa.info/wp-content/uploads/2018/11/twilio-3-768x208.png)

「最初のTwilio電話番号を取得」をクリックし電話番号を取得します。  
気に入らない場合は選び直しが可能です。  
なおトライアルアカウントで取得可能な電話番号は050のIP電話番号のみとなります。  
![soracomug_shinshu6 / 4-2 Twilio-GetNumber2](https://kizawa.info/wp-content/uploads/2018/11/twilio-4.png)

電話番号が取得できました。終了ボタンをクリックします。  
作成した電話番号はメモ帳等にコピーしておきます。  
![soracomug_shinshu6 / 4-3 Twilio-GetNumber3](https://kizawa.info/wp-content/uploads/2019/03/twilio-6.png)

**クレデンシャル情報の確認**  
AWS側からAPIで呼び出しできるよう、クレデンシャル情報を確認しておきます。  
[Twilioの設定画面](https://jp.twilio.com/console/project/settings)にアクセスします。  
![soracomug_shinshu6 / 4-3 Twilio-Credential](https://kizawa.info/wp-content/uploads/2018/11/twilio-5-768x533.png)  
ライブクレデンシャルの ACCOUNT SID と AUTH TOKENの内容をメモ帳等にコピーしておきます。この情報がLambda関数からの呼び出しに必要になります。

<h3 id="content5">5. Twilio Studio Flowの作成</h3>
電話を受けた後、任意のメッセージを再生できるよう、Studio Flowの作成を行います。

[Studio Dashboard](https://jp.twilio.com/console/studio)にアクセスし、Create a flowをクリックします。  
![soracomug_shinshu6 / 5-1 Twilio-Studio](https://kizawa.info/wp-content/uploads/2018/11/tstudio-1-1024x371.png)

続けてフローの名称を入力します。  
![soracomug_shinshu6 / 5-2 Twilio-Studio](https://kizawa.info/wp-content/uploads/2018/11/tstudio-2.png)

作成方法はStart from scratchとします。  
![soracomug_shinshu6 / 5-3 Twilio-Studio](https://kizawa.info/wp-content/uploads/2018/11/tstudio-3.png)

下のようなフロー作成画面が開きます。  
右側のWIDGET LIBRARYから、”Make Outgoing Call” と “Say/Play” のウィジェットをドラッグ、フローを繋げて以下のように設定します。  
また、Say/Playのウィジェットでは読み上げるメッセージと言語(Japanese)を設定します。  
![soracomug_shinshu6 / 5-4 Twilio-Studio](https://kizawa.info/wp-content/uploads/2018/11/tstudio-5-1024x657.png)

作成できたら、右上にあるPublishボタンを押して完成です。  
Studio Dashboardに戻りますので、作成したフローのSIDをメモ帳等にコピーしておきます。  
![soracomug_shinshu6 / 5-5 Twilio-Studio](https://kizawa.info/wp-content/uploads/2018/11/tstudio-7-1024x221.png)

<h3 id="content6">6. AWS Lambda関数の設置</h3>

SORACOM LTE-M Buttonが押された際にTwilioを呼び出すプログラム(Lambda関数)を設置します。  
（※今回はハンズオン時間の関係上、作成済の関数をアップロードして設置します）
[Lambda関数一式(zip)](https://github.com/kizawa2020/iot-showcase/raw/master/events/soracomug-shinshu6/lambda.zip)をダウンロードしてください。

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home)を開きログインした後、リージョンをオレゴンに変更し、Lambdaのコンソールを開きます。  
![soracomug_shinshu6 / 6-1 Lambda1](https://kizawa.info/wp-content/uploads/2019/03/lambda-1.png)

Lambdaコンソールが開きますので、ダッシュボードから関数の作成をクリックします。  
![soracomug_shinshu6 / 6-2 Lambda2](https://kizawa.info/wp-content/uploads/2019/03/lambda-0.png)

関数の作成画面が開きます。以下の情報を入力します。
* 作成方法：一から作成  
* 関数名：任意の名前
* ランタイム：Python3.7
* 実行ロール：基本的なLambdaアクセス権限で新しいロールを作成
![soracomug_shinshu6 / 6-3 Lambda2](https://kizawa.info/wp-content/uploads/2019/03/lambda-3.png)

続いて関数の編集画面が開きます。以下の設定を行います  
* 関数コードのセクション
    * コードエントリタイプ：.zipファイルをアップロード
    * 関数パッケージ：アップロードボタンをクリックし、先程ダウンロードしたzipファイルを指定
* 基本設定のセクション
    * タイムアウト時間を 3秒⇒10秒 に変更
![soracomug_shinshu6 / 6-4 Lambda2](https://kizawa.info/wp-content/uploads/2019/03/lambda-4.png)  
![soracomug_shinshu6 / 6-5 Lambda2](https://kizawa.info/wp-content/uploads/2019/03/lambda-5.png)  

最後に画面上方にある「保存」ボタンをクリックして下さい。  
以上で完了です。

<h3 id="content7">7. AWS IoT 1-Clickのプロジェクト・プレイスメント設定</h3>

**AWS IoT 1-Clickプロジェクト設定**  
AWS IoT 1-Click コンソールから [管理] > [プロジェクト] を開いた後 [プロジェクトの作成] をクリックします。  
![soracomug_shinshu6 / 7-1 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vSQtO8MYnq7k9drY2LWfYrhuWNmjZ16USKNslZr0L6mGvOET8KPYkePkvI3Sq8s3-HCelF3tfeFB5Vz/pub?w=897&h=473)

プロジェクト名として任意の名前を入力します。  
![soracomug_shinshu6 / 7-2 projectName](https://kizawa.info/wp-content/uploads/2018/11/aws1click-6.png)

**プレイスメントのテンプレート**  
プロジェクトのプレイスメントのテンプレートの定義画面に移ります。  
デバイステンプレートの定義の箇所をクリックします。  
![soracomug_shinshu6 / 7-3 devicetemplate1](https://kizawa.info/wp-content/uploads/2019/03/1click-1.png)

「すべてのボタンタイプ」の箇所をクリックします。  
![soracomug_shinshu6 / 7-4 devicetemplate2](https://kizawa.info/wp-content/uploads/2019/03/1click-2.png)

続けて先程作成したLambda関数と紐付けます。以下の情報を入力します。　　
* デバイステンプレート名：任意の名前
* アクション：Lambda関数の選択
* AWSリージョン：（先程Lambda関数を作成したリージョン）
* Lambda関数：先程作成したLambda関数名
![soracomug_shinshu6 / 7-5 devicetemplate3](https://kizawa.info/wp-content/uploads/2019/03/1click-3.png)

**プレイスメントの属性**  
引き続き画面下の方にあるプレイスメントの属性に以下の情報を入力します。
|属性の名前|デフォルト値|
|:--------|:----------|
|twilio_sid|(TwilioのACCOUNT SID)|
|twilio_token|(TwilioのAUTH TOKEN)|
|twilio_flowid|(Twilio Studio FlowのSID)|
|twilio_number|(Twilioで取得した電話番号 +8150xxxxxxxx の形式)|
|twilio_callto|(電話の発信先：Twilioに登録したご自身の携帯電話番号 +81xxxxxxxxxx の形式)|

![soracomug_shinshu6 / 7-6 placement](https://kizawa.info/wp-content/uploads/2019/03/1click-4.png)  
ここまで入力が完了したら「プロジェクトの作成」をクリックします。

![soracomug_shinshu6 / 7-3 projectLambda](https://kizawa.info/wp-content/uploads/2018/11/aws1click-7.png)

プロジェクトが作成されました。  
![soracomug_shinshu6 / 7-4 projectCreate](https://kizawa.info/wp-content/uploads/2018/11/aws1click-8.png)  
[プレイスメントの作成] をクリックします。

**プレイスメント設定**  
続けてプレイスメントの設定を行います。  
プレイスメントの設定で、登録したボタンのDSNコードと紐付けます。  
![soracomug_shinshu6 / 7-5 placement](https://kizawa.info/wp-content/uploads/2018/11/aws1click-9.png)
プロジェクトの新しいプレイスメントでは以下のように設定した後 [プレイスメントの作成] をクリックします。

* デバイスのプレイスメント名: `button1` (任意の文字列)
* [デバイスの選択] をクリック
    * ボタンの一覧が表示されます。結び付けたいボタンをクリックします。
* プレイスメントの属性は特に編集することはありません
    * 先に作成した「テンプレート」で設定した内容が引き継がれています
    * 逆にここでテンプレートから引き継がれた内容を上書きすることも可能です

以上で設定は完了です。

<h3 id="content8">8. 動作確認</h3>

ここまでの作業で AWS IoT 1-Click を通じて Twilio経由で電話がかけられるようになりました。  
ボタンを押すと、ご自身の携帯電話に電話が掛かってくるようになったでしょうか。  
（※うまく動作しない方はスタッフまでお問い合わせ下さい）

<h3 id="contentE">9. お片付け</h3>
AWS IoT 1-Click のコンソールを開きます。リージョンがオレゴンになっていることを確認してください。  
[管理] > [プロジェクト] とクリックした後、解除を行いたいデバイスが所属しているプロジェクトをクリックします。  
![1 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vTKFP7PyM2LajuqPhfZ8Gc3bGus8fbi1xJ6alpcEoOKLmPiM9m0YZ9F8Zn0t8KSQvN61lZh4F4zxov1/pub?w=601&h=591)

[プレイスメント] から解除したいデバイスの [...] をクリックした後に表示される [プレイスメントの編集] をクリックします。  
![2 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vS8f28yZgWHTjGktSFGbSNqRVgbbl1TX7Y99p2zlvbmd6r5rdVqvyCI9cNVvJiXp5KjJiO7XK71b6a-/pub?w=929&h=529)

デバイスが表示されている部分の [クリア] をクリックした後、[プレイスメントの更新] をクリックします。  
![3 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vSAticSljF3nnjF3xLZrwUNKVY7PHmwzPjSfFJqmcJJ8-n6S1LMqUtdm_IVDrZdkfQThKlSLa-pbMls/pub?w=928&h=407)

これでデバイスとプレイスメントの割り当てが無くなりました。  
[管理] > [デバイス] とクリックした後、解除を行いたいデバイスの [...] をクリックした後に表示される [デバイスの登録解除] をクリックします。  
最後に確認ダイアログの [登録解除] で解除が完了します。

※プレイスメントに割り当てられているデバイスは解除できませんので、プレイスメントから外してから行ってください。

![mkmk-button / 1 unclaim](https://docs.google.com/drawings/d/e/2PACX-1vTCsBV32iOWgBn8QZJbmiRQIIv1k4JxFmtw3STpYFl_I-iGZn-ejHO_7gSg1Nvv-IxkdtnpbOMHHUB8/pub?w=928&h=269)

一覧から対象デバイスが無くなれば解除完了です。  
こちらでハンズオンは終了です。お疲れ様でした。

## 最後に
最後に貸し出ししたSORACOM LTE-M Buttonをスタッフに手渡してください。  
お渡し頂くタイミングで、プレイスメントの割り当てが無くなっているかを確認させていただきます。
