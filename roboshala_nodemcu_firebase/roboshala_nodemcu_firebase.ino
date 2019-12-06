#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

//#include <FirebaseArduino.h>
//#include "DHT.h"
String myString; // complete message from arduino, which consistors of snesors data
char rdata; // received charactors
int firstVal, secondVal,thirdVal;
#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "iotbot-2877e.firebaseio.com"
#define WIFI_SSID "HKB" // Change the name of your WIFI
#define WIFI_PASSWORD "hehehaha" // Change the password of your WIFI
#define FIREBASE_AUTH "Ks0DcIoItCeCTV9F2xO5QIy9WYvYO8p579OBkNcZ"

//#define DHTPIN 14    // Data Pin of DHT 11 , for NodeMCU D5 GPIO no. is 14

//#define DHTTYPE DHT11   // DHT 11
//DHT dht(DHTPIN, DHTTYPE);
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void setup() {

 
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   //dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
 // Serial.begin(115200);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
}

void loop() {
 
    if (Serial.available() > 0 )
  {
    rdata = Serial.read();
    myString = myString+ rdata;
   
    Serial.print(rdata);
    if( rdata == '\n')
    {
   //  Serial.println(myString);
  // Serial.println("fahad");
// new code
String l = getValue(myString, ',', 0);
String m = getValue(myString, ',', 1);
String n = getValue(myString, ',', 2);


firstVal = l.toInt();
secondVal = m.toInt();
thirdVal = n.toInt();

  myString = "";
// end new code
    }
  }
  
  
 // float h = dht.readHumidity();
  
 // float t = dht.readTemperature();  // Reading temperature as Celsius (the default)
  Firebase.setInt ("one",firstVal);
  Firebase.setInt ("two",secondVal);
  Firebase.setInt ("three",thirdVal);
  delay(200);
}
