# GPS トラッカー
WioLTE を GPS トラッカーとして使うスケッチです。GPSモジュールを接続して電源を入れれば、GPSの座標を SORACOM Harvest に送信します。SORACOM Harvest の位置情報データ表示モードを使うことで、簡単に GPS データの可視化が行えます。
GPSモジュールが接続されていない場合や、GPS モジュールの測位が出来ていない場合には、LTE の基地局情報を元に大雑把な位置を求めることが出来ます。

![地図](../../../images/projects/WioLTE/gps-tracker/map.jpg)

# 配線
UART 端子に GPS モジュールを接続します。
D20 端子にボタンを接続しておくと、ボタンを押した時にすぐデータを送信します。

![配線](../../../images/projects/WioLTE/gps-tracker/gps-tracker.jpg)
