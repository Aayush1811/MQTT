#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoMqttClient.h>

const char* ssid = "Mr uptownfunks";
const char* password = "B101_102";
const char* mqtt_server = "broker.mqtt-dashboard.com";
const char* topic ; 

String str1;
int a = 12;

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(String topic, byte* payload, unsigned int length) 
{
  //Serial.print("Message arrived [");
  //Serial.print(topic);
  //Serial.print("] ");

  //Serial.println(topic);
  
  //Serial.println();
  if(topic == "bot1")
  
  {
  str1 = "";
  //Serial.println("this is bot1");
    for (int i = 0; i < length; i++) 
  {
    str1 += (char)payload[i];
    //Serial.print((char)payload[i]);
  }

    
  
  

  
  client.subscribe("topic");
  //Serial.println(str);

  topic = "";

  
  
  }
}

void reconnect() 
{
  
  while (!client.connected())
  {
    Serial.println("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    
    if (client.connect(clientId.c_str())) 
    {
      Serial.print("connected to ");
      Serial.println(mqtt_server);
      client.subscribe("bot1");
      //client.subscribe("bot2");
      //client.subscribe("id");
    }
    
    else 
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }

  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() 
{
  
  if (!client.connected()) 
  {
    reconnect();
  }
  client.loop();

  client.publish("bot1","aayush");



}
