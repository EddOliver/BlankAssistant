#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Pushbutton.h>
#define azul D2

Pushbutton button(D1);
const char* ssid = "";
const char* password =  "";
const char* mqttServer = "";
const int mqttPort = ;
const char* mqttUser = "";
const char* mqttPassword = "";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
  pinMode(D2,OUTPUT); 
  pinMode(D3,OUTPUT); 
  pinMode(D4,OUTPUT);
  digitalWrite(D2,LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,LOW);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client1", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
  client.subscribe("esp2/test");
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  String data="";
  for (int i = 0; i < length; i++) {
    data+=char(payload[i]);
  }
  Serial.print(data);
  if(data=="Hello from ESP8266")
  {
     digitalWrite(D2, !digitalRead(D2)); 
     digitalWrite(D3, !digitalRead(D3)); 
     digitalWrite(D4, !digitalRead(D4)); 
  }
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() {
    client.loop();
  if (button.getSingleDebouncedRelease())
    {
     client.publish("esp1/test", "Hello from ESP8266"); 
    }

}
