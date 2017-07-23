
 int trigPin= 2;
// int echoPin= A0;
// int echoPin1=A1;
 int echoPin2=A2;                       //Sonar Sensors

int motorpin1 = 4;          
int motorpin2 = 5;                      //LEFT Motor
int pwm1 = 6;                

int motorpin3 = 7;
int motorpin4 = 8;                      //RIGHT Motor
int pwm2 = 9;               

int s1 = 10; //orange                   // Sensor Array reads White =0 and Black =1
int s2 = 11; //white
int s3 = 12; //yellow
int s4 = 13; //black                    // sensors
int dis=0, ti=1;


void setup() {
  // Sensor pins declared by pinMode

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);
//  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);            
  
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

  // Motor pins and Pulse Width Modulation declared by pinMode
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {
  long duration, x2, distance;//, x1, x, difference; 
  
  int a, a1, a2, a3;
  a=digitalRead(s1);
  a1=digitalRead(s2);
  a2=digitalRead(s3);
  a3=digitalRead(s4);
  
    if  (a==1 && a1==0 && a2==0 && a3==1)
    {
      forward();
      ti=1;
    }
    else if (a==0 && a1==0 && a2==0 && a3==1)
    {
      leftTurn();
      ti=1;
    }
     else if (a==0 && a1==0 && a2==1 && a3==1)
    {
     leftTurn(); //Left turn
     ti=1;
    }
    else if (a == 0 && a1 == 1 && a2 == 1 && a3 == 1)
    {
     fastMoveLeft(); //Left turn
     ti=1;
    }
    else if (a == 1 && a1 == 0 && a2 == 0 && a3 == 0)
    {
      rightTurn();
      ti=1;
    }
    else if (a == 1 && a1 == 1 && a2 == 0 && a3 == 0)
    {
      rightTurn();    // Right turn
      ti=1;
    }
   else if (a == 1 && a1 == 1 && a2 == 1 && a3 == 0)
    {
      fastMoveRight();   // Right turn
      ti=1;
    }
    else if (a==1 && a1==1 && a2==0 && a3==1)
    {
      rightTurn(); //emergency turn
      ti=1;
    }
    else if (a==1 && a1==0 && a2==1 && a3==1)
    {
      leftTurn(); //emergency turn
      ti=1;
    }
    if (a == 0 && a1 == 0 && a2 == 0 && a3 == 0)
    {
        forward();
        ti=1;
        if(a == 1 && a1 == 1 && a2 == 1 && a3 == 1)
        {
          reverse();
          leftTurn();
        }
    }
    else if (a == 1 && a1 == 1 && a2 == 1 && a3 == 1)
    {
      digitalWrite(motorpin1, HIGH);
      digitalWrite(motorpin2, LOW);
      analogWrite(pwm1, 0);
      digitalWrite(motorpin3, HIGH);
      digitalWrite(motorpin4, LOW);
      analogWrite(pwm2, 0);
      
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin2, HIGH);
      distance = (duration/2) / 29.1;
      x2=distance;

      if(x2>20)
      {
        forward();
      }
      else if((x2<20)&&(ti==1))
      {
        dis=x2;
        forward();
      }
      else if((x2<20)&&(ti!=1)&&(x2>dis))
      {
        slow();
        delay(100);
        fastMoveRight();
        ti=3;
      }
      else if((x2<20)&&(ti!=1)&&(x2<dis))
      {
        slow();
        delay(100);
        fastMoveLeft();
        ti=3;
      }
    }
}
    
// Adjusting Directions

void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 112);
  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 112);
}

  void reverse() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 100);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 100);
}
void leftTurn() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 0);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 90);
}

void rightTurn(){
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 90);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 0);
}

void fastMoveRight()
{
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 110);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 60);
}

void fastMoveLeft(){
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 60);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 110);
}
void slow()
{  
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 50);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 50);
}
