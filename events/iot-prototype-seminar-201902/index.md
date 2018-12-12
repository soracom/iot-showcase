# Let's IoT プロトタイピング！ オンライン講座 〜今から帰るよボタンを作ってみよう〜

* イベントページ: [Day1](https://pages.soracom.jp/20190205_IoT-Prototype_lp.html), [Day2](https://pages.soracom.jp/20190206_IoT-Prototype_lp.html)

## セミナー中で使用するプログラムの配布

### Day 1

* (特に配布するプログラムはありません)

### Day 2

* <a href="https://github.com/j3tm0t0/1-click/blob/master/functions/ifttt/index.js" target="_blank">IFTTT 送信用 Lambda 関数 (別のタブで開きます)</a>
* AWS Lambda 関数 (1click-ifttt) のテスト用 JSON:
    ```json
    {
        "deviceEvent": {
            "buttonClicked": {
                "clickType": "SINGLE",
                "reportedTime": "2018-05-04T23:26:33.747Z"
            }
        },
        "deviceInfo": {
            "attributes": {},
            "type": "button",
            "deviceId": " G030PMXXXXXXXXXX ",
            "remainingLife": 5
        },
        "placementInfo": {
            "projectName": "TestProject",
            "placementName": "button1",
            "attributes": {
                "event": "button",
                "key": "YOUR_WEBHOOK_KEY",
                "value1": "値1"
            },
            "devices": {
                "myButton": " G030PMXXXXXXXXXX "
            }
        }
    }
    ```
