# AWS IoT 1-Click で自動生成された Lambda 関数や IAM ロール/ポリシー

これらは不要であれば全て削除可能です。

* AWS Lambda 関数
    * `iot1click_onclick_*`
* AWS IAM
    * ロール
        * `iot1click_onclick_*`
        * `[Lambda 関数名]-role-ランダム文字`
    * ポリシー
        * `AWSLambdaIoTButtonSESExecutionRole-*` (Email の場合)
        * `AWSLambdaIoTButtonSNSExecutionRole-*` (SMS の場合)
        * `AWSLambdaIoTButtonBasicExecutionRole-*`

これ以外にも Amazon SES で追加した verified email address の削除も必要であれば行ってください。

---

* [目次に戻る](../index#closing)
