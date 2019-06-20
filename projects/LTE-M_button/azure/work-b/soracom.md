# B-2 SORACOM Beam から Function App を呼び出す

本ページでは、ボタンを押した時に先ほど作成した Function を呼び出すために、SORACOM Beam の設定を行います。
B-1 の最後にメモしておいた URL を使いますので、もしメモしていなかった場合は Azure Portal で確認してください。

## SORACOM Beam とは
TODO

## グループの設定
作業A で作成したグループを使用します。

SIM 管理画面でボタンの SIM のグループ名をクリックし、グループ詳細画面を開きます。
> または、SORACOM ユーザコンソール 左上の「≡ Menu」から `SORACOM Air for Cellular` ＞ `SIM グループ` を開き、ボタンに割り当てているグループ詳細画面を開きます。

### SORACOM Beam 設定
「SORACOM Beam 設定」を開き、「＋」をクリックして、「UDP → HTTP/HTTPS エントリポイント」を選びます。

![Beam設定エントリーポイント選択](images/soracom-01.png)

転送先を下記のように設定します。

プロトコル： HTTPS 
ホスト名： URL の `oooo.azurewebsites.net` 部分 (`soracom-handson-xxxx.azurewebsites.net`) 
ポート番号： 空 (もしくは 443) 
パス： `/api/button2slack` から後ろの部分すべて 

![Beam転送先設定](images/soracom-02.png)

ヘッダ操作は、IMSI ヘッダのみを ON とします。

![Beamヘッダ操作設定](images/soracom-03.png)

最後に、一番下の「保存」を押します。

### Unified Endpoint 設定
レスポンスのフォーマットで「Beam」を選び、「保存」を押します。

![Unified Endpoint 設定](images/soracom-04.png)

## ボタンを押して Function App を呼び出す

ボタンを押して LED が緑色に光れば、呼び出し成功です。
Azure Portal の Function App のログを確認しましょう。

![Function App ログ](images/function-app-11.png)

## Slack の画面を確認する
Slack にクリックイベントが表示されるので、確認します。

![Slack](images/slack.png)

## 以上で本ページの作業は完了となります