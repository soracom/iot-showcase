# kintone の設定

kintoneのアプリ作成、認証情報取得について記載します。

## 手順

- [アプリの新規作成](#step1)
- [フォームの設定](#step2)
- [APIトークンの生成](#step3)
- [ドメイン/アプリIDの確認](#step4)

<h2 id="step1">アプリの新規作成</h2>

kintoneのトップページ右側の「+ボタン」よりアプリ作成画面を開きます。

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/kintone-capture1.png"/>

<br/><br/>

「はじめから作成」を選択します。
<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/kintone-capture2.png"/>

<h2 id="step2">フォームの設定</h2>

左側のフィールド一覧より「文字列（1行）」フィールドをドラッグ＆ドロップで移動させます。

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/kintone-capture3.png"/>

<br/><br/>

このままでも良いですが、あとで利用しやすいように配置したフィールドの右上歯車からフィールドの設定を開き、<br/>
「フィールドコード」を `text` 等のローマ字に変更します。

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/kintone-capture4.png"/>

<h2 id="step3">APIトークンの生成</h2>

kintoneには **ログイン認証 / APIトークン認証 / セッション認証** の3つの認証が利用できます。<br/>
今回はその中の **APIトークン認証** を利用します。<br/>

<br/>

設定タブからAPIトークンを選択します。

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/kintone-capture5.png"/>

<br/><br/>

「生成する」ボタンよりAPIトークンを生成し、 **アクセス権の「レコード追加」にチェックを付けます**。
<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/kintone-capture6.png"/>

<br/>

保存ボタンを選択して、「アプリを公開」を選択します。
<font color="red">(2回目以降も必ず設定を変更したら【アプリの更新】を選択してください)</font>

<br/><br/>

<h2 id="step4">ドメイン/アプリIDの確認</h2>

ブラウザでアプリ画面を開いている時の **URL** にドメインとアプリIDの情報があります。

- ドメイン

https:// **{◯◯.cybozu.com}** /k/~~~

- アプリID

https://◯◯.cybozu.com/k/ **{数字}**

<br/>

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/kintone-capture7.png"/>

<br/>

ここで取得した

- APIトークン
- ドメイン
- アプリID

を[こちら](aws-lambda-setting.md#step2)の Lambda 関数の環境変数に指定します。
