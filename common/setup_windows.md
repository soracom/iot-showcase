本テキストは [Wio LTE](https://soracom.jp/products/wio_lte/) を開発する際に必要な環境を Windows 上に構築する手順です

## 準備するもの

* パソコン / 1台
    * インターネットに接続できる環境
    * USB Type-A ポートが最低1つ以上あり、利用可能なこと
        * 電力供給が1A以上であること (USB 3.0対応していれば概ね安心です)
    * OS: Windows(8.1 もしくは 10)
        * ※ソフトウェアをインストールするため、PCに対する管理者権限を持っている事 と ブラウザでのアクセス制限がかかっていない事
* Wio LTE (本体、 電源兼シリアルコンソール用microUSBケーブル) / 1式

# Wio LTE 基礎

## 《知識》Wio LTE の電源ON/OFFの方法

Wio LTE には電源スイッチがありませんので、下記作業で ON / OFF してください

### 電源 ON

microUSB ケーブルを Wio LTE の microUSB ポートに接続すると自動的にONになります

![Wio LTE と PC を microUSBケーブルで取り付けたところ](https://docs.google.com/drawings/d/e/2PACX-1vSgLUCOrN928URIfbcNC0VR4xwSBOCYm8ngs0d2edkWyu4ZC7VNoXjALvKOXv121zk3RZB2vF9J40fB/pub?w=640&h=480)

### 電源 OFF

microUSB ケーブルを抜きます。いきなり抜いて OK です

※シャットダウン処理は存在しません

## 【作業】Wio LTE の "通常モード" と "DFUモード"

Wio LTE は２つのモードを持っています  
**この操作は Wio LTE の開発で何度も行うことになりますので、必ず覚えてください**

* 書き込まれたプログラムを実行する「通常モード」
* プログラムを書き込むことができる「DFUモード」 (DFU = Device Firmware Upgrade)

![フロー](https://docs.google.com/drawings/d/e/2PACX-1vQAcnymqWTTneRwnc9EFz21YvrmfCsIuV33yfqf1ODC_LKQR-6762CJDMclRIWC8BfUeDDLpC6KKs-2/pub?w=581&h=253)


これらのモードの切り替えは Wio LTE 上の **RSTボタン** と **BOOTボタン** の組み合わせで行います  
各ボタンの位置は下記のとおりです（ Wio LTE の表裏にボタンがあるため、横からみた図で確認ください）

![Wio LTE を横からみた図](https://docs.google.com/drawings/d/e/2PACX-1vRnhRiZC7-jRCqLaxJO6E7Bmq0_8BxornXgP1y6UHdYXhr6iBm_RNoV148oSzJKeHBYXRjYai9msQoz/pub?w=480&h=249)

### 「通常モード」での動作のさせ方

microUSBをPC等に接続して電源が供給されると Wio LTE は 通常モード で起動します  
もしくは、起動中の Wio LTE の *RSTボタン* を押すと 通常モード に移行します

RSTボタンを利用した通常モードへの移行

![RSTボタンを利用した通常モードへの移行動画](http://drive.google.com/uc?export=view&id=1YkxHW6LBtDQP6SKi1ytw3snOMe-Vt6HQ)

※動画ではmicroUSB接続をしていませんが、実際は接続した状態で行ってください

#### 確認方法

デバイスマネージャの *ユニバーサル シリアル バス デバイス* (Windows 7 の場合は *Universal Serial Bus Devices*) の一覧に **STMicroelectronics Virtual COM Port** が表示されていれば、通常モードで動作しています

※ 表示されなかった場合は Virtual COM Port ドライバが不足しています。[開発環境構築の手順](#devenv) の **Virtual COM Port ドライバ**のインストールを行ってください

![Windows 通常モードの時のデバイスマネージャの表示](https://dev.soracom.io/img/gs_wio-lte/basic-normal-win.png)

### 「DFUモード」での動作のさせ方

「通常モード」の Wio LTE に対して、下記操作を行います

1. *BOOTボタン* を押し、 **押し続けてください**
2. *RSTボタン* を押し、離します
3. 押し続けていた *BOOTボタン* を離します

DFUモードへの移行方法  
※動画ではmicroUSB接続をしていませんが、実際は接続した状態で行ってください

![DFUモードへの移行](http://drive.google.com/uc?export=view&id=1447mCTbYS7iMTtVWaTkXJzHD8vJ8lprJ)

#### 確認

デバイスマネージャの *ユニバーサル シリアル バス デバイス* (Windows 7 の場合は *Universal Serial Bus Devices*) の一覧に **STM32 BOOTLOADER** が表示されていれば、DFUモードで動作しています

※ 表示されなかった場合は WinUSB ドライバが不足しています。[開発環境構築の手順](#devenv) の **WinUSB ドライバ**のインストールを行ってください


![Windows DFUモードの時のデバイスマネージャの表示](https://dev.soracom.io/img/gs_wio-lte/basic-dfu-win.png)

<h1 id="devenv">開発環境構築の手順</h1>

Wio LTE を使うためには、開発環境の準備を行います

* [Virtual COM Port ドライバ](#vcomport)
* [WinUSB ドライバ](#winusb)
* [TeraTerm](#term)
* [Arduino IDE](#arduino-ide)
    * [Wio LTE ボード定義のインストール](#arduino-ide-board-manager)
    * [Wio LTE ライブラリのインストール](#arduino-ide-lib)

<h2 id="vcomport">1. Virtual COM Port ドライバ</h2>

Wio LTE を通常モードで動作させた際に、Wio LTE にシリアルポートでアクセスするためのドライバです

Virtual COM Port ドライバは [Virtual COM Portデバイスドライバーのインストール](https://seeedjp.github.io/Wiki/Wio_LTE_for_Arduino/InstallVCOMDriver-ja.html) の手順に従ってファイルの入手とインストールを行ってください

### 確認方法

Wio LTE を PC と接続してみてください  
その際デバイスマネージャ上で **STMicroelectronics Virtual COM Port** と表示されるようになれば、インストールに成功しています

![Windows 通常モードの時のデバイスマネージャの表示](https://dev.soracom.io/img/gs_wio-lte/basic-normal-win.png)

### よくある間違い

`VCP_V1.4.0_Setup.exe` を実行するとインストールが終わったように見えますが、それで **終了ではありません！**  
必ず [Virtual COM Portデバイスドライバーのインストール](https://seeedjp.github.io/Wiki/Wio_LTE_for_Arduino/InstallVCOMDriver-ja.html) の手順３を行うようにしてください

<h2 id="winusb">2. WinUSB ドライバ</h2>

Wio LTE を DFU モード に切り替えてファイル書き込みを行う際に必要なドライバです

### 2-1. [Zadigサイト](http://zadig.akeo.ie/) の Download にある **Zadig 2.4** をクリックして、zadig-2.4.exeをダウンロードします

**WinUSB ドライバのインストール作業を完了させるためには Wio LTE 本体が必要です**

もし Wio LTE 本体が無い場合は zadig-2.4.exe のダウンロードのみを行い、次の作業に進んでください  
※Wio LTE 本体が入手出来次第、ここからの作業を再開しましょう。ハンズオン等でスタッフがいる場合は、お声がけください

### 2-2. Wio LTE を DFUモード に切り替えます

DFUモードへの切り替え方は、このページの前半で確認してください

### 2-3. zadig-2.4.exe を起動する

### 2-4. zadig-2.4.exe の [Options] > [List All Devices]

### 2-5. **STM32 BOOTLOADER** を選んだ後、Driver の右の欄を *WinUSB* に変更してから、Replace Driver をクリックします

※もしくは `Install Driver` になってる場合でもクリックして大丈夫です

![](https://github.com/SeeedJP/WioLTEforArduino/wiki/img/11.png)

### 2-6. デバイスマネージャの *ユニバーサル シリアル バス デバイス* (Windows 7 の場合は *Universal Serial Bus Devices*) の一覧に **STM32 BOOTLOADER** が表示されていれば成功です

![Windows DFUモードの時のデバイスマネージャの表示](https://dev.soracom.io/img/gs_wio-lte/basic-dfu-win.png)

<h2 id="term">3. TeraTerm</h2>

Wio LTE からのシリアルコンソールを読み書きするためのソフトウェアです  
※Wio LTE 開発の際、Arduino IDE 標準搭載のシリアルモニターは動作が不安定になることがあるため、TeraTermを利用するようにしてください

検索エンジンで TeraTerm を探し、ダウンロードとインストールを行ってください

<h2 id="arduino-ide">4. Arduino IDE</h2>

Wio LTE の開発（ソースコード記述、コンパイル、バイナリファイル転送）には、Arduino IDEを利用します。 Arduino のサイトから [Arduino IDE をダウンロード](https://www.arduino.cc/en/main/software)し、表記に従ってインストールしてください

### 4-1. ダウンロード

![download-arduino](https://docs.google.com/drawings/d/e/2PACX-1vTOGgidIrsQ6NwO4fGlVHHaO_7kHsxBDDq-GzoFM-yZlvDHfjrSXvakwLhTZsYwyE6BTDcVDc4oJ01m/pub?w=841&h=544)

![arduino-ide-download-justdownload](https://docs.google.com/drawings/d/e/2PACX-1vSxk2FHGBqwe5MmiLxMCaJsXfruEOcZH8I_evvvE6jOiuXOKvs2o9Sj7WvG5i7n_-dK8nhZcpd6stgp/pub?w=745&h=472)

### 4-2. インストール

* ダウンロードした EXE ファイルをダブルクリックしてセットアップを開始してください

※スタートメニュー内の **Arduino** が「Arduino IDE」です。これをダブルクリックで Arduino IDE を起動することになります

<h2 id="arduino-ide-board-manager">5. Wio LTE ボード定義のインストール

Wio LTE を Arduino IDE で扱えるようにするための機能を追加します

### 5-1. Arduino IDE を起動する

スタートメニュー内の **Arduino** をダブルクリックします

### 5-2. Arduino IDE の [ファイル] > [環境設定]  

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRfOPHq6O844LQMs1CAdR-FpQ6-fKCaZux-OP42_GWksmxDcj6SFrcefLhuNiEsgPr9UPtn9EnTIAAK/pub?w=285&amp;h=387">

下記URL (https:// から .json まで) を 設定タブ にある **追加のボードマネージャのURL:** へ入力して、保存をクリックします

```
https://www.seeed.co.jp/package_SeeedJP_index.json
```

![追加の様子 wio-lte-handson / arduino-pref](https://docs.google.com/drawings/d/e/2PACX-1vRato9UW98VRjlt3A6oDULm9GTattfeIAdyBse9DnNduv1ZnoOBmJCBW_ZNB5aeGsv3qofMQZS7HcXj/pub?w=723&h=625)

### 5-3. メニューの [ツール] > [ボード] > [ボードマネージャ]

一覧の中から **Seeed STM32F4 Board (JP mirror) by Seeed K.K.** を選択しインストールをクリックします（Seeed Wio LTE Cat.1. という表示がされています）  
※ `wio lte cat` で検索すると見つけやすいです  
※ 似たようなボードに「Seeed Wio 3G, Seeed Wio LTE M1/NB1(BG96)」というものがありますが、そちらではありませんので注意してください

![インストールの様子 wio-lte-handson / board-manager-wiolte](https://docs.google.com/drawings/d/e/2PACX-1vR9IdCB5yo0Zvks5QG9XEVR1MAWilwUoeKHu0ebC0xmjLaUpC7wgwNTuzBS3jH4ER6L2m3I6JVdhrDS/pub?w=781&h=436)  

<h2 id="arduino-ide-lib">6. Wio LTE ライブラリのインストール</h2>

実際のプログラム（Arduino では スケッチと称します）で Wio LTE が使えるようにするライブラリを追加します

### 6-1. Arduino IDE を起動する

### 6-2. Arduino IDE の [スケッチ] > [ライブラリをインクルード] > [ライブラリを管理…]

一覧の中から **Wio LTE for Arduino by Seeed K.K.** を選択しインストールをクリックします  
※ `wio lte` で検索すると見つけやすいです
※ 似たようなライブラリに「Wio LTE Arduino Library by Seeed Studio」というものがありますが、そちらではありませんので注意してください

![インストールの様子 wio-lte-handson / lib-wiolte](https://docs.google.com/drawings/d/e/2PACX-1vRaUkBbjhKKwgX3VBlW644SPUoWibASHvIro6Bxxk28XOjrZjiWX9Y5tGexIe96stSQlFepAUxJfMv2/pub?w=969&h=554)  

## 以上で環境構築は終了です  
