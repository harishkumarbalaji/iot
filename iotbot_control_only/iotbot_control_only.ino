#include <SoftwareSerial.h>
SoftwareSerial Forward(0,1);
SoftwareSerial Backward(2,3);
SoftwareSerial Direction(4,5);
long cm1,cm2;
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
const int rf = 7;
const int enA = 10;
const int enB = 11;

int dir=0;
int dirnew;
#define PWM 90
#define DIS 25
//#define Stop 0
//#define forward 1
//#define backward 2
//#define Left 3
//#define Right 4
 
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
// Forward.begin(4800);
 //Backward.begin(4800);
 Direction.begin(4800);
}
void loop()
{ 
 if(Direction.available()>0)
 {
  dir=Direction.read();
 }
   
  Serial.println(dir);
 
//  cm1=FrontSensor();
 // cm2=BackSensor();
  if(dirnew != dir)
  {
  if(dir==1)
  {
  forward();
  dirnew=dir;
 }
   else if(dir==2)
  {
  turn_left();
  dirnew=dir;
 }
  else if(dir==3)
  {
  turn_right();
  dirnew=dir;
 }
  else if(dir==4)
  {
  reverse();
  dirnew=dir;
  }
   else
  {
    stop();
    dirnew=dir;
  }
  }
 //dir=dirnew;
  //delay(100);
 } 

void forward()
{
 digitalWrite(lb, HIGH);
 digitalWrite(lf, LOW);
 digitalWrite(rb, HIGH);
 digitalWrite(rf, LOW);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}
void turn_left()
{
 digitalWrite(lb, LOW);
 digitalWrite(lf, HIGH);
 digitalWrite(rb, HIGH);
 digitalWrite(rf, LOW);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}
void turn_right()
{
 digitalWrite(lb, HIGH);
 digitalWrite(lf, LOW);
 digitalWrite(rb, LOW);
 digitalWrite(rf, HIGH);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}
void reverse()
{
 digitalWrite(lb, LOW);
 digitalWrite(lf, HIGH);
 digitalWrite(rb, LOW);
 digitalWrite(rf, HIGH);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}
void stop()
{
 digitalWrite(lb, LOW);
 digitalWrite(lf, LOW);
 digitalWrite(rb, LOW);
 digitalWrite(rf, LOW);
 analogWrite(enA, LOW);
 analogWrite(enB, LOW);
}
