import boto3
import os

def lambda_handler(event, context):

    # Get click type from event.(these values was set by SORACOM.)
    clickType = event['deviceEvent']['buttonClicked']['clickType']

    # Set message.
    if clickType == "SINGLE":
        message = '塾が終わりました、迎えにきてください'
    elif clickType == "DOUBLE":
        message = '塾が終わるのが遅くなります。もう少しかかります'
    else:
        # clickType is "LONG"
        message = '今日は帰れません。'

    # Connect client.
    connect = boto3.client('connect')
    
    # Call to your mobile phone. See your connect flow.
    connect.start_outbound_voice_contact(
        DestinationPhoneNumber = os.environ['YourMobilePhoneNumber'],
        ContactFlowId = os.environ['FlowID'],
        InstanceId = os.environ['InstanceID'],
        SourcePhoneNumber = os.environ['YourConnectPhoneNumber'],
        Attributes = {
            'message': message
        }
    )
