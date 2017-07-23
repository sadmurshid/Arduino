
#define rightMotor1 9
#define rightMotor2 10
#define rightMotorPWM 11
#define leftMotor1 7
#define leftMotor2 8
#define leftMotorPWM 6

#define Kp 20
#define Ki 0
#define Kd 0
#define NUM_SENSORS  7

int rightMaxSpeed = 70;
int leftMaxSpeed = 70;
int rightBaseSpeed = 50;
int leftBaseSpeed = 50;

unsigned int sensorPins[NUM_SENSORS] = {A0, A1, A2, A3, A4, A5, 2};
unsigned int sensorValues[NUM_SENSORS];

int lastError = 0;

void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);
  pinMode(6, OUTPUT); //PWM Pin 1

  pinMode(11, OUTPUT); //PWM Pin 2

  pinMode(7, OUTPUT); //Left Motor Pin 1

  pinMode(8, OUTPUT); //Left Motor Pin 2

  pinMode(9, OUTPUT); //Right Motor Pin 1

  pinMode(10, OUTPUT); //Right Motor Pin 2
  pinMode(3, OUTPUT);

analogWrite(tr,255);
}

void loop() {
  // put your main code here, to run repeatedly:

}
