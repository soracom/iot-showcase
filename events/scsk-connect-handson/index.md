# 【ハンズオン】Amazon ConnectとSORACOMボタンで自動コールシステムをつくる

## ハンズオンの内容
SORACOM LTE-M Button powered by AWSを利用し、ボタンを押すとAmazon Connectから電話が掛かってくる仕組みを作成します。

### ハンズオンの構成
![soracombutton-connect全体像](http://drive.google.com/uc?export=view&id=1szQTuOtgQNUCOkgzIbEBW1UTKoIoKQZm)

## 本日の貸し出し機材
* SORACOM LTE-M Button powered by AWS（※ボタン貸出枠で参加の方）

## お客様の持ち物
* Wifi に繋がるPC (貸出PCもありますので必要な方はお申し出下さい)
* 会場で着信可能な携帯電話
   * ボタンを押したら電話がかかってくる宛先となります

## 参加費用
**無料**
* ただしAWSの利用料金が数十円が発生します。
* また、取得したAmazon Connect電話番号を削除せず残した場合、1日あたり0.1ドルの課金が発生します。
* AWS IoT 1-Clickに登録したデバイスを無効化あるいは削除せず残した場合、1ヶ月あたり0.25ドルの課金が発生します。

## 目次
1. [SORACOM LTE-M Button を AWS IoT 1-Click に登録する](#content1)
2. [Amazon Connectのインスタンス作成](#content2)
3. [Amazon Connectの電話番号取得](#content3)
4. [Amazon Connectのコールフロー作成](#content4)
5. [AWS Lambda関数の設置](#content5)
6. [AWS IoT 1-Clickのプロジェクト設定](#content6)
7. [動作確認](#content7)
8. [お片付け](#content8)

## プログラム
<h3 id="content1">1. SORACOM LTE-M Button を AWS IoT 1-Click に登録する</h3>

**AWS IoT 1-Click へ LTE-M Button を登録する**  
[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home)を開きログインした後、AWS IoT 1-Clickのコンソールを開きます。

![soracombutton-connect/ 1-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vTprwdD-l_uDEZbhNugIaePDUv9MYWYkXfxHFq4IA4fVNKfZFNrTqCWpDGMksArW7HhN7TtMWK_TKGF/pub?w=612&h=276)

AWS IoT 1-Click のコンソールから [デバイスの登録] をクリックします。  
![soracombutton-connect/ 1-2 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vRZ_OiMuE0UPvKG2QxIBfA1OP0laZJiDG4gWa-zwfcOqW6B82I3T0uCxasen8uCh_ttXJuHKBoye_q4/pub?w=752&h=216)

LTE-M Button の電池カバーを開けて DSN を AWS IoT 1-Click に入力し [登録] をクリックします。  
![soracombutton-connect/ 1-3 dsn](https://docs.google.com/drawings/d/e/2PACX-1vT5pWHfUR5phIDYUL0NdfyqZc5_fg3LxgomOqOSSvh6nDriZzSxMWNvRkBo8Hyl_CH9XBgKpJ9-t_iT/pub?w=532&h=352)

![soracombutton-connect/ 1-4 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vR0FV0g7ywhbb7-02pDvuB-ZB3oiwfomAyUur4Lfx0pLKXQT2EcaSv6tK8RKDVg6GeDoLNG8Vk0j8W1/pub?w=578&h=516)

LTE-M Button からのボタン押下を待ち受ける状態になります。  
このタイミングで LTE-M Button のボタンを１回押してください。  
(LED が赤点灯(= データ送信失敗)となった場合は、再度ボタンを押して下さい)

登録済みになりましたら [完了] をクリックします。  
![soracombutton-connect/ 1-5 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vSKoIzpJwqKkSXsDLEGAbdO4a6tKHx5-PKpSVv7KBWgY5_4wcZS3rhLZ_CSUlZ-Eqv6O4GsJFdPjAub/pub?w=499&h=726)

以下のようにデバイス一覧が表示されていれば登録成功です。  
![soracombutton-connect/ 1-6 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vQXuiKDLSeAUC9TbELS5yzMgC-_Ndl7KRuXcWScAYI_hu4t0xqK85Jn_qpGNSWwlxTdKCRTWqhdMd90/pub?w=929&h=315)

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
![soracombutton-connect/ 1-7 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vRZvuTrcEL7gn72cEFK11VO1HZticJRaUUgt0_znxQOX0MORBdVup1GDCdH32Rq1o_vLNqxP-Wm9p3c/pub?w=926&h=298)  
これでボタンが利用可能な状態になりました。

<h3 id="content2">2. Amazon Connectインスタンスの作成</h3>

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home)を開き、東京リージョンであることを確認後、Amazon Connectのコンソールを開きます。

初回アクセス時には以下のような画面が出ますので「今すぐ始める」をクリックします。
![soracombutton-connect/Connect初回画面](http://drive.google.com/uc?export=view&id=1tnCSmsx4E3oRfMLs_My9EohYS0VPXF9S)

「Amazon Connect内にユーザを保存」を指定し、Amazon ConnectのインスタンスURLを入力します。
このURLは次章以降で開くコンソールのログインURLとなりますので、任意の名前を指定します。
入力が終わったら「次のステップ」をクリックします。
![soracombutton-connect/インスタンス作成1](http://drive.google.com/uc?export=view&id=1p-FMiHAhURCgt7HywB5x_y3kpFw-Rpls)

管理者の名前を決めて入力します。
自身のお名前とユーザ名・パスワード・電子メールアドレスを入力し、「次のステップ」をクリックします。
パスワードは大文字・小文字・数字を含み8文字以上とする必要があります。
![soracombutton-connect/インスタンス作成2](http://drive.google.com/uc?export=view&id=1scBZXLWbMa56e2p41Agc00Z97Amhrxwz)

本インスタンスで電話の発信・着信処理を行うかどうかの選択を行います。
両方にチェックを入れ、「次のステップ」をクリックします。
![soracombutton-connect/インスタンス作成3](http://drive.google.com/uc?export=view&id=1AdYZafZqhE72GDpPNbkKSOOGv7_2r_4z)

データストレージを指定します。
問い合わせフローのログやデータの保存先はご自身のAWSアカウントに紐付くS3バケットとなります。
デフォルトで問題ありませんので、そのまま「次のステップ」をクリックします。
![soracombutton-connect/インスタンス作成4](http://drive.google.com/uc?export=view&id=1_OXyjRDIXPUyUnkNk1MYnNdYSHmXsb6X)

確認画面が表示されます。確認し「インスタンスの作成」を選択します。
![soracombutton-connect/インスタンス作成5](http://drive.google.com/uc?export=view&id=1WhgbK2tSwDZ7vODHDEle0AlTzSFkbosF)

インスタンスの作成には1～2分程度の時間が掛かります。
![soracombutton-connect/インスタンス作成6](http://drive.google.com/uc?export=view&id=1QPU0BsYt8iOJkdiDwTMi0f5Qgq_ItBpL)

作成が完了したら、「今すぐ始める」をクリックし、次章に進んでください。
![soracombutton-connect/インスタンスの作成7](http://drive.google.com/uc?export=view&id=1HxXvuLmqriM8qUe4yc3fK40cpz4i1WTX)

なお、インスタンスARN情報が後(5章)で必要となるため、コピーしておきます。
![soracombutton-connect/インスタンスの作成8](http://drive.google.com/uc?export=view&id=1IxQYVI3bjmZawpzx1tASGWctFNHkjUgD)

<h3 id="content3">3. Amazon Connect電話番号の取得</h3>

前章で指定したAmazon Connectインスタンスの開始画面に切り替わります。
「今すぐ始める」をクリックします。
![soracombutton-connect/電話番号取得1](http://drive.google.com/uc?export=view&id=1ydYm8aJGDBrU9czouoVYOpVtUnj4w1mM)

電話番号の取得を行います。
「国/地域」からJapan(+81)を選択、タイプとして「Direct Dial」を選択すると、電話番号の欄に電話番号の候補が表示されます。
お好みの電話番号を選択し「次へ」をクリックします。
![soracombutton-connect/電話番号取得2](http://drive.google.com/uc?export=view&id=13Z0Yifv6iFDi_coqjEE3WYWMmc3nXJec)

電話番号が取得できました。
発信のテスト画面が表示されますが、ここではスキップして問題ありません。
![soracombutton-connect/電話番号取得3](http://drive.google.com/uc?export=view&id=1Wj9EwIdOrmnM_NsCa2ILK9-DL-oVOFOf)

<h3 id="content4">4. Amazon Connectコールフローの作成</h3>
電話をかけた後、任意のメッセージを再生できるよう、問い合わせフローの作成を行います。
左側のメニューから「ルーティング」⇒「問い合わせフロー」を選択します。
![soracombutton-connect/フロー作成1](http://drive.google.com/uc?export=view&id=1-AYzopB2Cw3qL0EjpGXmUAOBBIQBzp3N)

問い合わせフローの一覧画面が表示されます。
「問い合わせフローの作成」をクリックします。
![soracombutton-connect/フロー作成2](http://drive.google.com/uc?export=view&id=1I-OL13BJeS6DMC9cPC1-WFEB1B1nd6n5)

問い合わせフローの編集画面が表示されます。
今回は以下のようなフローを作成します。
![soracombutton-connect/フロー作成3](http://drive.google.com/uc?export=view&id=1SP5B84Pkc7qcCxsZiZgrla_hZdT1KxOi)

**説明**  
* 音声の設定 ： 発話者を設定します（日本語の再生に必須です）日本語のデータは現在、男声(takumi)/女声(mizuki)の2種類です。
* プロンプトの再生 ： 任意の文字列や音声データ(wav)を再生できます。
* 切断/ハングアップ ： 電話を切ります。

まず、左側の一覧から「設定」⇒「音声の設定」を右側にドラッグし、開始エントリと線でつなぎます。
「音声の設定」をクリックし、日本語を選択、音声をMizuki/Takumiのどちらからか選びます。
![soracombutton-connect/フロー作成4](http://drive.google.com/uc?export=view&id=1stnq5Rea2bJG3vW77tOnr8irrYSM7vkZ)

続けて「操作」⇒「プロンプトの再生」をドラッグし、「音声の設定」と線でつなぎます。
「プロンプトの再生」を開き、テキスト読み上げ機能（アドホック）⇒「動的に入力する」を選択し、以下のように入力します。
![soracombutton-connect/フロー作成5](http://drive.google.com/uc?export=view&id=1oh7a4-IgY75DfznG92AkeyMnl6Z5n57s)

さらに「終了」⇒「切断/ハングアップ」をドラッグし、「プロンプトの再生」と線でつなぎます。
最後にフロー名を入力し、「公開」ボタンをクリックします。
![soracombutton-connect/フロー作成6](http://drive.google.com/uc?export=view&id=1ph12AwXn5eq19o6IcuRgOMH3APOj3dgK)

公開して良いかどうか表示されます。「公開」をクリックします。
![soracombutton-connect/フロー作成7](http://drive.google.com/uc?export=view&id=1vcL668t7K17K_7ixupSkQPRzvUXAWo3f)

公開済みになったことを確認します。
左側にある「追加のフロー情報の表示」をクリックし、表示されるARN情報(contact-flow以下の文字列)をコピーしておきます。
![soracombutton-connect/フロー作成7](http://drive.google.com/uc?export=view&id=1Ns1Jsl8DD_iGfWiqxCCasYTvPfKcFp8V)

<h3 id="content5">5. AWS Lambda関数の設置</h3>

SORACOM LTE-M Buttonが押された際にAmazon Connectを呼び出すプログラム(Lambda関数)を設置します。  
Lambda関数を実行させる際、電話の発信元(Amazon Connectの電話番号)や電話の発信先(自身の携帯電話)の番号が必要ですが、それらの値は環境変数に与えます。
また、LambdaからAmazon Connectのインスタンスを呼び出せるよう、実行権限を付与します。

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home)を開きログインした後、リージョンをオレゴンに変更し、Lambdaのコンソールを開きます。  
![soracombutton-connect/ 6-1 Lambda1](https://kizawa.info/wp-content/uploads/2019/03/lambda-1.png)

関数の作成をクリックします。  
![soracombutton-connect/ 6-2 Lambda2](https://kizawa.info/wp-content/uploads/2019/03/lambda-0.png)

関数の作成画面が開きます。以下の情報を入力します。
* 作成方法：一から作成  
* 関数名：任意の名前(callbuttonなど)
* ランタイム：Python3.7
* 実行ロール：基本的なLambdaアクセス権限で新しいロールを作成
![soracombutton-connect/ 6-3 Lambda2](https://kizawa.info/wp-content/uploads/2019/03/lambda-3.png)

続いて関数の編集画面が開きます。以下の設定を行います  
* 関数コードのセクション
    * コードエントリタイプ：コードをインラインで編集
    * lambda_function：import jsonから始まる現在の設定をすべて消し、[Lambda関数](https://github.com/kizawa2020/iot-showcase/raw/master/events/scsk-connect-handson/lambda.py)の内容にすべて置き換えてください。(コピーして貼り付けで可)

引き続き同画面で、環境変数値を入力します。電話の発信元や電話の発信先の番号などの入力になります。
* 環境変数のセクション
![soracombutton-connect/ 6-4 Lambda3](https://drive.google.com/uc?id=1yrVQJwLy_6pbUK6uVlUhnF0cZPnpcrU0)
    * 画像を参考にキーと値にそれぞれ以下の内容を入力
    * FlowID : (ConnectのフローID。Amazon Connectダッシュボードにおいて「追加のフロー情報の表示」をクリック。ARNの値、contact-flow/の右側の値をペースト)
    * InstanceID : (ConnectのインスタンスID。AWSコンソールからAmazon Connect、インスタンスエイリアスを選択。インスタンスARNの値、instance/の右側の値をペースト)
    * YourMobilePhoneNumber : (自分の電話番号。発信先電話番号。国番号(日本は+81)から。空白、ハイフンなし。最初の桁を外す。090-1234-5678なら、+819012345678)
    * YourConnectPhoneNumber : (Amazon Connectの電話番号。発信元電話番号。Amazon Connectダッシュボードにおいて「電話番号の表示」をクリック。国番号(日本は+81)から。空白、ハイフンなし。最初の桁を外す。)

引き続きLambdaにAmazon Connect実行権限を付与します。
同画面で以下操作をしてください。
![soracombutton-connect/ 6-5 Lambda4](https://drive.google.com/uc?id=1a-hWSYeCJtGGqSZjlgDD1UpdcuXFAq03)

IAMのページが別タブで開くので、ポリシーをアタッチしますをクリック。
![soracombutton-connect/ 6-6 Lambda5(IAM)](https://drive.google.com/uc?id=1pdnFv_lEYt1YgZbNzCiVKFzHHwa6nM6q)

検索欄に「connect」と入力し、「AmazonConnectFullAccess」を選択し、ポリシーのアタッチをクリック。
![soracombutton-connect/ 6-7 Lambda6(IAM)](https://drive.google.com/uc?id=1yx0ZOe5g3hqyL6ZHC5Gz9ceMeSB1y0kY)

ロールにConnectのポリシー（権限）を付与しました。
![soracombutton-connect/ 6-8 Lambda7(IAM)](https://drive.google.com/uc?id=1zzgcmX4xLhaupgyP3CSPK-_KJGUQpifi)

Lambdaの画面に戻ります。
Lambdaの画面から動作を確認しましょう。関数への実行時パラメータとなるテストイベントを作成します。
画面右上、テストイベントの設定をクリック
![soracombutton-connect/ 6-9 Lambda8(IAM)](https://drive.google.com/uc?id=13VH-l1ubuzmT81vTf1iD48pHO7wpMCvz)

開いた画面で以下入力します。
* イベント名：任意。TestClickButtonで良い。
* 入力欄：以下の内容をコピーして上書き。編集不要です。※このclickTypeの値によって処理が変化します。

```
{
  "deviceInfo": {
    "deviceId": "XXXXXXXXXXXXXX",
    "type": "button",
    "etc1": "無関係イベントの値は省略しています。"
  },
  "deviceEvent": {
    "buttonClicked": {
      "clickType": "SINGLE",
      "reportedTime": "2018-11-09T16:29:40.474Z"
    }
  },
  "placementInfo": {
    "etc1": "無関係イベントの値は省略しています。"
  }
}

```

入力したら作成をクリック。
![soracombutton-connect/ 6-10 Lambda9(IAM)](https://drive.google.com/uc?id=1WToI3Vf2UfIczmIkVItgJ6_S7ApvxbCK)


画面右上の保存をクリックすると準備は完了です。

これでLambdaが動作すると電話がかかる、という形になります。

「テスト」をクリックすると、テストイベントを元に関数が実行されます。
設定がうまく行けば電話がかかってきます。
うまく行かない場合はエラーログが出力されています。

テストイベントを編集し、SINGLEとなっているclickTypeをDOUBLEなどに変えてテストを再度実行すると、電話口のメッセージが変わります。
余裕があれば試してみてください。

最後に画面上方にある「保存」ボタンをクリックして下さい。  
以上で完了です。

<h3 id="content6">6. AWS IoT 1-Clickのプロジェクト設定</h3>

**AWS IoT 1-Clickプロジェクト設定**  
AWS IoT 1-Click コンソールから [管理] > [プロジェクト] を開いた後 [プロジェクトの作成] をクリックします。  
![soracombutton-connect/ 7-1 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vSQtO8MYnq7k9drY2LWfYrhuWNmjZ16USKNslZr0L6mGvOET8KPYkePkvI3Sq8s3-HCelF3tfeFB5Vz/pub?w=897&h=473)

プロジェクト名として任意の名前を入力します。  
![soracombutton-connect/ 7-2 projectName](https://kizawa.info/wp-content/uploads/2018/11/aws1click-6.png)

**プレイスメントのテンプレート**  
プロジェクトのプレイスメントのテンプレートの定義画面に移ります。  
デバイステンプレートの定義の箇所をクリックします。  
![soracombutton-connect/ 7-3 devicetemplate1](https://kizawa.info/wp-content/uploads/2019/03/1click-1.png)

「すべてのボタンタイプ」の箇所をクリックします。  
![soracombutton-connect/ 7-4 devicetemplate2](https://kizawa.info/wp-content/uploads/2019/03/1click-2.png)

続けて先程作成したLambda関数と紐付けます。以下の情報を入力します。　　
* デバイステンプレート名：任意の名前
* アクション：Lambda関数の選択
* AWSリージョン：（先程Lambda関数を作成したリージョン）
* Lambda関数：先程作成したLambda関数名
![soracombutton-connect/ 7-5 devicetemplate3](https://kizawa.info/wp-content/uploads/2019/03/1click-3.png)

**プレイスメントの属性**  
引き続き画面下の方にあるプレイスメントの属性に以下の情報を入力します。

| 属性の名前 | デフォルト値 |
|:--------------|:------------|
| twilio_sid    | (TwilioのACCOUNT SID)     |
| twilio_token  | (TwilioのAUTH TOKEN)      |
| twilio_flowid | (Twilio Studio FlowのSID) |
| twilio_number | (Twilioで取得した電話番号 +8150xxxxxxxx の形式) |
| twilio_callto | (電話の発信先：Twilioに登録したご自身の携帯電話番号 +81xxxxxxxxxx の形式) |

ここまで入力が完了したら「プロジェクトの作成」をクリックします。  
![soracombutton-connect/ 7-6 placement](https://kizawa.info/wp-content/uploads/2019/03/1click-4.png)  

プロジェクトが作成されました。  
![soracombutton-connect/ 7-4 projectCreate](https://kizawa.info/wp-content/uploads/2018/11/aws1click-8.png)  
[プレイスメントの作成] をクリックします。

**プレイスメント設定**  
続けてプレイスメントの設定を行います。  
プレイスメントの設定で、登録したボタンのDSNコードと紐付けます。  
![soracombutton-connect/ 7-5 placement](https://kizawa.info/wp-content/uploads/2019/03/1click-5.png)
プロジェクトの新しいプレイスメントでは以下のように設定した後 [プレイスメントの作成] をクリックします。

* デバイスのプレイスメント名: `button1` (任意の文字列)
* [デバイスの選択] をクリック
    * ボタンの一覧が表示されます。結び付けたいボタンをクリックします。
* プレイスメントの属性は特に編集することはありません
    * 先に作成した「テンプレート」で設定した内容が引き継がれています
    * 逆にここでテンプレートから引き継がれた内容を上書きすることも可能です

以上で設定は完了です。

<h3 id="content7">7. 動作確認</h3>

ここまでの作業で AWS IoT 1-Click を通じて Twilio経由で電話がかけられるようになりました。  
ボタンを押すと、ご自身の携帯電話に電話が掛かってくるようになったでしょうか。  
（※うまく動作しない方はスタッフまでお問い合わせ下さい）

<h3 id="content8">8. お片付け</h3>

**※ ボタン貸出枠で参加の方は、ボタン返却のため以下の手順の実施をしてください。**

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
