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
