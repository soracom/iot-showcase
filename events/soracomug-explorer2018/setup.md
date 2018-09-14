# ハンズオン受講 セットアップ

SORACOM UG Explore 2018 ハンズオンへようこそ！

このページではハンズオンが受講できるようにするためのセットアップについて解説しています。  
OS 毎に準備がありますので、それぞれの OS を選んでセットアップを進めてください。

* [Windows 編](#windows)
* [macOS 編](#macos)

[ハンズオンドキュメントへ戻る](index)

---

<h1 id="windows">ハンズオン準備 Windows 編</h1>

## 《確認》 準備するもの

* Wio LTE 本体 / 1個
    * パソコンとの接続用 USB ケーブル / 1本
* パソコン / 1台
    * インターネットに接続できる環境
    * USB Type-A ポートが最低 1 つ以上あり、利用可能なこと
        * 電力供給が1A以上であること (USB 3.0対応していれば概ね安心です)
        * アダプタ経由でも可能な場合がありますが、サポート外です
    * OS: Windows (8.1 もしくは 10)
        * ソフトウェアをインストールするため、PCに対する管理者権限を持っている事と、ブラウザでのアクセス制限がかかっていない事
        * Windows 7 でも動作する場合がありますが、サポート外です

## 《作業》 セットアップの手順

ソフトウェアをセットアップしていきます

* [WinUSB ドライバ](#winusb)

<h3 id="winusb">WinUSB ドライバ</h3>

Wio LTE を DFU モード (プログラムをマイコンに書き込み可能な状態) に切り替えてファイル書き込みを行う際に必要なドライバです。

#### 1. zadig-2.4.exe をダウンロードする

[Zadig のページ](http://zadig.akeo.ie/) にアクセスし、 ページ半ばにある **Zadig 2.4** をクリックして Zadig 2.4 をダウンロードします。

![iot-showcase/zadig-download](https://docs.google.com/drawings/d/e/2PACX-1vQhbYyzUOLoBkR7ee6tCXbrv7VC0C75FNhY9nZE-iyr2YimQKCiehHa14Pw3ewmUHk6hKIM1S9oGXJX/pub?w=527&h=283)

**ここから先は Wio LTE が必要になります。 Wio LTE をお持ちで無い方は、ここまでの手順を済ませておいてから、ハンズオン当日のスタッフにお声がけください**

#### 2. Wio LTE を DFU モードに切り替える

[DFU モードへの切り替え方](#dfu)をご覧ください。

#### 3. zadig-2.4.exe を起動する

#### 4. メニューの [Options] > [List All Devices] を選ぶ

#### 5. "STM32 BOOTLOADER" を選んだ後、Driver の右側が "WinUSB" になっている事を確認してから "Install Driver" (もしくは "Replace Driver" ) をクリックします

※ "STM32 BOOTLOADER" が見つからない場合は Wio LTE が DFU モードになっていません。[DFU モードへの切り替え方](#dfu)に沿って DFU モードに切り替えてください。  
※ Driver が WinUSB になっていなかった場合は WinUSB に切り替えてください。

![](https://raw.githubusercontent.com/wiki/SeeedJP/WioLTEforArduino/img/11.png)

#### 6. デバイスマネージャの "ユニバーサル シリアル バス デバイス" の一覧に "STM32 BOOTLOADER" が表示されていれば成功です

※ Windows 7 の場合は "Universal Serial Bus Devices" の中に "STM32 BOOTLOADER" が表示されます

![](https://dev.soracom.io/img/gs_wio-lte/basic-dfu-win.png)

**お疲れ様でした、以上でセットアップ終了です**

[ハンズオンドキュメントへ戻る](index)

---

<h1 id="macos">ハンズオン準備 macOS 編</h1>

## 《確認》 準備するもの

* パソコン / 1台
    * インターネットに接続できる環境
    * USB Type-A ポートが最低 1 つ以上あり、利用可能なこと
        * 電力供給が1A以上であること (USB 3.0対応していれば概ね安心です)
        * アダプタ経由でも可能な場合がありますが、サポート外です
    * OS: macOS (10.11 El Capitan 以上)
        * ソフトウェアをインストールするため、PCに対する管理者権限を持っている事と、ブラウザでのアクセス制限がかかっていない事

## 《作業》 セットアップの手順

ソフトウェアをセットアップしていきます

* [Homebrew](#homebrew)
* [libusb](#libusb)

<h3 id="homebrew">Homebrew</h3>

この後インストールをする [libusb](#libusb) をインストールするために必要なソフトウェアです。

#### 1. Terminal.app を起動して、コマンドを実行する

Terminal.app 内で下記コマンドを実行します。  
※ 実行中でパスワード入力を求めらたら macOS ログイン時のパスワードを入力してください。

```
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

最終的に下記のように表示されればインストール成功です。

```
==> Next steps:
- Run `brew help` to get started
- Further documentation:
   https://docs.brew.sh
```

<h3 id="libusb">libusb</h3>

Wio LTE を DFU モード (プログラムをマイコンに書き込み可能な状態) に切り替えてファイル書き込みを行う際に必要なドライバです。

#### 1. Terminal.app を起動して、コマンドを実行する

Terminal.app 内で下記コマンドを実行します。

```
brew install libusb
```

最終的に下記のように表示されればインストール成功です。

```
==> Downloading https://homebrew.bintray.com/bottles/libusb-1.0.21.el_capitan.bo
######################################################################## 100.0%
==> Pouring libusb-1.0.21.el_capitan.bottle.tar.gz
(ビールのアイコン)  /usr/local/Cellar/libusb/1.0.21: 29 files, 510.5KB
```

**お疲れ様でした、以上でセットアップ終了です**

[ハンズオンドキュメントへ戻る](index)

---

<h1 id="dfu">DFU モードへの切り替え方</h1>

プログラムを書き込むことができる状態のことを指します。  
以下の一連の操作で DFU モードにすることができます。

1. microUSB ケーブルを接続する
2. *BOOTボタン* を押し、 **押し続けてください**
3. *RSTボタン* を押し、離します
4. 押し続けていた *BOOTボタン* を離します

以上の操作です。各ボタンの位置は下図をご覧ください。

![Wio LTE を横からみた図](https://docs.google.com/drawings/d/e/2PACX-1vRnhRiZC7-jRCqLaxJO6E7Bmq0_8BxornXgP1y6UHdYXhr6iBm_RNoV148oSzJKeHBYXRjYai9msQoz/pub?w=480&h=249)

操作の様子は動画にまとめてあります。  
（見やすいように microUSB ケーブルは外していますが、実際は取り付けてから行ってください）

<iframe width="560" height="315" src="https://www.youtube.com/embed/5hgTU6tyIJ0?rel=0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

<h2 id="dfu2">DFU モードの確認の仕方</h2>

### Windows の場合

「デバイスマネージャ」で、動作モードが確認できます。

デバイスマネージャの *ユニバーサル シリアル バス デバイス* (Windows 7 の場合は *Universal Serial Bus Devices*) の一覧に **STM32 BOOTLOADER** が表示されていれば、DFUモードで動作しています

![Windows DFUモードの時のデバイスマネージャの表示](https://dev.soracom.io/img/gs_wio-lte/basic-dfu-win.png)

### STM32 BOOTLOADER が表示されていない場合

この状態ではプログラムを書き込むことができません。

原因は以下が考えられます。

* DFU モードへの移行をしていない
    * → DFU モードへの移行操作を再度行ってみてください
* WinUSB ドライバのインストールが完了していない
    * → [WinUSB ドライバのインストール](#winusb)に沿って作業を行ってください

**DFU モードの説明はこれで終了です。元の手順に戻ってください**

### macOS の場合

「システム情報」で、動作モードが確認できます。

![システム情報の出し方](https://docs.google.com/drawings/d/e/2PACX-1vRZ3vYr9qLtFYKL3gCZTJ7facHM7RBNsvenVCMyJ6acozLCOh4h4rcc9WMpRL0QVXJhgDbfZKBXB0sS/pub?w=669&h=402)

"システム情報" の *USB* の一覧に **STM32 BOOTLOADER** が表示されていれば、DFUモードで動作しています。

![macOS DFUモードの時のデバイスマネージャの表示](https://dev.soracom.io/img/gs_wio-lte/basic-dfu-macos.png)

※ すでに "システム情報" を表示している場合は [ファイル]-[情報の更新] をしてください

### STM32 BOOTLOADER が表示されていない場合

この状態ではプログラムを書き込むことができません。

原因は以下が考えられます。

* DFU モードへの移行をしていない
    * → DFU モードへの移行操作を再度行ってみてください

**DFU モードの説明はこれで終了です。元の手順に戻ってください**
