
# B-1 IFTTT で 通知 を行う Applet を作成する
本ページでは、IFTTT で 通知を行うためのサービス連携設定(Applet)を作成します。

## Applet を作成する
[New Applet](https://ifttt.com/create){:target="_blank"} から、新規 Applet を作成

- this 
  - Webhook 
    - Receive a web request
      - Event Name : button
- that
  - LINE
    - Send message
      - Receipient : 「 1:1 で LINE Notify から通知を受け取る」(または特定のグループなど)
      - Message :

```
ボタン \{\{Value1\}\} が \{\{Value2\}\} クリックされました<br>\{Value3\}}
```

- Rewview and finish
  - Finish を必ず押す

- [Webhooks settings](https://ifttt.com/services/maker_webhooks/settings){:target="_blank"} のページを開く
  - URL 欄 https://maker.ifttt.com/use/`key` の `key` 部分をメモしておく

## 以上で本ページの作業は完了となります