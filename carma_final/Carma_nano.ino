#include <SoftwareSerial.h>
SoftwareSerial Forward(0,2);
SoftwareSerial Backward(1,3);
SoftwareSerial Direction(4,5);
long cm1,cm2,cm3,cm4;
const int trigPinf = A0;
const int echoPinf = A1;
const int trigPinl = A2; //13;
const int echoPinl = A3;
const int trigPinr = A4;
const int echoPinr = A5;
const int trigPinb = 6;
const int echoPinb = 7;
const int lb = 8;
const int lf = 9;
const int rb = 12;
const int rf = 13;
const int enA = 10;
const int enB = 11;

int dir;
int dirnew;
#define PWM 90
#define DIS 25
#define Stop 0
#define forward 1
#define backward 2
#define Left 3
#define Right 4
 
void setup()
{
 pinMode(trigPinf, OUTPUT);
 pinMode(echoPinf, INPUT);

 pinMode(trigPinl, OUTPUT);
 pinMode(echoPinl, INPUT);
 pinMode(trigPinr, OUTPUT);
 pinMode(echoPinr, INPUT);
 pinMode(trigPinb,OUTPUT);
 pinMode(echoPinb,INPUT);

 pinMode (lb, OUTPUT);
 pinMode (lf, OUTPUT);
 pinMode (rb, OUTPUT);
 pinMode (rf, OUTPUT);
 pinMode (enA, OUTPUT);
 pinMode (enB, OUTPUT);
 Serial.begin(9600);
 Forward.begin(4800);
 Backward.begin(4800);
 Direction.begin(4800);
}
int direction()
{
  int Dir;
  Dir=Direction.parseInt();
  return Dir;
}
void DIRECTION()
{
  if(dirnew!=dir)
  {
  if(dir==1)
  {
  FORWARD();
  dirnew=dir;
 }
   else if(dir==2)
  {
  LEFT();
  
  delay(700);
  dirnew=dir;
 }
  else if(dir==3)
  {
  RIGHT();
  
  delay(700);
  dirnew=dir;
 }
  else if(dir==4)
  {
  BACKWARD();
  dirnew=dir;
  }
  else
  {
    STOP();
    dirnew=dir;
  }
  
  }
  
  } 

void loop()
{ 
  if(Direction.available()>0)
  {
  dir=Direction.read();
  }
  
//Serial.println(dir);
 //Serial.println(dirnew);
  cm1=FrontSensor();
  cm2=BackSensor();
 Serial.println(cm1);
  cm3=LeftSensor();
  cm4=RightSensor();
  if ( cm1 < DIS && cm4 <DIS && cm3<DIS) // obstacle infront of all 3 sides
 {
 BACKWARD();
 delay(500);
 STOP();
 
//then BACKWARD

 }
 else if (cm1 <DIS && cm4 <DIS && cm3 >DIS) // obstacle on right and front sides
 {
 RIGHT();
 delay(500);
 STOP();

// turn left side

 }
 else if (cm1 <DIS && cm4 >DIS && cm3 <DIS) // obstacle on left and front sides
 {
 LEFT();
 delay(500);
 STOP();
 
// turn right side

 }
 else if (cm1 <DIS && cm4 >DIS && cm3 >DIS) // obstacle on front sides
 {
 LEFT();
 delay(500);
 STOP();
// then turn right

 }
 else if (cm1 >DIS && cm4 >DIS && cm3 <DIS) // obstacle on left sides
 {
 LEFT();
// then turn right and then FORWARD
 delay(100);
 STOP();
  
 }
 else if (cm1 >DIS && cm4 <DIS && cm3 >DIS) // obstacle on right sides
 {
 RIGHT();
// then turn left and then right
 delay(100);
 STOP();

 }
 else if (cm2 <DIS && cm4 <DIS && cm3 >DIS) // obstacle on back and right sides
 {
 LEFT();
// then turn left and then right
 delay(100);
 FORWARD();

 }
 else if (cm2 <DIS && cm4 >DIS && cm3 <DIS) // obstacle on back and left sides
 {
 RIGHT();
// then turn left and then right
 delay(100);
 FORWARD();

 }
 else if (cm2 <DIS && cm4 <DIS && cm3 <DIS) // obstacle on back,left and right sides
 {
 FORWARD();
 
 }
 else
 {
  DIRECTION();
 }
 DIRECTION();


//Serial.println(dir);
 // Serial.println(dirnew);
  Forward.println(cm1);
//Serial.println(cm1);
  Backward.println(cm2);
  delay(1000);
  
}
void FORWARD()
{
 digitalWrite(lb, HIGH);
 digitalWrite(lf, LOW);
 digitalWrite(rb, HIGH);
 digitalWrite(rf, LOW);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}
void LEFT()
{
 digitalWrite(lb, LOW);
 digitalWrite(lf, HIGH);
 digitalWrite(rb, HIGH);
 digitalWrite(rf, LOW);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}
void RIGHT()
{
 digitalWrite(lb, HIGH);
 digitalWrite(lf, LOW);
 digitalWrite(rb, LOW);
 digitalWrite(rf, HIGH);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}
void BACKWARD()
{
 digitalWrite(lb, LOW);
 digitalWrite(lf, HIGH);
 digitalWrite(rb, LOW);
 digitalWrite(rf, HIGH);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}
void STOP()
{
 digitalWrite(lb, LOW);
 digitalWrite(lf, LOW);
 digitalWrite(rb, LOW);
 digitalWrite(rf, LOW);
 analogWrite(enA, LOW);
 analogWrite(enB, LOW);
}
long FrontSensor()
{
long dur;
 digitalWrite(trigPinf, LOW);
 delayMicroseconds(5); // delays are required for a succesful sensor
//operation.
 digitalWrite(trigPinf, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPinf, LOW);
 dur = pulseIn(echoPinf, HIGH);
 return (dur/58);// convert the distance to centimeters.
}
long RightSensor()
{
long dur;
 digitalWrite(trigPinl, LOW);
 delayMicroseconds(5); // delays are required for a succesful sensor
//operation.
 digitalWrite(trigPinl, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPinl, LOW);
 dur = pulseIn(echoPinl, HIGH);
 return (dur/58);// convert the distance to centimeters.
}
long LeftSensor() 
{
long dur;
 digitalWrite(trigPinr, LOW);
 delayMicroseconds(5); // delays are required for a succesful sensor
//operation.
 digitalWrite(trigPinr, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPinr, LOW);
 dur = pulseIn(echoPinr, HIGH);
 return (dur/58);// convert the distance to centimeters.
}
long BackSensor()
{
long dur;
 digitalWrite(trigPinb, LOW);
 delayMicroseconds(5); // delays are required for a succesful sensor
//operation.
 digitalWrite(trigPinb, HIGH);
 delayMicroseconds(10); //this delay is required as well!
 digitalWrite(trigPinb, LOW);
 dur = pulseIn(echoPinb, HIGH);
 return (dur/58);// convert the distance to centimeters.
}
