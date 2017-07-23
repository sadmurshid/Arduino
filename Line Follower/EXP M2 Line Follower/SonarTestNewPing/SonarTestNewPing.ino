#include <NewPing.h>

#define SONAR_NUM 3
#define MAX_DISTANCE 200
#define PING_INTERVAL 33

int motorpin1 = 4;          
int motorpin2 = 5;
int pwm1 = 6;                

int motorpin3 = 7;
int motorpin4 = 8;
int pwm2 = 9;               

int s1 = 10; 
int s2 = 11; 
int s3 = 12; 
int s4 = 13; 



unsigned long pingTimer[SONAR_NUM];
unsigned int cm[SONAR_NUM];
uint8_t currentSensor=0;

NewPing sonar[SONAR_NUM]={ 
  NewPing(A3,A0,MAX_DISTANCE),
  NewPing(A4,A1,MAX_DISTANCE),
  NewPing(A5,A2,MAX_DISTANCE),
  };

//NewPing sonar();

void setup() {
  Serial.begin(9600);
  pingTimer[0]=millis()+75;
  for(uint8_t i=1; i<SONAR_NUM; i++)
  {
    pingTimer[i]=pingTimer[i-1]+PING_INTERVAL;
  }
  
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);


  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {
  for(uint8_t i=0; i<SONAR_NUM; i++)
  {
    if(millis()>=pingTimer[i])
    {
      pingTimer[i]+=PING_INTERVAL*SONAR_NUM;
      if(i==0&&currentSensor==SONAR_NUM-1)
        oneSensorCycle();
      sonar[currentSensor].timer_stop();
      currentSensor=i;
      cm[currentSensor]=0;
      sonar[currentSensor].ping_timer(echoCheck);
    }
  }
if((cm[0]==0||cm[0]>15)&&(cm[1]==0||cm[1]>15)&&(cm[2]==0||cm[2]>15))
  forward();

else if(cm[0]<=5||cm[1]<=5||cm[2]<=5)
{
//  stand();
  reverse();
  reverse();
//  reverse();
}
else if(5<cm[0]<15)
{
  //stand();
  leftTurn();
  //stand();
}
else if(5<cm[1]<15)
{
  //stand();
  rightTurn();
  //stand();
}
else if(5<cm[2]<15)
{
  //stand();
  leftTurn();
  //stand();
}



  

}

void echoCheck()
{
  if(sonar[currentSensor].check_timer())
  {
    cm[currentSensor]=sonar[currentSensor].ping_result/US_ROUNDTRIP_CM;
  }
}

void oneSensorCycle()
{
  for(uint8_t i=0; i<SONAR_NUM; i++)
  {
    Serial.print(i);
    Serial.print("=");
    Serial.print(cm[i]);
    Serial.print("cm");
  }
  Serial.println();
}

void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 109);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 97);
}

  void reverse() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 250);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 210);
  } 

void leftTurn() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 0);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 110);
}

void rightTurn(){
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 120);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 0);
}


void slow()
{  
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 60);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 55);
}
void stand()
{
  
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 0);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 0);
}
