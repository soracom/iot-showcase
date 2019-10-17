# ボタンで EC2 インスタンスを操る

<!--
Google Drive Images: 
-->

## 全体の構成

Key = `Button-de`, Value = `Go!` というタグが割り当てられている EC2 インスタンスを対象に、ボタンの動作で start_instances もしくは stop_instances してみます。

### 注意

**本ハンズオンは他のインスタンスに影響がないことは検証済みではありますが、インスタンスの操作を伴う作業となるため適切なアカウントもしくはリージョンを選択するようにしてください。本作業によって発生した問題は免責させていただくことをご留意ください**

## 必要なもの

- AWS アカウント (持っていない場合の作成方法は [AWS アカウントの作成](create-aws-account){:target="_blank"} をご覧ください)
- SORACOM アカウント

## EC2 インスタンスを準備する

[インスタンスの作成]

### ステップ 1: Amazon マシンイメージ (AMI)

*Amazon Linux 2 AMI (HVM), SSD Volume Type* >> **64 ビット (x86)** >> [選択]

### ステップ 2: インスタンスタイプの選択

**t2.micro (無料枠の対象)** >> [次のステップ: インスタンスの詳細の設定]

### ステップ 3: インスタンスの詳細の設定

インスタンス数: `3` >> [次のステップ: ストレージの追加]

### ステップ 4: ストレージの追加

（項目は変更無しです） >> [次のステップ: タグの追加]

### ステップ 5: タグの追加

[タグの追加]

- キー: `Button-de`
- 値: `Go!`

[確認と作成]

### ステップ 7: インスタンス作成の確認

[起動]

「既存のキーペアを選択するか...」 ダイアログでは **キーペア無しで続行** にした後、「この AMI に組み込まれたパスワードがわからないと...」にチェックを付けて [インスタンスの作成]

[インスタンスの表示]

### 確認

- インスタンスの状態
- *インスタンスを1つ選択* >> [タグ]
    - キー = Button-de / 値 = Go! となっていることを確認

## AWS Lambda を準備する

リージョンは EC2 インスタンスが存在するところと同じにする

### 関数の作成

- FuncName: `ec2-instance-controller-by-button`
- Runtime: **Python 3.7**

### 基本設定

タイムアウト: 15 秒

### ポリシーの追加アタッチ

- `AmazonEC2FullAccess`

### コード

```python
# FuncName: `ec2-instance-controller-by-button`
# Runtime: **Python 3.7**
BUTTON_OP_MAP = {
    'DOUBLE': 'stop',
    'LONG':   'start'
}

import boto3
ec2 = boto3.client('ec2')
def get_instance_ids(Key='Button-de', Value='Go!'):
    targetIds = []
    instances = ec2.describe_instances()
    for reservation in instances['Reservations']:
        for instance in reservation['Instances']:
            if 'Tags' in instance:
                for tag in instance['Tags']:
                    if tag['Key'] == Key and tag['Value'] == Value:
                        targetIds.append(instance['InstanceId'])
    return targetIds

def lambda_handler(event, context):
    print(event)
    targetIds = get_instance_ids()
    print("targetIds are {}".format(targetIds))

    try:
        invoke_method_name = "{}_instances".format(BUTTON_OP_MAP[event['clickTypeName']])
    except KeyError:
        print("Ignored (No Mapping)")
        return {'statusCode': 204}
    
    if targetIds:
        print("Invoke {}".format(invoke_method_name))
        getattr(ec2, invoke_method_name)(InstanceIds=targetIds) # It's black magic..
    return {'statusCode': 204}
```

### テスト

イベント名: `SORACOMFunk`

```json
{
  "clickType": 1,
  "clickTypeName": "SINGLE",
  "batteryLevel": 1,
  "binaryParserEnabled": true
}
```

`clickTypeName` を `SINGLE`, `DOUBLE`, `LONG` とそれぞれ変えてみて「何もおこらない」「インスタンス停止」「インスタンス開始」と動作することを確認する。

- ※ `clickType` や他の値は今回は利用しません。
- ※ 対象インスタンスの状態が running もしくは stopped の時に操作可能です。それ以外の時には ClientError が発生します。

#### テストの出力サンプル:

##### `clickTypeName: "SINGLE"` の時

```
{'clickType': 1, 'clickTypeName': 'SINGLE', 'batteryLevel': 1, 'binaryParserEnabled': True}
targetIds are ['i-00143e861c65de56b', 'i-0e31228ddd9abf022', 'i-085caececdf653209']
Ignored (No Mapping)
```

##### `clickTypeName: "DOUBLE"` の時

```
{'clickType': 1, 'clickTypeName': 'DOUBLE', 'batteryLevel': 1, 'binaryParserEnabled': True}
targetIds are ['i-00143e861c65de56b', 'i-0e31228ddd9abf022', 'i-085caececdf653209']
Invoke stop_instances
```

※ この時、他のインスタンスに影響が無かったか確認するようにしてください。

##### `clickTypeName: "LONG"` の時

```
{'clickType': 1, 'clickTypeName': 'LONG', 'batteryLevel': 1, 'binaryParserEnabled': True}
targetIds are ['i-00143e861c65de56b', 'i-0e31228ddd9abf022', 'i-085caececdf653209']
Invoke start_instances
```

※ この時、他のインスタンスに影響が無かったか確認するようにしてください。

## SORACOM Funk を設定する

### AWS IAM を準備する

- AWS IAM ユーザ作成
    - プログラムによるアクセス
    - 既存のポリシーからアタッチ: `AWSLambdaRole`

アクセスキー ID とシークレットアクセスキー を記録

### SORACOM Funk を設定する

ええ感じに。TBD

### 実際にやってみる

LONG で起動
DOUBLE で停止

