# AWS IoT Core を使って会場にあるデバイスを制御

AWS IoT Core を利用して、会場に設置されたデバイスを制御します。

AWS IoT Core とその先の環境は運営側で準備しているため、この章では AWS IoT 1-Click から AWS IoT Core への送信までを行うのがゴールになります。

![mkmk-button / AWS IoT Core 全体像](https://docs.google.com/drawings/d/e/2PACX-1vSs0tF-8s21WZHxe7bWXMOkl5V06Y8hEdLnoQZQyDAMhnw5NCgCNYNJK_R-erEGY3sigR5RNlKS-2nj/pub?w=813&h=457)

## 作業1: AWS Lambda を作成する

AWS IoT 1-Click から呼び出され、AWS IoT Core に送信する Lambda 関数を作成します。

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home) を開きログインしたあと、リージョンが **オレゴン** (us-west-2) になっている事を確認します。  
なっていなければ **オレゴン** に切り替えてください。

![mkmk-button / 2-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vSgprF60wQZHq5nvPUcueml_-wNwuVn3EWx9FqRV73-7mxS0bapShs6fPVD2LMV-Lrr6GLlb-aEhjIr/pub?w=928&h=189)

AWS Lambda のコンソールを開き、 [関数の作成] をクリックします。

**一から作成** を選んだあと、以下のように入力して [関数の作成] をクリックします。

* 名前: `1click-updateAWSIoTCoreShadow` (任意の文字列)
* ランタイム: _Node.js 8.10_
* （アクセス権限は編集する必要はありませんが、選択する場合は `基本的な Lambda アクセス権限でロールを作成` を選んでください）

![mkmk-button / AWS Lambda 作成](https://docs.google.com/drawings/d/e/2PACX-1vSaizKKpVN_v5vhtVed2QzXGAXlVCuSDd7M-nkZKoPWGAiJu-mF6Vi6o1Mo40fWHEZp1f3Fo3qGLlT-/pub?w=929&h=594)

関数コードでは、以下のようにします。

コードを以下の URL のコードと入れ替えて [保存] をクリックします。  
[https://gist.github.com/ma2shita/7cfc919010bf9050a6edea2b741a31ee](https://gist.github.com/ma2shita/7cfc919010bf9050a6edea2b741a31ee)

![mkmk-button / AWS Lambda コード](https://docs.google.com/drawings/d/e/2PACX-1vSovMN3Ab8Ewgx3qFLk2afThD6j_20H8XDM6QlXwg-iSRF-YNBQaOxZMcXYBo2mZOQOhEnytgB6ACaX/pub?w=841&h=670)

環境変数では、以下のようにします。

* `ENDPOINT`: **ハンズオン運営から入手** (endpoint)
* `ACCESS_KEY_ID`: **ハンズオン運営から入手** (aws-accesskey-id)
* `SECRET_ACCESS_KEY`: **ハンズオン運営から入手** (aws-secret-accesskey-id)

![mkmk-button / AWS Lambda 環境変数](https://docs.google.com/drawings/d/e/2PACX-1vTt-iOLSHOljgkwY6lI7WqH4rqM7SHRLMfT-wDyqdyv3EFUOrsDc0Y1U2FT8VE9ThxRQmubYnj6Bbtm/pub?w=919&h=457)

メールの時同様に、テストを作成します。  
テストイベントは以下の JSON を使います。その際、以下の値を変更してください。

* thingName: **ハンズオン運営から入手** (awsiot-thing-name)

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
      "thingName": "運営から入手した `awsiot-thing-name` に置き換える"
    },
    "devices": {
      "myButton": " G030PMXXXXXXXXXX "
    }
  }
}
```

AWS Lambda 上でテストをして会場にあるデバイスが動けば成功です。  
**テスト前にはスタッフにお声がけください**

## 作業4: AWS IoT 1-Click の設定を行う

### デバイスの確認

今から行う作業の対象デバイスがすでに別のプレイスメントに割り当てられていると作業が継続できないため、あらかじめ [プレイスメントからデバイスの割り当てを外す](../unassing-placement) を参考に行ってください。

### プロジェクト/プレイスメントの作成

[管理] > [プロジェクト] とクリックした後、[作成] をクリックします。

以下、プロジェクト内での設定です。

* ステップ 1/2
    * プロジェクト名: `DeviceControl` (任意の文字列)
* ステップ 2/2
    * デバイステンプレートの定義: 全てのボタンタイプ
    * デバイステンプレート名: `AWSIoTCore` (任意の文字列)
    * アクション: Lambda 関数の選択
        * AWS リージョン: オレゴン
        * Lambda 関数: `1click-updateAWSIoTCoreShadow` (先ほど作成した Lambda 関数)
    * プレイスメントの属性
        * `thingName` = **ハンズオン運営から入手** (awsiot-thing-name)

![mkmk-button / AWS IoT 1-Click プロジェクト](https://docs.google.com/drawings/d/e/2PACX-1vS_Q8YXX3Dt80EYyGtlcpjLIPST0L7IUoEzL9Fo4xfpVg1rCb1FvPlojWaYnN_sh_spXSGWIgnAh0de/pub?w=601&h=689)

[プレイスメントの作成] をクリックした後、プレイスメント内での設定を以下のようにします。

* デバイスのプレイスメント名: `button1` (任意の文字列)
* デバイスの選択: 割り当てたいデバイスを選択
    * プレイスメントに未割り当てのボタンのみが表示されます

以上で終了です。

### 作業5: ボタンからの動作を確認してみる

SORACOM LTE-M Button を押して会場にあるデバイスが動くか確認してください。  
**実施前にスタッフにお声がけください**

ボタンのアクションとデバイスの制御は以下のように対応しています。

* SINGLE = デバイス ON
* DOUBLE or LONG = デバイス OFF

#### あとかたづけ

作業は任意です。

* AWS 関連
    * Lambda 関数の削除
    * IAM ロール (自動生成のロールは `Lambda 関数名-role-ランダム文字` となります。テキストに沿って作った場合は `1click-updateAWSIoTCoreShadow-role-ランダム文字` となっています)
    * AWS IoT 1-Click のプロジェクトの削除

---

* [目次に戻る](../index#work-b)
