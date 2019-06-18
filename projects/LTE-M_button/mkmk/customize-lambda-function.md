<h1>メールの内容を変えてみる</h1>

[目次に戻る](index#work-a)

[メールを使い動作を確認](claim-and-email-with-amazon-ses)では、Lambda 関数を作らずともメールの送信ができましたが、実際は AWS IoT 1-Click によって Lambda 関数が自動生成されており、ボタン押下のアクションではその自動生成された Lambda 関数が実行されていました。

本章では自動生成された Lambda 関数を編集することでメールの内容を変更してみます。  
変更の内容ですが、メールの本文の末尾に「`これは Lambda 関数で追加した行です`」という行を追加するという内容です。

![button-mkmk / Email 内容変更 全体像](https://docs.google.com/drawings/d/e/2PACX-1vReoXGGBp8iHUrHs6C7TLVDodef7xf_JBYKd34HSCfgHAI-9ZREBxb2slxLY6jGBKR1lC7T_GvnB8R_/pub?w=780&h=438)

## 作業1: 自動生成された Lambda 関数を確認してみる

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home) を開きログインしたあと、リージョンが **オレゴン** (us-west-2) になっている事を確認します。  
なっていなければ **オレゴン** に切り替えてください。

![mkmk-button / 2-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vSgprF60wQZHq5nvPUcueml_-wNwuVn3EWx9FqRV73-7mxS0bapShs6fPVD2LMV-Lrr6GLlb-aEhjIr/pub?w=928&h=189)

AWS Lambda のコンソールを開きます。

[サービス] をクリックした後、検索窓に `lambda` と入れるか、 "コンピューティング" カテゴリの中の Lambda をクリックしてください。

![1-1 lambda](https://docs.google.com/drawings/d/e/2PACX-1vTcwsmo-GqNPJI4Qw7wN5AuHdDEpZkcID27p5GYtQSRP-E1DM3ENEiAU9m5hHInfsxEp3lDdWVOcSMT/pub?w=569&h=260)

Lambda 関数の一覧が表示されます。この中で `iot1click_onclick_email_・・・` という関数が AWS IoT 1-Click によって自動生成された Lambda 関数です。

![1-2 lambda list](https://docs.google.com/drawings/d/e/2PACX-1vSjLoxIuYGaHHMBCQYtygx_Sk9d85YjzL5c4AMrVqYtbASyzKzHlxvyzxDrZH0l7ILSohoKzKa-iq-l/pub?w=927&h=344)

※もしも Lambda 関数一覧が表示されなかった場合は以下のように、右上のメニューから [関数] を選んでください。

![1-2 lambda menu](https://docs.google.com/drawings/d/e/2PACX-1vTDMmoIxiJdKQq4C1ld7nBDa5zuaaMmnBh-6WCU8gxS-w8UIUa85gwlGm384prnlfjhvYw_FPThIs1-/pub?w=758&h=342)

## 作業2: Lambda 関数を編集する

先ほど見つけた `iot1click_onclick_email_・・・` をクリックします。

![2-1 lambda](https://docs.google.com/drawings/d/e/2PACX-1vRYmfrgRRGOyen8HjZQt1hywHNd8NcPengOwb2Nn0NVmfJC1apbI3idt5tScf8YFIhRxKX_VcIv-F8n/pub?w=927&h=344)

スクロールすると **関数コード** というセクションがあります。ここに書かれた Python コードが自動生成された Lambda 関数の中身です。ここを編集していきます。

![2-2 content](https://docs.google.com/drawings/d/e/2PACX-1vQBR-ygv_46B1jXzf-qrffsVjuuH6Dj7CNV6JeQ5USwUr1JfztZdHsKDCE3l7Xu2g6FVGsP2BC921ms/pub?w=848&h=685)

43 行目に以下のコードを追加してください。

```python
    body += '\nこれは Lambda 関数で追加した行です'
```

![2-3 lambda edit](https://docs.google.com/drawings/d/e/2PACX-1vT1gR43OibwvTrF6a2oGIA6uUmfQUlyRnkyK8Bi3qFcfiRGH2-Xv7DgmYFME-IjOzYcyfI8k-YBtYQc/pub?w=778&h=388)

右上の [保存] をクリックします。

![2-3 lambda save](https://docs.google.com/drawings/d/e/2PACX-1vQS6wli8JFrkd8cXEn5XTd526lFK5TYcAeSocjUeVWfORWpqP63c5XM4T9r-XPO2kJ5LD4gsqCl0DYF/pub?w=638&h=259)

## 作業3: Lambda 関数のテストを行う

編集した内容が正常に動くかテストをしてみます。

Lambda 関数の編集画面 右上の [テストイベントの選択...] > [テストイベントの設定] をクリックします。

![2-4 lambda test event](https://docs.google.com/drawings/d/e/2PACX-1vQsW2isyThiYxS0VusJPUobmIJoGIM600c7hseEGYL1YS9wpRoS_dvAOEsHqZgsOsEegmj1_BKhGs0X/pub?w=641&h=182)

フォームに以下のように入力した後、[作成] をクリックします。

* _新しいテストイベントの作成_  (ここはデフォルトのままでＯＫです)
* イベントテンプレート: _Hello World_ (ここはデフォルトのままでＯＫです)
* イベント名: `1click` (任意の文字列)

テキストエリアに以下の JSON を入力します。その際 `email` の部分を送信先のアドレスに変更してください。

```json
{
  "deviceEvent": {
    "buttonClicked": {
      "clickType": "SINGLE",
      "reportedTime": "2018-05-04T23:26:33.747Z"
    }
  },
  "deviceInfo": {
    "attributes": {
    },
    "type": "button",
    "deviceId": " G030PMXXXXXXXXXX ",
    "remainingLife": 5
  },
  "placementInfo": {
    "projectName": "TestEmail",
    "placementName": "button1",
    "attributes": {
      "email": "you@example.jp",
      "subject": "テスト送信",
      "body": "SORACOM LTE-M Button のテスト送信"
    },
    "devices": {
      "myButton": " G030PMXXXXXXXXXX "
    }
  }
}
```

![2-5 lambda test event](https://docs.google.com/drawings/d/e/2PACX-1vSinELxr9AW0KBLxmz151VKMwFR0xwO3AANvDZZ34LT1hSLRkYJAIDfNs_x1k0k2xWpgJ2uwlR64cns/pub?w=960&h=720)

Lambda 関数の編集画面 右上が **1click** になっている事を確認したら [テスト] をクリックします。

![2-6 lambda test](https://docs.google.com/drawings/d/e/2PACX-1vQ3a80etJXpApHrp2SKC-ibVRsKkXGMQztywfEGOskxq8w7yBTA2UIF5_rpd7kU-QD8aBGi0GMqQPQg/pub?w=605&h=163)

テストの結果が Lambda 編集画面に表示されます。  
*Status* に実行結果が表示されるほか `logging.info` からの出力が表示されているのが確認できます。

![2-7 lambda result success](https://docs.google.com/drawings/d/e/2PACX-1vQAO7i9wX0vdkjxR7b3amm8fChHuNKIPoU0WANb0AQJPDa3wBBvAylaLrIJ7jwwB9KwkrIwPye74_xn/pub?w=934&h=541)

また、成功であればメールが届きます。

![2-7 email](https://docs.google.com/drawings/d/e/2PACX-1vTWgm6aQH-93sTpfQlRVL-8A8Nqq6rHNAv769KG7vyfKgVq1JUuc8GLrBrmqWkUz580x2SmV_pnAvZI/pub?w=322&h=241)

コードに不備があった場合は、以下のように `status: failed` となり、理由などが表示されているので、それを参照しながら修正を行ってください。

![2-7 lambda result failed](https://docs.google.com/drawings/d/e/2PACX-1vSIUlbW_P-v9hKrmfPcKlRErSMbZKXftuiUep4bJA4QWKdY1Ag1rbpbENzmWt1P4wGeNynYmHlQnw0J/pub?w=934&h=541)

## 作業4: ボタンからの動作を確認してみる

AWS Lambda は **保存** した時点でコードの内容が実行できるようになっています。そのためこの時点で AWS IoT 1-Click からの呼び出しにも新しいコードの内容で応答することになります。

実際にボタンを押してメールが届くか確認してみてください。

## 内容が変更されたメールが届いたらこの章は終了です

### まとめ

* AWS Lambda の編集方法
* AWS Lambda のテスト方法
    * ボタンの実機が無くてもテストイベントを設定することで開発が可能です

### 次へ進む

* [目次に戻る](index#work-b)

## トラブルシューティング

### テストのメールが届かない

* 原因: テストイベント作成時の JSON で `email` を送信先に変更し忘れている可能性があります。
* 対策: `email` の値は実際の送信先になるように変更してください。
