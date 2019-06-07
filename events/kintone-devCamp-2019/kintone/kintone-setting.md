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

配置したフィールドの右上歯車からフィールドの設定を開き、<br/>
「フィールド名」を `テキスト` に、「フィールドコード」を `text` に変更します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRLXZF-xWfqa2JM86fPWty5gltf4dUOT_XrMF2aMS9nvxcshB_kLeIRNFCvgjQu-0SrS_X0xcLVAF2t/pub?w=930&amp;h=489">

<br/>

同様にもう一つ文字列（1行）フィールドを配置して、<br/>
「フィールド名」を `ユーザー` に、「フィールドコード」を `user` に変更しておきます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vR636qxYfpOPWlUoNe4ub5LNVvCyzmt_Fg1mZwonHF9_50Xq5PAMBEmZ5oCU4NmC8ivKRfmk158e5In/pub?w=929&amp;h=487">

<br/>

配置後、「フォームを保存」を選択します。

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

を[こちら](aws-lambda-setting.md#step3)のLambda関数の環境変数に指定します。
