# kintone devCamp 2019 ― IoT ハンズオン

[目次へ戻る](index#index)

## SORACOM Funk で kintone と連携する

ボタンからのデータを SORACOM のデータ転送支援サービス [SORACOM Funk](https://soracom.jp/services/funk/) を用いて kintone と連携します。

### SORACOM Funk とは？

SORACOM Funk は 7/2 に発表された新サービスです。

これまでデバイスから AWS Lambda を始めとした FaaS (Function as a Service) との連携は、API Gateway のようなコンポーネントを必要としていました。  
SORACOM Funk は中間コンポーネントを省略し、直接 FaaS を起動できるようにするサービスです。

### ハンズオンのゴール

![kintone-devCamp2019 / overview soracom-funk](https://docs.google.com/drawings/d/e/2PACX-1vTUP6mkN7GYhoBN9iCLwFhpiG3RdtAcYnRpL6YriLSlWep7KelI5_TiCGH2cJGX4PHqNT_MQce8ngdn/pub?w=1099&h=364)

<h2 id="w1">作業 1: SIM グループを作成する</h2>

**解説:** これまで利用してきた SIM グループとは異なる SIM グループを設定します。

[SORACOM ユーザーコンソール](https://console.soracom.io/) の [SIM 管理] を開きます。続いて、SORACOM LTE-M Button の SIM にチェックマークを付けます。その後、[操作] ボタンから [所属グループ変更] を選択します。

![](https://dev.soracom.io/jp/img/gs_harvest/gp_group.png)

所属グループを選択するためのダイアログが表示されたら、[新しい所属グループ] ドロップダウンから [新しいグループを作成…] を選択します。

![](https://dev.soracom.io/jp/img/gs_harvest/gp_changegroup.png)

以下のようなグループ作成ダイアログが表示されます。グループの名称を入力して [グループ作成] ボタンをクリックします。 今回は `funk` というグループ名で作成します。

![kintone-devCamp2019 / soracom-funk group1](https://docs.google.com/drawings/d/e/2PACX-1vSM7ukS4Aj4ni33--7fKhGoqTyXEWlMOsSPMNNsgtZ0GwBaYwVq2L51jc-uWkpr9WrRP5nwG3QR9i16/pub?w=609&h=301)

[グループ作成] ボタンを押すと元の [SIM の所属グループ変更] ダイアログに戻ります。  
[新しい所属グループ] ドロップボックスが、今作成した `button` グループになっていることを確認し [グループ変更] ボタンを押します。

![kintone-devCamp2019 / soracom-funk group2](https://docs.google.com/drawings/d/e/2PACX-1vTqHTahhrZ-XwHH2FfY4KvHt5UFZ2w0T6IWioSYVZSyHy5Jmn4ZR1s7E2CABM_VjmPzMPPbS9OwtUV2/pub?w=607&h=319)

以下のように SIM(Button) のグループ列に `funk` と表示されていれば本作業は完了です。

![kintone-devCamp2019 / soracom-funk group3](https://docs.google.com/drawings/d/e/2PACX-1vSnQSdZNdW43VQqRlBpxpMGZZwVyzXZ0T0mDinYzhPE1yHjcf8WWYFt1CYMbSe2fB873_8ZSizKGU8T/pub?w=776&h=184)

<h2 id="w2">作業 2: SIM グループの設定を行う</h2>

**解説:** 作成した SIM グループに対して SORACOM Funk の設定を行います。

SIM 管理画面の SIM(Button) のグループ列に表示されている `funk` をクリックします。

![kintone-devCamp2019 / soracom-funk group3](https://docs.google.com/drawings/d/e/2PACX-1vSnQSdZNdW43VQqRlBpxpMGZZwVyzXZ0T0mDinYzhPE1yHjcf8WWYFt1CYMbSe2fB873_8ZSizKGU8T/pub?w=776&h=184)

SIM グループ設定画面内の [SORACOM Air for Cellular 設定] グループの下方にある [バイナリパーサ設定] のスイッチを "ON" に設定し、 [フォーマット] に `@button` と入力した後、 [保存] をクリックします。

![](https://dev.soracom.io/jp/img/gs_button/group_configuration_4.png)

同じ SIM グループ設定画面内の [SORACOM Funk 設定] グループの中にあるスイッチを "ON" に設定した後、以下のように入力します。

| 項目 | 値 |
|------|----|
| サービス | AWS Lambda |
| 送信データ形式 | JSON |
| 認証情報 | 《認証情報を新規作成する...》 → 最終的には `aws-lambda-iam` となる |
| 関数の ARN | 《運営から入手: `aws-lambda-arn`》 |

認証情報の登録は以下のように入力します。

| 項目 | 値 |
|------|----|
| 認証情報 ID | `aws-lambda-iam` |
| 概要 | 《空白》 |
| AWS Access Key ID | 《運営から入手: `aws-access-key-id`》 |
| AWS Secret Access Key | 《運営から入手: `aws-secret-access-key`》 |

![kintone-devCamp2019 / soracom-funk setting](https://docs.google.com/drawings/d/e/2PACX-1vTPUSIwWm6-ZJwgFSxu1JZjsVUxBZDkyPBRqyYZvOkIq2qDI3A_pPdAZ9BLaNyI2sJ0V7hnlaq_aNeE/pub?w=668&h=558)

以上で本作業は完了です。

<h2 id="w3">作業 3: 動作確認</h2>

**解説:** SORACOM Funk から先のシステムは準備済みであるため、SORACOM Funk の設定のみで完了です。

kintone アプリを表示します。

* URL: 《運営から入手: `kintone-app-url`》
* ID: 《運営から入手: `kintone-app-userid`》
* Password: 《運営から入手: `kintone-app-password`》

ボタンを押します。kintone アプリで以下のように押した情報が表示されれば成功です。

この kintone アプリはボタンのクリックに応じて、今日のハンズオンの感想を入れられるようになっています。是非とも入力してみてください。

* シングル = 良かった
* ダブル = ふつう
* ロング = いまいち

![kintone-devCamp2019 / kintone app1](https://docs.google.com/drawings/d/e/2PACX-1vSeD4CJEWw5wXsRA9LijBfIHHH7GbnC0QCx8g0k7MwlUzYIqFRhTgFA4gGPzr1ChRG0tgSkVddcL5J2/pub?w=762&h=219)

<h2 id="clear-up">あとかたづけ</h2>

あとかたづけは特にありません。

<h2 id="troubleshoot">トラブルシューティング</h2>

* LED が赤色になってしまう;
    * SORACOM Funk 設定を見直してください。

---

[目次へ戻る](index#index)

[EoT]
