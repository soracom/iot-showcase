# AWS IoT Core を使って会場にあるデバイスを制御

AWS IoT Core を利用して、会場に設置されたデバイスを制御します。

AWS IoT Core とその先の環境は運営側で準備しているため、この章では AWS IoT 1-Click から AWS IoT Core への送信までを行うのがゴールになります。

![button-mkmk / AWS IoT Core 全体像]()

## 作業1: AWS Lambda を作成する

AWS IoT 1-Click から呼び出され、AWS IoT Core に送信する Lambda 関数を作成します。

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home) を開きログインしたあと、リージョンが **オレゴン** (us-west-2) になっている事を確認します。  
なっていなければ **オレゴン** に切り替えてください。

![mkmk-button / 2-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vSgprF60wQZHq5nvPUcueml_-wNwuVn3EWx9FqRV73-7mxS0bapShs6fPVD2LMV-Lrr6GLlb-aEhjIr/pub?w=928&h=189)

AWS Lambda のコンソールを開き、 [関数の作成] をクリックします。

**一から作成** を選んだあと、以下のように入力して [関数の作成] をクリックします。

* 名前: `1click-updateAWSIoTCoreShadow` (任意の文字列)
* ランタイム: _Node.js 8.10_
* ロール: _1つ以上のテンプレートから新しいロールを作成します_
* ロール名: `1click-updateAWSIoTCoreShadow` (任意の文字列)
* ポリシーテンプレート: 空のままでＯＫです

関数コードでは、以下のようにします。

コードを以下の URL のコードと入れ替えて [保存] をクリックします。  
https://gist.github.com/ma2shita/7cfc919010bf9050a6edea2b741a31ee

環境変数を

* `ENDPOINT`: ()
* `ACCESS_KEY_ID`: ()TODO
* `SECRET_ACCESS_KEY`: ()TODO

テストイベントには以下の JSON を使います。その際、以下の値を変更してください。

* thingName: ()TODO

```json
{
  "deviceEvent": {
    "buttonClicked": {
      "clickType": "SINGLE",
      "reportedTime": "2018-05-04T23:26:33.747Z"
    }
  },
  "deviceInfo": {
    "attributes": {},
    "type": "button",
    "deviceId": " G030PMXXXXXXXXXX ",
    "remainingLife": 5
  },
  "placementInfo": {
    "projectName": "TestProject",
    "placementName": "button1",
    "attributes": {
      "thingName": "button"
    },
    "devices": {
      "myButton": " G030PMXXXXXXXXXX "
    }
  }
}
```

AWS Lambda 上でテストをして LINE Nofity からメッセージが届けば成功です。

## 作業4: AWS IoT 1-Click の設定を行う

### デバイスの確認

今から行う作業の対象デバイスがすでに別のプレイスメントに割り当てられていると作業が継続できないため、あらかじめ [プレイスメントからデバイスの割り当てを外す](../unassing-placement) を参考に行ってください。

### プロジェクト/プレイスメントの作成

[管理] > [プロジェクト] とクリックした後、[作成] をクリックします。

以下、プロジェクト内での設定です。

* ステップ 1/2
    * プロジェクト名: `IFTTT` (任意の文字列)
* ステップ 2/2
    * デバイステンプレートの定義: 全てのボタンタイプ
    * デバイステンプレート名: `IFTTT` (任意の文字列 (プロジェクト名と異なってもＯＫ))
    * アクション: Lambda 関数の選択
        * AWS リージョン: オレゴン
        * Lambda 関数: `1click-updateAWSIoTCoreShadow` (先ほど作成した Lambda 関数)
    * プレイスメントの属性
        * `event` = (IFTTT で設定した `Event Name`)
        * `key` = (IFTTT の Webhooks で入手したキー)
        * `value1` = (任意の文字列)
        * `value2` = (任意の文字列)
        * `value3` = (任意の文字列)

以下、プレイスメント内での設定です。

* デバイスのプレイスメント名: `button1` (任意の文字列)
* デバイスの選択: 割り当てたいデバイスを選択
    * プレイスメントに未割り当てのボタンのみが表示されます

以上で終了です。

### 作業5: ボタンからの動作を確認してみる

SORACOM LTE-M Button を押してメッセージが届くか確認してください。

#### いろいろ試してみる

* AWS IoT 1-Click のプレイスメントの属性における value1 などを編集してみてください
* IFTTT のアプレットにおける Message を変更してみたり、 Photo URL を入れてみてください。
    * 画像サンプル: https://blog.soracom.jp/images/2018-07-04-soracom-lte-m-button/soracom-lte-m-button-powered-by-aws.png

#### あとかたづけ

作業は任意です。

* IFTTT と LINE の接続を切断する
    * [IFTTT の Services から LINE](https://ifttt.com/line) を選択、Settings で *Disconnect LINE* で切断。
    * [LINE Notify のマイページ](https://notify-bot.line.me/my/) の連携中サービスで IFTTT との接続を解除
* AWS 関連
    * Lambda 関数の削除
    * IAM ロール / ポリシーの削除 (作った場合)
    * AWS IoT 1-Click のプロジェクトの削除

---

* [目次に戻る](../index#work-b)
