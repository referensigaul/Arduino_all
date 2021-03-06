#include <NewPing.h>
#define ANODE3 11 
#define ANODE1 13
#define ANODE2 12
 #define TRIGGER_PIN  8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.


# define TASK_100HZ 1
# define TASK_50HZ 2
# define TASK_10HZ 10
# define TASK_1HZ 100

unsigned long previousTime = 0;
unsigned long currentTime = 0;
unsigned long dt = 0;

unsigned long frameCounter = 0;


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  // put your setup code here, to run once:
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(ANODE3,OUTPUT);
pinMode(ANODE1,OUTPUT);
pinMode(ANODE2,OUTPUT);

Serial.begin(9600);


}

int value;
int num1;
int num2;
int num3;
int CurrentPos=1;
void loop() {



 currentTime = micros();
  dt = currentTime - previousTime;
  if (dt >= 10000) {//10 milli seconds(1/100=0.01)
    frameCounter++;
  
     
         
    if (frameCounter % TASK_50HZ == 0) {
    
      value=sonar.ping_cm();
       num1=(int)value/100;
        num2=(int)((value%100)/10);
          num3=(int)((value%100)%10);    
        
          
       
      

    }
    if (frameCounter % TASK_10HZ == 0) {
    
     
        
         
        

      
    } if (frameCounter % TASK_1HZ == 0) { // 1 Hz tasks 
     
    
         
    } 
    previousTime = currentTime;
  } 
  
  if (frameCounter >= 100) {
    frameCounter = 0;
  }

  


        
 
          Display(1,num3);
           delay(10);
          Display(2,num2);
         delay(5);
         Display(3,num1);
        delay(5);

        Serial.print("Current pos=");
        Serial.println(CurrentPos);




}

void Display(int digit,int value)
{

  if (digit == 1)
  {
    digitalWrite(ANODE1, HIGH);
    digitalWrite(ANODE2, LOW);
    digitalWrite(ANODE3, LOW);

  } else if (digit == 2)
  {
    digitalWrite(ANODE1, LOW);
    digitalWrite(ANODE2, HIGH);
    digitalWrite(ANODE3, LOW);
  }
  else {
    digitalWrite(ANODE1, LOW);
    digitalWrite(ANODE2, LOW);
    digitalWrite(ANODE3, HIGH);
  }
  
    digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);


if(value==0)
{
  
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
else if(value==1)
 {

  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
 }
 else if(value==2)
{ 
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
 
}
else if(value==3)
{ 

digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(7,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
}
else if(value==4)
{
 

  digitalWrite(2,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(3,LOW);
}else if(value==5)
{

  digitalWrite(1,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
}
else if(value==6)
{
 digitalWrite(1,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
}else if(value==7)
{

  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
}
else if(value==8)
{
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
else
{
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
}

}
