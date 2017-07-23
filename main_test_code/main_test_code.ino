#include <NewPing.h>

#define SONAR_NUM 3
#define MAX_DISTANCE 200
#define PING_INTERVAL 33

unsigned long pingTimer[SONAR_NUM];
unsigned int cm[SONAR_NUM];
uint8_t currentSensor=0;

NewPing sonar[SONAR_NUM]={ 
  NewPing(A3,A0,MAX_DISTANCE),
  NewPing(A4,A1,MAX_DISTANCE),
  NewPing(A5,A2,MAX_DISTANCE),
  };

int t=1;
int dis=0;

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
  long duration, distance, x1, x2, x, difference;
  int a, a1, a2, a3;
  a=digitalRead(s1);
  a1=digitalRead(s2);
  a2=digitalRead(s3);
  a3=digitalRead(s4);


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

  Serial.print(a);
  Serial.print(a1);
  Serial.print(a2);
  Serial.print(a3);
  Serial.println("   ");


  if((cm[0]==0||cm[0]>15)&&(cm[1]==0||cm[1]>15)&&(cm[2]==0||cm[2]>15))
  {
    t=1;
    if ((a==1 && a1==0 && a2==0 && a3==1) || (a==0 && a1==0 && a2==0 && a3==0)||(a==0 && a1==0 && a2==1 && a3==0) || (a==0 && a1==1 && a2==0 && a3==0) || (a==0 && a1==1 && a2==0 && a3==1) || (a==0 && a1==1 && a2==1 && a3==0))
    {
      forward();
    }
   
  
    else if ((a==0 && a1==0 && a2==0 && a3==1)||(a==0 && a1==0 && a2==1 && a3==1)||(a == 0 && a1 == 1 && a2 == 1 && a3 == 1))
    {
    leftTurn();
    }

  else if(a==1 && a1==1 && a2==0 && a3==1)
    {
      leftTurn();
      if(a==1 && a1==1 && a2==1 && a3==1)
      {
        leftTurn();
        delay(100);
      }
    }
    else if ((a==1 && a1==1 && a2==0 && a3==0)||(a==1 && a1==0 && a2==0 && a3==0)||(a==1 && a1==1 && a2==1 && a3==0)){
      rightTurn();
    }
    else if(a==1 && a1==0 && a2==1 && a3==1)
    {
      rightTurn();
      if(a==1 && a1==1 && a2==1 && a3==1)
      {
        rightTurn();
        delay(100);
      }
    }
  
   else if (a == 1 && a1 == 0 && a2 == 1 && a3 == 0){
      slow();
   }
  
   else if (a==1 && a1==1 && a2==1 && a3==1)
      reverse();
      if(a==1 && a1==1 && a2==1 && a3==1)
      {
        
          if(a==1 && a1==1 && a2==0 && a3==1)
          {
            rightTurn();
            delay(700);
          }
        
      }
  }

  else if((cm[0]<15)&&(cm[0]!=0))
  {
    leftTurn();
    while(!(a==1 && a1==1 && a2==1 && a3==1))
      {leftTurn();}
    while(!(a==0 && a1==0 && a2==0 && a3==0))
    {rightTurn();}
    rightTurn();
    delay(1000);
      
  }
  else if((cm[1]<15)&&(cm[2]<15)&&(t==1))
  {
    stand();
    dis=cm[1];
    t=2;
    forward();
  }
  else if((cm[1]<15)&&(cm[2]<15)&&(t==2)&&(dis==cm[1]))
  {
    t=2;
    forward();
  }
  else if((cm[1]<15)&&(cm[2]<15)&&(t==2)&&(dis>cm[1]))
    rightTurn();
  else if((cm[1]<15)&&(cm[2]<15)&&(t==2)&&(dis<cm[1]))
    leftTurn();
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




// Adjusting Directions

void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 180);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 160);
}

  void reverse() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 100);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 88 );
  } 

void leftTurn() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 0);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 107);
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

