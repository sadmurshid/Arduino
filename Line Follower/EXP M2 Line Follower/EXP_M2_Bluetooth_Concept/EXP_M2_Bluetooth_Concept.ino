// EXP M2 Bluetooth Concept
                          // Check- TUTOR.ROBOGEARSBD.COM for Bluetooth Module code
                          // Check github.com/mmshaifur for L293D Motor Tester
int pwm1 = 4; 
int motorpin1 = 2;
int motorpin2 = 3;      // LEFT motor pin and pwm


int motorpin3 = 5;
int motorpin4 = 6;
int pwm2= 7;          // RIGHT motor pin and pwm

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11); // Connection pins for bluetooth RX & TX. 
//I used software serial so that you can upload the code even with the bluetooth module connected.
int received;

                  
void setup() {
// Motor pins and Pulse Width Modulation declared by pinMode
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

pinMode(13,OUTPUT);
Serial.begin(9600);
bluetooth.begin(9600);                         //Check 192.168.10.21:8080
digitalWrite(13,0);
  
}

void loop() {
  while (bluetooth.available()) { // Receives Data from bluetooth and stores in recieved variable
received = bluetooth.read();

if (received == 255){
  stand();
}

if (received == 1){
  forward();
}

if (received == 2){
  leftturn();
}

if (received == 3){
  rightturn();
}

if (received == 4){
  reverse();
}

Serial.println(received); // Prints the last received data.
  }

  }

// Adjusting Directions

void stand() {
  Serial.println("Stand");
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1,0);
  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2,0);
}

void forward() {
  Serial.println("Forward");
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 255);
  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 255);
}

 void reverse() {
  Serial.println("Reverse");
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 220);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 220);
  } 

void leftturn() {
  Serial.println("Left Turn");
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 0);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 180);
}

void rightturn() {
  Serial.println("Right Turn");
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 180);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 0);
}

void clock360() {
  
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 180);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 180);
}

void anticlock360() {
  
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 180);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 180);
}
