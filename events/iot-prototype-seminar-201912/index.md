# Let’s try IoT プロトタイピング！ オンライン講座 〜定点カメラデバイスを作ろう〜

## イベントページ

- [Day1](){:target="_blank"}
- [Day2](){:target="_blank"}

## 準備するもの

* Raspberry Pi 3 model B+ x 1 ※
    * microUSB ケーブル x 1 ※
    * Raspberry Pi 3 用電源アダプタ x 1 ※ (PCからの給電でも可能な場合があります)
* microSD (16GB以上) x 1 ※
    * microSD と PC を接続するアダプタ等 x 1
* 有線 LAN (USB 型のアダプタ等形状問わず) x 1
    * LAN ケーブル x 1
* USB カメラ x 1 ※
* SORACOM 特定地域向け IoT SIM (標準サイズ) x 1
* AK-020 (USB ドングル型モデム) x 1

# Day1

## Raspberry Pi のセットアップ

### Raspbian (OS) のダウンロードと microSD カードへの書き込み

* [Download Raspbian](https://www.raspberrypi.org/downloads/raspbian/){:target="_blank"} のページから **Raspbian Buster Lite** (約430MB) をダウンロードして、ZIP ファイル内の `.img` ファイルを取り出します。
* [balenaEtcher](https://www.balena.io/etcher/){:target="_blank"} 等のイメージ書込みソフトウェアを利用して、 先ほどの `.img` ファイルを microSD カードに書き込みます。

### 書き込んだ後の設定

PC 上で以下二つのファイルを作成します。テキストエディタで作成してください。

* `wpa_supplicant.conf`
* `ssh`

#### wpa_supplicant.conf

このファイルは Raspberry Pi 起動時に接続する Wi-Fi のアクセスポイントをあらかじめ書いておくことができます。

* `network={...` の `ssid` には SSID を、 `psk` にはパスフレーズを書きます。
* `network={...` は複数書くことができるので、家や職場を指定しておくと便利です。

```
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
country=JP
update_config=1

network={
    ssid="YOUR_WIFI_AP_SSID1"
    psk="password1"
}

network={
    ssid="YOUR_WIFI_AP_SSID2"
    psk="password2"
}
```

#### ssh

このファイルは「存在する事」が重要です。ファイルの中身は「空 (=0バイト)」で構いません。

#### ２つのファイルの配置先

microSD を Raspberry Pi に **入れる前に** 、再度 PC 側に差し込むと **boot** というディスクが見えるので、その中に先ほどのファイルをすべてコピーし、そして microSD を PC から取り外します。

## Raspberry Pi の起動から OS の最新化

有線 LAN と PC を接続し、また、microSD を Raspberry Pi に取り付けてから電源を入れます。  
しばらく経ってから Mac もしくは Windows 10 最新版 で以下のように入力し、Raspberry Pi へリモートログインを行います。

* ※ Windows 10の以前の場合(最新版でない場合も同様)は、 Apple iTunes をインストールしてください。 (mDNS が使える必要があります)
* ※ 電源を接続する **前に** 有線 LAN を接続しないと、リモートログインできない場合があります。

### PC 側で実行

```
ssh pi@raspberrypi.local
```

初期パスワードは [Raspbian のドキュメント](https://www.raspberrypi.org/documentation/linux/usage/users.md){:target="_blank"} に記載されていますので、それを利用してログインしてください。

### 以降は Raspberry Pi 側で実行

```
sudo timedatectl set-timezone Asia/Tokyo
sudo apt update && sudo apt upgrade -y
sudo systemctl reboot
```

## USB カメラを動作させる

USB カメラを接続します。接続先 USB ポートはどこでも構いません。

### PC 側で実行

```
ssh pi@raspberrypi.local
```

### 以降は Raspberry Pi 側で実行

```
v4l2-ctl --list-devices
```

このような出力ならば USB カメラが認識できています。

```
bcm2835-codec-decode (platform:bcm2835-codec):
        /dev/video10
        /dev/video11
        /dev/video12

BUFFALO BSWHD06M USB Camera
:  (usb-3f980000.usb-1.1.2):
        /dev/video0
        /dev/video1
```

もし認識できていない場合は以下のように `Cannot open device ...` と表示されます。USB カメラを挿し直したり、他のカメラと変更してみてください。

```
bcm2835-codec-decode (platform:bcm2835-codec):
        /dev/video10
        /dev/video11
        /dev/video12

Cannot open device /dev/video0, exiting.
```

### 以降は Raspberry Pi 側で実行

```
sudo apt install fswebcam -y
fswebcam -q --device /dev/video0 test1.jpg
python3 -m http.server 8000
```

簡易的な Web サーバが Raspberry Pi 上で起動しました。

ここでホスト側のブラウザから `http://raspberrypi.local:8000` を開き、ファイル一覧の中に表示された `test1.jpg` をクリックします。  
カメラの画像が確認できればカメラが正常に動作している確認となります。

Raspberry Pi 側に戻り `CTRL + C` を押して、Webサーバを止めます。

## SORACOM Air の接続

### PC 側で実行

```
ssh pi@raspberrypi.local
```

### 以降は Raspberry Pi 側で実行

```
curl -O https://soracom-files.s3.amazonaws.com/setup_air.sh
sudo bash setup_air.sh
```

USB ドングル型モデムに SIM を挿入し、Raspberry Pi に接続します。  
 (ポートはどこでも構いませんが、この後に接続する USB カメラとの位置で競合しないようにしてください。USB ドングル型モデム、USB カメラ共に Raspberry Pi の電源が ON 状態でもいつでも抜き挿し可能です)

**確認**: この段階で SIM の登録がまだの方は [SORACOM IoT SIM の登録](https://dev.soracom.io/jp/start/begin_soracom/#register){:target="_blank"} を参考に SIM の登録を完了してください。

USB ドングル型モデムの LED を見ながら接続状態になったのを見計らって、以下に進みます。

### 以降は Raspberry Pi 側で実行

```
ping -c 4 metadata.soracom.io
```

この時、期待される出力は以下の通りです。

```
PING metadata.soracom.io (100.127.100.127) 56(84) bytes of data.
64 bytes from 100.127.100.127 (100.127.100.127): icmp_seq=1 ttl=64 time=75.6 ms
64 bytes from 100.127.100.127 (100.127.100.127): icmp_seq=2 ttl=64 time=58.8 ms
64 bytes from 100.127.100.127 (100.127.100.127): icmp_seq=3 ttl=64 time=55.4 ms
64 bytes from 100.127.100.127 (100.127.100.127): icmp_seq=4 ttl=64 time=43.4 ms
```

これで Raspberry Pi から SORACOM Air を通じてインターネット接続が可能になりました。

### 以降は Raspberry Pi 側で実行

最後に Raspberry Pi のシステム停止を紹介します。

```
sudo systemctl halt
```

LED 点灯が落ち着いたら microUSB ケーブルを抜くことができます。

# Day2

## カメラの画像を SORACOM Harvest Files にアップロードする

USB カメラが接続されていない場合は、ここで接続します。

### SORACOM Harvest Files を有効化

* デフォルトパス: `/online-seminar/:time.jpg`
* ロール: *空*

![harvest-files-setting1](https://docs.google.com/drawings/d/e/2PACX-1vRhb4VxcHUxuxrOylVojtK7hTWvVp64U5cFnRauwhC0KLDjRfe-vuSkYRV1sHsic0QM11zdcIXRxG8X/pub?w=902&h=462)

### 以降は Raspberry Pi 側で実行

```
fswebcam -q --device /dev/video0 test2.jpg
curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@test2.jpg' harvest-files.soracom.io
```

SORACOM Harvest Files 上にファイルができているか、確認します。

![harvest-files-list1](https://docs.google.com/drawings/d/e/2PACX-1vR-ZLsYEmwBcYhBaYqJRGnDu5EJNutxmzisAWx8KG1ga8JPiY5zsbZCWCI0obhAoiTADWpLZ-Xov3Qr/pub?w=590&h=229)

ファイルを作らずにカメラから直接 SORACOM Harvest Files にアップロードしてみます。

### 以降は Raspberry Pi 側で実行

```
fswebcam -q --device /dev/video0 - | curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@-' harvest-files.soracom.io
```

SORACOM Harvest Files 上に新しくファイルができているか、確認します。

![harvest-files-list2](https://docs.google.com/drawings/d/e/2PACX-1vQjMN2nTig48k-GS34r603iV0Gv0Q60AZFgdKAuKg_Avsq2I2nNZazuSfXkVDo1EDhnUoO-1M254ayR/pub?w=607&h=258)

これで、カメラの画像を手動で SORACOM Harvest Files にアップロードできるようになりました。

## SORACOM Harvest Files と SORACOM Lagoon を連動させる

### SORACOM Harvest Files の追加設定

* Harvest Data 連携設定
    * 保存対象のパス: `/online-seminar/`

![harvest-files-setting2](https://docs.google.com/drawings/d/e/2PACX-1vQnZqsh1LtDE0-M69lByXvgVz0LepdAAKsqJAydPHBHXhcYz1PO6NAL4Nt_G7HmOnk00bn3p1eE2iRJ/pub?w=743&h=574)

### 以降は Raspberry Pi 側で実行

```
fswebcam -q --device /dev/video0 - | curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@-' harvest-files.soracom.io
```

SORACOM Harvest Data にデータが作成されているか確認します。

![harvest-data](https://docs.google.com/drawings/d/e/2PACX-1vQA612U2QirB4vz1r2irVA2vpx9KZkwLz6DaZfvOs9bP5EWS0AK09CUoZWDjtAGIb9ls7bshbzkgLrr/pub?w=658&h=172)

### SORACOM Lagoon の SORACOM Dynamic Image Panel で表示

![lagoon-dynamic-image-panel](https://docs.google.com/drawings/d/e/2PACX-1vQud_4JqPa2vmciWJwSNczK35dlqKxqjInlIGXoLe-Zh42efjVcID38IyzfHzEobyPM6xk8DMRI1waz/pub?w=638&h=538)

これで、カメラの画像を SORACOM Lagoon で表示できるようになりました。

## タイマーで定期的にカメラ撮影を行い、SORACOM Harvest Files へアップロードする

### 以降は Raspberry Pi 側で実行

```
sudo loginctl enable-linger $USER
curl -O https://gist.githubusercontent.com/ma2shita/e0545e6c1b51ac32026f1ae197226512/raw/ee292aaba9f319167e4de50a599725fdb959e34c/camera_shooting.bash
curl -O https://gist.githubusercontent.com/ma2shita/c79aad276c0b0f3eccb8e0040b5bc106/raw/2fc0171be99191d3b67490d3d167db42ffac1b1a/camera_shooting@.service
curl -O https://gist.githubusercontent.com/ma2shita/61ba5f98b3e50a025e0b51a43417d6e2/raw/258c0b8749cbba6ac3f4164049997e974ef14553/camera_shooting.socket
systemctl --user enable $PWD/camera_shooting.socket
systemctl --user enable $PWD/camera_shooting@.service
systemctl --user start camera_shooting.socket
journalctl -n 1
```

最後の `journalctl` で期待される出力は以下の通りです。

```
Nov 05 12:55:57 raspberrypi systemd[677]: Listening on Shooting camera server (listener).
```

期待通りであれば、続けます。

### 以降は Raspberry Pi 側で実行

```
echo "shooting!" | nc 127.0.0.1 19000
journalctl -n 6
```

最後の `journalctl` で期待される出力は以下の通りです。

```
Nov 05 12:56:34 raspberrypi systemd[677]: Started Shooting camera server (implementation) (127.0.0.1:53164).
Nov 05 12:56:34 raspberrypi bash[2505]: Taking a Photo!
Nov 05 12:56:36 raspberrypi bash[2505]:   % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
Nov 05 12:56:36 raspberrypi bash[2505]:                                  Dload  Upload   Total   Spent    Left  Speed
Nov 05 12:56:37 raspberrypi bash[2505]: [237B blob data]
Nov 05 12:56:37 raspberrypi systemd[677]: camera_shooting@6-127.0.0.1:19000-127.0.0.1:53164.service: Succeeded.
```

うまく動作していれば、また新たな画像が SORACOM Harvest Files にアップロードされているので、SORACOM Lagoon 上で確認することができます。

もしこの時、SORACOM Harvest Files の設定がされていない場合は、以下のような出力がされます。SIM グループの設定や SORACOM Harvest Files の設定を見直してください。

```
Nov 05 12:35:21 raspberrypi bash[1790]: {"message":"Harvest files is disabled. Please set { enabled: true }"}
```

### 以降は Raspberry Pi 側で実行

引き続き、タイマーの設定を行います。

```
curl -O https://gist.githubusercontent.com/ma2shita/ce40d5794146dbd147d5cb63eb3eb841/raw/22248196a776adac0b92d995865e3eebbd6f412a/timer_shooting.bash
curl -O https://gist.githubusercontent.com/ma2shita/7004d3f35f03a67815e734042eea9cf2/raw/4d5cbc3985a9dd4bbd494ee3b6da6b306d4aa7b1/timer_shooting.service
curl -O https://gist.githubusercontent.com/ma2shita/97519a3f0a6cb936f7480b5de11dc444/raw/9d607f3a86f1bcae07e824b821c284e0a5e30f53/timer_shooting.timer
systemctl --user enable $PWD/timer_shooting.timer
systemctl --user enable $PWD/timer_shooting.service
systemctl --user start timer_shooting.timer
```

これで、10分に1回カメラ撮影がされて SORACOM Harvest Files にアップロードされるようになりました。  
次回の起動までの残り時間といった状態は以下のコマンドで確認できます。

```
systemctl --user status timer_shooting.timer
``` 

## GPIO からの信号をきっかけにカメラ撮影 (タクトスイッチ版)

### タクトスイッチの取り付け

GPIO の BCM Pin 番号の 6 と GND に接続します。

![gpio6](https://docs.google.com/drawings/d/e/2PACX-1vR_7n4UvxIb4u1NNxaJhYPhuX8BJnN9QeMC6zZHoI8xk6VTgNZfevlezYjQ9OwhlJsl56x4VPHrv3wD/pub?w=573&h=396    )

Raspberry Pi 3 modeb B+ は [内部にプルアップ/プルダウン抵抗を持っている](https://github.com/raspberrypilearning/physical-computing-guide/blob/master/pull_up_down.md) ため、タクトスイッチのようなセンサーを直接接続することが可能です。  
また、同様のセンサーとしては CdS セル(フォトトランジスタ; 光量の強弱で抵抗値が変化)するものや、磁気式リードスイッチといったものがあり、これらの入力をトリガーに GPIO の値をhん化させることが可能です。

### 以降は Raspberry Pi 側で実行

```
sudo apt install wiringpi -y
curl -O https://gist.githubusercontent.com/ma2shita/22d5161ee03da4971560bb96078a1596/raw/596a724365b972b7689922851498ba29d4506f18/gpio6_shooting.bash
bash gpio6_shooting.bash
```

テストをしてみます。期待される出力は以下の通りです。

```
gpio6_shooting.bash
Diff!: 1 -> 0
gpio6_shooting.bash END
gpio6_shooting.bash
Diff!: 0 -> 1
gpio6_shooting.bash END
```

ボタンを押すと `0` として認識されます。そのため `1 -> 0` に変化したときに TCP localhost:19000 を呼び出す(= camera_shooting を起動) するようになっています。

あとはこのプログラムがバックグラウンドで起動するようにします

### 以降は Raspberry Pi 側で実行

```
curl -O https://gist.githubusercontent.com/ma2shita/8ee3f93a209025433c5a44bddbcdaaba/raw/2d62931aadf85807b98c3d356617798fc942ce2c/gpio6_shooting.service
systemctl --user enable $PWD/gpio6_shooting.service
systemctl --user start gpio6_shooting.service
```

EoT
