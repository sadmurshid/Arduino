int motorpin1 = 4;          
int motorpin2 = 5;
int pwm1 = 6;                

int motorpin3 = 7;
int motorpin4 = 8;
int pwm2 = 9;               

int s1 = 40; 
int s2 = 41; 
int s3 = 42; 
int s4 = 43; 
int s5 = 44;
int s6 = 45;
int s7 = 46;



void setup() {

  Serial.begin(9600);
  
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);

  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}



void loop() {
  long duration, distance, x1, x2, x, difference;
  int a, a1, a2, a3, a4, a5, a6;
  a=digitalRead(s1);
  a1=digitalRead(s2);
  a2=digitalRead(s3);
  a3=digitalRead(s4);
  a4=digitalRead(s5);
  a5=digitalRead(s6);
  a6=digitalRead(s7);

  Serial.print(a);
  Serial.print(a1);
  Serial.print(a2);
  Serial.print(a3);
  Serial.print(a4);
  Serial.print(a5);
  Serial.print(a6);
  Serial.println("   ");
  if (a==0 && a1==0 && a2==0 && a3==0)
  {
    forward();
  }

  else if( (a==1 && a1==1 && a2==0 && a3==1) || (a==1 && a1==0 && a2==0 && a3==1) || (a==1 && a1==0 && a2==1 && a3==1)    )
    {
      forward();
    }
    else if (a==0 && a1==0 && a2==0 && a3==1)
    {
      
      leftTurn();
        
    }
    else if ((a==0 && a1==0 && a2==1 && a3==0) || (a==0 && a1==1 && a2==0 && a3==0) || (a==0 && a1==1 && a2==0 && a3==1) || (a==0 && a1==1 && a2==1 && a3==0) )
    {
      slow();
    }
    else if (a==0 && a1==0 && a2==1 && a3==1)
    {
     rightTurn();
    }
    else if (a == 0 && a1 == 1 && a2 == 1 && a3 == 1)
    {
      leftTurn();
    }
    else if (a == 1 && a1 == 0 && a2 == 0 && a3 == 0)
    {
      
      rightTurn();
      
      
    }
    
    else if (a == 1 && a1 == 0 && a2 == 1 && a3 == 0)
    {
      slow();
    }
    
    else if (a == 1 && a1 == 1 && a2 == 0 && a3 == 0)
    {
      rightTurn();    // Right turn
    }
    else if (a==1 && a1==1 && a2==1 && a3==1)
    {
      reverse();
    }
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
