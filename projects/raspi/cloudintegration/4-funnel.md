# SORACOM Funnel を使用した IoT データの AWS への連携

本章では SORACOM Funnel を使用して Raspberry Piからのデータを AWS に連携します。

## ハンズオンのゴール

Raspberry Piからデータを送信し、Funnel によってデータが Amazon Kinesis Data Firehose に連携、 Amazon S3 に保存されることを確認します。

## 1. SORACOM へ認証情報を保管する

[SORACOM Webコンソール](https://console.soracom.io/) で [右上のユーザー名] > [セキュリティ]をクリックします

![soracom-menu-security](https://docs.google.com/drawings/d/e/2PACX-1vRjYW4eP-Cv1GTPmgGD01OEGiszvYmy1gmbsAQx50O6knq0UEPBozSQ8W3ezngFS6Z7B-8ArZkIXSWW/pub?w=344&h=334)

[認証情報ストア] > [認証情報を登録] で 認証情報入力画面を開きます

![soracom-cred-store](https://docs.google.com/drawings/d/e/2PACX-1vRoPNOwuGigBjl6MNfqQpXZL1MFmgPeUuwFLNF3TTRDZMQJf1G-HdwukH5otE7tdHy0YM9MWXmLac6z/pub?w=624&h=309)

認証情報を登録する画面では下記の通り入力し、保存してください

* 認証情報 ID: **進捗表から入手 (cred-name1)**
* 概要: `AWS IoT Core DataAccess`
* 種別: *AWS 認証情報* (これを選択すると、下記IDを入力するテキストボックスが増えます)
* AWS Access Key ID: **進捗表から入手 (aws-accesskey-id)**
* AWS Secret Access Key ID: **進捗表から入手 (aws-secret-accesskey-id)**

![soracom-cred-save](https://docs.google.com/drawings/d/e/2PACX-1vR6S9T-9TZbcdB8XwcUrBE7MQCyIsT-zOA2LQGspbv5r72CxT_qc1pyIdgmIXqVU79qOEKfOzuA8vXZ/pub?w=644&h=642)

※進捗表から入手する情報は、本来ご自身でご用意いただくことになります。実際の準備方法は [AWS IoT Core の準備](#setup-awsiotcore) をご覧ください

## 2. SORACOM Funnel 設定

SIMグループで SORACOM Funnel を有効にします。まだSIMグループを作成していない場合は以下の手順で作成してください。作成済みの場合は手順2-2に進んでください。

### 2-1. SIMグループの作成とSIMの割り当て

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

### 2-2. Funnelの有効化

[SORACOM Webコンソール](https://console.soracom.io/) で 左上[Menu] > [SIM グループ]

自身のSIM グループを選択します。

SORACOM Funnel のアコーディオンメニューを開き設定を ON 、下記の通り入力し、保存してください

* 転送先サービス: *AWS IoT*
* 転送先URL: **進捗表から入手 (endpoint-url)**
* 認証情報: (先ほど作成した認証情報 進捗表の **cred-name1** を選ぶ)
* 送信データ形式: *JSON*

![soracom-funnel](https://docs.google.com/drawings/d/e/2PACX-1vQ1u87_1m7Mlk-t9G33ho7s8f_4-F8pIGjksjJxBFRhgYYVwJiBWAOVRr0_XWv5ehjU_4hqDvH7kXI_/pub?w=926&h=435)



## 以上で本章は終了です

* [目次ページへ戻る](index.md)
