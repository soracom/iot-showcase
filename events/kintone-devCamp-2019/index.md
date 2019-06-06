# kintone devCamp 2019 ― IoT ハンズオン

[kintone](https://kintone.cybozu.co.jp/) へのデータ入力デバイスとして [SORACOM LTE-M Button](https://soracom.jp/products/gadgets/) を組み合わせるハンズオンです。

<h2 id="overview">ハンズオン概要</h2>

あらゆる業務改善を支援するプラットフォーム "kintone" へのデータ入力方法は、主に PC やスマホ、そして外部システムとの連携が使用されます。

そこに IoT 技術を組み合わせることで、より省力化、より確実にデータの記録が可能となり、新たに集まるデータで業務改善の幅を広がることは間違いありません。

<iframe width="560" height="315" src="https://www.youtube.com/embed/DEx8Xv5YPWY" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

本ハンズオンでは、すでに市販されている「どこでもボタン」 SORACOM LTE-M Button の「ボタンを押した」というデータを kintone に記録していくハンズオンです。

### ハンズオンのゴール

![kintone-devCamp2019 / overview](https://......)

### SORACOM LTE-M Button とは？

SORACOM LTE-M Buttonは、省電力型のモバイル通信 "LTE-M" と、組み込み型 SIM "eSIM" を内蔵した「どこでもボタン」を実現するボタン型デバイスです。

![kintone-devCamp2019 / SORACOM LTE-M Button](TODO)

Wi-Fi や Bluetooth のような事前設定をしなくても、クラウド連携が可能となります。電源は交換可能な単４電池２本で、小型で持ち運びも可能です。接続するセンサーやクラウドに合わせて３モデルあります。

詳細は [SORACOM LTE-M Button シリーズ](https://soracom.jp/products/gadgets/) をご覧ください。

<h2 id="check">ハンズオンに必要なもの（持ち物のご確認）</h2>

* 外部の Wi-Fi に接続できる PC
    * OS は問いません
    * 最新の Google Chrome が利用でき、プロキシサーバ設定などが変更可能なもの)

### ハンズオン運営からお貸しするもの (要返却)

* SORACOM アカウント x 1
* SORACOM LTE-M Button x 1
* TODO

<h2 id="prepare">作業前の準備</h2>

TODO

<h2 id="index">作業: 目次</h2>

* [ボタンからのデータを SORACOM Harvest に蓄積・収集する](soracom-harvest)
* [SORACOM Beam で kintone と連携する](kintone)

<h2 id="clean-up">作業: あとかたづけ</h2>

TODO

<h2 id="afterfollow">今後の自習方法について</h2>

* 本ドキュメントはイベント後でも閲覧いただくことができます。
* 運営側で準備した Amazon API Gateway / AWS Lambda / kintone の環境はイベント終了後に停止しますが、以下のドキュメントから同等の環境を構築することが可能です。
    * [SORACOM LTE-M Button デザインパターン ― AWS と連携させる / SORACOM Beam + Amazon API Gateway パターン](https://dev.soracom.io/jp/design_patterns/soracom_aws/#aws1)
    * [kintone 側環境の構築](TODO)
    * [本日利用した Lambda 関数について](TODO)

[EoT]
