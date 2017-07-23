    
int motorpin1 = 4;       //green
int motorpin2 = 5;      //blue                                      // LEFT motor pin and pwm
int pwm1 = 6;          // purple  

int motorpin3 = 8;      //white
int motorpin4 = 7;      //gray
int pwm2 = 9;          //black                                     // RIGHT motor pin and pwm         

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

//////////////////////////////BLACK LINE
  
  if((a1==0 && a2==0 && a3==0 && a4==1 && a5==0 && a6==0 && a7==0) || 
      
     (a1==0 && a2==0 && a3==1 && a4==1 && a5==1 && a6==0 && a7==0) || 
     (a1==1 && a2==1 && a3==1 && a4==1 && a5==1 && a6==1 && a7==1))
  {
    Serial.print("Forward");
    forward();
  }

  else if((a1==1 && a2==1 && a3==1 && a4==1 && a5==0 && a6==0 && a7==0) || 
     (a1==1 && a2==1 && a3==1 && a4==0 && a5==0 && a6==0 && a7==0) || 
     (a1==1 && a2==1 && a3==0 && a4==0 && a5==0 && a6==0 && a7==0) || 
     (a1==1 && a2==0 && a3==0 && a4==0 && a5==0 && a6==0 && a7==0) || 
     (a1==0 && a2==1 && a3==0 && a4==0 && a5==0 && a6==0 && a7==0) || 
     (a1==0 && a2==0 && a3==1 && a4==0 && a5==0 && a6==0 && a7==0) || 
     (a1==0 && a2==1 && a3==1 && a4==0 && a5==0 && a6==0 && a7==0) ||
     (a1==0 && a2==1 && a3==0 && a4==1 && a5==0 && a6==0 && a7==0) ||     // LEFT ANGULAR TURNS
     (a1==1 && a2==1 && a3==0 && a4==1 && a5==0 && a6==0 && a7==0) ||
     (a1==1 && a2==0 && a3==0 && a4==1 && a5==0 && a6==0 && a7==0) ||
     (a1==0 && a2==0 && a3==1 && a4==1 && a5==0 && a6==0 && a7==0) )
     
    {
    Serial.print("Left Turn");
    leftTurn();
  }


  

  else if((a1==0 && a2==0 && a3==0 && a4==1 && a5==1 && a6==1 && a7==1) || 
     (a1==0 && a2==0 && a3==0 && a4==0 && a5==1 && a6==1 && a7==1) || 
     (a1==0 && a2==0 && a3==0 && a4==0 && a5==0 && a6==1 && a7==1) || 
     (a1==0 && a2==0 && a3==0 && a4==0 && a5==0 && a6==0 && a7==1) || 
     (a1==0 && a2==0 && a3==0 && a4==0 && a5==0 && a6==1 && a7==0) || 
     (a1==0 && a2==0 && a3==0 && a4==0 && a5==1 && a6==0 && a7==0) || 
     (a1==0 && a2==0 && a3==0 && a4==0 && a5==1 && a6==1 && a7==0) ||
     (a1==0 && a2==0 && a3==0 && a4==1 && a5==0 && a6==1 && a7==0) ||     // RIGHT ANGULAR TURNS
     (a1==0 && a2==0 && a3==0 && a4==1 && a5==0 && a6==1 && a7==1) || 
     (a1==0 && a2==0 && a3==0 && a4==1 && a5==0 && a6==0 && a7==1) ||
     (a1==0 && a2==0 && a3==0 && a4==1 && a5==1 && a6==0 && a7==0)) 
  {
    Serial.print("Right Turn");
    rightTurn();
   }
//   else if(a1==0 && a2==0 && a3==0 && a4==0 && a5==0 && a6==0 && a7==0)
//   {
//    reverse();
//   }

  
}




//  //////////////////////////////WHITE LINE
//   if(
//   (a1==1 && a2==1 && a3==1 && a4==0 && a5==1 && a6==1 && a7==1) || 
//   (a1==1 && a2==1 && a3==0 && a4==0 && a5==1 && a6==1 && a7==1) || 
//   (a1==1 && a2==1 && a3==1 && a4==0 && a5==0 && a6==1 && a7==1) || 
//   (a1==1 && a2==1 && a3==0 && a4==0 && a5==0 && a6==1 && a7==1) || 
//   (a1==0 && a2==0 && a3==0 && a4==0 && a5==0 && a6==0 && a7==0))
//  {
//    Serial.print("Forward");
//    forward();
//  }
//
//  if((a1==0 && a2==0 && a3==0 && a4==0 && a5==1 && a6==1 && a7==1) || 
//     (a1==0 && a2==0 && a3==0 && a4==1 && a5==1 && a6==1 && a7==1) || 
//     (a1==0 && a2==0 && a3==1 && a4==1 && a5==1 && a6==1 && a7==1) || 
//     (a1==0 && a2==1 && a3==1 && a4==1 && a5==1 && a6==1 && a7==1) || 
//     (a1==1 && a2==0 && a3==1 && a4==1 && a5==1 && a6==1 && a7==1) || 
//     (a1==1 && a2==1 && a3==0 && a4==1 && a5==1 && a6==1 && a7==1) || 
//     (a1==1 && a2==0 && a3==0 && a4==1 && a5==1 && a6==1 && a7==1))
//  {
//    Serial.print("Left Turn");
//    leftTurn();
//  }
//
//  if((a1==1 && a2==1 && a3==1 && a4==0 && a5==0 && a6==0 && a7==0) || 
//     (a1==1 && a2==1 && a3==1 && a4==1 && a5==0 && a6==0 && a7==0) || 
//     (a1==1 && a2==1 && a3==1 && a4==1 && a5==1 && a6==0 && a7==0) || 
//     (a1==1 && a2==1 && a3==1 && a4==1 && a5==1 && a6==1 && a7==0) || 
//     (a1==1 && a2==1 && a3==1 && a4==1 && a5==1 && a6==0 && a7==1) || 
//     (a1==1 && a2==1 && a3==1 && a4==1 && a5==0 && a6==1 && a7==1) || 
//     (a1==1 && a2==1 && a3==1 && a4==1 && a5==0 && a6==0 && a7==1))
//  {
//    Serial.print("Right Turn");
//    rightTurn();
//   }
//
//  if((a1==1 && a2==1 && a3==1 && a4==1 && a5==1 && a6==1 && a7==1))
//  {
//    Serial.print("Reverse");
//    reverse();
//  }
//}
   


  //////////////////////////////////Adjust Directions
  
void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 140);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 125);
}

  void reverse() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 95);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 95);
  } 

void leftTurn() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 0);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 100);
}


void rightTurn() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 100);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 0);
}


