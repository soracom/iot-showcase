
# B-1 IFTTT で 通知 を行う設定を作成する
本ページでは、IFTTT で 通知を行うためのサービス連携設定を作成します。
すでに IFTTT のサインアップは終わってるものとしますが、まだの場合は [IFTTT Sign up](https://ifttt.com/join){:target="_blank"} からアカウントを作成してください。

## 設定を新規作成する
[Create your own - IFTTT](https://ifttt.com/create){:target="_blank"} を開いて `This` をクリックします。

![IFTTT 01](images/ifttt-01.png)

[Search services] の所に、`webhooks` とタイプし Webhooks のアイコンをクリックします

![IFTTT 02](images/ifttt-02.png)

`Connect` を押します

![IFTTT 03](images/ifttt-03.png)

`Receive a web request` をクリックします。

![IFTTT 04](images/ifttt-04.png)

Event Name 欄に `button` と入力し、 `Create trigger` をクリックします。

> 必ず 小文字で `button` と指定して下さい

![IFTTT 05](images/ifttt-05.png)

`That` をクリックします。

![IFTTT 06](images/ifttt-06.png)

[Search services] に `LINE` と入力し、 LINE のアイコンをクリックします。

> LINE をご利用されていない場合は、Twitter や Facebook 、Gmail など適宜別のサービスをご選択下さい

![IFTTT 07](images/ifttt-07.png)

`Connect` をクリックします。

![IFTTT 08](images/ifttt-08.png)

LINE アカウントに登録されているメールアドレス・パスワードでログインします。

![IFTTT 09](images/ifttt-09.png)

> もしメールアドレス認証を指定ない場合には、まず　LINE アプリからメールアドレス認証を行う必要があります

![IFTTT 10](images/ifttt-10.png)

Send message をクリックします。

![IFTTT 11](images/ifttt-11.png)

Message 欄を以下のように変更し Create action をクリックします。

> {% raw %}`ボタン {{Value1}} が {{Value2}} クリックされました<br>{{Value3}}`{% endraw %}

![IFTTT 12](images/ifttt-12.png)

Finish をクリックします。

> トリガー時にアプリ通知が必要ない場合には `Receive notifications when this Applet runs`　をオフにします

![IFTTT 13](images/ifttt-13.png)

[Webhooks](https://ifttt.com/services/maker_webhooks/settings){:target="_blank"} のページを開き、Documentation をクリックします。

![IFTTT 14](images/ifttt-14.png)

`Your key is:` の後ろの文字列をどこかにメモしておきます。

![IFTTT 15](images/ifttt-15.png)

## 以上で本ページの作業は完了となります