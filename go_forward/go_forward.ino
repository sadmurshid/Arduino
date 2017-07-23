  
int motorpin1 = 4;          
int motorpin2 = 5;
int pwm1 = 6;                

int motorpin3 = 7;
int motorpin4 = 8;
int pwm2 = 9;  


void setup() {
  // put your setup code here, to run once:
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {
  forward();

}
void forward() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 255);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 255);
}
