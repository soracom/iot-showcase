# プレイスメントからデバイスの割り当てを外す

デバイスに新しいプロジェクトを割り当てたり、デバイスの解除を行う前には必ずプレイスメントからデバイスの割り当てを解除する必要があるため、ここでプレイスメントからデバイスの割り当てを外す作業を学んでおきます。  
（比較的頻繁に行う作業です）

## 作業: プレイスメントから外す

[AWS マネジメントコンソール](https://console.aws.amazon.com/console/home) を開きログインしたあと、リージョンを "オレゴン" に変更し、 AWS IoT 1-Click のコンソールを開きます。

[管理] > [プロジェクト] とクリックした後、解除を行いたいデバイスが所属しているプロジェクトをクリックします。

![1 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vTKFP7PyM2LajuqPhfZ8Gc3bGus8fbi1xJ6alpcEoOKLmPiM9m0YZ9F8Zn0t8KSQvN61lZh4F4zxov1/pub?w=601&h=591)

[プレイスメント] から解除したいデバイスの [...] をクリックした後に表示される [プレイスメントの編集] をクリックします。

![2 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vS8f28yZgWHTjGktSFGbSNqRVgbbl1TX7Y99p2zlvbmd6r5rdVqvyCI9cNVvJiXp5KjJiO7XK71b6a-/pub?w=929&h=529)

デバイスが表示されている部分の [クリア] をクリックした後、[プレイスメントの更新] をクリックします。

![3 unassing placement](https://docs.google.com/drawings/d/e/2PACX-1vSAticSljF3nnjF3xLZrwUNKVY7PHmwzPjSfFJqmcJJ8-n6S1LMqUtdm_IVDrZdkfQThKlSLa-pbMls/pub?w=928&h=407)

これでデバイスとプレイスメントの割り当てが無くなりました。

## プレイスメントへの再割り当て

外す時と同様の手順でプレイスメントの編集から [デバイスの選択] で割り当てたいデバイスを選び [プレイスメントの更新] をクリックします。

## 以上でこの章は終了です

* [目次に戻る](index#work-a)
