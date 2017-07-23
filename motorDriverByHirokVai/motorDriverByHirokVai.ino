/*
Author: M M Shaifur Rahman
Created Date: 11 Nov 2016
Web: http://shaifur.me
E-mail: mail@shaifur.me
Connection Diagram:
Arduino <-->  Motor Driver
  D2    <--> MotorA1
  D4    <--> MotorA2
  D3    <--> MotorA-PWM
  D5    <--> MotorB1
  D7    <--> MotorB2
  D6    <--> MotorB-PWM
Description:
This code will help you to test any L293D or L298N based standard Motor Driver.This default code will drive your every possible combination. Use this functions and do further modification to make it work in your real project.
*/

byte LeftMotorA = 2;
byte LeftMotorB = 4;
byte LeftMSpeed = 3; 

byte RightMotorA = 5;
byte RightMotorB = 7;
byte RightMSpeed = 6;

void setup() 
{
Serial.begin(9600);
//Initialized Motor Driver Pins as Output
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);

}

void loop() 
{
MotorSpeed(); // Set Motor Speed
Serial.println("Driving Forward");
drive_forward();
delay(1000);
motor_stop();

Serial.println("Driving Forward");
drive_backward();
delay(1000);
motor_stop();

Serial.println("Turnning Left");
turn_left();
delay(1000);
motor_stop();

Serial.println("Turnning Left");
turn_right();
delay(1000);
motor_stop();

Serial.println("Testing Done !");
delay(2000);
}

// Motor Driving Functions

// Set Motor Speed 0 is stop & 255 is max speed
void MotorSpeed(){
analogWrite(LeftMSpeed, 255);
analogWrite(RightMSpeed,255);
}
//Stop Both Motor
void motor_stop(){
digitalWrite(LeftMotorA, LOW); 
digitalWrite(LeftMotorB, LOW); 
digitalWrite(RightMotorA, LOW); 
digitalWrite(RightMotorB, LOW);
delay(5);
}

void drive_forward(){
digitalWrite(LeftMotorA, HIGH); 
digitalWrite(LeftMotorB, LOW); 
digitalWrite(RightMotorA, HIGH); 
digitalWrite(RightMotorB, LOW);
delay(5);
}

void drive_backward(){
digitalWrite(LeftMotorA, LOW); 
digitalWrite(LeftMotorB, HIGH); 
digitalWrite(RightMotorA, LOW); 
digitalWrite(RightMotorB, HIGH);
delay(5); 
}

void turn_left(){
digitalWrite(LeftMotorA, LOW); 
digitalWrite(LeftMotorB, LOW); 
digitalWrite(RightMotorA, HIGH); 
digitalWrite(RightMotorB, LOW);
delay(5); 
}

void turn_right(){
digitalWrite(LeftMotorA, HIGH); 
digitalWrite(LeftMotorB, LOW); 
digitalWrite(RightMotorA, LOW); 
digitalWrite(RightMotorB, LOW);
delay(5); 
}
