# A-1-1. すでに AWS アカウント持っている場合の確認事項

すでに AWS アカウントを持っていて、そのアカウントを利用する場合は以下を確認願います。

## ルートアカウントを利用する場合

特に確認すべき事項はありません。先に進んでください。

[目次に戻る](index#work-a)

## IAM アカウントを利用する場合

AWS IoT 1-Click と、そこから利用されるサービスへの権限が割り当てられているかを IAM アカウント管理者に確認してください。

* 本資料では必要権限の解説およびサポートは致しかねますが、主に AWS IoT 1-Click, AWS Lambda, Amazon SES といったサービスへの権限、ならびに AWS IAM におけるロールの作成といった権限になります
    * [AWS IoT 1-Click に対する認証とアクセスコントロール](https://docs.aws.amazon.com/ja_jp/iot-1-click/latest/developerguide/1click-authentication.html){:target="_blank"} などを参照ください
* `AdministratorAccess` ポリシーが割り当てられていればハンズオンは完遂可能です (同ポリシーを割り当てたことによる影響については IAM アカウント管理者にご相談ください)

確認が終わったら先に進んでください。

[目次に戻る](index#work-a)
