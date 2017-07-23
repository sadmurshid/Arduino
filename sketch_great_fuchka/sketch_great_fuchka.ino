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

void loop() {long duration, distance, x1, x2, y2, y1, x, y;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  x=distance;
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

  Serial.print(digitalRead(s1));
  Serial.print(digitalRead(s2));
  Serial.print(digitalRead(s3));
  Serial.print(digitalRead(s4));
  Serial.println();


    Serial.print(x);
    Serial.print(" cm   ");
    Serial.print(x1);
    Serial.print(" cm   ");
    Serial.print(x2);
    Serial.println(" cm");
  
  delay(500);
}
