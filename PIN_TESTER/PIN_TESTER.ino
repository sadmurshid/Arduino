/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {           
  digitalWrite(2, HIGH);    
  delay(500);              
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(4, HIGH);   
  delay(500);              
  digitalWrite(5, HIGH);    
  delay(500);              
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(7, HIGH);   
  delay(500);              
  digitalWrite(8, HIGH);    
  delay(500);
  digitalWrite(9, HIGH);   
  delay(500);              
  digitalWrite(10, HIGH);    
  delay(500);
  digitalWrite(11, HIGH);   
  delay(500);              
  digitalWrite(12, HIGH);    
  delay(500);              
  digitalWrite(13, HIGH);
  delay(500);
}
