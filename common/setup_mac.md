本テキストは [Wio LTE](https://soracom.jp/products/wio_lte/) を開発する際に必要な環境を macOS 上に構築する手順です

## 準備するもの

* パソコン / 1台
    * インターネットに接続できる環境
    * USB Type-A ポートが最低1つ以上あり、利用可能なこと
        * 電力供給が1A以上であること (USB 3.0対応していれば概ね安心です)
    * OS: macOS (10.11 El Capitan 以上)
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

「システム情報」で、動作モードが確認できます

![システム情報の出し方](https://docs.google.com/drawings/d/e/2PACX-1vRZ3vYr9qLtFYKL3gCZTJ7facHM7RBNsvenVCMyJ6acozLCOh4h4rcc9WMpRL0QVXJhgDbfZKBXB0sS/pub?w=669&h=402)

システム情報の *USB* の一覧に **STM32 Virtual ComPort in FS Mode** が表示されていれば、通常モードで動作しています

![macOS 通常モードの時のデバイスマネージャの表示](https://dev.soracom.io/img/gs_wio-lte/basic-normal-macos.png)

### 「DFUモード」での動作のさせ方

「通常モード」の Wio LTE に対して、下記操作を行います

1. *BOOTボタン* を押し、 **押し続けてください**
2. *RSTボタン* を押し、離します
3. 押し続けていた *BOOTボタン* を離します

DFUモードへの移行方法  
※動画ではmicroUSB接続をしていませんが、実際は接続した状態で行ってください

![DFUモードへの移行](http://drive.google.com/uc?export=view&id=1447mCTbYS7iMTtVWaTkXJzHD8vJ8lprJ)

#### 確認

システム情報の *USB* の一覧に **STM32 BOOTLOADER** が表示されていれば、DFUモードで動作しています  
※すでにシステム情報を表示している場合は [ファイル]-[情報の更新] をしてください

![macOS DFUモードの時のデバイスマネージャの表示](https://dev.soracom.io/img/gs_wio-lte/basic-dfu-macos.png)

# 開発環境構築の手順

Wio LTE を使うためには、開発環境の準備を行います

* [Homebrew](#brew)
    * [libusb](#libusb)
* [Arduino IDE](#arduino-ide)
    * [Wio LTE ボード定義のインストール](#arduino-ide-board-manager)
    * [Wio LTE ライブラリのインストール](#arduino-ide-lib)

<h2 id="brew">1. Homebrew</h2>

後述する libusb をインストールするために必要です

### 1-1. Terminal.app を起動する

Terminal.app 内で下記コマンドを実行します  
※途中でパスワード入力を求めらたら macOS ログイン時のパスワードを入力してください

```
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

最終的に下記のように表示されればインストール成功です

```
==> Next steps:
- Run `brew help` to get started
- Further documentation:
   https://docs.brew.sh```
```

<h2 id="libusb">2. libusb</h2>

Wio LTE を DFU(Device Firmware Upgrade) モード に切り替えてファイル書き込みを行う際に必要なドライバです

### 2-1. Terminal.app を起動する

Terminal.app 内で下記コマンドを実行します

```
brew install libusb
```

最終的に下記のように表示されればインストール成功です

```
==> Downloading https://homebrew.bintray.com/bottles/libusb-1.0.21.el_capitan.bo
######################################################################## 100.0%
==> Pouring libusb-1.0.21.el_capitan.bottle.tar.gz
:beer:  /usr/local/Cellar/libusb/1.0.21: 29 files, 510.5KB
```

<h2 id="arduino-ide">3. Arduino IDE</h2>

Wio LTE の開発（ソースコード記述、コンパイル、バイナリファイル転送）には、Arduino IDEを利用します。 Arduino のサイトから [Arduino IDE をダウンロード](https://www.arduino.cc/en/main/software)し、表記に従ってインストールしてください

### 3-1. ダウンロード

![download-arduino](https://docs.google.com/drawings/d/e/2PACX-1vTOGgidIrsQ6NwO4fGlVHHaO_7kHsxBDDq-GzoFM-yZlvDHfjrSXvakwLhTZsYwyE6BTDcVDc4oJ01m/pub?w=841&h=544)

![arduino-ide-download-justdownload](https://docs.google.com/drawings/d/e/2PACX-1vSxk2FHGBqwe5MmiLxMCaJsXfruEOcZH8I_evvvE6jOiuXOKvs2o9Sj7WvG5i7n_-dK8nhZcpd6stgp/pub?w=745&h=472)

### 3-2. インストール

* ダウンロードした ZIP ファイルをダブルクリックして展開してください
* 展開後の **Arduino** アイコンを "アプリケーション" フォルダへ移動してください

※アプリケーションフォルダに移動した **Arduino** が「Arduino IDE」です。これをダブルクリックで Arduino IDE を起動することになります

<h2 id="arduino-ide-board-manager">4. Wio LTE ボード定義のインストール</h2>

Wio LTE を Arduino IDE で扱えるようにするための機能を追加します

### 4-1. Arduino IDE を起動する

アプリケーションフォルダ内の **Arduino** をダブルクリックします

### 4-2. メニューの [Arduino] > [Preferences...]  

![Preferences](http://drive.google.com/uc?export=view&id=14ohj6_a8k-ENlQKHelaalB_iid-W4Zg3)

下記URL (https:// から .json まで) を 設定タブ にある **追加のボードマネージャのURL:** へ入力して、保存をクリックします

```
https://www.seeed.co.jp/package_SeeedJP_index.json
```

![追加の様子 wio-lte-handson / arduino-pref](https://docs.google.com/drawings/d/e/2PACX-1vRato9UW98VRjlt3A6oDULm9GTattfeIAdyBse9DnNduv1ZnoOBmJCBW_ZNB5aeGsv3qofMQZS7HcXj/pub?w=723&h=625)

### 4-3. メニューの [ツール] > [ボード] > [ボードマネージャ]

一覧の中から **Seeed STM32F4 Board (JP mirror) by Seeed K.K.** を選択しインストールをクリックします（Seeed Wio LTE Cat.1. という表示がされています）  
※ `wio lte cat` で検索すると見つけやすいです  
※ 似たようなボードに「Seeed Wio 3G, Seeed Wio LTE M1/NB1(BG96)」というものがありますが、そちらではありませんので注意してください

![インストールの様子 wio-lte-handson / board-manager-wiolte](https://docs.google.com/drawings/d/e/2PACX-1vR9IdCB5yo0Zvks5QG9XEVR1MAWilwUoeKHu0ebC0xmjLaUpC7wgwNTuzBS3jH4ER6L2m3I6JVdhrDS/pub?w=781&h=436)  

<h2 id="arduino-ide-lib">5. Wio LTE ライブラリのインストール</h2>

実際のプログラム（Arduino では スケッチと称します）で Wio LTE が使えるようにするライブラリを追加します

### 5-1. Arduino IDE を起動する

### 5-2. Arduino IDE の [スケッチ] > [ライブラリをインクルード] > [ライブラリを管理…]

一覧の中から **Wio LTE for Arduino by Seeed K.K.** を選択しインストールをクリックします  
※ `wio lte` で検索すると見つけやすいです
※ 似たようなライブラリに「Wio LTE Arduino Library by Seeed Studio」というものがありますが、そちらではありませんので注意してください

![インストールの様子 wio-lte-handson / lib-wiolte](https://docs.google.com/drawings/d/e/2PACX-1vRaUkBbjhKKwgX3VBlW644SPUoWibASHvIro6Bxxk28XOjrZjiWX9Y5tGexIe96stSQlFepAUxJfMv2/pub?w=969&h=554)  

## 以上で環境構築は終了です  

## うまく動かなかったら（トラブルシュート）

古い Xcode がインストールされていると Homebrew のインストールに失敗します  
Xcode をアンインストールし、 `/Library/Developer/CommandLineTools` フォルダをリネームもしくは削除したうえで、再度 Homebrew をインストールしてください (Xcodeの再インストールは不要です)

**※アンインストール作業については特にご注意ください!!**

デフォルトSHELLが bash じゃないと homebrew のインストールコマンドで失敗します (評価をミスる)  
`curl ... | ruby` として流し込んでみてください
