int trigPin= 2;
 int echoPin= A0;
// int echoPin1=A1;
// int echoPin2=A2; 


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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


  Serial.print(x);
  Serial.println(" cm   ");
  
  


}
