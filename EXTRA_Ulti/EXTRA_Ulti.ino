int motorpin1 = 4;          
int motorpin2 = 5;                      //LEFT Motor
int pwm1 = 6;                

int motorpin3 = 7;
int motorpin4 = 8;                      //RIGHT Motor
int pwm2 = 9;               

int s1 = 2; //orange                   // Sensor Array reads White =0 and Black =1
int s2 = 3; //white
int s3 = 5; //yellow
int s4 = 6; //black                    // sensors
int s5 = 7;


void setup() {
 pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

  // Motor pins and Pulse Width Modulation declared by pinMode
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
} 

void loop() {
  long a, a1, a2, a3, a4;
  a= digitalRead(s1);
  a1=digitalRead(s2);
  a2=digitalRead(s3);
  a3=digitalRead(s4);
  a4=digitalRead(s5);

  Serial.print(a);
  Serial.print(a1);
  Serial.print(a2);
  Serial.print(a3);
  Serial.print(a4);


if (a==1 && a1==0 && a2==0 && a3==1){
  forward();
}
if (a==0 && a1==0 && a2==0 && a3==1){
  leftTurn();
}
if (a==1 && a1==0 && a2==0 && a3==0){
  rightTurn();
}
if (a==0 && a1==0 && a2==1 && a3==1){
  fastMoveRight();
}
if (a==1 && a1==1 && a2==0 && a3==0){
  fastMoveLeft();
}
}
  void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 60);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 52);
}

  void reverse() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 60);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 52);
  } 

void leftTurn() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 60);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 52);
}

void rightTurn(){
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 60);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 52);
}

void fastMoveRight()
{
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 65);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 50);
}

void fastMoveLeft()
{
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 60);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 65);
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
