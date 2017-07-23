
int mot1a=8;
int mot1b=7;
int motspeed1=6;

int mot2a=4;
int mot2b=2;
int motspeed2=5;
  
 
void setup() {
  pinMode(mot1a ,OUTPUT);       //pinmode declaring for motor 1 and motor 1 speed
  pinMode(mot1b ,OUTPUT);
  pinMode(motspeed1 , OUTPUT);
  
  pinMode(mot2a ,OUTPUT);    //pinmode declaring for motor 2 and motor 2 speed
  pinMode(mot2b ,OUTPUT);
  pinMode(motspeed2 ,OUTPUT);

}

 void loop() {
  digitalWrite(mot1a ,LOW);
  digitalWrite(mot1b ,HIGH);
  analogWrite(motspeed1 ,255);
  digitalWrite(mot2a ,HIGH);
  digitalWrite(mot2b ,LOW);
  analogWrite(motspeed2 ,255);
  delay(1000);
  digitalWrite(mot1a ,LOW);
  digitalWrite(mot1b ,HIGH);
  analogWrite(motspeed1 ,70);
  digitalWrite(mot2a ,HIGH);
  digitalWrite(mot2b ,LOW);
  analogWrite(motspeed2 ,255);
  delay(500);
  digitalWrite(mot1a ,HIGH);
  digitalWrite(mot1b ,LOW);
  analogWrite(motspeed1 ,255);
  digitalWrite(mot2a ,LOW);
  digitalWrite(mot2b ,HIGH);
  analogWrite(motspeed2 ,255);
  delay(1000);
    digitalWrite(mot1a ,LOW);
  digitalWrite(mot1b ,HIGH);
  analogWrite(motspeed1 ,70);
  digitalWrite(mot2a ,HIGH);
  digitalWrite(mot2b ,LOW);
  analogWrite(motspeed2 ,255);
  delay(500);
}

