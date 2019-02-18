# Let's IoT プロトタイピング！ オンライン講座 〜スタッフ呼び出しボタンを作ってみよう〜

### イベントページ

* [Day1](https://pages.soracom.jp/20190306_IoT_Prototype_seminar.html)
* [Day2](https://pages.soracom.jp/20190307_IoT_Prototype_seminar.html)

## セミナー中で使用するプログラムの配布

### Day 1

#### 2-1. Slack / Incoming Webhook の設定

1. Slack にログイン
2. チーム名(右上) > [その他管理項目] > [App 管理]
3. (App ディレクトリを検索) で `Incoming Webhook` を検索、クリック
4. **Incoming Webhook** のページで [設定を追加] をクリック
5. 設定ページで以下のように設定
    * チャンネルへの投稿: **#random** (任意のチャンネルを選んでください)
6. 同ページの [Incoming Webhook インテグレーションの追加] をクリック
7. Webhook URL をメモ (後ほど利用します)

#### 2-2. Slack へ投稿する Lambda 関数 (post_to_slack) の作成

##### コード

```python
# Name: post_to_slack
import json
import os
import logging
logger = logging.getLogger()
logger.setLevel(logging.INFO)
import urllib.request, urllib.parse

INCOMING_WEBHOOK = os.environ['INCOMING_WEBHOOK']
THING_MAP = {
    'LONG':   {'thingName': 'yaman'},
    'SINGLE': {'thingName': 'max'},
    'DOUBLE': {'thingName': 'moto'},
}

def lambda_handler(event, context):
    logger.info('Received event: ' + json.dumps(event)) # Output to Cloudwatch Log
    t = THING_MAP[event['deviceEvent']['buttonClicked']['clickType']]['thingName']

    body = {'text': '<!here> {} が呼ばれたよ！'.format(t)}
    headers = {'Content-Type': 'application/json'}
    req = urllib.request.Request(INCOMING_WEBHOOK,
                                  data=json.dumps(body).encode('utf-8'),
                                  method='POST', headers=headers)
    with urllib.request.urlopen(req) as res:
        logger.info(res.read().decode("utf-8"))

    return {"statusCode": 200}
```

##### INCOMING_WEBHOOK 環境変数の設定

`post_to_slack` の環境変数 `INCOMING_WEBHOOK` に Slack から得た Incoming Webhook の URL を記載

##### post_to_slack 用のテストデータ

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

#### AWS IoT Core / モノを作成

`max` , `yaman` , `moto` という "モノ" を作成

※この名称は AWS IoT Core 上の "モノ" と、後述する Lambda 関数とで全て一致させてください

#### Slack へ投稿しつつ、シャドウを更新する Lambda 関数の作成 (post_to_slack_and_update_shadow)
#### API Gateway をトリガーにシャドウを更新する Lambda 関数の作成 (update_shadow_from_api_gateway)
#### Amazon API Gateway の設定
#### Slack / Outgoing Webhook の設定
#### 一定時間でシャドウを更新する Lambda 関数の作成
#### Web への表示
