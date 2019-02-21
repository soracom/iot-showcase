# Let's IoT プロトタイピング！ オンライン講座 〜スタッフ呼び出しボタンを作ってみよう〜

### イベントページ

* [Day1](https://pages.soracom.jp/20190306_IoT_Prototype_seminar.html)
* [Day2](https://pages.soracom.jp/20190307_IoT_Prototype_seminar.html)

## セミナー中で使用するプログラムの配布

### Day 1

#### 1. Slack / Incoming Webhook の設定

1. Slack にログイン
2. チーム名(右上) > [その他管理項目] > [App 管理]
3. (App ディレクトリを検索) で `Incoming Webhook` を検索、クリック
4. **Incoming Webhook** のページで [設定を追加] をクリック
5. 設定ページで以下のように設定
    * チャンネルへの投稿: **#random** (任意のチャンネルを選んでください)
6. 同ページの [Incoming Webhook インテグレーションの追加] をクリック
7. Webhook URL をメモ (後ほど利用します)

#### 2. Slack へ投稿する Lambda 関数の作成

##### コード (post_to_slack)

```python
# Runtime: Python 3.7, Name: post_to_slack
import json
import os
import logging
logger = logging.getLogger()
logger.setLevel(logging.INFO)
import urllib.request, urllib.parse

INCOMING_WEBHOOK = os.environ['INCOMING_WEBHOOK']
THING_MAP = {
    'SINGLE': {'memberName': 'max'},
    'DOUBLE': {'memberName': 'moto'},
    'LONG':   {'memberName': 'yaman'}
}

def lambda_handler(event, context):
    logger.info('Received event: ' + json.dumps(event)) # Output to Cloudwatch Log
    memberName = THING_MAP[event['deviceEvent']['buttonClicked']['clickType']]['memberName']

    body = {'text': '<!here> {} が呼ばれたよ！'.format(memberName)}
    headers = {'Content-Type': 'application/json'}
    req = urllib.request.Request(INCOMING_WEBHOOK,
                                  data=json.dumps(body).encode('utf-8'),
                                  method='POST', headers=headers)
    with urllib.request.urlopen(req) as res:
        logger.info(res.read().decode("utf-8"))

    return {"statusCode": 204}
```

##### INCOMING_WEBHOOK 環境変数の設定 (post_to_slack)

環境変数 `INCOMING_WEBHOOK` に Slack の Incoming Webhook の URL を記載

##### テスト (post_to_slack)

```json
{
  "deviceInfo": {
    "deviceId": "_YOUR_DEVICE_DSN_",
    "type": "button",
    "remainingLife": 99.9,
    "attributes": {
      "projectRegion": "ap-northeast-1",
      "projectName": "Button",
      "placementName": "_YOUR_PLACEMENT_NAME_",
      "deviceTemplateName": "_YOUR_TEMPLATE_NAME_"
    }
  },
  "deviceEvent": {
    "buttonClicked": {
      "clickType": "SINGLE",
      "reportedTime": "2019-03-05T13:43:17.745Z"
    }
  },
  "placementInfo": {
    "projectName": "Button",
    "placementName": "_YOUR_PLACEMENT_NAME_",
    "attributes": {
    },
    "devices": {
      "_YOUR_TEMPLATE_NAME_": "_YOUR_DEVICE_DSN_"
    }
  }
}
```

テストを実行して Slack の `#random` チャンネルに `@here max が呼ばれたよ！` と表示されれば成功です。

### Day 2

#### 1. AWS IoT Core で "モノ" の作成と、エンドポイント URL を入手

`soracom_max` , `soracom_moto` , `soracom_yaman` という "モノ" を作成

* この "モノ" の名称は 、後述する Lambda 関数とで全て一致させてください

##### シャドウの初期設定

```json
{
  "reported": {
    "status":"idle",
    "welcome":null
  },
  "desired":{
    "status":null,
    "welcome":null
  }
}
```

* AWS IoT Core の "設定" からカスタムエンドポイントをメモ (後ほど利用)

#### 2-1. Amazon Cognito, AWS IAM の設定

Amazon Cognito;

* ID プールの作成
  * *認証されていない ID に対してアクセスを有効にする* を有効に
  * 新規にロールを作成
  * `ID プールの ID` をメモ (後ほど利用)

AWS IAM;

* `Cognito_**UnAuth_Role` へポリシーを割り当て
  * テスト環境下においては `AWSIoTDataAccess` を割り当て
  * 本番においては Appendix を参照のこと

#### 2-2. Web ページの準備

* [call_monitor.html](https://gist.github.com/ma2shita/4a43d39a8d61f6be8f1163050498e498) で以下を編集
  * `YOUR_AMAZON_COGNITO_POOL_ID` を Amazon Cognito で得た `ID プール ID` にする
  * `YOUR_AWS_IOTCORE_CUSTOM_ENDPOINT` を AWS IoT Core で得た `カスタムエンドポイント` にする

以上が終了したら Amazon S3 へアップロード、公開設定とする

**この時点で Web をロードすると "呼び出しOK!" と表示されているはずです。**

#### 3. Slack へ投稿しつつ、シャドウを更新する Lambda 関数の作成

##### コード (post_to_slack_and_update_shadow)

```python
# Runtime: Python 3.7, Name: post_to_slack_and_update_shadow
import json
import os
import logging
logger = logging.getLogger()
logger.setLevel(logging.INFO)
import urllib.request, urllib.parse
import boto3
iot = boto3.client('iot-data')

INCOMING_WEBHOOK = os.environ['INCOMING_WEBHOOK']
THING_MAP = {
    'SINGLE': {'memberName': 'max', 'thingName': 'soracom_max'},
    'DOUBLE': {'memberName': 'moto', 'thingName': 'soracom_moto'},
    'LONG':   {'memberName': 'yaman', 'thingName': 'soracom_yaman'}
}

def lambda_handler(event, context):
    logger.info('Received event: ' + json.dumps(event)) # Output to Cloudwatch Log
    memberName = THING_MAP[event['deviceEvent']['buttonClicked']['clickType']]['memberName']

    body = {'text': '<!here> {} が呼ばれたよ！現場に行けそうなら `ok ~~` と返すとステータスが更新されるよ。気付いてなさそうならフォローを！'.format(memberName)}
    headers = {'Content-Type': 'application/json'}
    req = urllib.request.Request(INCOMING_WEBHOOK,
                                  data=json.dumps(body).encode('utf-8'),
                                  method='POST', headers=headers)
    with urllib.request.urlopen(req) as res:
        logger.info(res.read().decode("utf-8"))

    thingName = THING_MAP[event['deviceEvent']['buttonClicked']['clickType']]['thingName']
    shadowDoc = {'state':{'reported':{'status':'calling'}}}
    iot.update_thing_shadow(thingName=thingName, payload=json.dumps(shadowDoc))

    return {"statusCode": 204}
```

##### INCOMING_WEBHOOK 環境変数の設定やテスト (post_to_slack_and_update_shadow)

`post_to_slack` 同様に設定

#### 4. 一定時間でシャドウを更新する Lambda 関数の作成

##### コード (transition_maker)

```python
# Runtime: Python 3.7, Name: transition_maker
import json
import logging
logger = logging.getLogger()
logger.setLevel(logging.INFO)
import time
import boto3
iot = boto3.client('iot-data')

def lambda_handler(event, context):
    logger.info('Received event: ' + json.dumps(event))    
    time.sleep(event['transition_wating_sec'])

    shadowDoc = {'state':{'reported':{'status': event['transition_to']}}}
    iot.update_thing_shadow(thingName=event['thing_name'], payload=json.dumps(shadowDoc))

    return {"statusCode": 204}
```

* 基本設定の **タイムアウト** を `transition_wating_sec` よりも長く設定すること (1 分など)

##### テスト (transition_maker)

```json
{
  "transition_wating_sec": 5,
  "thing_name": "soracom_max",
  "transition_to": "idle"
}
```

##### コード (post_to_slack_and_update_shadow_with_transition_to_idle)

```python
# Runtime: Python 3.7, Name: post_to_slack_and_update_shadow_with_transition_to_idle
import json
import os
import logging
logger = logging.getLogger()
logger.setLevel(logging.INFO)
import urllib.request, urllib.parse
import boto3
iot = boto3.client('iot-data')
f = boto3.client('lambda')

INCOMING_WEBHOOK = os.environ['INCOMING_WEBHOOK']
THING_MAP = {
    'SINGLE': {'memberName': 'max', 'thingName': 'soracom_max'},
    'DOUBLE': {'memberName': 'moto', 'thingName': 'soracom_moto'},
    'LONG':   {'memberName': 'yaman', 'thingName': 'soracom_yaman'}
}

def lambda_handler(event, context):
    logger.info('Received event: ' + json.dumps(event)) # Output to Cloudwatch Log
    memberName = THING_MAP[event['deviceEvent']['buttonClicked']['clickType']]['memberName']

    body = {'text': '<!here> {} が呼ばれたよ！現場に行けそうなら `ok ~~` と返すとステータスが更新されるよ。気付いてなさそうならフォローを！'.format(memberName)}
    headers = {'Content-Type': 'application/json'}
    req = urllib.request.Request(INCOMING_WEBHOOK,
                                  data=json.dumps(body).encode('utf-8'),
                                  method='POST', headers=headers)
    with urllib.request.urlopen(req) as res:
        logger.info(res.read().decode("utf-8"))

    thingName = THING_MAP[event['deviceEvent']['buttonClicked']['clickType']]['thingName']
    shadowDoc = {'state':{'reported':{'status':'calling'}}}
    iot.update_thing_shadow(thingName=thingName, payload=json.dumps(shadowDoc))

    f.invoke(
        FunctionName='transition_maker',
        InvocationType='Event',
        Payload=json.dumps({
            'thing_name': thingName,
            'transition_wating_sec': 10,
            'transition_to': 'idle'
        })
    )

    return {"statusCode": 204}
```

##### INCOMING_WEBHOOK 環境変数の設定やテスト (post_to_slack_and_update_shadow_with_transition_to_idle)

`post_to_slack` 同様に設定

##### AWS IoT 1-Click の設定変更

`post_to_slack_and_update_shadow_with_transition_to_idle` を実行するように変更

#### 5. API Gateway をトリガーにシャドウを更新する Lambda 関数の作成

##### コード (transition_to_running_then_to_idle)

```python
# Runtime: Python 3.7, Name: transition_to_running_then_to_idle
import json
import os
import logging
logger = logging.getLogger()
logger.setLevel(logging.INFO)
import urllib.parse
import boto3
iot = boto3.client('iot-data')
f = boto3.client('lambda')

SLACK_NAME_MAP = {
    'ma2shita': {'thingName': 'soracom_max'},
    'moto': {'thingName': 'soracom_moto'},
    'katayama': {'thingName': 'soracom_yaman'}
}

def lambda_handler(event, context):
    logger.info('Received event: ' + json.dumps(event)) # Output to Cloudwatch Log
    b = urllib.parse.parse_qs(event['body'])
    logger.info('Parsed body: ' + json.dumps(b)) # Output to Cloudwatch Log

    thingName = SLACK_NAME_MAP[b['user_name'][0]]['thingName']
    shadowDoc = {'state':{'reported':{'status':'running'}}}
    iot.update_thing_shadow(thingName=thingName, payload=json.dumps(shadowDoc))

    f.invoke(
        FunctionName='transition_maker',
        InvocationType='Event',
        Payload=json.dumps({
            'thing_name': thingName,
            'transition_wating_sec': 10,
            'transition_to': 'idle'
        })
    )

    return {"statusCode": 204}
```

##### テスト (transition_to_running_then_to_idle)

```json
{
    "body": "user_name=ma2shita"
}
```

#### 6. Amazon API Gateway の設定

* 新しい API
* リソース: `slack-outgoing-acceptor`
  * POST メソッドを作成
    * 統合タイプ: Lambda
    * Lambda プロキシ統合の使用: ON
    * Lambda 関数: `transition_to_running_then_to_idle`

##### テスト

リクエスト本文

```
user_name=ma2shita
```

※エディタ上で文法不正のようなチェックがつきますが、無視して構いません

テストが成功したら **API のデプロイ** をして、URL を入手しメモ (後ほど利用)

#### 7. Slack / Outgoing Webhook の設定

1. Slack にログイン
2. チーム名(右上) > [その他管理項目] > [App 管理]
3. (App ディレクトリを検索) で `Outgoing Webhook` を検索、(発信 Webフックを)クリック
4. **発信 Webフック** のページで [設定を追加] をクリック
5. 設定ページで以下のように設定
    * チャンネル: **#random** (任意のチャンネルを選んでください)
    * 引き金となる言葉: `ok ` (末尾にスペースを入れた方が誤判定が少なくなる)
    * URL: **API Gateway の URL**
    * （トークンをメモ (後ほど利用)）
6. 同ページの [設定を保存する] をクリック

この時点でチャンネル上で `ok 駆けつける` など ok から始まる文字を投稿すると API Gateway を経由して `transition_to_running_then_to_idle` が動くようになります。

## Appendix: AWS IoT Core シャドウへのアクセス制限 (AWS IAM の policy での制限の場合)

AWS IAM 上での Policy ドキュメント内の Resource に指定できるのは、実際の Publish や Subscribe で指定される文字列との一致を確認しています。(いるようです) そのため「意味的には同じ」となるはずの文字列でもマッチしません。

例えば `$aws/things/+/shadow/update` は `$aws/things/THING_NAME/shadow/update` に MQTT 的なトピック名としてはマッチはしますが、AWS IAM Policy ドキュメントでは一致しません。MQTT トピック的なマッチをさせたい場合は AWS IoT Core における Policy で設定することになります。

Amazon Cognito と AWS IoT Core の Policy を結びつけることは、Auth な ID に対しては可能ですが、UnAuth な ID については確認が取れなかったため、ここでは Amazon Cognio から AWS IAM ロール/ポリシーにて制限するようにしています。

この場合、対象の "モノ" が増えた場合の運用が柔軟ではないため、要自動化ポイントになるかと思います。


```json
{
    "Version": "2012-10-17",
    "Statement": [
        {
            "Sid": "iot1",
            "Effect": "Allow",
            "Action": "iot:Publish",
            "Resource": [
                "arn:aws:iot:*:*:topic/$aws/things/soracom_max/shadow/update",
                "arn:aws:iot:*:*:topic/$aws/things/soracom_max/shadow/get",
            ]
        },
        {
            "Sid": "iot2",
            "Effect": "Allow",
            "Action": "iot:Receive",
            "Resource": [
                "arn:aws:iot:*:*:topic/$aws/things/soracom_max/shadow/update/documents",
                "arn:aws:iot:*:*:topic/$aws/things/soracom_max/shadow/get/accepted",
                "arn:aws:iot:*:*:topic/$aws/things/soracom_max/shadow/get/rejected",
            ]
        },
        {
            "Sid": "iot3",
            "Effect": "Allow",
            "Action": "iot:Connect",
            "Resource": [
                "arn:aws:iot:*:*:client/webclient0"
            ]
        },
        {
            "Sid": "iot4",
            "Effect": "Allow",
            "Action": "iot:Subscribe",
            "Resource": [
                "arn:aws:iot:*:*:topicfilter/$aws/things/+/shadow/update/documents",
                "arn:aws:iot:*:*:topicfilter/$aws/things/+/shadow/get/+"
            ]
        }
    ]
}
```

### iot:Subscribe と iot:Receive の違い

一見すると同じ意味で、特に iot:Receive の役割がわかりづらいため解説します。

iot:Subscribe は **MQTT クライアントから subscribe 操作の受付** です。一方 iot:Receive は **接続済みの MQTT クライアントに対してのデータ配信** になります。そのため **Subscribe は成功したが、(Receive で制限されていたため)データが降ってこない** ということになります。

例として `/shadow/get` は `/shadow/get/accepted` と `/shadow/get/rejected` を持っています。そのため `/shadow/get/+` とすれば双方からデータが得られますが、例えば `Receive Deny /shadow/get/accepted` というポリシーが適用されたら `/shadow/get/+` に Subscribe はできるけど `/shadow/get/rejected` からのみデータが得られるという構成を作ることができます。

## Appendix: Slack の Outgoing Webhook トークンを検証する Lambda 関数の作成と API Gateway の設定

このままだと API Gateway に POST をするだけで誰でも更新できてしまうため、トークンを検証して Slack からの Outgoing リクエストであることを確認します。

##### コード (transition_to_running_then_to_idle_with_token_validator)

```python
# Runtime: Python 3.7, Name: transition_to_running_then_to_idle_with_token_validator
import json
import os
import logging
logger = logging.getLogger()
logger.setLevel(logging.INFO)
import urllib.parse
import boto3
iot = boto3.client('iot-data')
f = boto3.client('lambda')

SLACK_NAME_MAP = {
    'ma2shita': {'thingName': 'soracom_max'},
    'moto': {'thingName': 'soracom_moto'},
    'katayama': {'thingName': 'soracom_yaman'}
}

def lambda_handler(event, context):
    logger.info('Received event: ' + json.dumps(event)) # Output to Cloudwatch Log
    b = urllib.parse.parse_qs(event['body'])
    logger.info('Parsed body: ' + json.dumps(b)) # Output to Cloudwatch Log

    if b['token'][0] != os.environ['OUTGOING_TOKEN']:
        return {
            'statusCode': 403,
            'body': json.dumps('Invalid Token')
        }

    thingName = SLACK_NAME_MAP[b['user_name'][0]]['thingName']
    shadowDoc = {'state':{'reported':{'status':'running'}}}
    iot.update_thing_shadow(thingName=thingName, payload=json.dumps(shadowDoc))

    f.invoke(
        FunctionName='transition_maker',
        InvocationType='Event',
        Payload=json.dumps({
            'thing_name': thingName,
            'transition_wating_sec': 10,
            'transition_to': 'idle'
        })
    )

    return {"statusCode": 204}
```

##### 環境変数の設定 (transition_to_running_then_to_idle_with_token_validator)

環境変数 `OUTGOING_TOKEN` に Slack の発信 Webフックのトークンを記載

##### テスト (transition_to_running_then_to_idle_with_token_validator)

```json
{
  "body": "user_name=ma2shita&token=トークンに置き換える"
}
```

##### Amazon API Gateway の呼び出し Lambda 関数を変更してデプロイ

`slack-outgoing-acceptor` の POST メソッドから呼び出される Lambda 関数を `transition_to_running_then_to_idle_with_token_validator` に変更してデプロイ

##### テスト

リクエスト本文

```
user_name=ma2shita&token=トークンに置き換える
```

※改行に気を付けてください
