int motorpin1 = 4;          
int motorpin2 = 5;
int pwm1 = 6;                

int motorpin3 = 8;
int motorpin4 = 7;
int pwm2 = 9;               

int s1 = A0; 
int s2 = A1; 
int s3 = A2; 
int s4 = A3; 
int s5 = A4;
int s6 = A5;
int s7 = 3; 
int sen= 12;   //brown


void setup() {

  Serial.begin(9600);
  
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);
  pinMode(sen, OUTPUT);
  
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}



void loop() {
  analogWrite(sen, 255);
//  int duration, distance, x1, x2, x, difference;
  int  a1, a2, a3, a4, a5, a6, a7;
  a1=digitalRead(s1);
  a2=digitalRead(s2);
  a3=digitalRead(s3);
  a4=digitalRead(s4);
  a5=digitalRead(s5);
  a6=digitalRead(s6);
  a7=digitalRead(s7);

  Serial.print(a1);
  Serial.print(a2);
  Serial.print(a3);
  Serial.print(a4);
  Serial.print(a5);
  Serial.print(a6);
  Serial.print(a7);
  Serial.println("   ");
  
  if((a2==a6 && a3==a5 && a3==a2 && a4!=a2) || (a1==1 && a2==0 && a3==1 && a4==1 && a5==0 && a6==0 && a7==1) || (a1==1 && a2==0 && a3==0 && a4==1 && a5==1 && a6==0 && a7==0))
  {
    Serial.print("Forword");
    forward();
  }
  else if((a4==a3 && a4==a2 && a4!=a5 && a4!=a6) || (a4==a3 && a4!=a5 && a4!=a2 && a4!=a6) || (a4==a3 && a4==a5 && a4==a6 && a4==a7 && a4!=a2 && a4!=a1) || (a4==a2 && a4==a1 && a4==a5 && a4==a6 && a4==a7 && a4!=a3))
  {
    Serial.print("Right");  
    rightTurn();
  }
  else if((a4==a5 && a4==a6 && a4!=a3 && a4!=a2) || (a4==a5 && a4!=a6 && a4!=a3 && a4!=a2) || (a4==a3 && a4==a5 && a4==a2 && a4==a1 && a4!=a6 && a4!=a7) || (a4==a1 && a4==a2 && a4==a3 && a4==a6 && a4==a7 && a4!=a5))
  {  
    Serial.print("left");
    leftTurn();
  }
  else if(a4==a3 && a4==a1 && a4!=a2 && a4!=a7)
  { 
    Serial.print("right"); 
    rightTurn();
    delay(20);
  }
  else if(a4==a5 && a4==a7 && a4!=a6 && a4!=a1)
  {  
    Serial.print("LEFT");
    leftTurn();
    delay(20);
  }
  
  else if(a1==0 && a2==0 && a3==0 && a4==0 && a5==0 && a6==0 && a7==0)  
  {
    stand();
    Serial.print("STAND");
    for(int i=0; i<1; i++)
    {
      analogWrite(sen, 255);
      if(a1==0 && a2==0 && a3==0 && a4==0 && a5==0 && a6==0 && a7==0)
      {
        Serial.print("forward");
        a1=digitalRead(s1);
  a2=digitalRead(s2);
  a3=digitalRead(s3);
  a4=digitalRead(s4);
  a5=digitalRead(s5);
  a6=digitalRead(s6);
  a7=digitalRead(s7);

  Serial.print(a1);
  Serial.print(a2);
  Serial.print(a3);
  Serial.print(a4);
  Serial.print(a5);
  Serial.print(a6);
  Serial.print(a7);
  Serial.println("   ");
        forward();
        i=-1;
      }
      else 
      {
        Serial.print("LEFT");
        rightTurn();
      }
    }
  }
  else if(a1==1 && a2==1 && a3==1 && a4==1 && a5==1 && a6==1 && a7==1)  
  {
    stand();
    Serial.print("STAND");
    for(int i=0; i<1; i++)
    {
      analogWrite(sen, 255);
      a1=digitalRead(s1);
  a2=digitalRead(s2);
  a3=digitalRead(s3);
  a4=digitalRead(s4);
  a5=digitalRead(s5);
  a6=digitalRead(s6);
  a7=digitalRead(s7);

  Serial.print(a1);
  Serial.print(a2);
  Serial.print(a3);
  Serial.print(a4);
  Serial.print(a5);
  Serial.print(a6);
  Serial.print(a7);
  Serial.println("   ");
      if(a1==1 && a2==1 && a3==1 && a4==1 && a5==1 && a6==1 && a7==1)
      {
        Serial.print("forward");
        forward();
        i=-1;
      }
      else
      {
        Serial.print("LEFT");
        rightTurn();
      }
    }
  }
  
  
//  if (a==0 && a1==0 && a2==0 && a3==0)
//  {
//    forward();
//  }
//
//  else if( (a==1 && a1==1 && a2==0 && a3==1) || (a==1 && a1==0 && a2==0 && a3==1) || (a==1 && a1==0 && a2==1 && a3==1)    )
//    {
//      forward();
//    }
//    else if (a==0 && a1==0 && a2==0 && a3==1)
//    {
//      
//      leftTurn();
//        
//    }
//    else if ((a==0 && a1==0 && a2==1 && a3==0) || (a==0 && a1==1 && a2==0 && a3==0) || (a==0 && a1==1 && a2==0 && a3==1) || (a==0 && a1==1 && a2==1 && a3==0) )
//    {
//      slow();
//    }
//    else if (a==0 && a1==0 && a2==1 && a3==1)
//    {
//     rightTurn();
//    }
//    else if (a == 0 && a1 == 1 && a2 == 1 && a3 == 1)
//    {
//      leftTurn();
//    }
//    else if (a == 1 && a1 == 0 && a2 == 0 && a3 == 0)
//    {
//      
//      rightTurn();
//      
//      
//    }
//    
//    else if (a == 1 && a1 == 0 && a2 == 1 && a3 == 0)
//    {
//      slow();
//    }
//    
//    else if (a == 1 && a1 == 1 && a2 == 0 && a3 == 0)
//    {
//      rightTurn();    // Right turn
//    }
//    else if (a==1 && a1==1 && a2==1 && a3==1)
//    {
//      reverse();
//    }
}
void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 120);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 105);
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
  analogWrite(pwm2, 120);
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
  analogWrite(pwm1, 40);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 40);
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
