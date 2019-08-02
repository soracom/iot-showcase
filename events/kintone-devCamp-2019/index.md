# kintone devCamp 2019 ― IoT ハンズオン

[kintone](https://kintone.cybozu.co.jp/) へのデータ入力デバイスとして [SORACOM LTE-M Button](https://soracom.jp/products/gadgets/) を組み合わせるハンズオンです。

<h2 id="overview">ハンズオン概要</h2>

あらゆる業務改善を支援するプラットフォーム "kintone" へのデータ入力方法は、主に PC やスマホ、そして外部システムとの連携が使用されます。

そこに IoT 技術を組み合わせることで、より省力化、より確実にデータの記録が可能となり、新たに集まるデータで業務改善の幅を広がることは間違いありません。

例えば愛知の自動車部品の製造などを手掛ける旭鉄工さんは、製造ラインの状況報告を SORACOM LTE-M Button にしました。  
Wi-Fi などの設備が無くとも、このボタン一つで即座に現場のデジタル化を実現しています。

<iframe width="560" height="315" src="https://www.youtube.com/embed/DEx8Xv5YPWY" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

本ハンズオンでは、すでに市販されている「どこでもボタン」 SORACOM LTE-M Button の「ボタンを押した」というデータを kintone に記録していくハンズオンです。

### ハンズオンのゴール

ボタンは「シングル押し」「ダブル押し」「長押し」というデータを送ることができるため、kintoneアプリ上で識別できるようにしてあります。

![kintone-devCamp2019 / overview](https://docs.google.com/drawings/d/e/2PACX-1vSeNzwTEbvTHXjZK0l2rUmzJTUaPdWfiYcT27QKTgFAqtH4vUQyAJQxZShbQGz6ttKMGI4_6xGoOjWk/pub?w=1099&h=364)

### SORACOM LTE-M Button とは？

SORACOM LTE-M Buttonは、省電力型のモバイル通信 "LTE-M" と、組み込み型 SIM "eSIM" を内蔵した「どこでもボタン」を実現するボタン型デバイスです。

![kintone-devCamp2019 / SORACOM LTE-M Button](https://docs.google.com/drawings/d/e/2PACX-1vRSi9wEeW_wVzlubiVDseBbTSPR9g0UNNAgak-ddvzTCIPa00YgO3fofi6v83cbEB_gp0omfO80Rldm/pub?w=454&h=236)

Wi-Fi や Bluetooth のような事前設定をしなくても、クラウド連携が可能となります。電源は交換可能な単４電池２本で、小型で持ち運びも可能です。接続するセンサーやクラウドに合わせて３モデルあります。

詳細は [SORACOM LTE-M Button シリーズ](https://soracom.jp/products/gadgets/) をご覧ください。

<h2 id="check">ハンズオンに必要なもの（持ち物のご確認）</h2>

* 外部の Wi-Fi に接続できる PC
    * OS は問いません
    * 最新の Google Chrome が利用でき、プロキシサーバ設定などが変更可能なもの)

### ハンズオン運営からお貸しするもの (要返却)

* SORACOM アカウント x 1
* SORACOM LTE-M Button x 1

<h2 id="prepare">作業前の準備</h2>

### SORACOM LTE-M Button を借りた方

* [ハンズオンに必要なもの](#check) がお手元にそろっているか確認してください。

### SORACOM LTE-M Button 持ち込みの方

* 有効な SORACOM アカウント x 1
    * 持っていない場合: 有効なクレジットカード(1枚) と、ハンズオン会場で確認可能なメールアドレス(1つ) を利用し [SORACOM アカウントの作成](https://dev.soracom.io/jp/start/console/#account) の手順に沿って作成します。
* SOARCOM アカウントに登録済みの SORACOM LTE-M Button x 1
    * 未登録の場合: [【ステップ１: SIM管理の画面から Enterprise ボタンを確認する】のみ](https://dev.soracom.io/jp/start/enterprise_button_harvest/#enterprise_button) を行って登録します。

<h2 id="index">作業: 目次</h2>

* [ボタンからのデータを SORACOM Harvest Data に蓄積・収集する](soracom-harvest)
* [SORACOM Beam で kintone と連携する](kintone)
* [SORACOM Funk で kintone と連携する](soracom-funk)

<h2 id="clean-up">作業: あとかたづけ</h2>

### SORACOM LTE-M Button を借りた方

* SORACOM LTE-M Button を運営に返却ください。
* SORACOM ユーザーコンソール上で行うことは特にありません。

### SORACOM LTE-M Button 持ち込みの方

特に料金に関する設定項目を OFF にしてください。

* SORACOM Harvest Data の料金について
    * 本ハンズオンで使用した SORACOM Harvest Data は、 **実際の通信の有無によらず** SORACOM Harvest Data が利用可能状態の SIM(Button) の枚数に応じて日当たりの料金が発生します。詳しくは [SORACOM Harvest Data のご利用料金](https://soracom.jp/services/harvest/price/) をご覧ください。
    * SIM グループの設定で SORACOM Harvest Data を "OFF" にすることで、翌日以降の料金が発生しなくなります。または SIM グループを削除することで、当該 SIM グループに設定されている機能をすべて OFF にすることができます。
    * 蓄積済みデータは SORACOM Harvest Data を OFF にしても残りますが、保管費用はかかりません。ただし、標準ではデータ発生から 40 日後に削除されますので、その前にデータエクスポート等を行うようにしてください。
* SORACOM Beam の料金について
    * 本ハンズオンで使用した SORACOM Beam は発生したリクエストに応じて料金が発生する完全従量課金制サービスです。詳しくは [SORACOM Beam のご利用料金](https://soracom.jp/services/beam/price/) をご覧ください。
    * SIM グループの設定で SORACOM Beam が "ON" になっていたとしても、リクエストが発生しなければ料金は発生しませんが、 "OFF" にする、もしくは設定や SIM グループを削除することをおすすめいたします。

### MEMO: 運営側のあとかたづけ

* SIM グループの削除
    * [SIM グループ] > 当該の SIM グループ > [高度な設定] > 削除
    * 削除するためには [SIM 管理] からボタンに紐づいているグループを解除する必要があります
* SORACOM Harvest Data のデータの削除

<h2 id="afterfollow">今後の自習方法について</h2>

* 本ドキュメントはイベント後でも閲覧いただくことができます。
* 運営側で準備した Amazon API Gateway / AWS Lambda / kintone の環境はイベント終了後に停止しますが、以下のドキュメントから同等の環境を構築することが可能です。
    * [SORACOM LTE-M Button デザインパターン ― AWS と連携させる / SORACOM Beam + Amazon API Gateway パターン](https://dev.soracom.io/jp/design_patterns/soracom_aws/#aws1)
    * [kintone 側環境の構築](kintone/kintone-setting)
    * [本日利用した Lambda 関数について](kintone/aws-lambda-setting)

[EoT]
