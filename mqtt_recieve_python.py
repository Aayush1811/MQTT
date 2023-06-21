import paho.mqtt.client as mqttclient 

s = 0


def on_connect(client,userdata,flag,rc):
    if rc == 0:
        print("client is connectd")
        global connected
        connected = True
        

    else:
        print("client is not connected")
        
def on_message(client,userdata,message):
    print("msg")
    messagearrieved = True
    global s
    s = message.payload.decode("utf-8")
    s = str(s)
    
        
connected = False
messagearrieved = False

#brokeradd = "64:ff9b::12c4:a6b5"
brokeradd = "broker.mqtt-dashboard.com"
port = 1883

client = mqttclient.Client("MQTT")
client.on_connect=on_connect
client.on_message=on_message
client.connect(brokeradd,port=port)
client.loop_start()
client.subscribe("bot1")

while(True):
    
    print(s)
    if(s == "1"):
        break
