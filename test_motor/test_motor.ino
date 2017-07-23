int motor1=4;
int motor2=5;
int motor3=6;
int motor4=7;
int ena=8;
int enb=9;
void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}

void loop() {

  
  digitalWrite(motor1, LOW);
  analogWrite(motor2, 200);
  digitalWrite(motor3, HIGH);
  analogWrite(motor4, 100);
  analogWrite(ena, 20);
  analogWrite(enb, 10);
}
