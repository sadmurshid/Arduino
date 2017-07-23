 int trigPin= 2;
 int echoPin= A0;
 int echoPin1=A1;
 int echoPin2=A2; 
 int buzz=A5;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);            
  pinMode(buzz, OUTPUT);
  
}

void loop() {
   long duration, distance, x1, x2, x, difference;
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
  x=distance;

      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin2, HIGH);
      distance = (duration/2) / 29.1;
      x2=distance;

      if((x==0)||(x1==0)||(x2==0))
      {
        digitalWrite(buzz, HIGH);
      }
            Serial.print(x);
      Serial.print(" cm   ");
      Serial.print(x1);
      Serial.print(" cm   ");
      Serial.print(x2);
      Serial.println(" cm");
      
}
