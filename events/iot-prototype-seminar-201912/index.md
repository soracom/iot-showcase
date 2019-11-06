# Let’s try IoT プロトタイピング！ オンライン講座 〜定点カメラデバイスを作ろう〜

## イベントページ

- [Day1]()
- [Day2]()

# Day1

## Raspberry Pi のセットアップ

### Raspbian (OS) のダウンロードと microSD カードへの書き込み

* [Download Raspbian](https://www.raspberrypi.org/downloads/raspbian/) のページから **Raspbian Buster Lite** (約430MB) をダウンロードして、ZIP ファイル内の `.img` ファイルを取り出します。
* [balenaEtcher](https://www.balena.io/etcher/) 等のイメージ書込みソフトウェアを利用して、 先ほどの `.img` ファイルを microSD カードに書き込みます。

### 書き込んだ後の設定

PC 上で以下二つのファイルを作成します。

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

---

## Raspberry Pi の起動から OS の最新化

microSD を Raspberry Pi に取り付け、電源を入れます。  
しばらく経ってから Mac もしくは Windows 10 最新版 で以下のように入力し、Raspberry Pi へリモートログインを行います。

※Windows 10の以前の場合(最新版でない場合も同様)は、 Apple iTunes をインストールしてください。 (mDNS が使える必要があります)

### PC 側で実行

```
ssh pi@raspberrypi.local
```

### 以降は Raspberry Pi 側で実行

```
sudo timedatectl set-timezone Asia/Tokyo
sudo apt update && sudo apt upgrade -y
sudo systemctl reboot
```

## USB カメラを動作させる

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

### 以降は Raspberry Pi 側で実行

```
sudo systemctl halt
```

これでカメラの動作の確認、そして Raspberry Pi のシステム停止ができました。

# Day2

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

## カメラの画像を SORACOM Harvest Files にアップロードする

USB カメラが接続されていない場合は、ここで接続します。

### SORACOM Harvest Files を有効化

TODO

### 以降は Raspberry Pi 側で実行

```
fswebcam -q --device /dev/video0 test2.jpg
curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@test2.jpg' harvest-files.soracom.io
```

SORACOM Harvest Files 上にファイルができているか、確認します。

TODO

ファイルを作らずにカメラから直接 SORACOM Harvest Files にアップロードしてみます。

### 以降は Raspberry Pi 側で実行

```
fswebcam -q --device /dev/video0 - | curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@-' harvest-files.soracom.io
```

SORACOM Harvest Files 上に新しくファイルができているか、確認します。

これで、カメラの画像を手動で SORACOM Harvest Files にアップロードできるようになりました。

## SORACOM Harvest Files と SORACOM Lagoon を連動させる

### SORACOM Harvest Files の追加設定

TODO

### 以降は Raspberry Pi 側で実行

```
fswebcam -q --device /dev/video0 - | curl -X POST -H 'Content-Type: image/jpeg' --data-binary '@-' harvest-files.soracom.io
```

SORACOM Harvest Data にデータが作成されているか確認します。

### SORACOM Lagoon の SORACOM Dynamic Image Panel で表示

TODO

これで、カメラの画像を SORACOM Lagoon で表示できるようになりました。

---

## タイマーで定期的にカメラ撮影を行い、SORACOM Harvest Files へアップロードする

### 以降は Raspberry Pi 側で実行

```
sudo loginctl enable-linger $USER
mkdir -p ~/.config/systemd/user
curl -O https://gist.githubusercontent.com/ma2shita/e0545e6c1b51ac32026f1ae197226512/raw/ee292aaba9f319167e4de50a599725fdb959e34c/camera_shooting.bash
curl -O https://gist.githubusercontent.com/ma2shita/c79aad276c0b0f3eccb8e0040b5bc106/raw/2fc0171be99191d3b67490d3d167db42ffac1b1a/camera_shooting@.service
curl -O https://gist.githubusercontent.com/ma2shita/61ba5f98b3e50a025e0b51a43417d6e2/raw/258c0b8749cbba6ac3f4164049997e974ef14553/camera_shooting.socket
curl -O https://gist.githubusercontent.com/ma2shita/ce40d5794146dbd147d5cb63eb3eb841/raw/22248196a776adac0b92d995865e3eebbd6f412a/timer_shooting.bash
curl -O https://gist.githubusercontent.com/ma2shita/7004d3f35f03a67815e734042eea9cf2/raw/4d5cbc3985a9dd4bbd494ee3b6da6b306d4aa7b1/timer_shooting.service
curl -O https://gist.githubusercontent.com/ma2shita/97519a3f0a6cb936f7480b5de11dc444/raw/9d607f3a86f1bcae07e824b821c284e0a5e30f53/timer_shooting.timer
ln -s ~/camera_shooting@.service ~/.config/systemd/user/
ln -s ~/camera_shooting.socket ~/.config/systemd/user/
systemctl --user enable camera_shooting.socket
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

もしこの時、SORACOM Harvest Files の設定がされていない場合は、以下のような出力がされます。SIM グループの設定や SORACOM Harvest Files の設定を見直してください。

```
Nov 05 12:35:21 raspberrypi bash[1790]: {"message":"Harvest files is disabled. Please set { enabled: true }"}
```

これで、10分に1回カメラ撮影がされて SORACOM Harvest Files にアップロードされるようになりました。

---

## GPIO からの信号をきっかけにカメラ撮影 (タクトスイッチ版)

### タクトスイッチの取り付け

TODO

### 以降は Raspberry Pi 側で実行

```
sudo apt install wiringpi -y
curl -O https://gist.githubusercontent.com/ma2shita/22d5161ee03da4971560bb96078a1596/raw/596a724365b972b7689922851498ba29d4506f18/gpio6_shooting.bash
bash gpio6_shooting.bash
```

テストをしてみます。期待される出力は以下の通りです。

```
TODO
```

あとはこのプログラムがバックグラウンドで起動するようにします

### 以降は Raspberry Pi 側で実行

```
curl -O https://gist.githubusercontent.com/ma2shita/8ee3f93a209025433c5a44bddbcdaaba/raw/2d62931aadf85807b98c3d356617798fc942ce2c/gpio6_shooting.service
ln ~/gpio6_shooting.service ~/.config/systemd/user/
systemctl --user enable gpio6_shooting.timer
systemctl --user start gpio6_shooting.timer
```

EoT
