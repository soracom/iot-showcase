# SORACOM Harvest を使用した IoT データの蓄積、保存

本章では SORACOM Harvest を使用して Raspberry Piからのデータを受信、蓄積する様子を確認します。

## ハンズオンのゴール

Raspberry Piからデータを送信し、Harvestでデータが保存されることを確認します。

![3-harvest.png](images/3-harvest.png)

## 1. SORACOM Harvest の設定をする

[SORACOM Webコンソール](https://console.soracom.io/) で 左上[Menu] > [SIM グループ]をクリックします

![soracom-menu](https://docs.google.com/drawings/d/e/2PACX-1vRhgmsjqpncv2HQ0jAZwiYf0knTfvmCMl6x_flrdeGQV4N60trp8M981gCAfitVSmXU4tqAYm6MmyRb/pub?w=331&h=410)
![soracom-menu-sim-group](https://docs.google.com/drawings/d/e/2PACX-1vTqI-f2K8n-TuUvVEGPnmDcFxG2f87so3Qfe5K11sn0pXG8Q4v2lJX0UT9tjlH7sDQRb1FC7aFfckjb/pub?w=353&h=290)

[追加] で、SIMグループを作成します。グループ名は`handson-<お名前>`と入力します。(既にグループが作成済みの場合は飛ばしてください)

![soracom-menu-sim-group-create](https://docs.google.com/drawings/d/e/2PACX-1vQ-wJ7Ixk-BQDtxXweBkhl-deBJzh3behOo_rQNNxm3gO73sKHEV_RvqO7cWrSKJT0AZltPaF_K0qPf/pub?w=381&h=315)

![soracom-menu-sim-group-create-dialog](https://docs.google.com/drawings/d/e/2PACX-1vRjDUj0AzCWEBNyy9GTqWf6jPANTk4WIEZcarMaYd9GhbM-_2AhBru9WglGRplqo0jUroC9rIq82G8h/pub?w=631&h=306)

先ほど作成した SIMグループ をクリック、SORACOM Harvest のアコーディオンメニューを開き、設定を ON にして保存をクリックします

![soracom-menu-sim-group-list](https://docs.google.com/drawings/d/e/2PACX-1vTpWazZ3_xwnViyK1XJXVo3Aa8BeqhLsdeE4v1SHsUNUhKQw-mS15ZovR4kEzNfhJZw2PYdGEcLB9Fr/pub?w=316&h=334)

![soracom-harvest-on](https://docs.google.com/drawings/d/e/2PACX-1vRjSkL7huwCXXSSknkDnuVbPqYSo9a-rJ0PInLFa-mmgBx1fhhHdVu339RbtSuAuhY2bcFlyMxsGWs1/pub?w=504&h=685)

続いて、SIMグループにSIMを追加します。左上[Menu] > [SIM 管理]をクリックします

![soracom-menu](https://docs.google.com/drawings/d/e/2PACX-1vRhgmsjqpncv2HQ0jAZwiYf0knTfvmCMl6x_flrdeGQV4N60trp8M981gCAfitVSmXU4tqAYm6MmyRb/pub?w=331&h=410)
![soracom-sim-mgr](https://docs.google.com/drawings/d/e/2PACX-1vTUi6LN6Hsctv4KdaZj8uOUFg_ZyROx73f1TzFq41KIlRzjUmE_bc2NR5UnS8cn15TD_S2s8FA-DHzA/pub?w=353&h=290)

SIM を選択 > [操作] > [所属グループ変更]をクリックします

![soracom-select-sim](https://docs.google.com/drawings/d/e/2PACX-1vQpULGXvkk5htY266aDd2iWJueVphdm8DFRVy_BF5JnWnZfBBLF19U42ni5lU6VxN5ucmwqKHx4ACjg/pub?w=526&h=489)

先ほど作成した SIMグループ に SIM を所属させます

![sim-group-select](https://docs.google.com/drawings/d/e/2PACX-1vR1DJQnKw0NVvv83qxiTiDkh0AYfF6u8g3En7EDQtt2M2OjCRzl_tmlB-02cyiLBHLwWHjpOshFKTAA/pub?w=643&h=334)

以上で SORACOM Web コンソール上での作業は終了です。SIM の "グループ" が、先ほど作った SIM グループ名になっていれば成功です

![sim-list](https://docs.google.com/drawings/d/e/2PACX-1vSjr7j-ld8piy6POBYX1r8Ib2nW1DLjwanI1bqDXS0VsWh6SFK8RXvfDop5X0hzg2Auq2aSvdH8eDPm/pub?w=520&h=464)

## 2. 動作確認

Raspberry PiにSSH接続している端末上で以下のコマンドを何度か実行します

```console
cat /proc/uptime | cut -d ' ' -f 1 | echo '{"uptime": '$(cat)'}' | curl -X POST http://uni.soracom.io -d @-
```

[SORACOM Webコンソール](https://console.soracom.io/) で 左上[Menu] > [SIM 管理]をクリックします

![soracom-menu](https://docs.google.com/drawings/d/e/2PACX-1vRhgmsjqpncv2HQ0jAZwiYf0knTfvmCMl6x_flrdeGQV4N60trp8M981gCAfitVSmXU4tqAYm6MmyRb/pub?w=331&h=410)
![soracom-sim-mgr](https://docs.google.com/drawings/d/e/2PACX-1vTUi6LN6Hsctv4KdaZj8uOUFg_ZyROx73f1TzFq41KIlRzjUmE_bc2NR5UnS8cn15TD_S2s8FA-DHzA/pub?w=353&h=290)

SIM を SORACOM Webコンソール上で選択し [操作] > [データを確認]をクリックします

![harvest-view](https://docs.google.com/drawings/d/e/2PACX-1vRGN09AF9n0GafAg8Ut9s8QYAmEd4h5Oj4fTYUQjqKEFXCj_aIRjyS3u5zpim0eqtnnh-csIl6sAHaU/pub?w=526&h=489)

下図のように SORACOM Harvest 上で稼働時間が表示されるようになります  
※自動更新を ON にすると、画面の再描画が自動的に行われます  
※グラフ種類を折れ線グラフや棒グラフに変更することができます

![SORACOM Harvest で表示している様子](https://dev.soracom.io/img/gs_wio-lte/soracom-harvest-rendering.png)

これでSORACOM Harvest を使用して Raspberry Piからのデータを受信、蓄積する様子が確認できました。

## 以上で本章は終了です

* [目次ページへ戻る](index.md)
