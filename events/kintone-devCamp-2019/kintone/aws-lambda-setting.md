# 本日利用した Lambda 関数について

今回利用したLambda関数の設定方法、およびプログラムについて記載します。

## 手順

- [Lambda 関数のプログラム作成](#step1)
- [実行ファイルのアップロード](#step2)
- [環境変数の設定](#step3)

<h2 id="step1">Lambda 関数のプログラム作成</h2>

今回は 「ボタンを押したらkintoneへレコード登録する」プログラムを記述します。<br/>
SORACOM LTE-M Buttonは **シングルクリック / ダブルクリック / ロングクリック** の3つの押し方に対応しているため、<br/>
それぞれの押し方で異なるデータが登録できるようにしています。

### Node プロジェクトの準備

1. 作業ディレクトリの作成と移動

```bash
$ mkdir my_project && cd $_
```

2. Node プロジェクトの作成

```bash
$ npm init -y
```
3. 必要モジュールのインストール

今回はkintoneへHTTPリクエストを送るため、requestモジュールを利用します。

```bash
$ npm i request
$ npm i request-promise
```

### 実行プログラムの作成

index.jsとして以下を記述したJavaScriptを作成します。<br/>
(一部Lambdaの環境変数を利用しています)

```javascript

const request = require('request-promise');

// パラメータを作成する関数
const createParams = (TEXT, USER) => {
  return {
    url: `https://${process.env.KINTONE_DOMAIN}/k/v1/record.json`,
    method: 'POST',
    headers: {
      'X-Cybozu-API-Token': process.env.KINTONE_APITOKEN,
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({
      app: process.env.KINTONE_APPID,
      record: {
        text: {
          value: TEXT,
        },
        user: {
          value: USER,
        }
      },
    }),
  };
};

// kintoneへレコードを登録する関数
const postRecord = (PARAMS) => {
  return request(PARAMS)
    .then(resp => resp)
    .catch(err => err);
};

// Lambdaのイベントハンドラー
exports.handler = async (event) => {
  const body = JSON.parse(event.body);
  const header = event.headers[process.env.CUSTOM_HEADER];
  let params;

  // ボタンの押し方によってパラメータを変更
  switch(body.clickType) {
    case 1: { // singleクリック
      params = createParams('single click', header);
      break;
    }
    case 2: { // doubleクリック
      params = createParams('double click', header);
      break;

    }
    case 3: { // Longクリック
      params = createParams('long click', header);
      break;
    }
  }
  // レコード登録
  await postRecord(params);
  return {
    statusCode: 200,
    body: JSON.stringify({
      message: 'kintone Data POST Success!!',
    }),
  };
};

```

<h2 id="step2">実行ファイルのアップロード</h2>

Lambdaへアップロードするために実行ファイルをzip化します。<br/>
(-r オプションをつけて、node_module配下のものもすべてzip化します)

```bash
$ zip -r LambdaFunction.zip index.js node_module/
```

関数コードのコードエントリタイプを「.zipファイルをアップロード」に変更し、先ほどzip化した **LambdaFunction.zip** をアップロードします。

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/aws-lambda_capture6.png">

<h2 id="step3">環境変数の設定</h2>

Lambdaの環境変数を設定します。ここに **kintoneのURL / APIトークン / アプリID** を記述します。<br/>
この環境変数を利用することで、JavaScript上で `process.env.◯◯` と記述できます。<br/>
(kintoneの準備は [こちら](kintone-setting.md) をご覧ください)

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSKKxZsP2AWpvtGbRJi79pq0rQFo-sa1f4xTDjGm2TQI_xmIgY9Cb_ZqlxjQvV2z11_amMEP-rSeTD-/pub?w=961&amp;h=508">

<br/><br/><br/>

以上でLambda関数の準備は完了です。<br/>
API Gatewayの設定で生成したURLをSORACOM Beamに設定することで、<br/>
`SORACOM LTE-M Button -> SORACOM Beam -> AWS Lambda -> kintone` という流れが完成します。
