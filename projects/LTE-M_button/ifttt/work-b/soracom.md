# B-2 SORACOM Beam から IFTTT を呼び出す

本ページでは、ボタンを押した時に先ほど作成した IFTTT Applet を呼び出すために、SORACOM Beam の設定を行います。
B-1 の最後にメモしておいた `key` を使いますので、もしメモしていなかった場合は [Webhooks settings](https://ifttt.com/services/maker_webhooks/settings){:target="_blank"} のページで確認してください。

## SORACOM Beam とは

IoT デバイスにかかる暗号化等の高負荷処理や接続先の設定を、クラウドにオフロードできるサービスです。  
SORACOM LTE-M Button for Enterprise はデバイス実装のシンプル・低価格化を実現するため、ボタンデバイスのデータ送信先は Unified Endpoint に固定されており、SORACOM の各種サービスを切り替えて使う事が可能となっています。実際の連携先クラウドの情報はグループ設定内で設定することで、クラウドの進化に対してデバイスの設定を変えることなく追従することができます。また、セキュア通信についても LTE-M の通信レベルでの暗号化と SORACOM Beam による暗号化変換による組み合わせでトータルで実現しています。

詳細は [SORACOM Beam サービス紹介ページ](https://soracom.jp/services/beam/) をご覧ください。

## グループの設定
作業A で作成したグループを使用します。

SIM 管理画面でボタンの SIM のグループ名をクリックし、グループ詳細画面を開きます。
> または、SORACOM ユーザコンソール 左上の「≡ Menu」から `SORACOM Air for Cellular` ＞ `SIM グループ` を開き、ボタンに割り当てているグループ詳細画面を開きます。

### SORACOM Beam 設定
「SORACOM Beam 設定」を開き、「＋」をクリックして、「UDP → HTTP/HTTPS エントリポイント」を選びます。

![Beam設定エントリーポイント選択](images/soracom-01.png)

転送先を下記のように設定します。

- プロトコル： HTTPS
- ホスト名： `handson.soracom.io`
- ポート番号： 空 (もしくは 443)
- パス： `/button/ifttt`

![Beam転送先設定](images/soracom-02.png)

> TODO 画像入れ替え

ヘッダ操作

- IMSI ヘッダ または IMEI ヘッダ を オン (通知したい方を選択、両方をオンにした場合は IMEI が優先)
- 署名ヘッダ付与: オン
- 事前共有鍵: 運営より入手

![Beamヘッダ操作設定](images/soracom-03.png)

> TODO 画像入れ替え

カスタムヘッダには、下記のの２つを設定します

- x-ifttt-key: B-1 でメモしておいた `key` を指定
- x-api-key: 運営より入手

最後に、一番下の「保存」を押します。

### Unified Endpoint 設定
レスポンスのフォーマットで「Beam」を選び、「保存」を押します。

![Unified Endpoint 設定](images/soracom-04.png)

## ボタンを押して IFTTT を呼び出す

ボタンを押して LED が緑色に光れば、呼び出し成功です。

## LINE の通知を確認する
LINE にクリックイベントが通知されるので、確認します。

> TODO: スクショを追加

# 以上で本ページの作業は完了となります

## トラブルシュート

* ボタン押下の結果、LED が赤になってしまう
    * A: 15秒以上経ってから LED が赤になる場合は、電波状況が悪い場合があるため再度試してみてください
    * B: 10秒程度で LED が赤になる場合は Beam の見直しが必要な場合があります

## クリックの種類ごとにメッセージを変えるには？

- Beam 転送先設定でパスを `/button/ifttt` → `/button/ifttt/click-type` に変更
- IFTTT で　`Event Name` を変えて `SIGNLE` / `DOUBLE` / `LONG` それぞれに Applet を作成する
  - 例) シングルクリック →「今ここにいます」 / ダブルクリック →「迎えに来て」 / 長押し → 「助けて」