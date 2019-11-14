# SORACOM Funnel を使用した IoT データの AWS への連携

本章では SORACOM Funnel を使用して Raspberry Piからのデータを AWS に連携します。

## ハンズオンのゴール

Raspberry Piからデータを送信し、Funnel によってデータが Amazon Kinesis Data Firehose に連携、 Amazon S3 に保存されることを確認します。

## 1. SORACOM へ認証情報を保管する

## 1-1. AWS IAM を準備する

Funnelから呼び出すために、Kinesis Data Firehoseにデータを投入する権限を持つIAMユーザーを作成します。

AWS Management Consoleを表示し、画面上部の[サービス]をクリック、検索のテキストボックスに「IAM」と入力して表示される[IAM]を選択し、IAMの管理画面を表示します。

画面左のメニューから[ユーザー]を選択、[ユーザーを追加]ボタンをクリックして以下の通りIAMユーザーを作成します。

- [ユーザー詳細の設定]画面
    - ユーザー名 : `soracom-funnel-test-<お名前>`
    - アクセスの種類 : [プログラムによるアクセス]のチェックをオン
- [アクセス許可の設定]画面
    - 「既存のポリシーを直接アタッチ」を選択
    - 検索テキストボックスに`Firehose`と入力して表示される「AmazonKinesisFirehoseFullAccess」ポリシーのチェックボックスをオン
- 残りの項目は既定のまま[ユーザーの作成]ボタンをクリックしてIAMユーザーを作成

作成完了画面の「アクセスキー ID」と「シークレットアクセスキー」([表示]リンクをクリックして表示))を控えておきます。

![figure9.png](images/figure9.png)

## 1-2. SORACOMに認証情報を登録

[SORACOM Webコンソール](https://console.soracom.io/) で [右上のユーザー名] > [セキュリティ]をクリックします

![soracom-menu-security](https://docs.google.com/drawings/d/e/2PACX-1vRjYW4eP-Cv1GTPmgGD01OEGiszvYmy1gmbsAQx50O6knq0UEPBozSQ8W3ezngFS6Z7B-8ArZkIXSWW/pub?w=344&h=334)

[認証情報ストア] > [認証情報を登録] で 認証情報入力画面を開きます

![soracom-cred-store](https://docs.google.com/drawings/d/e/2PACX-1vRoPNOwuGigBjl6MNfqQpXZL1MFmgPeUuwFLNF3TTRDZMQJf1G-HdwukH5otE7tdHy0YM9MWXmLac6z/pub?w=624&h=309)

認証情報を登録する画面では下記の通り入力し、保存してください

* 認証情報 ID: `handson-funnel-<お名前>`
* 概要: `Amazon Kinesis Firehose Access`
* 種別: *AWS 認証情報* (これを選択すると、下記IDを入力するテキストボックスが増えます)
* AWS Access Key ID: 手順1-1の「アクセスキー ID」
* AWS Secret Access Key ID: 手順1-1の「シークレットアクセスキー」

![soracom-cred-save](https://docs.google.com/drawings/d/e/2PACX-1vR6S9T-9TZbcdB8XwcUrBE7MQCyIsT-zOA2LQGspbv5r72CxT_qc1pyIdgmIXqVU79qOEKfOzuA8vXZ/pub?w=644&h=642)

## 2. Amazon Kinesis Data Firehoseの構成

ここでは、Funnelが連携するKinesis Data Firehoseを設定します。

AWS Management Consoleを表示し、画面上部の[サービス]をクリック、検索のテキストボックスに「kinesis」と入力して表示される[Kinesis]を選択し、Amazon Kinesisの管理画面を表示します。

以下の手順でFirehoseからS3にデータを保管する設定を追加します。

- 画面左側のメニューから[Data Firehose]をクリック、[Create delivery stream]ボタンをクリック
- [Delivery stream name]に `soracom-funnel-<お名前>`と入力、他の項目は既定のまま[Next]ボタンをクリック
- [Process records]画面は既定のまま[Next]ボタンをクリック
- [Select a destination]画面では[Destination]に「S3」が選択されていることを確認、[S3 bucket]の項目右側にある[Create new]ボタンをクリック
- S3 bucket nameに`soracom-funnel-<お名前>`と入力、Regionは既定のまま[Create S3 bucket]ボタンをクリック
- 元の画面に戻り、[Next]ボタンをクリック
- [Configure settings]画面では[S3 buffer conditions] - [Buffer interval]を `60` に変更
- 同じ画面の[Permissions] - [IAM role]にある「Create new or choose」ボタンをクリック
- [IAM ロール]は「新しいIAMロールの作成」を選択し、[ロール名]に`firehose_delivery_role-<お名前>`と入力、[許可]ボタンをクリック(「成功」と表示され元の画面に戻ります)
- [Next]をクリックし、確認画面で[Create delivery stream]ボタンをクリック

作成したDelivery streamの[Status]列が「Active」になったら完了です。[Destination]列のリンクをクリックし、S3管理画面を表示させておきます。

## 3. SORACOM Funnel 設定

SIMグループで SORACOM Funnel を有効にします。まだSIMグループを作成していない場合は以下の手順で作成してください。作成済みの場合は手順3-2に進んでください。

### 3-1. SIMグループの作成とSIMの割り当て

[SORACOM Webコンソール](https://console.soracom.io/) で 左上[Menu] > [SIM グループ]をクリックします

![soracom-menu](https://docs.google.com/drawings/d/e/2PACX-1vRhgmsjqpncv2HQ0jAZwiYf0knTfvmCMl6x_flrdeGQV4N60trp8M981gCAfitVSmXU4tqAYm6MmyRb/pub?w=331&h=410)
![soracom-menu-sim-group](https://docs.google.com/drawings/d/e/2PACX-1vTqI-f2K8n-TuUvVEGPnmDcFxG2f87so3Qfe5K11sn0pXG8Q4v2lJX0UT9tjlH7sDQRb1FC7aFfckjb/pub?w=353&h=290)

[追加] で、SIMグループを作成します。グループ名は`handson-<お名前>`と入力します。

![soracom-menu-sim-group-create](https://docs.google.com/drawings/d/e/2PACX-1vQ-wJ7Ixk-BQDtxXweBkhl-deBJzh3behOo_rQNNxm3gO73sKHEV_RvqO7cWrSKJT0AZltPaF_K0qPf/pub?w=381&h=315)

![soracom-menu-sim-group-create-dialog](https://docs.google.com/drawings/d/e/2PACX-1vRjDUj0AzCWEBNyy9GTqWf6jPANTk4WIEZcarMaYd9GhbM-_2AhBru9WglGRplqo0jUroC9rIq82G8h/pub?w=631&h=306)

続いて、SIMグループにSIMを追加します。左上[Menu] > [SIM 管理]をクリックします

![soracom-menu](https://docs.google.com/drawings/d/e/2PACX-1vRhgmsjqpncv2HQ0jAZwiYf0knTfvmCMl6x_flrdeGQV4N60trp8M981gCAfitVSmXU4tqAYm6MmyRb/pub?w=331&h=410)
![soracom-sim-mgr](https://docs.google.com/drawings/d/e/2PACX-1vTUi6LN6Hsctv4KdaZj8uOUFg_ZyROx73f1TzFq41KIlRzjUmE_bc2NR5UnS8cn15TD_S2s8FA-DHzA/pub?w=353&h=290)

SIM を選択 > [操作] > [所属グループ変更]をクリックします

![soracom-select-sim](https://docs.google.com/drawings/d/e/2PACX-1vQpULGXvkk5htY266aDd2iWJueVphdm8DFRVy_BF5JnWnZfBBLF19U42ni5lU6VxN5ucmwqKHx4ACjg/pub?w=526&h=489)

先ほど作成した SIMグループ に SIM を所属させます

![sim-group-select](https://docs.google.com/drawings/d/e/2PACX-1vR1DJQnKw0NVvv83qxiTiDkh0AYfF6u8g3En7EDQtt2M2OjCRzl_tmlB-02cyiLBHLwWHjpOshFKTAA/pub?w=643&h=334)

SIM の "グループ" が、先ほど作った SIM グループ名になっていれば成功です

### 3-2. Funnelの有効化

[SORACOM Webコンソール](https://console.soracom.io/) で 左上[Menu] > [SIM グループ]

自身のSIM グループを選択、SORACOM Funnel のアコーディオンメニューを開き設定を ON 、下記の通り入力し、保存してください

* 転送先サービス: Amazon Kinesis Firehose
* 転送先URL: `https://firehose.ap-northeast-1.amazonaws.com/<手順2で作成したDelivery stream名>` (東京リージョンの場合)
* 認証情報: 手順1-2で作成した`handson-funnel-<お名前>`
* 送信データ形式: *JSON*

![soracom-funnel](https://docs.google.com/drawings/d/e/2PACX-1vQ1u87_1m7Mlk-t9G33ho7s8f_4-F8pIGjksjJxBFRhgYYVwJiBWAOVRr0_XWv5ehjU_4hqDvH7kXI_/pub?w=926&h=435)

これでFunnelの設定は完了です。

## 4. 動作確認

Raspberry PiにSSH接続している端末上で以下のコマンドを何度か実行します

```console
cat /proc/uptime | cut -d ' ' -f 1 | echo '{"uptime": '$(cat)'}' | curl -X POST http://uni.soracom.io -d @-
```

手順2で表示したS3管理画面のリロードアイコンをクリックし、データが格納されるのを待ちます。

実行した年(例:`2019`)のフォルダが表示されたら、クリックし、その下の階層のフォルダを何度かクリックすると `soracom-funnel-<お名前>-<数字>-<タイムスタンプ>`というファイルが確認できます。

ファイルを選択し[S3 Select]タブをクリック、ファイル形式の「JSON」を選択し[プレビュー] - [ファイルプレビュー表示]で以下のような内容が確認出来ます。

```json
[
    {
        "operatorId": "OP00XXXXXXXX",
        "timestamp": 1573713415392,
        "destination": {
            "resourceUrl": "https://firehose.ap-northeast-1.amazonaws.com/soracom-funnel-<お名前>",
            "service": "firehose",
            "provider": "aws"
        },
        "credentialsId": "handson-funnel-<お名前>",
        "payloads": {
            "uptime": 58805.86
        },
        "sourceProtocol": "http",
        "imsi": "XXXXXXXXXXXXXXX"
    }
]
```

これでSORACOM FunnelによってデバイスからのデータをAmazon Kinesis Data Firehoseに転送、S3にデータが保存される様子を確認できました。

## 以上で本章は終了です

* [目次ページへ戻る](index.md)
