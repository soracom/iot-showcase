# IoT 体験キット 〜距離測定センサー〜

# ハンズオン用テキスト

### 株式会社ソラコム

#### [1章 ユーザーコンソールを使用してAir SIMを管理する](#section1)
[SORACOM ユーザーアカウントの作成と設定](#section1-1) <br>
[SORACOM アカウントの作成](#section1-2)<br>
[ユーザーコンソールへのログイン](#section1-3)<br>
[支払情報の設定](#section1-4)<br>
[Air SIM の登録](#section1-5)<br>
[ユーザーコンソールでの Air SIM の登録](#section1-6)<br>

#### [2章 Raspberry Piのセットアップ](#section2)

#### [3章 Air SIMを使って、インターネットに接続する](#section3)
[Raspberry Pi に USBドングルを接続する](#section3-1)<br>
[接続スクリプトのダウンロード](#section3-2)<br>
[接続確認する](#section3-3)<br>

#### [4章 ユーザーコンソールによる通信の確認](#section4)
[データ通信量と利用料金の確認](#section4-1)<br>
[Air SIMのデータ通信量の確認](#section4-2)<br>
[利用料金の確認](#section4-3)<br>
[監視機能の確認](#section4-4)<br>

#### [5章 超音波センサーを使って距離を計測する](#section5)
[超音波センサーの動作原理](#section5-1)<br>
[配線](#section5-2)<br>
[センサーをテストしてみる](#section5-3)<br>
[トラブルシュート](#section5-4)<br>

#### [6章 クラウドにデータを送る](#6-0)
[SORACOM Harvest とは](#6-1)<br>
[SORACOM Harvest を有効にする](#6-2)<br>
[プログラムのダウンロード・実行](#6-3)<br>
[データの確認](#6-4)<br>

#### [7章 Twitterと連携してみる](#section7)
[IFTTT とは](#section7-1)<br>
[IFTTTの設定](#section7-2)<br>
[レシピの作成](#seciton7-3)<br>
[SORACOM Beam の設定](#seciton7-4)<br>
[プログラムのダウンロード・実行](#section7-5)<br>

## はじめに

このハンズオンでは、SORACOMとRaspberry Piと超音波センサを用いてクラウドにデータを送り可視化したり、IFTTTを利用してデータ転送からTwitterへの呟きに連動させます。まずは、SORACOMのユーザーアカウントを作成してみましょう。

## <a name="section1">1章 ユーザーコンソールを使用してAir SIMを管理する
ここでは、SORACOM ユーザーコンソール(以降、ユーザーコンソール)を使用して、SORACOM AirのSIM (以降、Air SIM)をSORACOMのユーザーアカウントに登録します。ユーザーコンソールを使用するために、ユーザーアカウントの作成、および、支払情報の設定(クレジットカード情報)の登録を行います。


#### <a name="section1-1">1.SORACOM ユーザーアカウントの作成と設定
ユーザーコンソールを使用するためには、SORACOMユーザーアカウント(以降、SORACOMアカウント)の作成が必要となります。アカウントの作成には、メールアドレスが必要となります。

#### <a name="section1-2">SORACOM アカウントの作成
ユーザーコンソールをご利用いただくためには、まずSORACOM アカウントを作成してください。
https://console.soracom.io/#/signup にアクセスします。
「アカウント作成」画面が表示されますのでメールアドレスおよびパスワードを入力して、[アカウントを作成] ボタンをクリックします。

![アカウント作成](image/1.png)

複数人でAir SIMの管理を行う場合は、事前にメーリングリストのアドレスを取得するなど、共有のメールアドレスをご利用ください。
下記の画面が表示されるので、メールを確認してください。

![](image/2.png)

メールが届いたらリンクをクリックしてください。

![](image/3.png)

自動的にログイン画面に遷移しますので、メールアドレスとパスワードを入力してログインしてください。

#### <a name="section1-3">ユーザーコンソールへのログイン
ログイン画面が表示されるので、アカウント作成時に登録したメールアドレスとパスワードを入力し、 [ログイン] ボタンをクリックしてください。(ログイン画面が表示されない場合はブラウザで https://console.soracom.io にアクセスします。)
![](image/4.png)



以下のような「SIM管理」画面が表示されたらログイン完了です。引き続き、支払情報の設定に進みましょう！
![](image/5.png)




#### <a name="section1-4">支払情報の設定
通信料の支払い方法はクレジットカードになります。クレジットカードの情報を登録するには、メイン画面上部のユーザー名から[お支払い方法設定]を開きます。

![](image/6.png)


お支払方法で各情報を入力し、支払い方法を登録します。


![](image/7.png)


### <a name="section1-5">3.Air SIM の登録

#### <a name="section1-6">ユーザーコンソールでの Air SIM の登録

ユーザーコンソールにログインして、Air SIM の登録を行います。左上の [SIM登録] ボタンをクリックします。
![](image/8.png)


「SIM登録」画面で、Air SIM の台紙の裏面に貼ってある IMSI と PASSCODE を入力してください。

![](image/9.png)


名前、グループは空欄のままでも構いません。[登録] を押して SIM 登録を完了してください。（複数の Air SIM を続けて登録することも可能です。）

![](image/10.png)


Air SIM を登録した直後の状態は「準備完了」と表示され、通信可能な状態になっています。ただし、まだセッションは確立されていないので、セッション状態は「オフライン」になっていることを確認してください。



SORACOMではSIMの登録や「使用開始」「休止」「解約」といったモバイル通信の状態の更新をユーザー自身がユーザーコンソールを使用して、実施することが可能です。


なお、初めての通信、もしくは、ユーザーコンソール/APIで使用開始処理を行うことで、状態は「使用中」に変わります。 まだ通信を行いたくない場合は、ユーザーコンソールもしくはAPIで休止処理を行ってください。これにより「休止中」の状態となり通信は行われません。

## <a name = "section2">2章 Raspberry Piのセットアップ</a>
### <a name="raspbian-install">Raspbian のインストール</a>
#### Raspbian とは
Raspberry Pi で使用する事ができる OS は様々なものがありますが、最も多く使われているのは、[Raspbian](https://www.raspbian.org) と呼ばれる Raspberry Pi での動作に最適化された Debian ベースの Linux です。

SORACOMのハンズオンでは、特に理由がない限りは Raspbian を利用する前提でスクリプトや手順が作られています。ここでは、Raspbian のインストール(MicroSDへの書き込み)方法について、解説します。

#### 準備
必要なものは以下となります。

- PC(Mac、Windowsなど)
- SDカードリーダー/ライター (PC本体にSDスロットがある場合には不要)
- Micro SD カード (8GB以上が望ましい)
 ※もし初代Raspberry Piを利用する場合には、通常サイズのSDカードを用意して下さい

#### OSイメージファイルのダウンロード
Raspbian は、デスクトップGUI環境を含む通常版と、CUIのみのLite版があります。
本ハンズオンでは Raspberry Pi にキーボードやマウスを接続して操作を行わないので、Lite版を利用します。

Raspbian Lite の イメージは、下記URLのミラーサイトからダウンロードするとよいでしょう。
http://ftp.jaist.ac.jp/pub/raspberrypi/raspbian_lite/images/

- [2016-05-27バージョン(292MB)](http://ftp.jaist.ac.jp/pub/raspberrypi/raspbian_lite/images/raspbian_lite-2016-05-31/2016-05-27-raspbian-jessie-lite.zip) をダウンロード
- zipファイルを解凍して、イメージファイル(2016-05-27-raspbian-jessie-lite.img)を取り出す

#### イメージの書き込み(Macの場合)
##### SDカードの接続
PC本体にSDカードスロットがある場合には、変換アダプタを介して接続して下さい。
![SDカードアダプタ](../common/image/raspbian-install-001.jpg) ![SDカードスロット](../common/image/raspbian-install-002.jpg)
もしPC本体にSDカードスロットがない場合には、USB接続カードリーダー/ライターなどを使って接続して下 さい。
![USB接続カードリーダー/ライター](../common/image/raspbian-install-003.jpg)

##### disk番号の確認
接続をしたら、ターミナルを起動して diskutil list というコマンドを実行します。

```
~$ diskutil list
(略) :
/dev/disk4 (external, physical):
   #:                       TYPE NAME                    SIZE       IDENTIFIER
   0:     FDisk_partition_scheme                        *15.6 GB    disk4
   1:                 DOS_FAT_32 NO NAME                 15.6 GB    disk4s1
```

この場合、容量やフォーマットから disk2 がSDカードである事がわかります。環境によって disk3 であったり disk4 であったりする事がありますので、適宜読み替えて下さい。

> 注意： もし誤って disk0 や disk1 に書き込んでしまった場合、OSが起動で きなくなったりする可能性がありますので、十分注意して下さい

##### イメージファイルの書き込み
diskの番号が確認できたら、パーティションをマウント解除し、disk全体にイメージを書き込みます。 書き込みが終わったら eject して、SDカードを取り外します。

```
~$ diskutil unmount disk4s1
Volume NO NAME on disk4s1 unmounted
~$ cd Downloads (イメージファイルを解凍した場所mに応じて読み替えてください)
~/Downloads$ sudo dd if=2016-05-27-raspbian-jessie-lite.img of=/dev/rdisk4 bs=1m
Password: (パスワードを打ち込む)
1048576 bytes transferred in 0.427695 secs (2451691 bytes/sec)
1323+0 records in
1323+0 records out
1387266048 bytes transferred in 128.769184 secs (10773277 bytes/sec)
~/Downloads$ diskutil eject disk4
Disk disk4 ejected
```

#### イメージの書き込み(Windowsの場合)
##### SDカードの接続
PC本体にSDカードスロットがない場合には、USB接続カードリーダー/ライターなどを使って接続して下 さい。
![USB接続カードリーダー/ライター](../common/image/raspbian-install-003.jpg)

##### Win32 Disk Imager のインストール
[Win32 Disk Imager](https://osdn.jp/projects/sfnet_win32diskimager/)のサイトから、インストーラーをダウンロード・実行します。

##### イメージファイルの書き込み
Win32 Disk Imager を起動し、右上のDeviceがSDカードのドライブ名である事を確認します。
ドライブ名の左のボタンを押し、イメージファイルの場所を指定します。
Write を押すと、SDカードへの書き込みが開始されます。

![Win32 Disk Imager](../common/image/raspbian-install-004.png)

しばらくして、Write Successful. と表示されれば、書き込み完了です。

![Win32 Disk Imager](../common/image/raspbian-install-005.png)

### <a name="ssh-login">Raspberry Pi への ログイン</a>
Raspberry Pi へ SSH を使ってログインします。
ユーザ名とパスワードは、それぞれ pi / raspberry になります。

#### 接続先の調べ方
Raspberry Pi は接続元の PC と同じネットワークに有線LANで接続されているものとします。

接続元のPCが以下のいずれかであれば、Raspberry Pi のIPアドレスが分からなくてもログインが可能です。

- Mac を使用している
- Linux 等でAvahiデーモンが動作している
- Windows で Bonjour サービスをインストールしている(iTunesのインストールでもOK)
- Windows10 で mDNS を有効にしている

上記の場合、raspberrypi.local というホスト名でLANに接続された Raspberry Pi に接続が出来ます。

もし上記に該当しない場合、HDMIケーブルを使ってPCモニターやテレビなどに Raspberry Pi を接続し、下記のように画面上に表示される IP アドレスを確認する事が出来ます。

```
My IP address is 192.168.1.xxx
```

#### ssh接続
接続先がわかったら、自分の端末からRaspberry Piに接続(SSH)します。

MacやLinuxの場合には、ターミナルを立ち上げ、以下のコマンドを実行してください。

```
$ ssh pi@raspberrypi.local
The authenticity of host 'raspberrypi.local (fe80::bb8:70cb:474d:220%en0)' can't be established.
ECDSA key fingerprint is SHA256:MOOy0pXAzbJMFh4ZzkYzQS7Dl6YeU2y6TT0mRYKb/MA.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added 'raspberrypi.local' (ECDSA) to the list of known hosts.
pi@raspberrypi.local's password: (raspberry と入力)

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Sun Jun 26 07:09:55 2016 from 192.168.1.101
pi@raspberrypi:~ $
```

Windowsの場合は、[TeraTerm](https://osdn.jp/projects/ttssh2/)を使用するといいでしょう。

パッケージをダウンロードしてインストールした後、プログラムを立ち上げて以下のように接続先を指定して接続します。

![TeraTerm接続先](../common/image/connect-air-001.png)![TeraTerm認証情報](../common/image/connect-air-002.png)

## <a name="section3">3章 Air SIMを使って、インターネットに接続する
ここでは、先ほど登録したSORACOM AirのSIM (以降、Air SIM)を使用して、Raspberry Piからインターネットに接続します。

### <a name = "section3−1">1.	Raspberry Pi に USBドングルを接続する

![](image/3-1.jpg)

Air SIMを取り外します。Air SIMの端子を触らないように気をつけます。

![](image/3-2.jpg)
![](image/3-3.jpg)

#### FS01BUの場合

![](image/3-4.jpg)
![](image/3-5.jpg)


#### Air SIMをドングルから取り出す際の注意

![](image/3-6.jpg)

#### AK-020の場合
![](image/AK-020.PNG)

###  <a name = "section3−2">2. 接続スクリプトのダウンロード

> ここから先の作業は、Raspberry Pi にログインした状態でコマンドを実行してください

以下に、モデムの初期化、APNの設定、ダイアルアップなどを行うスクリプトが用意されています。

https://soracom-files.s3.amazonaws.com/setup_air.sh

以下のコマンドを実行し、このスクリプトをダウンロードし、接続用シェルスクリプトを作成します。

#### コマンド
```
curl -O https://soracom-files.s3.amazonaws.com/setup_air.sh
sudo bash setup_air.sh
```

#### 実行結果
```
pi@raspberrypi:~ $ curl -O https://soracom-files.s3.amazonaws.com/setup_air.sh

  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  4040  100  4040    0     0  17211      0 --:--:-- --:--:-- --:--:-- 17264
pi@raspberrypi:~ $ sudo bash setup_air.sh
--- 1. Check required packages
wvdial is not installed! installing wvdial...
  :
  :
ok.

--- 2. Patching /lib/systemd/system/ifup@.service
ok.

--- 3. Generate config files
Adding network interface 'wwan0'.
Adding udev rules for modem detection.
ok.

--- 4. Connect
Found un-initilized modem. Trying to initialize it ...
Now you are all set.

Tips:
 - When you plug your usb-modem, it will automatically connect.
 - If you want to disconnect manually or connect again, you can use 'sudo ifdown wwan0' / 'sudo ifup wwan0' commands.
 - Or you can just execute 'sudo wvdial'.
```

これで、自動的に 3G モデムが初期化され、Raspberry Pi が SORACOM 経由でインターネットに接続します。 また、再起動時やモデムを接続した際にも、自動的に接続されるようになっています。

**このスクリプトをインストールするとRaspberry Pi が起動すると自動的にAir SIMでネットワーク接続が行われるようになります。データの送受信には通信料金が発生しますのでご注意ください。**

### <a name="section3-3">接続確認する</a>

接続が出来ている時は、ppp0インターフェースが存在しているはずなので、以下のコマンドで接続状況を確認出来ます。

#### コマンド
```
ifconfig ppp0
```

#### 実行結果
```
pi@raspberrypi:~ $ ifconfig ppp0
ppp0      Link encap:Point-to-Point Protocol
          inet addr:10.xxx.xxx.xxx  P-t-P:10.64.64.64  Mask:255.255.255.255
          UP POINTOPOINT RUNNING NOARP MULTICAST  MTU:1500  Metric:1
          RX packets:133 errors:0 dropped:0 overruns:0 frame:0
          TX packets:134 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:3
          RX bytes:2092 (2.0 KiB)  TX bytes:4039 (3.9 KiB)
```

"inet addr" の後ろに表示されているのが、デバイスに割り当てられた IP アドレスとなります。

次に、インターネットへの疎通が出来るかどうかを確認しましょう。

Google Public DNS (8.8.8.8) への到達性を ping コマンドで調べます。

#### コマンド

※下記コマンドは、一行ずつ実行してください

```
ping 8.8.8.8
(Ctrl+C で止める)
```

#### 実行結果
```
pi@raspberrypi:~ $ ping 8.8.8.8
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=55 time=343 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=55 time=342 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=55 time=361 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=55 time=340 ms
^C
--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3002ms
rtt min/avg/max/mdev = 340.908/347.329/361.814/8.434 ms
```

ping コマンドの応答からインターネットへの疎通が取れていることが確認できました。

## <a name = "section4"> 4章 ユーザーコンソールによる通信の確認
インターネットに接続できましたので、ユーザーコンソールからデータ通信量、利用料金を確認して、監視機能を設定しましょう。


### <a name = "section4-1">1.	データ通信量と利用料金の確認

#### <a name = "section4-2">Air SIMのデータ通信量の確認
ユーザーコンソールでは、データ通信量をSORACOM AirのSIM(以降、Air SIM)ごとにチャート形式で確認することができます。<br>
データ通信量を確認したいAir SIMにチェックを入れ [詳細] ボタンをクリックします。
![](image/4-1.png)
[SIM 詳細] ダイアログが表示されますので、[通信量履歴] タブを開きます。 データ使用量は、表示期間を変更することもできます。

 	データ通信量が反映されるまでに5〜10分かかります。
先ほどのデータ通信が反映されていない場合はしばらくお待ちください。




![](image/4-2.png)

#### <a name = "section4-3">利用料金の確認

ユーザーコンソールからデータ通信料金と基本料金を確認できます。
メイン画面上部のナビゲーションバーから [課金情報] を選択します。

![](image/4-3.png)



表示されている時間時点の課金情報を確認することができます。

![](image/4-4.png)


また、画面下部にある [データ使用量実績データを CSV 形式でダウンロード] から、期間を選択して [ダウンロード] ボタンをクリックすることで、基本料金、転送データ量などの詳細を確認することができます。


```
 	請求額詳細のCSVには、IMSIごとに以下の項目が記載されています。
✓	date (日付)
✓	billItemName (basicCharge は基本料金、upload/downloadDataChargeは転送データ量に対する課金)
✓	quantity (数量: upload/downloadDataChargeの場合の単位はバイト)
✓	amount (金額: 日ごとの料金。この項目の総合計が、月額請求額となります)
✓	タグ、グループ
```

#### <a name = "section4-4">監視機能の確認
通信量にしきい値を設定し、超えた場合にメールでの通知と通信帯域制限をすることができます。監視できる項目は以下のとおりです。
●	各 SIM の日次通信量
●	各 SIM の今月の合計通信量
●	全ての SIM の今月の合計通信

例えば、全ての Air SIM の合計通信量が5000MB以上になった場合にメール通知を受けたい場合や、ある Air SIM の日次通信量が100MB以上になった場合にはその日の通信速度を制限するというような処理を行いたい場合に、この機能を利用することができます。

通信量はメガバイト単位（1以上の整数値）で入力できます。メールの宛先は登録されているメールアドレスです。通信速度を制限した場合は s1.minimum になり、解除された際は、 s1.standard に復帰します。 (APIを用いた場合には、制限時の通信速度、制限解除時の通信速度を任意に設定することも可能です)

Air SIMに監視の設定をしましょう。当ハンズオンの間に通知がくるように、1MiBで設定します。

「SIM詳細」画面で [監視] タブを開き、[SIM] をクリックして、監視設定を行ったら [設定を更新] ボタンをクリックして保存します。


![](image/4-5.png)



ここでの設定は、対象のAir SIMごとに有効になります。

```
 	監視の設定は、以下の3つを対象することができます。
✓	Air SIM<br>
✓	(Air SIMの所属する)グループ<br>
✓	(登録した)全てのSIM
```


すぐに、メール通知を確認したい場合は、Raspberry Piから以下のコマンドを実行して、1MiBのダウンロードを実施してみてください。

```
pi@raspberrypi ~ $ wget http://soracom-files.s3.amazonaws.com/1MB
```

以下のような通知が届きます。(通知は最大で5分程度かかります。)

![](image/4-6.png)

ここまでで、1〜4章までが完了しました。

- 1章 ユーザーコンソールを使用してAir SIMを管理する<br>
- 2章 Raspberry Piのセットアップ<br>
- 3章 Air SIMを使って、インターネットに接続する<br>
- 4章 ユーザーコンソールによる通信の確認<br>

## <a name = "section5">5章 超音波センサーを使って距離を計測する

#### <a name = "section5-1">1.	超音波センサーの動作原理
超音波の反射時間を利用して非接触で測距するモジュールです。外部からトリガパルスを入力すると超音波パルス（８波）が送信され、出力された反射時間信号をマイコンで計算することによって距離を測ることができます。
![](image/5-1.png)

- 具体的にはセンサーの Trig ピンにパルス(短い時間)電圧をかけて測定を開始
- EchoピンがHIGHである時間の長さを計測

#### <a name = "section5-2">2.	配線

1.必要なパーツが揃っているか確認しましょう

- 超音波センサー HC-SR04 (スピーカのような形の青い基板)

- ブレッドボード(穴がたくさん空いた白い板)

- ジャンパーコード(オス-メス/赤黒黄青の４本)

![](image/5-2.png)


2.最初に、センサーをブレッドボードに刺します(端から２列目に刺すと安定します)

![](image/5-3.png)

3.ジャンパーコードを刺していきます(センサーの表面のVCC→GNDの順に、赤・青・黄・黒)

![](image/5-5.png)

4.ラズパイにケーブルを刺します<br>

●	刺すピンを間違えると故障の原因になるので、十分気をつけてください<br>
●	赤いケーブルを最後に接続してください

![](image/5-6.png)

#### <a name = "section5-3">3.センサーをテストしてみる
以下のコマンドで、プログラムをダウンロード・実行し、正しくセンサー値が読み出せるか試しましょう

```
pi@raspberrypi ~ $ wget http://soracom-files.s3.amazonaws.com/sensor_test.py
--2016-03-23 18:07:17--  http://soracom-files.s3.amazonaws.com/sensor_test.py
Resolving soracom-files.s3.amazonaws.com (soracom-files.s3.amazonaws.com)... 54.231.225.133
Connecting to soracom-files.s3.amazonaws.com (soracom-files.s3.amazonaws.com)|54.231.225.133|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 870 [text/plain]
Saving to: ‘sensor_test.py’

sensor_test.py      100%[===================>]     870  3.72KB/s   in 0.2s

2016-03-23 18:07:19 (3.72 KB/s) - ‘sensor_test.py’ saved [870/870]

pi@raspberrypi ~ $ python sensor_test.py
distance: 38.6 cm
distance: 38.9 cm
distance: 2.3 cm  ← センサーの前に手をかざして変化を確認しましょう
     :
```

#### <a name = "section5-4">4.トラブルシュート

何も出力されない場合<br>
接続するピンを間違えている可能性が高いです<br>
もう一度ケーブルを接続する位置を確かめましょう


## <a name="6-0">6章 SORACOM Harvest で可視化してみる</a>
SORACOM のサービス、Harvest を体験してみましょう。

### <a name="6-1">SORCOM Harvest とは、</a>
SORACOM Harvest(以下、Harvest) は、IoTデバイスからのデータを収集、蓄積するサービスです。

SORACOM Air が提供するモバイル通信を使って、センサーデータや位置情報等を、モバイル通信を介して容易に手間なくクラウド上の「SORACOM」プラットフォームに蓄積することができます。
保存されたデータには受信時刻や SIM の ID が自動的に付与され、「SORACOM」のユーザーコンソール内で、グラフ化して閲覧したり、API を通じて取得することができます。なお、アップロードされたデータは、40日間保存されます。

![](https://soracom.jp/img/fig_harvest.png)

> 注意: SORACOM Harvest を使うには追加の費用がかかります
> 書き込みリクエスト: 1日 2000リクエストまで、1SIMあたり 1日5円
> 1日で2000回を超えると、1リクエスト当り0.004円

### <a name="6-2">SORACOM Harvest を有効にする</a>
SORACOM Harvest を使うには、Group の設定で、Harvest を有効にする必要があります。

グループ設定を開き、SORACOM Harvest を開いて、ON にして、保存を押します。

![](image/8-1.png)

### <a name="6-3">プログラムのダウンロード・実行</a>

#### コマンド
```
sudo apt-get install -y python-pip libssl-dev
curl -O http://soracom-files.s3.amazonaws.com/send_to_harvest.py
python send_to_harvest.py
```

#### 実行結果
```
pi@raspberrypi:~ $ sudo apt-get install -y python-pip libssl-dev
:
pi@raspberrypi:~ $ curl -O http://soracom-files.s3.amazonaws.com/send_to_harvest.py
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  2443  100  2443    0     0   3966      0 --:--:-- --:--:-- --:--:--  3972
pi@raspberrypi:~ $ python send_to_harvest.py
- 距離を計測します
距離: 15.1 cm
- データを送信します
<Response [201]>

- 距離を計測します
距離: 4.4 cm
- データを送信します
<Response [201]>
```

> 正常にデータが送信されたらレスポンスコードが 201 になります

#### トラブルシュート

以下のようなエラーメッセージが出た場合には、設定を確認して下さい

* `{"message":"No group ID is specified: xxxxxxxxxxxxxxx"}` → SIM にグループが設定されていない
* `{"message":"Configuration for SORACOM Harvest is not found"}` → グループで Harvest を有効にしていない

### <a name="6-4">データの確認</a>
コンソールから、送信されたデータを確認してみましょう。

SIMを選択して、操作から「データを確認」を選びます。

![](image/8-2.png)

グラフが表示されていると思います。

![](image/8-3.png)

スクリプトのデフォルト設定では５秒に一度データが送信されるので、自動更新のボタンをオンにすると、グラフも自動的に更新されます。

とても簡単に可視化が出来たのがおわかりいただけたと思います。

## <a name = "section7">7章 Twitterと連携してみる

IFTTTというサービスを使うと、デバイスから簡単に様々なサービスと連携を行う事が出来ます。
この章では、センサーで障害物を検知した際に、SORACOM Beam 経由で IFTTT の Maker Channel を呼び出し、Twitter へとリアルタイムに通知を行ってみましょう。

#### <a name = "section7-1">1.	IFTTT とは
IFTTT(https://ifttt.com/) とは、IF-This-Then-That の略で、もし「これ」が起きたら「あれ」を実行する、つまり「これ」がトリガーとなって、「あれ」をアクションとして実行する、サービスとなります。
様々なサービスや機器と連携していて、何度かクリックするだけで簡単な仕組みを作る事が出来ます。
今回のハンズオンでは、HTTPSのリクエストをトリガーとして、アクションとして Twitter につぶやくために、IFTTTTを使います。

#### <a name = "section7-2">2.	IFTTT の設定
まずアカウントをお持ちでない方は、IFTTT のサイト https://ifttt.com/ で、Sign Up してください。

![](image/iffft_wh00.png)

#### <a name = "section7-3">3.	IFFFT アプレットの作成
次にサービス同士の組み合わせ(Applet = アプレットと呼ばれます)を作成します。
https://ifttt.com/my_applets にアクセスして、右上の New Applet をクリックします。

表示された文字列から this をクリックし、表示された検索ボックスで webhooks 検索します。次に表示された Webhooks のパネルを選択してください。

![](image/iffft_wh02.png)

トリガーとして Receive a web request が書いてあるパネルを選択します。
![](image/iffft_wh03.png)


Event Name を設定します(ここでは sensor とします)

これでトリガーの設定は完了です。次にアクションとして、Twitter の設定を行います。

that をクリックし、表示された検索ボックスで Twitter を検索します。次に表示された Twitter のパネルを選択してください。
IFFFT で初めて Twitter と連携する場合は、認証画面に遷移するのでご自身のアカウントでログインして認証を完了する必要があります。

アクションは左上の、Post a tweet を選んでください。 ![](image/iffft_wh10.png)

Twitter の Tweet text には、例えば下記のような文言を入れてみてください。グレーの ``Value1`` などの文字は ``Add ingredient`` をクリックすることにより選択して入力することも可能です。
![](image/iffft_wh11.png)

> センサーの状態が "{{Value1}}" に変化しました(前回からの経過時間:{{Value2}}秒) 時刻:{{OccurredAt}} #soracomhandson

最後に Webhooks のページ https://ifttt.com/maker_webhooks を開いて、右上の Documentation をクリックしたあとに表示される画面で key を確認します(後ほど使います)

![](image/iffft_wh13.png)

![](image/iffft_wh14.png)



#### <a name = "section7-4">4.	SORACOM Beam の設定</a>

IFTTTへのデータ転送を設定します。IFTTTへのデータ転送は[HTTPエントリポイント]を使用します。[SORACOM Beam 設定] から[HTTPエントリポイント]をクリックします。
![](image/7-8.png)

表示された画面で以下のように設定してください。

- 設定名： `IFTTT` (別の名前でも構いません)
- エントリポイントパス： `/`
- 転送先プロトコル： *HTTPS*
- 転送先ホスト名： `maker.ifttt.com`
- 転送先パス： `/trigger/sensor/with/key/{maker_key}/`
  - {maker_key} は、Maker Channelをコネクトすると発行される文字列です。 https://ifttt.com/maker から確認できます。

![](image/7-9.png)


[保存]をクリックします。
以上でBeamの設定は完了です。

```
 	ここで設定した通り、IFTTTへのアクセスURLは、{maker_key}を含んでいますが、Beamを使用することで、デバイスに認証情報をもたせる必要がなくなります。
これにより、認証情報が盗まれるリスクを回避できます。また、変更になった場合もたくさんのデバイスに手を入れることなく、変更を適用することができます。
```

#### <a name = "section7-5">5.	プログラムのダウンロード・実行

IFTTTへの送信をおこないます。
以下のコマンドを実行し、プログラムをダウンロード・実行し、Beamを経由して正しくデータが送信できるか確認しましょう。

SORACOM Harvest の場合と同様に、Beamを使用する(「send_to_ifttt.py」の実行時)には、SORACOM Airで通信している必要があります。

```
pi@raspberrypi ~ $ wget http://soracom-files.s3.amazonaws.com/send_to_ifttt.py
--2016-03-24 03:24:30--  http://soracom-files.s3.amazonaws.com/send_to_ifttt.py
soracom-files.s3.amazonaws.com (soracom-files.s3.amazonaws.com) をDNSに問いあわせています...<br>
 54.231.226.26
soracom-files.s3.amazonaws.com (soracom-files.s3.amazonaws.com)|54.231.226.26|:80 に接続しています... 接続しました。
HTTP による接続要求を送信しました、応答を待っています... 200 OK<br>
長さ: 2457 (2.4K) [text/plain]
`send_to_ifttt.py' に保存中

100%[====================================================>] 2,457       --.-K/s 時間 0s

2016-03-24 03:24:31 (31.7 MB/s) - `send_to_ifttt.py' へ保存完了 [2457/2457]

pi@raspberrypi ~ $ python send_to_ifttt.py
- 条件設定
障害物を 10 cm 以内に 3 回検知したら IFTTT にデータを送信します
センサーを手で遮ったり、何か物を置いてみたりしてみましょう
- 準備完了
距離(cm): 5.3 <= 10 , 回数: 1 / 3
距離(cm): 5.6 <= 10 , 回数: 2 / 3
距離(cm): 5.2 <= 10 , 回数: 3 / 3
- ステータスが 'in'(何か物体がある) に変化しました
- Beam 経由でデータを送信します
status changed to 'in' : {"value3": "", "value2": "5", "value1": "in"}
<Response [200]> ← 正常にデータが送信されたら 200 になります
距離(cm): 54.9 > 10 , 回数: 1 / 3
距離(cm): 55.2 > 10 , 回数: 2 / 3
距離(cm): 55.3 > 10 , 回数: 3 / 3
- ステータスが 'out'(何も物体がない) に変化しました
- Beam 経由でデータを送信します
status changed to 'out' : {"value3": "", "value2": "9", "value1": "out"}
<Response [200]> ← 正常にデータが送信されたら 200 になります
```

すると、下記のようなツイートが行われます。
![](image/7-10.png)



ハッシュタグで検索してみましょう
https://twitter.com/search?f=tweets&q=%23soracomhandson&src=typd


おめでとうございます！皆さんは、IoT 体験キット 〜距離測定センサー〜を完了しました。SORACOMを使ったハンズオンを楽しんで頂けましたでしょうか？

さらにSORACOMに興味を持っていただいた方は、以下の Getting Startedもご覧ください！

SORACOM Getting Started
https://dev.soracom.io/jp/start/