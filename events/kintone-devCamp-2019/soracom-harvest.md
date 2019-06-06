# kintone devCamp 2019 ― IoT ハンズオン

[目次へ戻る](index#index)

## ボタンからのデータを SORACOM Harvest に蓄積・収集する

まずはボタンからのデータを、SORACOM のデータ蓄積・収集サービス "SORACOM Harvest" に格納してみましょう。  
外部サービス連携前のデバイス側の動作確認に役立ちます。

### ハンズオンのゴール

![kintone-devCamp2019 / overview soracom-harvest](https://docs.google.com/drawings/d/e/2PACX-1vRBRDn4w_vgsUdQ8fJsFvx6fbfVPQydxN1TWWOVMV90m7UJhfLfUoF9Zy4l9SwbHk7SVUOP4F11kR51/pub?w=1099&h=364)

<h2 id="w1">作業 1: SIM グループを作成する</h2>

**解説:** SORACOM の様々なサービスは "SIM グループ" に対して設定を行い、その設定が有効なグループに SIM (回線や Button) を所属させることで機能を有効にします。ここでは SORACOM LTE-M Button 用のグループを作成し、そのグループにSORACOM LTE-M Button を登録します。

[SORACOM ユーザーコンソール](https://console.soracom.io/) の [SIM 管理] を開きます。続いて、SORACOM LTE-M Button の SIM にチェックマークを付けます。その後、[操作] ボタンから [所属グループ変更] を選択します。

![](https://dev.soracom.io/jp/img/gs_harvest/gp_group.png)

所属グループを選択するためのダイアログが表示されたら、[新しい所属グループ] ドロップダウンから [新しいグループを作成…] を選択します。

![](https://dev.soracom.io/jp/img/gs_harvest/gp_changegroup.png)

以下のようなグループ作成ダイアログが表示されます。グループの名称を入力して [グループ作成] ボタンをクリックします。 今回は `button` というグループ名で作成します。

![](https://dev.soracom.io/jp/img/gs_button/group_configuration_1.png)

[グループ作成] ボタンを押すと元の [SIM の所属グループ変更] ダイアログに戻ります。  
[新しい所属グループ] ドロップボックスが、今作成した `button` グループになっていることを確認し [グループ変更] ボタンを押します。

![](https://dev.soracom.io/jp/img/gs_button/group_configuration_2.png)

以下のように SIM(Button) のグループ列に `button` と表示されていれば本作業は完了です。

![](https://dev.soracom.io/jp/img/gs_button/group_configuration_3.png)

<h2 id="w2">作業 2: SIM グループの設定を行う</h2>

**解説:** 作成した SIM グループに対して SORACOM Harvest の設定を行います。

SIM 管理画面の SIM(Button) のグループ列に表示されている `button` をクリックします。

![](https://dev.soracom.io/jp/img/gs_button/group_configuration_3.png)

SIM グループ設定画面内の [SORACOM Air for Cellular 設定] グループの下方にある [バイナリパーサ設定] のスイッチを "ON" に設定し、 [フォーマット] に `@button` と入力した後、 [保存] をクリックします。

![](https://dev.soracom.io/jp/img/gs_button/group_configuration_4.png)

同じ SIM グループ設定画面内の [SORACOM Harvest 設定] グループの中にあるスイッチを "ON" に設定した後、 [保存] をクリックします。  
その後表示されるダイアログは [OK] をクリックします。

![](https://dev.soracom.io/jp/img/gs_harvest/group_configuration_6.png)

以上で本作業は完了です。

<h2 id="w3">作業 3: 動作確認</h2>

**解説:** 以上の作業で SORACOM LTE-M Button が押された時のデータを SORACOM Harvest で可視化できるようになったので動作を確認します。

[SIM 管理] を開きます。続いて、SORACOM LTE-M Button の SIM にチェックマークを付け、 [操作] > [データを確認] をクリックします。

![](https://dev.soracom.io/jp/img/gs_button/send_click_event_1.png)

グラフ表示を [集合棒グラフ] に切り替え、 [自動更新] を "ON" にした後、 SORACOM LTE-M Button を押してください。  
Button の LED が緑色に点灯し、SORACOM の設定が成功していれば下記の通りデータが表示されます。

※ **Button は押されてから通信完了(LED が緑)になるまで 8~12秒ほどかかります。連打はしないでください。**

うまくいかない場合は、テキストの見直し、もしくは [トラブルシューティング](#troubleshoot) をご覧ください。  
また、通信に失敗した場合は LED が赤色となります。その際は LED が消灯してから再度押してみてください。

![kintone-devCamp2019 / dataview](https://docs.google.com/drawings/d/e/2PACX-1vSxOpOCTYFs5gSMFXW6L5-nLSUVZtA30L5PaSqu6i09LkrHDGpLLIGk2-L7rXeGLRJzyx2vMehvZNQP/pub?w=931&h=471)

<h2 id="clear-up">あとかたづけ</h2>

あとかたづけは特にありません。

<h2 id="troubleshoot">トラブルシューティング</h2>

* "データ確認" で、データが表示されない場合;
    * ボタン(SIM)に SIM グループに所属できているか確認してください。
* "データ確認" で、![{"payload":"TQEDUQ=="} / kintone-devCamp2019 / binaryParser trouble](https://docs.google.com/drawings/d/e/2PACX-1vQ5SGgeYRjNN_3dPfV1kK7ZVFsroiSDdt27sBzx57mX3sRzTiCY60fff-g3dNdiS71dJ2YBshKg4TY6/pub?w=187&h=100) のようにデータが読めない状態の場合;
    * [SORACOM Air for Cellular 設定] の [バイナリパーサ設定] が "ON" になっており、かつ、フォーマットに `@button` が設定されているか確認してください。

---

[目次へ戻る](index#index)

[EoT]
