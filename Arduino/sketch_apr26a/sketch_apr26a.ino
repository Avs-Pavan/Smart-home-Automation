#include <ESP8266WiFi.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>



// Replace your wifi credentials here
const char* ssid     = "venke";// ssid: your wifi name

const char* password = "11111111";// password: your wifi password


const char* mqtt_server = "142.93.57.145";
const char* mqtt_username = "";
const char* mqtt_password = "";
const int mqtt_port =1883;

int bedRoom = 5;
int hall = 4;
int garage = 3;



WiFiClient  wifiClient;
PubSubClient client(wifiClient);



void setup() {
  Serial.begin(115200);
  delay(100);
  
 pinMode(bedRoom, OUTPUT);
 pinMode(hall, OUTPUT);
  pinMode(garage, OUTPUT);

  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

}

void callback(char* topic, byte* payload, unsigned int length) {
  String incommingMessage = "";
  for (int i = 0; i < length; i++) incommingMessage+=(char)payload[i];

  Serial.println("Message arrived ["+String(topic)+"]"+incommingMessage);
  

 if(incommingMessage.equalsIgnoreCase("111")){
   digitalWrite(bedRoom, HIGH);
 }

  if(incommingMessage.equalsIgnoreCase("112")){
  digitalWrite(bedRoom, LOW);
  }


 if(incommingMessage.equalsIgnoreCase("211")){
   digitalWrite(hall, HIGH);
 }

  if(incommingMessage.equalsIgnoreCase("212")){
  digitalWrite(hall, LOW);
  }
   if(incommingMessage.equalsIgnoreCase("421")){
   digitalWrite(garage, HIGH);
 }

  if(incommingMessage.equalsIgnoreCase("422")){
  digitalWrite(garage, LOW);
  }
}
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";   // Create a random client ID
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");

      client.subscribe("shas");   // subscribe the topics here

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");   // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) reconnect(); // check if client is connected
  client.loop();
}