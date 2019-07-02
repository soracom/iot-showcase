# SORACOM Napter:TODO ハンズオン

<h2 id="overview">ハンズオン概要</h2>

SORACOM Air SIM を利用してモバイル通信をしているデバイスに対して、 SSH や RDP, VNC だけでなく、デバイス上で動作している HTTP サーバに対して安全にリモートアクセスを実現する [SORACOM Napter:TODO](:TODO) を体験できるハンズオンです。

※ SSH(Secure Shell), RDP(Remote Desktop Protocol), VNC(Virtual Network Computing) いずれも、遠隔にあるコンピュータをセキュアに操作することができるプロトコル。

### ハンズオンのゴール

"クイック・リモートアクセス" SORACOM Napter:TODO を利用して、PC からインターネットを経由して SORACOM Air SIM によるモバイル通信をしている Raspberry Pi 上の SSH および HTTP サーバにアクセスします。

![SORACOM Napter:TODO Handson / ハンズオン構成図](https://docs.google.com/drawings/d/e/2PACX-1vSOlc1LTdgJkEZQ5NoqNE6YmRLNDZ6PuiFylecs64rpXe-yiq21iGKojNx5E4bvtl_OMaRscLFwYLXp/pub?w=912&h=372)

### SORACOM Napter:TODO とは？

:TODO 説明を書く。

<h2 id="check">ハンズオンに必要なもの（持ち物のご確認）</h2>

:TODO

* 外部の Wi-Fi に接続できる PC
    * OS は問いません
    * 最新の Google Chrome が利用でき、プロキシサーバ設定などが変更可能なもの)
    * SSH クライアント: TeraTerm(Windows), Terminal.app(macOS) など
* クレジットカード x 1
    * SORACOM アカウントをお持ちでない方は、当日アカウントを作成する際にクレジットカードが必要になります
    * デビットカード、プリペードカードはご利用いただけません。
* 当日利用するPCで SORACOM から受信する内容をその場で確認できるメールアドレス
    * アカウント作成のためにメールアドレス認証が必要です
* SORACOM Air SIM x 1
* SIM アダプタ (nano → micro) x 1
 
### ハンズオン運営からお貸しするもの (要返却)

:TODO

* リモートアクセス先の Raspberry Pi x 1
* USB ドングル x 1

※ リモートアクセス先の Rasbperry Pi の構成については [Appendix: RPi の構成](#a-rpi) をご覧ください。

<h2 id="index">作業: 目次</h2>

* [SORACOM アカウント作成](#w1)
* [SORACOM Air SIM の登録と SIM の挿入](#w2)
* [SORACOM Napter:TODO 設定](#w3)
* [リモートアクセスをする](#w4)
* [あとかたづけ](#clean-up)

<h3 id="w1">SORACOM アカウント作成</h3>

:TODO

<h3 id="w2">SORACOM Air SIM の登録と SIM の挿入</h3>

:TODO

<h3 id="w3">SORACOM Napter:TODO 設定</h3>

:TODO

<h3 id="w4">リモートアクセスをする</h3>

:TODO

<h2 id="clean-up">作業: あとかたづけ</h2>

:TODO

### オプション: クーポンの登録

クーポンが割り当てられている場合は:TODO

## Appendix

<h3 id="a-rpi">RPi の構成</h3>

リモートアクセス用に用意した Raspberry Pi (以下、 RPi) は以下のようにされています。  
SORACOM Napter:TODO 用の構成は特にありません。

* OS: Raspbian (2019-04-08)
    * SSH
        * OS 起動時の自動立ち上げ
    * HTTP
        * Nginx のインストールと `index.html` の編集
        * OS 起動時の自動立ち上げ
    * SORACOM Air への接続設定
        * [setup_air.sh](https://soracom-files.s3.amazonaws.com/setup_air.sh) の実行

```
$ :TODO
```

[EoT]
