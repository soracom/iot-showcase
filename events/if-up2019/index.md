# if-up 2019

## ハンズオンの内容
SORACOM LTE-M Button powered by AWS を使いSORACOM LTE-M Button を押したらSMSが飛ぶように設定しよう！

## 本日の貸し出し機材
* SORACOM LTE-M Button powered by AWS

## お客様の持ち物
* Wifi に繋がるPC
* クレジットカード（AWSアカウント作成に必要になります）
* SMS を受けることができる携帯電話

## 参加費用
無料（ただしAWSの利用料金は発生します）

## 目次
1. [AWS アカウントの作成](#content1)
2. [SORACOM LTE-M Button を AWS IoT 1-Click に登録しよう](#content2)
3. [SMSを送ってみよう！](#content3)
4. [プレイスメントからデバイスの割り当てを外そう](#content4)

<h3 id="content1">1. AWS アカウントの作成</h3>
<a href="https://aws.amazon.com/jp/register-flow/" target="_blank">AWS アカウント作成の流れ (AWS のページに飛びます)</a> から進み、作成してください。

アカウント作成時のポイント
電話音声による認証が必要となります
「非通知」からの着信となるため、必要ならば非通知着信が可能になるようにしてください

AWS サポートプランについて
理由がない限り「ベーシックプラン」を選択してください。それ以外のプランは費用がかかります

すでにアカウントをお持ちの方はこちらをスキップし「2. SORACOM LTE-M Button を AWS IoT 1-Click に登録しよう」にお進みください。

<h3 id="content2">2. SORACOM LTE-M Button を AWS IoT 1-Click に登録しよう</h3>

AWS IoT 1-Click ではボタンと Lambda 関数を結びつける概念として「プレイスメント」と「テンプレート」そして「プロジェクト」が存在します。これらを全て作成したうえで、それぞれボタンと Lambda 関数に結び付けていきます。

![mkmk-button / overview-aws-iot-1-click-structure](https://docs.google.com/drawings/d/e/2PACX-1vRNsm3bCso3sEDoLqx0F7ReWgvOUvpyxAxbIkRDHHhhhTCkIbc8xuLW2zwsfSFIkHntgxUSaXCoHC0B/pub?w=927&h=520)

AWS IoT 1-Click へ LTE-M Button を登録する

AWS マネジメントコンソールを開きログインしたあと、リージョンをオレゴンに変更し、 AWS IoT 1-Click のコンソールを開きます。

![mkmk-button / 1-1 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vSzawNDQ3RDZ0RiN6lu1nv5Y57aUOlSuYoK47BZIs72nt6bHnlbhHf6QAn4bxmJQnZHmQES6gAAn-j5/pub?w=927&h=284)

![mkmk-button / 1-2 aws-console](https://docs.google.com/drawings/d/e/2PACX-1vTprwdD-l_uDEZbhNugIaePDUv9MYWYkXfxHFq4IA4fVNKfZFNrTqCWpDGMksArW7HhN7TtMWK_TKGF/pub?w=612&h=276)

AWS IoT 1-Click のコンソールから [デバイスの登録] をクリックします。

![mkmk-button / 1-3 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vRZ_OiMuE0UPvKG2QxIBfA1OP0laZJiDG4gWa-zwfcOqW6B82I3T0uCxasen8uCh_ttXJuHKBoye_q4/pub?w=752&h=216)

LTE-M Button の電池カバーを開けて DSN を AWS IoT 1-Click に入力し [登録] をクリックします。

![mkmk-button / 1-4 dsn](https://docs.google.com/drawings/d/e/2PACX-1vT5pWHfUR5phIDYUL0NdfyqZc5_fg3LxgomOqOSSvh6nDriZzSxMWNvRkBo8Hyl_CH9XBgKpJ9-t_iT/pub?w=532&h=352)

![mkmk-button / 1-5 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vR0FV0g7ywhbb7-02pDvuB-ZB3oiwfomAyUur4Lfx0pLKXQT2EcaSv6tK8RKDVg6GeDoLNG8Vk0j8W1/pub?w=578&h=516)

LTE-M Button からのボタン押下を待ち受ける状態になります。このタイミングで LTE-M Button のボタンを１回押してください。

* LED が赤点灯 (= データ送信失敗) だった場合は、再度ボタンを１回押してください

登録済みになりましたら [完了] をクリックします。

![mkmk-button / 1-6 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vSKoIzpJwqKkSXsDLEGAbdO4a6tKHx5-PKpSVv7KBWgY5_4wcZS3rhLZ_CSUlZ-Eqv6O4GsJFdPjAub/pub?w=499&h=726)

以下のようにデバイス一覧が表示されていれば登録成功です。

![mkmk-button / 1-7 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vQXuiKDLSeAUC9TbELS5yzMgC-_Ndl7KRuXcWScAYI_hu4t0xqK85Jn_qpGNSWwlxTdKCRTWqhdMd90/pub?w=929&h=315)

一覧に表示されている意味は以下の通りです。

* デバイス ID
    * DSN と呼ばれる一意の番号です。 AWS IoT 1-Click 対応デバイスには SORACOM LTE-M Button の他に AWS IoT エンタープライズボタンといったものがありますが、それら全てにおいて一意になる番号です。
* タイプ
    * デバイスの形状を表します。現在は `button` のみです。
* デバイスリージョン
    * デバイスが管理されているリージョンです。現在のところ利用者はリージョンを選ぶことができず、オレゴン(us-west-2) 固定となります。
* 有効
    * *有効* もしくは *無効* です。初期状態は *無効* です。 *有効* は課金対象デバイスです。 
* プロジェクト、配置
    * ボタンに紐づいた機能(Lambda 関数)の状況です。初期状態は双方とも _未割り当て_ です。
* ヘルス
    * ボタンの寿命です。

登録したボタンの右にある [...] をクリックした後、[デバイスの有効化] をクリックします。

![mkmk-button / 1-8 aws-iot-1-click](https://docs.google.com/drawings/d/e/2PACX-1vRZvuTrcEL7gn72cEFK11VO1HZticJRaUUgt0_znxQOX0MORBdVup1GDCdH32Rq1o_vLNqxP-Wm9p3c/pub?w=926&h=298)

これでボタンが利用可能な状態になりました。

<h3 id="content3">3. SMSを送ってみよう！</h3>
左のメニューから「管理」->「プロジェクト」をクリックして、「プロジェクトの作成」をクリックします。

![aws-iot-1click3](https://docs.google.com/drawings/d/e/2PACX-1vTLb69Qn6f_8IAaD_4clObCuXcls8tGz9uCMvNJZoysrNEonsLN5tdFljQwZkmjFaMyI00DqoCXjFGo/pub?w=933&amp;h=437)

プロジェクト名を入力します。
![aws-iot-1click4](https://docs.google.com/drawings/d/e/2PACX-1vSUawRU2ywznZ5Ukc35TQkA6YLeWEJZ3wKKvfDkdh1VIsVmA8dXKGGsKCxxlGl96kQFn2o-ns2MfIoG/pub?w=932&amp;h=567)

次にデバイステンプレートを作成します。 デバイステンプレート名を入力し、ここではアクションに「SMSを送信する」を選択します。
![aws-iot-1click5](https://docs.google.com/drawings/d/e/2PACX-1vQSLxymO2zZhUzAPpt9bFCMTS1qfsr4ATeJ-qtyhNjBSzqs0fjafEY8eJxeDtmLzKUOSytg8JtfdqLT/pub?w=929&amp;h=511)

続いて、プレイスメントの属性に電話番号とSMSメッセージを入力します。 (SMSが受信できる電話番号を入力してください。電話番号は国番号から入力してください。)
![aws-iot-1click7](https://docs.google.com/drawings/d/e/2PACX-1vS1Fy_7YSCb9HqnRaLYHzvdh0joAZfDrif-BV_xVz-Esyf3-jpAnzS1T_SwE-1sfxLe8ZnUvPqQzcva/pub?w=935&amp;h=426)


「プロジェクトの作成」をクリックします。
次にプレイスメントを作成します。 「プレイスメントの作成」をクリックします。
![aws-iot-1click7](https://docs.google.com/drawings/d/e/2PACX-1vS4xj56dkNmVD9uE5O9zHva6VCjIT9ZZW5ApdnHp0muL2ZMqVHeyDbOkLG0u-A14Eb8pD7gJarOwgWq/pub?w=936&amp;h=572)


デバイスのプレイスメント名を入力し、さきほど登録した SORACOM LTE-M Buttonを選択します。
![aws-iot-1click8](https://docs.google.com/drawings/d/e/2PACX-1vRQVthnV6fjzyEbkQ_dbhiD4cYeqMB0YFBDsI4gPg1E1lgbOoaZBwX7fSfDsv0i7YdvnwRgZjrhbC_X/pub?w=841&amp;h=692)

「プレイスメントの作成」をクリックします。
Buttonをクリックして、SMSが送信されることを確認してください。

![aws-iot-1clic11](https://docs.google.com/drawings/d/e/2PACX-1vQmP2TdPjM8wGSLbtQwAYzZrU29sctmPOlFB3rRUs8K-cGTm7MjVNZRbdMXU4bRvrck3wpHy9Igacwn/pub?w=323&amp;h=570)

SMSが送信されない場合、これまでの設定をご確認ください。 また、AWS IoT 1-Click のダッシュボードから呼び出し回数を確認できますので、こちらも合わせてご確認ください。

![aws-iot-1click12](https://docs.google.com/drawings/d/e/2PACX-1vQCVDnHA_m2gQuOwDHD_KQ1jKBetmxn7g2KxU5mnF27XBLRv21_ZhcrJhOCpBVQZUcoTkGnDiGF7UxS/pub?w=864&amp;h=688)


<h3 id="content4">4. プレイスメントからデバイスの割り当てを外そう</h3>


[管理] > [プロジェクト] とクリックした後、解除を行いたいデバイスが所属しているプロジェクトをクリックします。

![1 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vQ5QgL25ObwbFDcqpdM7eJd9a2UEItxLOxXzrDKB2AkOtKF1Z-9DbdSmhpg5ve29jc5647a-a_IPeG6/pub?w=601&h=591)

[プレイスメント] から解除したいデバイスの [...] をクリックした後に表示される [プレイスメントの編集] をクリックします。

![2 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vS8f28yZgWHTjGktSFGbSNqRVgbbl1TX7Y99p2zlvbmd6r5rdVqvyCI9cNVvJiXp5KjJiO7XK71b6a-/pub?w=929&h=529)

デバイスが表示されている部分の [クリア] をクリックした後、[プレイスメントの更新] をクリックします。

![3 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vSAticSljF3nnjF3xLZrwUNKVY7PHmwzPjSfFJqmcJJ8-n6S1LMqUtdm_IVDrZdkfQThKlSLa-pbMls/pub?w=928&h=407)

これでデバイスとプレイスメントの割り当てが無くなりました。

こちらでハンズオンは終了です。お疲れ様でした。

## 最後に
最後に貸し出ししたSORACOM LTE-M Buttonをスタッフに手渡してください。
お渡し頂くタイミングで、プレイスメントの割り当てが無くなっているかを確認させていただきます。
