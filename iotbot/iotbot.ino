#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

int lf = 6 ;
int lb = 3 ;

int rb = 4 ;
int rf = 5 ;
int s=0;
#define STOP 0
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
void setDirection(int dir) {

  if ( dir == FORWARD ) {
    digitalWrite(lf, LOW);   // Left wheel forward
    digitalWrite(lb, HIGH);
    digitalWrite(rb, HIGH);  // Right wheel forward
    digitalWrite(rf, LOW);
  }
  else if ( dir == LEFT ) {
    digitalWrite(lf, HIGH);   // Left wheel forward
    digitalWrite(lb, LOW );
    digitalWrite(rb, HIGH );  // Right wheel forward
    digitalWrite(rf, LOW);
  }
  else if ( dir == RIGHT ) {
    digitalWrite(lf, LOW);   // Left wheel forward
    digitalWrite(lb, HIGH);
    digitalWrite(rb, LOW);  // Right wheel forward
    digitalWrite(rf, HIGH);
  }
  else if ( dir == STOP ) {
    digitalWrite(lf, HIGH);   // Left wheel forward
    digitalWrite(lb, HIGH );
    digitalWrite(rb, HIGH );  // Right wheel forward
    digitalWrite(rf, HIGH);
  }
  else if ( dir == BACKWARD ) {
    digitalWrite(lf, HIGH );   // Left wheel forward
    digitalWrite(lb, LOW );
    digitalWrite(rb, LOW );  // Right wheel forward
    digitalWrite(rf, HIGH );
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() 
{
 if(Serial.available()>0){
 s=Serial.read();
 Serial.println(s); 

 }
}
