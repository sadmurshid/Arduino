//////// The Sketch is given here as follows---

// EXP M2 Line Follower
// White Track on Black Turf
//Sonar Sensors
 int trigPin= 0;
 int echoPin= 1;
 int echoPin1=2;
 int echoPin2=3;

// Sensor Array reads White =0 and Black =1
int motorpin1 = 4;          
int motorpin2 = 5;
int pwm1 = 6;                

int motorpin3 = 7;
int motorpin4 = 8;
int pwm2 = 9;               

int s1 = 10; //orange
int s2 = 11; //white
int s3 = 12; //yellow
int s4 = 13; //black                    // sensors

void setup() {
  // Sensor pins declared by pinMode

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin1, INPUT);
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
  int diffarence;
  long duration, distance, duration1, duration2, distance1, distance2;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;

  Serial.print(digitalRead(s1));  // Mark the Sensors for instant Digital Read in 0,1
  Serial.print(digitalRead(s2));
  Serial.print(digitalRead(s3));
  Serial.print(digitalRead(s4));
  Serial.println();
  
  if(distance<5)
  {
    rightTurn();
  }
  else
  {
    if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0)
    {
      forward();
    }
    else if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 1)
    {
      leftTurn();
    }
    else if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 0)
    {
      //forward();                 V Curv Spatial case
    }
    else if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 1)
    {
      fastMoveRight();
    }
    else if (digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 0 && digitalRead(s4) == 0)
    {
      //forward();               V Curv left spacial case
    }
    else if (digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 0 && digitalRead(s4) == 1)
    {
      //forward();
    }
    else if (digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 0)
    {
      //forward();
    }
    else if (digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 1)
    {
      //forward();
    }
    else if (digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0)
    {
      rightTurn();
    }
    else if (digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 1)
    {
      forward();
    }
    else if (digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 0)
    {
      //forward();
    }
    else if (digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 1)
    {
      //forward();
    }
    else if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 0 && digitalRead(s4) == 0)
    {
      fastMoveLeft();
    }
    else if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 0 && digitalRead(s4) == 1)
    {
      //forward();
    }
    else if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0)
    {
      forward();
    }
    else if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 0)
    {
      //forward();
    }
    else if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 1)
    {
      diffarence=distance1-distance2;
      if(abs(diffarence)<=4)
      {
        forward();
      }
      else
      {
        if((distance1>distance2)&&(abs(diffarence)<=10))
        {
          fastMoveLeft();
        }
        else if((distance1<distance2)&&(abs(diffarence)<=10))
        {
          fastMoveRight();
        }
      }
      
    }
    
  }

}




// Adjusting Directions

void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 120);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 120);
}

/* void reverse() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 200);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 200);
  } */

void leftTurn() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 0);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 70);
}

void rightTurn(){
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 70);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 0);
}

void fastMoveRight()
{
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 140);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 110);
}

void fastMoveLeft()
{
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 110);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 140);
}
