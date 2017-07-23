int s1=A3 ;                                      //declaring motor , sensor , motor speed pin no 
int s2=A2 ;
int s3=A1 ;
int s4=A0 ; 

int mot1a=4;
int mot1b=5;
int motspeed1=3;

int mot2a=10;
int mot2b=11;
int motspeed2=9;

 

void setup() {
  Serial.begin(9600);
  pinMode(s1, INPUT);               //pinmode declaring for sensor
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

  pinMode(mot1a ,OUTPUT);       //pinmode declaring for motor 1 and motor 1 speed
  pinMode(mot1b ,OUTPUT);
  pinMode(motspeed1 , OUTPUT);
  
  pinMode(mot2a ,OUTPUT);    //pinmode declaring for motor 2 and motor 2 speed
  pinMode(mot2b ,OUTPUT);
  pinMode(motspeed2 ,OUTPUT);

}

void loop() {
 Serial.print(digitalRead(s1));
 Serial.print(digitalRead(s2));
 Serial.print(digitalRead(s3));
 Serial.print(digitalRead(s4));
 
 if ((digitalRead(s1==0))&&(digitalRead(s2==1))&&(digitalRead(s3==1))&&(digitalRead(s4==0))){
  fwd();          // declaring moving forward function
 }
 
  //bckwd();       // declaring moving backward function
 
if((digitalRead(s1==0))&&(digitalRead(s2==1))&&(digitalRead(s3==0))&&(digitalRead(s4==0))){
  right();      // declaring moving rightfunction
}

if((digitalRead(s1==1))&&(digitalRead(s2==1))&&(digitalRead(s3==0))&&(digitalRead(s4==0))){
  right();      // declaring moving rightfunction
}

if((digitalRead(s1==1))&&(digitalRead(s2==0))&&(digitalRead(s3==0))&&(digitalRead(s4==0))){
  right();      // declaring moving rightfunction
}

 if((digitalRead(s1==0))&&(digitalRead(s2==0))&&(digitalRead(s3==1))&&(digitalRead(s4==0))){
  left();      // declaring moving left function
 }

if((digitalRead(s1==0))&&(digitalRead(s2==0))&&(digitalRead(s3==1))&&(digitalRead(s4==1))){
  left();      // declaring moving left function
 }

if((digitalRead(s1==0))&&(digitalRead(s2==0))&&(digitalRead(s3==0))&&(digitalRead(s4==1))){
  left();      // declaring moving left function
 }


}

void fwd(){
  
  digitalWrite(mot1a ,HIGH);
  digitalWrite(mot1b ,LOW);

  analogWrite(motspeed1 ,pwm);
  
  digitalWrite(mot2a ,HIGH);
  digitalWrite(mot2b ,LOW);

  analogWrite(motspeed2 ,pwm);
  
  
  }
//  void bckwd(){
//  
//  digitalWrite(mot1a ,LOW);
//  digitalWrite(mot1b ,HIGH);
//
//  analogWrite(motspeed1 ,pwm);
//  
//  digitalWrite(mot2a ,LOW);
//  digitalWrite(mot2b ,HIGH);
//
//  analogWrite(motspeed2 ,pwm);
//  
//  
//  }
//  void right(){
//  
//  digitalWrite(mot1a ,LOW);
//  digitalWrite(mot1b ,LOW);          
//
//  analogWrite(motspeed1 ,0);
//  
//  digitalWrite(mot2a ,HIGH);
//  digitalWrite(mot2b ,LOW);
//
//  analogWrite(motspeed2 ,pwm);
//  
//  
//  }
  void left(){
  
  digitalWrite(mot1a ,HIGH);
  digitalWrite(mot1b ,LOW);

  analogWrite(motspeed1 ,60);
  
  digitalWrite(mot2a ,LOW);
  digitalWrite(mot2b ,LOW);

  analogWrite(motspeed2 ,0);
  
  
  }
