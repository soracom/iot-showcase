# B-1 SORACOM Lagoon で通知を送る

SORACOM Harvest Data に蓄積されたデータを基に、SORACOM Lagoon で通知を送ってみます。

## SORACOM Lagoon とは

SORACOM Lagoon はダッシュボード作成/共有サービスです。  
データ収集、蓄積サービス SORACOM Harvest に集められたデータを対象に目的に応じて複数のグラフ、テーブル、地図等を組み合わせたダッシュボードを作成し、それらを共有できる他、条件に応じて様々なサービスへ通知を送ることができます。

詳細は [SORACOM Lagoon サービス紹介ページ](https://soracom.jp/services/lagoon/) をご覧ください。

## SORACOM Lagoon の有効化と SORACOM Lagoon ユーザの作成

### ボタンを借りた方 (SAM ユーザでログイン)

左上の [Menu] から [データ収集・蓄積・可視化] > [SORACOM Lagoon] を開きます。

![go-lagoon.png](https://docs.google.com/drawings/d/e/2PACX-1vRcLctepbC1RZLYJOXThPrqh_ViEclBUfCwWpfrcPq7umjHxdpIdI7uquKBiu9q0JiWiGqdj1jXTJwH/pub?w=290&h=395)

[ユーザー追加] をクリックします。

![add-lagoon-user.png](https://docs.google.com/drawings/d/e/2PACX-1vSnhhU3G_7Th69n1hPon0VqeKp7XvEpXg-FPwPMKs-AKFFEW9AQma5gRp0RpDxVuEwaXEqbDgSq0eB3/pub?w=641&h=371)

SORACOM Lagoon ユーザを作成します。以下のように設定してから [追加] をクリックします。

- 権限: **編集可能**
- メールアドレス: 運営から入手 (Lagoon メールアドレス列)
- パスワード: 運営から入手 (Lagoon パスワード列)

![add-lagoon-user-dialog.png](https://docs.google.com/drawings/d/e/2PACX-1vQv1DzgEWC_j3djqPRJpqSOd0t9NVgQPGCSzQRACkdAunlxHg4j1ABiOIyvtFtUfW5g9NDOQjq-92jV/pub?w=608&h=687)

[SORACOM Lagoon Console へアクセス] をクリックします。

![open-lagoon.png](https://docs.google.com/drawings/d/e/2PACX-1vSTZxgjBlrIr8RUvz9lYf2DiMZqjP7QKW6TpijcN30ftCcirEgCoKdgiC-3OjnahUCIbT7SGTLwMbHN/pub?w=739&h=377)

### ボタンを持ち込んだ方 (ルートアカウントでログイン)

左上の [Menu] から [データ収集・蓄積・可視化] > [SORACOM Lagoon] を開きます。

![go-lagoon.png](https://docs.google.com/drawings/d/e/2PACX-1vRcLctepbC1RZLYJOXThPrqh_ViEclBUfCwWpfrcPq7umjHxdpIdI7uquKBiu9q0JiWiGqdj1jXTJwH/pub?w=290&h=395)

[SORACOM Lagoon の利用を開始する] をクリックして、表示されたダイアログでは "Free" を選択し、[続行する] をクリックします。

![start-lagoon.png](https://docs.google.com/drawings/d/e/2PACX-1vSeBfLfdpGTvtP7-bbOWPOXlWYzzygw5A_f8j3LxpAVe_u_ihDhae391NTn-6H8ZJQMYLiEO3HWIzTz/pub?w=676&h=572)

初期の SORACOM Lagoon ユーザーのパスワードを設定します。すべて☑が付くようになるようなパスワードを設定して [利用開始] をクリックします。

![start-lagoon-set-password.png](https://docs.google.com/drawings/d/e/2PACX-1vT33cPmL9cEdhTK03Kzpcp8XwWa4sOsYzS4MwKYTH1uNpVFApHpQsau-Pn5VSMgOM7nfUDsWIMsJqs9/pub?w=632&h=651)

[SORACOM Lagoon Console へアクセス] をクリックします。

![open-lagoon.png](https://docs.google.com/drawings/d/e/2PACX-1vSTZxgjBlrIr8RUvz9lYf2DiMZqjP7QKW6TpijcN30ftCcirEgCoKdgiC-3OjnahUCIbT7SGTLwMbHN/pub?w=739&h=377)

## SORACOM Lagoon へのログイン

SORACOM Lagoon へのログイン画面が表示されます。下記の情報でログインしてください。

- メールアドレス: ルートユーザーのメールアドレス、もしくは Lagoon メールアドレス列)
- パスワード: 先ほど設定したパスワード、もしくは Lagoon パスワード列

![login-lagoon](https://docs.google.com/drawings/d/e/2PACX-1vTDTewEk3BnTvARpg8LFxDlX6kIqp71w-fI7CRuGcEZZ88bi4MQiLRb-od3d5vf2JX2UpYdv-ffg3uR/pub?w=634&h=288)

## 通知チャンネルの作成

SORACOM Lagoon へログイン後、左のメニューから通知チャンネルを作成します。

[鈴のアイコン] > [通知チャンネル] > [チャンネルを追加] と進みます。

![go-alert-channel.png](https://docs.google.com/drawings/d/e/2PACX-1vSQsOTKTsmw6xOGLz4deQY0rWU2BVVMobrfGl61PQgxP4zfcqlcyKdu06qEAMaBuihXv5JQwofTQKuu/pub?w=719&h=562)

新しい通知チャンネルを追加で、以下のように入力します。

- 名前: `メール` (任意の文字列)
- タイプ: **Email**
- 全てのアラートで送信: (チェックせず)
- Email Addresses: 通知の送信先のメールアドレスを記載してください

入力が終わったら、まず [送信テスト] をクリックします。

![create-alert-channel.png](https://docs.google.com/drawings/d/e/2PACX-1vRPDVWEk7QGQPvRbLabfolka-eLIVUksBddvPapx3JdHC9YQTPvdpKYJTsRGJJaEdLA-fuKDTsxBKsx/pub?w=496&h=686)

このようなメールが届けば設定成功です。

![testing-alert.png](https://docs.google.com/drawings/d/e/2PACX-1vSATHIhIHnkMeV4yE0qpYwVGWuIfJFNmHYjF8r6sPdYo3v8_60dlxpyoIt8bfFKnfrbQFuvwoZ8wfmC/pub?w=675&h=562)

"新しい通知チャンネル" の画面に戻り [保存] をクリックしてください。

## 新規ダッシュボードの作成

SORACOM Lagoon でダッシュボードを作成します。

[＋のアイコン] > [ダッシュボード] と進みます。

![lagoon-new-dashboard.png](https://docs.google.com/drawings/d/e/2PACX-1vS40fmPex1A5ycG3JXqyL0MhGSoCnOuresDPzj3KVdESLs0b0j08OoinIPIpp23mpzIllBMkGDRMNzC/pub?w=282&h=181)

## 新規グラフパネルの作成と設定

"New Panel" が表示されている場合は [Add] > [Graph] と進みます。  
（もしも "New Panel" が表示されていない場合は、画面右上の ![パネルを追加](images/new-panel-icon.png) をクリックすると "New Panel" が表示されます）

![new-panel-graph.png](https://docs.google.com/drawings/d/e/2PACX-1vQSGp7g3hI8m7Z0Ds80mJdxUf6sFgmudhWOm8ym5VYM5049JFIrZFTsp6ahVuF_pioYjqG441ohSx98/pub?w=547&h=377)

グラフ（まだデータはありませんが）が表示されたら "Panel Title" となっている部分をクリックし [編集] と進みます。

![go-edit-panel.png](https://docs.google.com/drawings/d/e/2PACX-1vQOK6CCu9o6ynUb0FEEmk4S0krgRlKrTgaTmxnuREYm6lRs-I9PNRS3l4NrJ6yA0uoL1EFZHSPzJmKH/pub?w=309&h=280)

### メトリックタブ

[メトリック] タブをクリックした後、以下のように設定します。

- データソース: **default**
- **Air** / [LTE-M Button の SIM を選択]  / **Standard** / **clickType**

![panel-metrics.png](https://docs.google.com/drawings/d/e/2PACX-1vRVL7tCT_mxj7_FWfh0z_vUdw90i7DjuCOqI047vaPX1WXvQO1rHDZ6RvrVqPcORBTAE6pdWEcJzgxu/pub?w=741&h=285)

### 表示タブ

[表示] タブをクリックした後、以下のように設定します。

- 描画モード
    - 棒 (チェックをつける)
    - 線 (チェックを外す)

![panel-behavior.png](https://docs.google.com/drawings/d/e/2PACX-1vQ6-zDL4P_WAZAZ5dxTJrREMYY-45CsCtJcxEFLBbSrUC8iplUaS8kuhadU8-uTeYlNmthZcK_sx78N/pub?w=549&h=306)

ここまで設定したら、画面右上の ![ダッシュボードを保存](images/save-dashboard.png) をクリックし、ダッシュボードを保存します。  
ダッシュボード名は任意で構いません。

ダッシュボードに戻ったら、再度 [Panel Title] > [編集] を開き、設定を続けます。

### アラートタブ

[アラート] タブをクリックした後、以下のように設定します。

#### アラート設定

- 条件:
    - WHEN `last()`
    - OF `query(A, 1m, now)`
    - **IS ABOVE** `0`
- データが無いか全ての値が Null の時: **Ok**

#### 通知

- 送り先: **メール** (通知チャンネルで作成した名前を選択)

![panel-alert.png](https://docs.google.com/drawings/d/e/2PACX-1vRwPQoeeKG9Tk6Ig-DnWBQshekzrTRsTNnL9fXgXenRnzGHiEnQmMXF1OP6DTzuhSyArXGn312Wn5qQ/pub?w=717&h=693)

ここまで設定したら、画面左上の ![ダッシュボードを保存](images/save-dashboard.png) をクリックし、ダッシュボードを保存します。  

## 通知を試してみる

ボタンを押すと、それに対応してメールに通知されます。

![lagoon-notify.png](https://docs.google.com/drawings/d/e/2PACX-1vSL9up4bpUwVjMuJXcEgXY7EMEhWbg4wB4G_IN68-673IwK-QxR7YqT9dh0b44RRfzx1WNhf1a5t6A3/pub?w=825&h=517)

**注意点;**

- 次の通知は、通知発生後１分※以上経過してから受け取ることができます。これは過剰な連続通知を避けるための仕組みです。
- 2019年10月時点では通知発生後１分※を経過する "OK" のステートの通知が発生しますが、これは正常な動作です。

※ SORACOM Lagoon のプランによって異なります。Freeプランは最小60秒。Proプランでは5秒です。

# 以上で本ページの作業は完了となります

## トラブルシュート
