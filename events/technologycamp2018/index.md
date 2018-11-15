# SORACOM Technology Camp 2018
## SORACOM ハンズオンコーナー

## ハンズオンの内容
LTEモジュールが搭載された[Wio LTEデバイス](https://soracom.jp/products/wio_lte/)、超音波Groveセンサー、SORACOM Air for セルラーを使い、駐車場管理システムを作ります。既にWio LTEデバイスにはコードは書き込まれているので、データの取得、可視化を体験いただきます。

## 費用
参加費用はかかりませんが、本ハンズオンでご登録いただくSIMカードは1日10円の基本料金と通信量に応じた料金、追加サービスSORACOM Harvestの料金が発生します。
SORACOM Air for セルラーの料金は[こちら](https://soracom.jp/services/air/cellular/price/)をご覧ください。
SORACOM Harvest の料金は[こちら](https://soracom.jp/services/harvest/price/)をご覧ください。

## 本日の機材（ソラコムが提供するもの）
* [Grove IoT スターターキット for SORACOM](https://soracom.jp/products/#grovestarter_kit)
* [SORACOM Air for セルラー](https://soracom.jp/products/sim/plan-d/)

## 参加する皆様に用意いただくもの
* PC（外部のPCに接続できること。Google Chromeが利用可能なこと）
* クレジットカード
* メールアドレス

## 駐車場管理システムを作ってみよう！
### 手順
1. [SORACOM アカウント作成](#handson1)
2. [支払い情報の設定](#handson2)
3. [SORACOM SIM 登録](#handson3)
4. [SORACOM Harvest 設定](#handson4)
5. [Wio LTEにSIMを挿入](#handson5)
6. [SORACOM Harvest でデータを可視化](#handson6)

<h3 id="handson1"> 1. SORACOM アカウント作成</h3>

[SORACOM ウェブサイト](https://soracom.jp/)から、User Consoleをクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vR7ktcIhkVAi4SHnsxjtNyesTwkcRqyWH13O06P7IDgPTWQgZu90wbMxMucWiHkomr1kZwQ6GcqHD0V/pub?w=921&amp;h=408">

アカウントを作成をクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vRIbsOZm8KiysVlqsQTR6Yxvxi5XlsIxb2gDxPVwQcFKTav036YROtcOLgVQUlX8kp6zPeG9OOrhmIJ/pub?w=930&amp;h=406">

「カバレッジタイプJapan」を選択します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSkgiSvtFlsUQJegTkLPiJVJg8vB0zhlujcxbLJ_2c6bko6Y4GcU_FN9VATHuLuO_I--TWndMYM_iru/pub?w=678&amp;h=261">

必要事項を入力します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vReb-X0b1hNlM6ncDw7DZtRJOxccL3R9BaTyymLVSSPDV6EXapy-V_L74YOukki1BdUompNAUhhFTaO/pub?w=274&amp;h=667">

入力が終了したら「アカウントを作成」をクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQsccaDXfmA0BaSrCXGMdg-LhE0d4pCGo8LtNdd7PtO9hED_unQynsdJJt-k6Rpf3nDrHNPTD_RXew6/pub?w=674&amp;h=329">

メール送信完了のメッセージが表示されますので、メールの到着をお待ちください。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ7fBRpDPtkt9VL7lGjgZwSXQsWvWCrKeGcVNGmo3EFdlXP2qUf14Lw6e4Xxco87jCvJLnPJd3HTMM8/pub?w=927&amp;h=351">

メールが届いたらリンクをクリックしてください。自動的にログイン画面に遷移します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ6cRun2KmVkTYV8xCXf0DDG9NdSjBlh-bGhBGvO8lhh7er2IHXr2RdMJEUQopZLwqb1yOgPYekuV4Q/pub?w=620&amp;h=413">

<h3 id="handson2"> 2. 支払い情報の設定</h2>

通信料の支払い方法はクレジットカード払いとなります(法人のお客様は請求書払いにも対応しています)。クレジットカードの情報を登録するには、メイン画面右上のユーザー名が表示されているボタンから [お支払い方法設定] をクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQEdcNmOnSQYbaolqmEUN8HF55sstp1DxOvhU_uuckJTDbm4FCHAqlR9--xZ_0v67uRpWharuHS81wC/pub?w=762&amp;h=418">

入力画面が表示されたら、入力フォームに沿ってクレジットカード情報を入力します。最後に[登録] ボタンをクリックすると支払い方法の登録完了です。

<h3 id="handson3"> 3. SORACOM SIM 登録</h3>

左上の [SIM 登録] ボタンをクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vRNnZLOT3ztm_m3Nbi-ORGtZTgHK-LCthd3onZDiVqJzkics9hksK4_mVlxKkgvlSlqZ4uX9d8hNM1A/pub?w=756&amp;h=310">

「SIM 登録」画面が表示されたら、Air SIM の台紙の裏面に貼ってある IMSI と PASSCODE を入力してください。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQPQ03CBEX9D4MLwFGK1ubSw49tummvvwOwqtDvoB4QawP7UiVDfBnVGl1F3K8_9-4LsMhNkZr2kPv0/pub?w=509&amp;h=392">

名前、グループは空欄のままでも構いません。[登録] を押して SIM 登録を完了してください。複数の Air SIM を続けて登録することも可能です。

<h3 id="handson4"> 4. SORACOM Harvest 設定</h3>

SORACOM Webコンソール で 左上[Menu] > [SIM グループ] を選択します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSn0Zi77g_YUfJPD4SMgpspn-sCiShXibex_Bd288IC5d8-TfFPfCxanjfTdza-7OT5FgQNCuU8UPls/pub?w=691&amp;h=397">

[追加] で、SIMグループを作成します (グループ名 harvest もしくは任意でかまいません)
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSPANZwqx8KjZsVl_gzqv09OKc-i4-CJb1SjrlCiNj6zFN0XM-4ialXN270wHaIgBqYApUjcH1BaUwH/pub?w=639&amp;h=625">


先ほど作成した SIMグループ をクリックし、 SORACOM Harvest の設定を ON にして保存をクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ3JxlDr0DwQ3D_4RNWiMYPBwW3Z-OyftYaNmuM-NIZ0grqn5qgnZvO_gAhCkcQs8nBA7RZ1qeyPlCT/pub?w=867&amp;h=681">

SORACOM Webコンソール で 左上[Menu] > [SIM 管理]を選択します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vR1p_9PqCjBoB3xh_nEta2grhXZlJI3zyrXOjXjH59Vgq69cD5XbVA3PIppl0X6sNYqM538K8G2iK4U/pub?w=704&amp;h=393">

先ほど登録したSIM を選択 > [操作] > [所属グループ変更]をクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vR9udoWlimJIJv51_uvGoJ2SxIiOga1VQS09JnCr1gjUXg9LxmDoMH33mAagYZQDDCIUm-9Fn3K8TzB/pub?w=544&amp;h=506">

先ほど作成した SIMグループ に所属させます。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vSlVDzWGlXw6w6CpMhGG5weDgJYzcr2Uo7bXXpMfOG5ZfGX53y7yLVfTBY7DvSvFrm0yL5L_HJlYU2L/pub?w=650&amp;h=336">

以上で SORACOM Web コンソール上での作業は終了です
下記のように先ほど登録した SIM の “グループ” が、先ほど作った SIM グループ名になっていれば成功です。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQLn4aBcEup1UuMJQ3XZ5oKDasjDtHSfqjvAykYAnK_EU1TbBI9l9HFS19yOoLeaCYh3_YCh6rAy6BO/pub?w=526&amp;h=485">


<h3 id="handson5"> 5. Wio LTEにSIMを挿入</h3>

先ほど登録したSIMカードを、赤色のWio LTEデバイスの中に挿入します。
スロットが上下に二箇所ありますが、必ず基板側のSIMスロットにSIMを差し込んで下さい。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQnYVov-k_BRy-k_rWqQWwIXq3MwGc4af2EXcC9XuodRuDvwtZPNFLeh11S8lD8_WesE7U9tVJLEIJX/pub?w=512&amp;h=250">

A6 端子に 超音波センサーを取りつけ、USBケーブルをPCに接続します。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTmSgkyFdnlFKvjEnFdeNzJ6ns8TxHRrnhqkhceZLOFKlyn03NXvuGhMVgh0m7T4N3spOuluOXUb7jY/pub?w=890&amp;h=545">

<h3 id="handson6"> 6. SORACOM Harvest でデータを可視化</h3>

SORACOM Harvestの設定をしたSIMを選択し、「操作」からデータを確認を選びます。
右上の自動更新（5秒）をONにします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vS5Y8Qmk9BZJgpPQS7zUEyehjqLFjxrMl3qSZ9gEYe9V1GtWqiN4jnznxHlC6zUdNT_X8pk5WnmvCzS/pub?w=438&amp;h=502">

超音波距離センサーを使って車との距離を計測し、一定の距離以下であった時は駐車しているとみなします。

超音波センサーに机の上にある車を近づけ、パーキングをしてみてください。

現在の車が駐車している時間（CurrentParkingSeconds)と、のべ駐車時間(TotalParkingSeconds)を Harvest に送信し、グラフにします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ9cqXuprpSbfIxvj59nnzEX2fvaXtJvNrxCmBT0oquHX_uklZHlbBtCJUx8JlwzDwaPEauX-1xtdMg/pub?w=923&amp;h=432">

## 片付け方法
Wio LTEデバイスに取り付けたSIMを外します。SIMを取り出す際に、金具を引っ張りすぎないように気をつけてください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ3KJI8hNF1CDcFz3hkpgiVtQoPhRPGrKLd3c4_g6wo1KVRIFgW8XPNSCklHZ5KmUmwHsE_hLbIsk-e/pub?w=688&amp;h=696">

また、本日登録いただいたSORACOM Harvestは1SIM カードあたり 1日5円の費用がかかります。
本日設定したSORACOM Harvestは、SIM グループのHarvestの設定をオフにしてください。

以上になります。本日ご利用いただいたSIMカードはお持ち帰りいただけます。
