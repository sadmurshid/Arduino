// EXP M2 Line Tracker


int motorpin1 = 6;
int motorpin2 = 7;
int pwm1 = 5;               // LEFT motor pin and pwm

int motorpin3 = 13;
int motorpin4 = 12;
int pwm2 = 10;               // RIGHT motor pin and pwm

int s1 = 2; //orange
int s2 = 3; //white
int s3 = 4; //brown
int s4 = 8; //black                    // sensors

void setup() {
  // Sensor pins declared by pinMode

  Serial.begin(9600);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

  // Motor pins and Pulse Width Modulation declared by pinMode
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {

  Serial.print(digitalRead(s1));  // Mark the Sensors for instant Digital Read in 0,1
  Serial.print(digitalRead(s2));
  Serial.print(digitalRead(s3));
  Serial.print(digitalRead(s4));
  

  if (digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 0) {
    //Serial.println("FORWARD");
    forward();
  }
    else if  (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 1) {
      // Serial.println("");
      rightturn();
    }
    else if  (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 0) {
      // Serial.println("");
      rightturn();
    }
    else if  (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 1) {
      // Serial.println("");
      rightturn();
    }

    else if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 0 && digitalRead(s4) == 0) {
      //Serial.println("");
      leftturn();
    }
    else if (digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0) {
      //Serial.println("");
      leftturn();
    }
    else if (digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 0 && digitalRead(s4) == 0) {
      //Serial.println("");
      leftturn();
    }

  else if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0) {
    //Serial.println("FORWARD");
    forward();
  }

}




// Adjusting Directions

void forward() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 90);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 90);
}

/* void reverse() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  analogWrite(pwm1, 200);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
  analogWrite(pwm2, 200);
  } */

void leftturn() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 0);

  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 60);
}

void rightturn() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  analogWrite(pwm1, 60);

  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, LOW);
  analogWrite(pwm2, 0);
}







