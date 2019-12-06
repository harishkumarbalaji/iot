
#include <SoftwareSerial.h>

#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>


String myString; // complete message from arduino, which consistors of snesors data
char rdata; // received charactors
int firstVal, secondVal,thirdVal;
int RecVal;
#include  <ESP8266WiFi.h>
SoftwareSerial NodeMCU1(D2,D3);
SoftwareSerial NodeMCU2(D6,D7);
SoftwareSerial Nano(D8,D5);
#define FIREBASE_HOST "iottt-21bfd.firebaseio.com"
#define WIFI_SSID "BB" // Change the name of your WIFI
#define WIFI_PASSWORD "##denack##" // Change the password of your WIFI
#define FIREBASE_AUTH "1Sd7RSshy55dNAC0KMgYqj5ckKtm8p3cwZUiGOVp"



void setup() {

 
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
   Serial.begin(9600);
    NodeMCU1.begin(4800);
    NodeMCU2.begin(4800);
    Nano.begin(4800);
   
  }
   
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
}

void loop() {
 
    if ((NodeMCU1.available() > 0 )||(NodeMCU2.available()>0))
  {
    firstVal=NodeMCU1.parseInt();
    secondVal=NodeMCU2.parseInt();
  }
  
 
  Firebase.setInt ("one",firstVal);
  Firebase.setInt ("two",secondVal);
  
  RecVal=Firebase.getString("Direction").toInt();
  
  
  Serial.println(secondVal);
  Nano.write(RecVal);
  delay(500);
}
