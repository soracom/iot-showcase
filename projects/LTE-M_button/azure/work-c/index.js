var connectionString = '運営から入手';
var targetDevice = '運営から入手';

var Client = require('azure-iothub').Client;
var Message = require('azure-iot-common').Message;

var serviceClient = Client.fromConnectionString(connectionString);
serviceClient.open(function (err) {
    if (err) {
        console.error('Could not connect: ' + err.message);
    }
    else
    {
        serviceClient.getFeedbackReceiver(receiveFeedback);
    }
});

function printResultFor(op) {
    return function printResult(err, res) {
      if (err) console.log(op + ' error: ' + err.toString());
      if (res) console.log(op + ' status: ' + res.constructor.name);
    };
}

function receiveFeedback(err, receiver){
    receiver.on('message', function (msg) {
        console.log('Feedback message:')
        console.log(msg.getData().toString('utf-8'));
    });
}

module.exports = async function (context, req) {
    context.log('JavaScript HTTP trigger function processed a request.');
    console.log(req);

    if (req.body && req.body.clickType) {
        console.log(req.body.clickType);
        var message = new Message(req.body.clickType.toString());
        message.ack = 'full';
        message.messageId = "My Message ID";
        console.log('Sending message: ' + message.getData());
        await serviceClient.send(targetDevice, message, printResultFor('send'));            
        context.res = {
            // status: 200, /* Defaults to 200 */
            body: req.body.clickType + " click detected."
        };
    }
    else {
        context.res = {
            status: 400,
            body: "Please pass clickType in the request body"
        };
    }
};