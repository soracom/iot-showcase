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
