## センシングデータを SORACOM Lagoon で可視化


### SORACOM Lagoon アカウントの設定
[SORACOM Web コンソール](https://console.soracom.io/#/login?return_to=)の[Menu]> 「ダッシュボード作成・共有」 をクリックします。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTMMlRhzS5KKB1UoIjCFN3UYo2NjaoOATnPZJKOaeCPbt-axRdH9xPXSRErSff9QiPy0nKevNCFKphC/pub?w=435&amp;h=427">

#### Lagoon を有効化する
「SORACOM Lagoonの利用を開始する」ボタンをクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vTxHwWrPSKmuGSjuT7d4oTYCxU3iFj6mhhkSJjDRoYRt4x1GmvBUAIHnu0hMLzkzVtRo6kDU1u5lj50/pub?w=515&amp;h=216">

パスワードを設定します。
このパスワードはSORACOM コンソールのルートアカウントのメールアドレスでLagoonへログインする時に必要なパスワードとなります。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vRDokf99GyS3RmqIl9vCHMCCeOwtCS9divrVIDirnfRGq6MLwwbF3W4NfsNuauULw9JK6tIid2E2eIq/pub?w=673&amp;h=638">

#### SORACOM Lagoonにログイン
「SORACOM Lagoon にアクセス」ボタンをクリックします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vQfmO-6xiPFg8NKb8wPa7GwygRSI3PdKz0a6qnASKXnf_233nv0PDrcjeAZPGYR3ih7MUtoHidpcsom/pub?w=925&amp;h=394">

オペレータアカウントのメールアドレスと先ほど設定したパスワードを入力しログインします。
<img src="https://docs.google.com/drawings/d/e/2PACX-1vRMnwpb0e7nrYVMF2_emXJfwioll6cewS0KJ7bR75gXEHkWY811rcCMh2a4uX0_zCJRjTCItpFsZhXA/pub?w=594&amp;h=340">

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRUY5V5rociUbX60oo3wz9JkQj1740GVrzcLe8nvf0tXApV1uAnLSVqFuGv2MLKQ-v9bhwo8gSAbk08/pub?w=953&h=541">
SORACOM Lagoonにログイン後、上記の画面が出てきたら、ログイン成功です。

### SORACOM Lagoon を使ってセンシングデータを可視化

Lagoon Demoサイトのダッシュボードを作成する手順を掲載しています。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTjC8MPqlL2WMAn9OTvH0_aQ12zce82smW_-FeSFfCE_5sZFBrT_9ApGvNJ5wAt0CdweR0sTjePBeQr/pub?w=961&h=454">


---


## 目次
以下の手順でダッシュボードを作成していきます。

1. [ダッシュボードの作成](#handson1)
2. [ドアの開閉グラフの作成](#handson2)
3. [現在の温度/湿度パネルの作成](#handson3)
4. [温度/湿度の分布パネルの作成](#handson4)
5. [温湿度の2軸グラフの作成](#handson5)
6. [ドアの開閉に応じたイメージパネルの作成](#handson6)

## ハンズオンの前提
以下の条件を前提にしています。
- SORACOMのアカウントを取得していること
- [SORACOM Harvestの設定、およびデータ格納ができていること](harvest-setting)
- SORACOM Lagoonのアカウントを取得し編集ユーザーとしてログインできること

<h3 id="handson1"> 1. ダッシュボードの作成</h3>
まず初めにLagoonへログインすると以下の様なHome画面へ遷移します。  
まだダッシュボードを作成していないので空の状態です。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRUY5V5rociUbX60oo3wz9JkQj1740GVrzcLe8nvf0tXApV1uAnLSVqFuGv2MLKQ-v9bhwo8gSAbk08/pub?w=953&h=541">

画面左のサイドメニューにある「+」ボタンからダッシュボードを作成することができます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTuSUU6QHZsE4IS7-nz9FSqMBNm7IbGTly8-mMJa5Jp2mBQnmmWtfrLqTZfUDOh6ZglBWlxjJ16lpBg/pub?w=961&h=622">

以下の様に新しいダッシュボードが作成され、パネルを選択し作成する画面へ遷移します。  
この時点でパネル作成が可能となりますが、ぐっと堪えまずはダッシュボードに名前をつけて保存しておきます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRrwfT8KrRkUF7ZMiqhJkZ-w3RLf0cdb1uLDBojJZeJYv4zFlt3WaZ5F8ShZ6RG91tf3pNYbb-Dw3vb/pub?w=966&h=496">

画面右上の保存ボタンをクリックし、ダッシュボードの名前を設定し保存します。（ダッシュボードの名前は後からでも変更することができるので、保存しておくことが重要です）

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSojmK-aQXB92ghZm00CnAZsNoXCqF7jNS23aABaXy5GpBMLTAOo9fY-Q_ji728ThDr90V6TwWRazxs/pub?w=968&h=406">

画面左上に保存した名前でダッシュボードが保存できているかを確認します。
保存できていればいよいよ各パネルを作成していきます。
画面上部の「パネルを追加」からパネルの選択画面を出します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRKUXc5B_jGpIlELGAHIRuKgFigCrKzfAt_5AYpRptijq8HL3f_m9pfyuM68khEFsoL1_8A1GYUEL5T/pub?w=955&h=288">

以上で「1. ダッシュボードの作成」が完了しました。

<h3 id="handson2"> 2. ドアの開閉グラフの作成</h3>

ドアの開閉の推移を時系列で表現するグラフを作成します。

ダッシュボード右上のパネルです。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQ0HqHZ1eOJxMSvaJeygRH1T6sfyQZx9JKl5v77qg-Uelw1DLCvz1i7DZld_DyFJKscluAp52wRX_O6/pub?w=943&h=461">

パネルの選択ウィンドウから「Graph」を選択します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQFk54Hx5lH3bMnxBoug9vUAaNfKv1FbkKC6MFKXuU9stKTdLq67_bJ6Jk_eDOQWyNtNrPB2BQqpjr2/pub?w=949&h=518">

空のグラフパネルが表示されるのでパネル上部をクリックし、メニューの「編集」をクリックし編集画面を開ます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQjeGl4YTihBCIXfqY19zzDJl01iiHesZq1oK8qtotsoJbkTnmWw4HHYTmX6hQOuKVkqgXCGnmsPKw_/pub?w=953&h=526">

「全般」タブをクリックしパネルのタイトルを入力します。タイトルはパネルをダッシュボードに並べた時の上部に表示されます。（後から変更することができます。）

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQHjNnfzrtUjrvpdwL6td1sVf6y2OTWPd0av5xNMLSnRqtcZbdLMrXX3dvaM_6n793n1nRLUZk1Afqt/pub?w=955&h=318">

「メトリック」タブをクリックしデータを選択していきます。

「データソース」では「Harvest」を選択してください。
クエリを設定していきます。

今回はSIMを利用したので「Air」を選択します。

利用したAir SIMの「IMSI」を選択します。利用したIMSIはソラコム コンソールからご確認いただけます。

次に「Standard」を選択します。

最後に今回は冷蔵庫のドアの開閉状況を0と1で表現しているため「door」を選択してください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRAfMuYlTWdHM_Qvlx5WrIsOgzlsdPTAzYPHH5AkXFD_OYuE7DDho59lCYXZD7OPdcuXaqXwoaTbZ_y/pub?w=959&h=319">

「軸」タブをクリックし軸の設定を行います。

今回は横軸（X軸）は時間、縦軸（Y軸）はドアの開閉（0〜1）を表示したいので、「左Y」の設定項目を以下のように設定してください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vS3Y5KaZzg8vPXugXLW9kt0CM1eC3oVSGkMe5_Sr3F7-7-0N6P6izdEKIE_YqPzdzmav0pdA4yGEvmK/pub?w=955&h=324">

以上の設定でドアの開閉に応じたグラフが作成できました。（こまめに保存することをお勧めいたします。）


より発展的な内容として、例えばドアが開いた状態が続いた時にメールやLINEに通知を出す。といった機能もLagoonであれば簡単に実現することができます。

もし興味があればSORACOMのデベロッパー向けドキュメントの[SORACOM Lagoon を利用してアラートを設定する](https://dev.soracom.io/jp/start/lagoon-alert/)を参照してチャレンジしてみてください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSQV83DJMFxsKRP9q_aAWv9fDD86JOtQ8hp6ZVzxaIICrJQ1ruPP8WhjRlwMl5aKm12mJg9x7CIhtr4/pub?w=954&h=562">



<h3 id="handson3"> 3. 現在の温度/湿度パネルの作成</h3>

現在の温度と湿度を表現するパネルを作成します。
ダッシュボード上、中央の２つのパネルです。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTqh3KplaCd6ZpQFre32owu2Ca2zfufj9fPabWhzCltJ-mxP7LtzviDdSdr7opEk6EAVqnxA-4P7N3b/pub?w=953&h=460">

パネルの選択ウィンドウから「Graph」を選択します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTGQSHPgWQNiDgJusyMmUh6ayWgB6V9qpcWeY8ZYp3M9c20FEUPjgaS3keFTOKLMJEgYZzw6IM0GcUL/pub?w=944&h=513">

空のパネルが表示されるのでパネル上部をクリックし、メニューの「編集」をクリックし編集画面を開ます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQjeGl4YTihBCIXfqY19zzDJl01iiHesZq1oK8qtotsoJbkTnmWw4HHYTmX6hQOuKVkqgXCGnmsPKw_/pub?w=953&h=526">

「全般」タブをクリックしパネルのタイトルを入力します。タイトルはパネルをダッシュボードに並べた時の上部に表示されます。（後から変更することができます。）

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSq6QxOaRaYD1uYsC03pwqRqUpTomrpKKQMAN591M4p_a0NKSij8qqclvD6fno9pSjMwURaikgYlUG2/pub?w=956&h=327">

「メトリック」タブをクリックしデータを選択していきます。

「データソース」では「Harvest」を選択してください。
クエリを設定していきます。

今回はSIMを利用したので「Air」を選択します。

利用したAir SIMの「IMSI」を選択します。利用したIMSIはソラコム コンソールからご確認いただけます。

次に「Standard」を選択します。

最後に今回は冷蔵庫の現在の温度を表示するため「temp」を選択してください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTWL3hsuNb4U_g3UuBKr4s3r-JQ4y8k8KTNoXTcCCXyhrF6_dgQEL795gRHWSzP-sEQdVtBjBBCcbKn/pub?w=951&h=318">

「オプション」タブをクリックし、値や色の調整を行います。

今回表示する値を「現在値」とし大きさを「200%」に設定しています。
また、このパネルは温度を表したいので「接尾語」に「℃」を設定し大きさを「120%」に調整しています。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRucHQWEoNdzqJkR4psWZpcmQoyE4AWRiyLbtcQiNSdUT9tIQv-AnTXdgxI2cqagsdrihZytx_GnAHn/pub?w=955&h=327">

以上の設定で現状の温度を表示するパネルが作成できました。
湿度についてのパネルは新規パネルを作成し「メトリック」タブから「humi」を選択することで作成できます。

このパネルの詳細な使い方についてはSORACOMのデベロッパー向けドキュメントの[SORACOM Lagoon でシングルスタットパネルを設定する](https://dev.soracom.io/jp/start/lagoon-panel/#singlestat_panel)を参照してください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSQV83DJMFxsKRP9q_aAWv9fDD86JOtQ8hp6ZVzxaIICrJQ1ruPP8WhjRlwMl5aKm12mJg9x7CIhtr4/pub?w=954&h=562">


<h3 id="handson4"> 4. 温度/湿度の分布パネルの作成</h3>

温度と湿度の分布を表すパネルを作成します。
ダッシュボード下の２つのパネルです。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTesTaC-AQbtspwO8HlylqHxsaS05vHn87bKg07XPpXeN_8L4VcGCfVswfvfvozvAEjl2P-BAvkYGts/pub?w=954&h=448">


パネルの選択ウィンドウから「Heatmap」を選択します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQvrbfizgz-7u49uliFiqnQJr_sCirvcL8HGHWAHdtq3QmhANNr-oa9EjICH6MQRRkHxmlNjZXzM8da/pub?w=948&h=518">

空のパネルが表示されるのでパネル上部をクリックし、メニューの「編集」をクリックし編集画面を開ます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQjeGl4YTihBCIXfqY19zzDJl01iiHesZq1oK8qtotsoJbkTnmWw4HHYTmX6hQOuKVkqgXCGnmsPKw_/pub?w=953&h=526">

「全般」タブをクリックしパネルのタイトルを入力します。タイトルはパネルをダッシュボードに並べた時の上部に表示されます。（後から変更することができます。）

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRc-wHGQmsKBxxvrGcWpAfa5peoXLiEy9Pqfe6Yg7N68FHgUuitnuu8ksvvi-_8wlNmi3GvGu0nNvzi/pub?w=954&h=322">

「メトリック」タブをクリックしデータを選択していきます。

「データソース」では「Harvest」を選択してください。
クエリを設定していきます。

今回はSIMを利用したので「Air」を選択します。

利用したAir SIMの「IMSI」を選択します。利用したIMSIはソラコム コンソールからご確認いただけます。

次に「Standard」を選択します。

最後に今回は冷蔵庫の温度の分布を表示するため「temp」を選択してください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTnHZOk3oehbXssrm7fkR1OTxCHuENAYgo38N_g9Ba82Vdepcg-RH1OclqgyXvfCw973diuvlyM1QYf/pub?w=953&h=327">

以上の設定で現状の温度の分布を表示するパネルが作成できました。
湿度についてのパネルは新規パネルを作成し「メトリック」タブから「humi」を選択することで作成できます。

このパネルの詳細な使い方についてはSORACOMのデベロッパー向けドキュメントの[SORACOM Lagoon でヒートマップパネルを設定する](https://dev.soracom.io/jp/start/lagoon-panel/#heatmap_panel)を参照してください。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQKeikofLajkaMu4Yx_yoLsZDvNzuak7g8F3dNQRtux6jV1jL6d4ZDdN4QvusftetYT6kvvnG1MSQ9g/pub?w=954&h=565">

<h3 id="handson5"> 5. 温湿度の2軸グラフの作成</h3>

温度と湿度の推移を時系列で表現するパネルを作成します。
ダッシュボード真ん中のパネルです。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTeqzRJigSV6GW5z7hCnJmsSq6SZShVC6uOx01DPkna090ZZoykoCMAp0ZqIZR_6WOpFJrOoOjXA1wc/pub?w=951&h=459">

パネルの選択ウィンドウから「Graph」を選択します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQFk54Hx5lH3bMnxBoug9vUAaNfKv1FbkKC6MFKXuU9stKTdLq67_bJ6Jk_eDOQWyNtNrPB2BQqpjr2/pub?w=949&h=518">

空のグラフパネルが表示されるのでパネル上部をクリックし、メニューの「編集」をクリックし編集画面を開ます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQjeGl4YTihBCIXfqY19zzDJl01iiHesZq1oK8qtotsoJbkTnmWw4HHYTmX6hQOuKVkqgXCGnmsPKw_/pub?w=953&h=526">

「全般」タブをクリックしパネルのタイトルを入力します。タイトルはパネルをダッシュボードに並べた時の上部に表示されます。（後から変更することができます。）

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRTmXLjfL1okeQ3BPyIi_UDtWhn7xuSJirU5JZsDTZM7MfPD8EF7HNeuvDjaSVj2r-c8mczuw4OVdZY/pub?w=950&h=320">

「メトリック」タブをクリックしデータを選択していきます。

「データソース」では「Harvest」を選択してください。

クエリを設定していきます。
今回は温度と湿度を１つのグラフで表現するので２つのクエリを準備します。

今回はSIMを利用したのでそれぞれ「Air」を選択します。

利用したAir SIMの「IMSI」を選択します。１つのAir SIMで温度と湿度の２つのデータを取得しているため、選択する「IMSI」の値は同じものとなります。
また、利用したIMSIはソラコム コンソールからご確認いただけます。

次はそれぞれ「Standard」を選択します。

最後に今回は温度と湿度を１つのグラフで表現するので、それぞれ「temp」「humi」を選択します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRTAgc-SIIeuSS6fB8h70eSm5X4KD5CwQc-k1mjW90Z2quMvs8UoMQm50lgXPWUOjN4i6fdI4ehkU-t/pub?w=951&h=318">

「軸」タブをクリックし軸の設定をしていきます。
今回作成する２軸グラフは左のY軸を温度、右のY軸を湿度とします。
そのため、それぞれ単位とラベルを以下のように設定します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSMM9tJGzGbI44jYg-cFgDJBrUVklPLayIlOQhNFBU3H6vM3EgyezZgWUaQYMJoUK7vabaTOx2jnmQ2/pub?w=951&h=320">

「表示」タブをクリックし各データの表示を設定していきます。
左にある「表示のオーバーライド」を選択します。
「エイリアスもしくは正規表現」に「メトリック」タブで設定したデータ「temp」を入力します。（メトリックタブを適切に設定できていれば補完が効きます）
その右にある「＋」をクリックすることで設定内容を追加していくことができます。今回は「Line fill」を１に設定、「Color」を赤に設定しています。
軸に関しては何も設定せず左Y軸を利用します。

次に下にある「＋オーバーライドを追加」をクリックし、「エイリアスもしくは正規表現」に「メトリック」タブで設定したデータ「humi」を入力します。
それぞれ「Line fill」を１に設定、「Color」を青に設定しています。
「Y-axis」に2を設定することでこの「humi」データを右Y軸にマッピングしています。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSVEYgzALK9fUUpIxLhhLg-ttG8pEKDTSskrXiHxrFAfR28IQ758bYznl2C0ZCN1qqoCJxtzArKjtnd/pub?w=956&h=319">

以上の設定で温度と湿度の推移を時系列で表現するパネルが作成できました。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vTK8IOB31j8ZWjt06uVNueYajpO1G6YPPBEo7P_Dc8cpU7kLDhBvNipt6ec4O3odkwDgNiZW4VoA22n/pub?w=951&h=543">


<h3 id="handson6"> 6. ドアの開閉に応じたイメージパネルの作成</h3>

ドアの開閉を画像で表すパネルを作成します。
ダッシュボード左上のパネルです。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSslUu1TskGz0Ge4I7I9uWoHBmHNiwVwOzYXOTVAc7sZ-FbhP5XjNLOrlty29S28bYF-YC4FVUv8HZI/pub?w=958&h=459">

パネルの選択ウィンドウから「Graph」を選択します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRijkEXKzzh8mZXb_wq9Xn-90PewnBlEG2pnoR3pJarMHBTi7aDdrgUvNCF7g7TUWnnQOX6_92wrfHo/pub?w=946&h=517">

空のグラフパネルが表示されるのでパネル上部をクリックし、メニューの「編集」をクリックし編集画面を開ます。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQjeGl4YTihBCIXfqY19zzDJl01iiHesZq1oK8qtotsoJbkTnmWw4HHYTmX6hQOuKVkqgXCGnmsPKw_/pub?w=953&h=526">

「全般」タブをクリックしパネルのタイトルを入力します。タイトルはパネルをダッシュボードに並べた時の上部に表示されます。（後から変更することができます。）

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSy7eRX3ES9Xa-pPpWMC4C0biBhzlRwu2YK6KqK5N4WWhd0KXy_oeB8aMiTrPYvq_W7TKG5wsaesmVa/pub?w=954&h=314">

「メトリック」タブをクリックしデータを選択していきます。

「データソース」では「Harvest」を選択してください。

クエリを設定していきます。

今回はSIMを利用したのでそれぞれ「Air」を選択します。

利用したAir SIMの「IMSI」を選択します。
利用したIMSIはソラコム コンソールからご確認いただけます。

次は「Standard」を選択します。

最後に今回はドアの開閉をデータソースとするため「door」を選択します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vRK4LcjkievqZN9nqCokqfXK9k53LWg_vWM8UlGvzIY4RliIP1lQiZH4qzjMJTmX_qGFj80oLRJgl8L/pub?w=966&h=256">


「設定」タブをクリックし表示するデータの設定を行います。
「背景画像のURL」に画像のURLを入力します。
今回はドアが閉じている画像を「rfg_0.jpg」とし、ドアが開いている画像を「rfg_1.jpg」としています。
その際、この欄に入力するURLは「（URL）/rfg_」となります。

また、下のメトリックに名前には「メトリック」タブで設定した「A-door」を選択します。

<img src="https://docs.google.com/drawings/d/e/2PACX-1vQEJ0pz4H18e4JjX5b2-6OrsxW5LIZW7mp5Vi89eEm94V6Rzeo07xZJHeKxPTQ187mXeacwzS9sK47O/pub?w=951&h=399">



<img src="https://docs.google.com/drawings/d/e/2PACX-1vRTwvh8SYX_kpvRRtLTg2HrY0PYrZ7xcWOUrxtMn8RX_kP-DfOYF8tG7Eviq5n9N6Dal7t2xWxlBn5O/pub?w=960&h=720">

以上の設定でドアの開閉を画像で表すパネルが作成できました。
