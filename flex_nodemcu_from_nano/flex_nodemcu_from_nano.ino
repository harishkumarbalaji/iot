#include <SoftwareSerial.h>

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
//SoftwareSerial uno(D6,D7);

// Set these to run example.
#define FIREBASE_HOST "iotboard-d8175.firebaseio.com"
#define FIREBASE_AUTH "SsqpDHwofbq4JEYUH7okJv2sg0bD0v3YI53893Yh"
#define WIFI_SSID "HKB"
#define WIFI_PASSWORD "hehehaha"

void setup() {
  Serial.begin(9600);
 // uno.begin(4800);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  pinMode(2,OUTPUT);
    digitalWrite(2,LOW);
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int flex = 0;

void loop() {
  // set value
 /* if(uno.available()>0)
  {
    flex=uno.parseInt();
  }*/
  Firebase.setInt("flex",flex);
  Serial.println(flex); 
 delay(200);
  }
  
  
  
  
