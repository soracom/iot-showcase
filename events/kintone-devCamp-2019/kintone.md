# kintone devCamp 2019 ― IoT ハンズオン

[目次へ戻る](index#index)

## SORACOM Beam で kintone と連携する

ボタンからのデータを SORACOM のデータ転送支援サービス [SORACOM Beam](https://soracom.jp/services/beam/) を用いて kintone と連携します。

### ハンズオンのゴール

![kintone-devCamp2019 / overview kintone](https://docs.google.com/drawings/d/e/2PACX-1vRFQVh0vA_KSqx_ivqey-cOQvcBZDrd0doU4EB-Hj6MB4bYLWBGvdjPlg1jej3o9GgoH1hyL9L54FoE/pub?w=1099&h=364)

<h2 id="w1">作業 1: SIM グループの設定を行う</h2>

**解説:** 先に設定した `button` グループに対して、SORACOM Beam の設定を追加します。

SIM 管理画面の SIM(Button) のグループ列に表示されている `button` をクリックします。

![](https://dev.soracom.io/jp/img/gs_button/group_configuration_3.png)

SIM グループ設定画面内の [SORACOM Beam 設定] を開き、 [＋] をクリックした後、UDP → HTTP/HTTPS エントリポイント]をクリックします。

![](https://dev.soracom.io/jp/img/gs_button/beam_group_configuration_4.png)

[SORACOM Beam - UDP → HTTP/HTTPS 設定]ダイアログが開いたら、以下を入力し保存します。

| 項目名 | 値 |	解説 |
|-------|----|------|
| プロトコル | HTTPS | 転送先へ転送する際に使用するプロトコル |
| ホスト名 | 《運営から入手: `beam-host`》 | 転送先のホスト名 |
| パス | 《運営から入手: `beam-path`》 | 転送先のパス |

また、設定の下方で「カスタムヘッダ」を追加してください。

| アクション | ヘッダ名 | 値 |
|-----------|---------|----|
| 追加      | X-BUTTON-NO | 《運営から入手: `button-no`》 |

![kintone-devCamp2019 / SORACOM Beam setting / custom header](https://docs.google.com/drawings/d/e/2PACX-1vQjiPTZQi1UcjZBGmj7mob1_UYEMpZOYXoOEqJBttpnkbjYD03WGUeIyaIU6_nKq3k3AH8WMHdOAEhj/pub?w=511&h=371)

SORACOM Beam 設定が以下のようなっていることを確認してから [保存] します。

![kintone-devCamp2019 / SORACOM Beam setting](https://docs.google.com/drawings/d/e/2PACX-1vQ40g49iyJU176CVS-BIjAGeggsurvP94V1HcLme3sZezdt1WlXGyWXerYzb-pWB6MHemHec_kijLSI/pub?w=574&h=427)

SIM グループ設定画面内の [Unified Endpoint 設定] を開き、フォーマットを **SORACOM Beam** に変更し、[保存] します。

![kintone-devCamp2019 / Unified Endpoint Setting](https://docs.google.com/drawings/d/e/2PACX-1vRkcsGoTDDS0mDGsPjdGx_LFzvJOs5SCo2vXRQogZp9czq2oTokdarbm5A3em3dkDtIhOUuldoNuQRB/pub?w=780&h=447)

<h2 id="w2">作業 2: 動作確認</h2>

**解説:** SORACOM Beam から先のシステムは準備済みであるため、SORACOM Beam の設定のみで完了です。

kintone アプリを表示します。

* URL: 《運営から入手: `kintone-app-url`》
* ID: 《運営から入手: `kintone-app-userid`》
* Password: 《運営から入手: `kintone-app-password`》

ボタンを押します。kintone アプリで以下のように押した情報が表示されれば成功です。

![kintone-devCamp2019 / kintone app](https://docs.google.com/drawings/d/e/2PACX-1vRFSl12xG8u74BrLDFMrzfVtayirDbckzcpANMrhVkVWK2NrPz_x0H6RkGdohmex3peglGOm5ZcQnh4/pub?w=1115&h=184)

<h2 id="clear-up">あとかたづけ</h2>

あとかたづけは特にありません。

<h2 id="troubleshoot">トラブルシューティング</h2>

* LED が赤色になってしまう;
    * kintone アプリにデータは送信されているのに LED が赤色の場合は、Unified Endpoint 設定を見直してください。
    * kintone アプリにデータが送信されていない場合は、 SORACOM Beam 設定を見直してください。

---

[目次へ戻る](index#index)

[EoT]
