# 本日利用した Lambda 関数について

今回利用したLambda関数の設定方法、およびプログラムについて記載します。

## 手順

- [Lambda 関数の作成](#step1)
- [Lambda 関数のプログラム作成](#step2)
- [実行ファイルのアップロード](#step3)
- [環境変数の設定](#step4)

<h2 id="step1">Lambda 関数の作成</h2>

[AWSマネジメントコンソール](https://aws.amazon.com/jp/console/) からコンソールへログインして、Lambdaのページへアクセスします。<br/>
右側の「関数の作成」よりLambda関数を新規作成します。

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/aws-lambda_capture1.png">

<br/><br/>

関数名を入力し(kintone-soracom-button)、「関数の作成」を選択します。<br/>
(今回はNode.jsでプログラムを記述するため、ランタイムは初期設定のままで大丈夫です)

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/aws-lambda_capture2.png">

<br/><br/>

Lambda関数が作成できたら、次はトリガーに **API Gateway** を指定します。

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/aws-lambda_capture3.png">

<br/><br/>

API Gatewayの設定をそれぞれ指定します。<br/>
(今回は「新規のAPI作成」/セキュリティは「オープン」にしていますが、こちらはご自身の設定に合わせて変更してください。)

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/aws-lambda_capture4.png">

<br/><br/>

API Gatewayの設定後、一度画面右上の「保存」ボタンを押すことで、API GatewayのURLが生成されます。<br/>
こちらのURLをSORACOM Beamの送信先として指定します。

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/aws-lambda_capture5.png">

<h2 id="step2">Lambda 関数のプログラム作成</h2>

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
const createParams = (TEXT) => {
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
        title: {
          value: TEXT,
        },
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
  let params;

  // ボタンの押し方によってパラメータを変更
  switch(body.clickType) {
    case 1: { // singleクリック
      params = createParams('single click');
      break;
    }
    case 2: { // doubleクリック
      params = createParams('double click');
      break;

    }
    case 3: { // Longクリック
      params = createParams('long click');
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

<h2 id="step3">実行ファイルのアップロード</h2>

Lambdaへアップロードするために実行ファイルをzip化します。<br/>
(-r オプションをつけて、node_module配下のものもすべてzip化します)

```bash
$ zip -r LambdaFunction.zip index.js node_module/
```

関数コードのコードエントリタイプを「.zipファイルをアップロード」に変更し、先ほどzip化した **LambdaFunction.zip** をアップロードします。

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/aws-lambda_capture6.png">

<h2 id="step4">環境変数の設定</h2>

Lambdaの環境変数を設定します。ここに **kintoneのURL / APIトークン / アプリID** を記述します。<br/>
この環境変数を利用することで、JavaScript上で `process.env.◯◯` と記述できます。<br/>
(kintoneの準備は [こちら](kintone-setting.md) をご覧ください)

<img src="https://kintone-devcamp2019-soracom.s3-ap-northeast-1.amazonaws.com/aws-lambda_capture7.png">

<br/><br/><br/>

以上でLambda関数の準備は環境です。<br/>
API Gatewayの設定で生成したURLをSORACOM Beamに設定することで、<br/>
`SORACOM LTE-M Button -> SORACOM Beam -> AWS Lambda -> kintone` という流れが完成します。
