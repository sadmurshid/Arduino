
 int trigPin= 2;
 int echoPin= A0;
 int echoPin1=A1;
 int echoPin2=A2; 

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
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);            
  
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
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  x=distance;
  
  Serial.print(a);
  Serial.print(a1);
  Serial.print(a2);
  Serial.print(a3);
  Serial.println("   ");

  
  if((x<11)&&(x>6))
  {
    leftTurn();
  }
  else if(x<6)
  {
    reverse();
  }
  else
  {
    if (a==0 && a1==0 && a2==0 && a3==0)
    {
      
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin2, HIGH);
      distance = (duration/2) / 29.1;
      x2=distance;
      
      if(x2<15)
      {
        stand();
        leftTurn();
        stand();
      }
      else if((x2>=15)||(x2==0))
      {
        forward();
      }
    }
    else if( (a==1 && a1==1 && a2==0 && a3==1) || (a==1 && a1==0 && a2==0 && a3==1) || (a==1 && a1==0 && a2==1 && a3==1)    )
    {
      forward();
    }
    else if (a==0 && a1==0 && a2==0 && a3==1)
    {
      stand();
      leftTurn();
      stand();
      
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
      stand();
      rightTurn();
      stand();
      
    }
    
    else if (a == 1 && a1 == 0 && a2 == 1 && a3 == 0)
    {
      slow();
    }
    
    else if (a == 1 && a1 == 1 && a2 == 0 && a3 == 0)
    {
      rightTurn();    // Right turn
    }
    else if (a==1 && a1==1 && a2==0 && a3==1)
    {
      forward();
    }
    else if (a == 1 && a1 == 1 && a2 == 1 && a3 == 0)
    {
      rightTurn();
    }
    else if (a == 1 && a1 == 1 && a2 == 1 && a3 == 1)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin1, HIGH);
      distance = (duration/2) / 29.1;
      x1=distance;
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin2, HIGH);
      distance = (duration/2) / 29.1;
      x2=distance;

      Serial.print(x);
      Serial.print(" cm   ");
      Serial.print(x1);
      Serial.print(" cm   ");
      Serial.print(x2);
      Serial.println(" cm");
    
      
         
      difference=x1-x2;
      if(abs(difference)<=4)
      {
        forward();
      }
      else
      {
        if((x1>x2)&&(abs(difference)<=10)&&((x1+x2)<30))
        {
          leftTurn();
        }
        else if((x1<x2)&&(abs(difference)<=10)&&((x1+x2)<30))
        {
          rightTurn();
        }
        else if((x>15)&&(x1>15)&&(x2>15))
        {
          rightTurn();
        }
        else if((x1<x2)&&(abs(difference)>=10)&&((x1+x2)>30))
        {
          forward();
        }
        else if((x1>x2)&&(abs(difference)>=10)&&((x1+x2)>30))
        {
          forward();
        }
      }
      
    }
    
  }

}




// Adjusting Directions

void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 110);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 97);
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

