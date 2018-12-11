# SORACOM LTE-M Button を AWS IoT 1-Click から解除

* [目次に戻る](../index#closing)

登録したボタンは解除することができます。主に別の AWS アカウントへ再登録する際に利用する機能です。

## 作業: プレイスメントから外す

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home) を開きログインしたあと、リージョンを "オレゴン" に変更し、 AWS IoT 1-Click のコンソールを開きます。

[管理] > [プロジェクト] とクリックした後、解除を行いたいデバイスが所属しているプロジェクトをクリックします。

![1 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vTKFP7PyM2LajuqPhfZ8Gc3bGus8fbi1xJ6alpcEoOKLmPiM9m0YZ9F8Zn0t8KSQvN61lZh4F4zxov1/pub?w=601&h=591)

[プレイスメント] から解除したいデバイスの [...] をクリックした後に表示される [プレイスメントの編集] をクリックします。

![2 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vS8f28yZgWHTjGktSFGbSNqRVgbbl1TX7Y99p2zlvbmd6r5rdVqvyCI9cNVvJiXp5KjJiO7XK71b6a-/pub?w=929&h=529)

デバイスが表示されている部分の [クリア] をクリックした後、[プレイスメントの更新] をクリックします。

![3 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vSAticSljF3nnjF3xLZrwUNKVY7PHmwzPjSfFJqmcJJ8-n6S1LMqUtdm_IVDrZdkfQThKlSLa-pbMls/pub?w=928&h=407)

これでデバイスとプレイスメントの割り当てが無くなりました。

## 作業: 登録解除をする

[管理] > [デバイス] とクリックした後、解除を行いたいデバイスの [...] をクリックした後に表示される [デバイスの登録解除] をクリックします。  
最後に確認ダイアログの [登録解除] で解除が完了します。

※プレイスメントに割り当てられているデバイスは解除できませんので、プレイスメントから外してから行ってください。

![mkmk-button / 1 unclaim](https://docs.google.com/drawings/d/e/2PACX-1vTCsBV32iOWgBn8QZJbmiRQIIv1k4JxFmtw3STpYFl_I-iGZn-ejHO_7gSg1Nvv-IxkdtnpbOMHHUB8/pub?w=928&h=269)

一覧から対象デバイスが無くなれば解除完了です。

## 以上でこの章は終了です

(貸し出しの方へ) **必ずスタッフに解除確認をもらうようにしてください**

* [目次に戻る](../index#closing)
