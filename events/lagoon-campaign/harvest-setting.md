## センシングデータを SORACOM Harvest で可視化

### SIMグループを作成
SORACOM Webコンソール で 左上[Menu] > [SIM グループ]を選択します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSA_Ja2Y2IDFu45-17hHpUVh1Y8dHO0gOIWeG20RcJ3xRN6rgBc1RPPFDyS08oCTFb8FrJYMVjWk23M/pub?w=714&amp;h=400">

[追加] で、SIMグループを作成します (グループ名 harvest もしくは任意でかまいません)。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTwB_bgNPCWCNYJ5BLTFhpvrxjtW--eyDiIpmik6YhI7cilfXp6Jk1rtYN2xq2IANPCcfRVyy_GKfmx/pub?w=639&amp;h=616">

### SORACOM Harvest の設定
先ほど作成した SIMグループ をクリックし、 SORACOM Harvest の設定を ON にして保存をクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSlf4hxEqJzmGDIY7bV0edY7yeWIsaCaNFdOlXejaLh3UBxC_I2mYRj--7ib8IAXQK_kC9vejyZE09R/pub?w=839&amp;h=680">

SORACOM Webコンソール で 左上[Menu] > [SIM 管理]を選択します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vRpLdUVrbLhOoeQ26uoYXS9z-hvfmirP2R-XaIQrPh-_k5TvQ3l-WH_DMpw8wQZIAkaYx59J1sjsDI1/pub?w=692&amp;h=404">

Wio LTE に取り付けている SIM を選択し > [操作] > [所属グループ変更] で、先ほど作ったグループに変更します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTnIaV_8SHw918zxurqj5ZZ6STDT5RBsI4sfhdeNrDAbCyQDJ7-T8HjFHGzAjkCkHOzyCgR9deJbRoX/pub?w=502&amp;h=712">

下記のように Wio LTE に取り付けている SIM の “グループ” が、先ほど作った SIM グループ名になっていれば成功です
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSBLqovlcUNH1nUyf2S_07_pvRDp4RBp2UMHqrbXxzJRPNcwS9xphqca5prWxDR-J1emEE2uWORpreb/pub?w=541&amp;h=468">

### SORACOM Harvest でデータを確認
Wio LTE に取り付けている SIM を SORACOM Webコンソール上で選択し [操作] > [データを確認]を選択します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQWBdzfKyvYRijHcnzkZuWNnMtcHphbdQ-tQNwXG1fhrJcv29fEs4WlStoTDlvDw5CGDnvs6Ax9Jyyg/pub?w=546&amp;h=499">

下図のように SORACOM Harvest 上で温湿度のデータ、ドアの開閉状況のデータを表示しています。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQnel3b-6Q_NlVfWl19749zoRV3W_mNbloqyQUVLmAQktxG1_Dvzz7EUL6RJUICnEUAQicqQk2w3nNw/pub?w=934&amp;h=393">
