// EXP M2 Maze Solver

// Sensor Pins read Black = 1 & White = 0 

int motorpin1 = 4;          
int motorpin2 = 5;
int pwm1 = 6;                // Left Motor

int motorpin3 = 7;
int motorpin4 = 8;
int pwm2 = 9;               // Right Motor

int s1 = 10;                // Sensors
int s2 = 11; 
int s3 = 12; 
int s4 = 13; 

void setup() {

  Serial.begin(9600);
  
  pinMode(s1, INPUT);                     //Sensor Pins
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

  pinMode(motorpin1, OUTPUT);             //Motor Pins
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}



void loop() {
  
  int a1, a2, a3, a4;
  a1=digitalRead(s1);        //Track -- White Background with Black Lines
  a2=digitalRead(s2);
  a3=digitalRead(s3);
  a4=digitalRead(s4);

//Sensor arrays

  if (a1==0 && a2==1 && a3==1 && a4==0)   //straight
  {
    forward();
  }

   else if (a1==1 && a2==1 && a3==1 && a4==1)   //all black
  {
    slow();
    leftTurn();
  }

   if( (a1==1 && a2==0 && a3==0 && a4==0) || (a1==1 && a2==1 && a3==0 && a4==0) || (a1==1 && a2==1 && a3==1 && a4==0) )
  { 
    leftTurn();
  } 

   else if( (a1==0 && a2==0 && a3==0 && a4==1) || (a1==0 && a2==0 && a3==1 && a4==1) || (a1==0 && a2==1 && a3==1 && a4==1) )
  {
    rightTurn();
  } 

  else if (a1==0 && a2==1 && a3==0 && a4==0)   
  {
    leftTurn();
  }

  else if (a1==0 && a2==0 && a3==1 && a4==0)   
  {
    rightTurn();
  }

   else if (a1==0 && a2==0 && a3==0 && a4==0)  //all white
  {
    clock360();
  }

  }



// Adjusting Directions

void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 120);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 105);
}

void clock360() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
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
  analogWrite(pwm2, 105);
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
