# B-2 SORACOM Funk から 関数(Function) を呼び出し Slack へ通知を行う

本ページでは、ボタンを押した時に先ほど作成した 関数(Function) を呼び出すために、SORACOM Funk の設定を行います。
B-1 の最後にメモしておいた URL を使いますので、もしメモしていなかった場合は GCP コンソール で確認してください。

## SORACOM Funk とは

SORACOM Funk(以下、Funk) は、クラウドサービスの Function を直接実行できるサービスです。クラウドリソースを活用することでデバイス側の実装をシンプルに保ち、処理をオフロードや低電力消費化が可能となります。
本章では、SORACOM Funk の連携先として 先ほど作成した Function を設定してみましょう。

詳細は [SORACOM Funk サービス紹介ページ](https://soracom.jp/services/funk/){:target="_blank"} をご覧ください。

## グループの設定
作業A で作成したグループを使用します。

[SORACOM ユーザーコンソール](https://console.soracom.io/){:target="_blank"} を開き、SIM 管理画面でボタンの SIM のグループ名をクリックし、グループ詳細画面を開きます。
> または、SORACOM ユーザコンソール 左上の「≡ Menu」から `SORACOM Air for Cellular` ＞ `SIM グループ` を開き、ボタンに割り当てているグループ詳細画面を開きます。

### SORACOM Funk 設定
「SORACOM Funk 設定」を開き、下記のように設定します。

- サービス: Google Cloud Functions
- 送信データ形式: JSON
- 関数のURL: B-1 でメモした URL

![Funk](images/soracom-funk.png)

## ボタンを押して 関数(Function) を呼び出す

ボタンを押して LED が緑色に光れば、呼び出し成功です。

## Slack の画面を確認する
Slack にクリックイベントが表示されるので、確認します。

![Slack](images/slack.png)

## 以上で本ページの作業は完了となります

## トラブルシュート

* ボタン押下の結果、LED が赤になってしまう
    * A: 15秒以上経ってから LED が赤になる場合は、電波状況が悪い場合があるため再度試してみてください
    * B: 10秒程度で LED が赤になる場合は Function 設定の見直しが必要な場合があります
        * URL は正しく指定出来ているか
        * Function のコードが正しくコピー出来ているか
        * package.json で追加パッケージが指定されているか
        * 実行関数を `main` に書き換えたか
        * Function のページで「ログを表示」をクリックし、メッセージを確認

## 参考情報
SORACOM Funk から Google Cloud Functions を HTTP トリガーで呼ぶ際に、x-soraocm-token というヘッダに呼び出し元のアカウントや SIM に関する情報が JWT (JSON Web Token)形式で渡されます。

デバッグログを見て以下のような文字列が出てきますので、これを [jwt.io](https://jwt.io/){:target="_blank"} でデコードしてみましょう。
PAYLOAD の所を見ると、ctx というキーの下に SIM やデバイスの固有番号、オペレータID(ソラコムのユーザID)などがあります。
例えば特定のオペレータIDしか許可しない、といったような形で使う事ができますし、クリック時の基地局のIDを利用した簡易的な位置情報なども取得できます。

#### PAYLAOD のサンプル
```
{
  "iss": "https://soracom.io",
  "aud": "srn:soracom:OP0059150966:jp:Subscriber:440525060013710",
  "jti": "m7m5s0emq88",
  "iat": 1568272434,
  "typ": "soracom/token/v1",
  "sub": "funk.soracom.io",
  "ctx": {
    "operatorId": "OP0059150966",
    "coverage": "jp",
    "resourceType": "Subscriber",
    "resourceId": "440525060013710",
    "sourceProtocol": "udp",
    "srn": "srn:soracom:OP0059150966:jp:Subscriber:440525060013710",
    "imsi": "440525060013710",
    "imei": "359565091023647",
    "locationQueryResult": "success",
    "location": {
      "lat": 35.660842139821305,
      "lon": 139.729163646698
    }
  }
}
```