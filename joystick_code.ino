#define joystickX    A0
#define pwm1         8
#define pwm2         7
#define joystickY    A1
#define pwm3         5
#define pwm4         4
//#define switchfast   A2
//#define switchslow   A3
int xDirection = 0;
int yDirection = 0; 
int motor_control;
 
void setup() {
  Serial.begin(9600);
  pinMode(pwm1,   OUTPUT);
  pinMode(pwm2,   OUTPUT); 
  pinMode(pwm3,   OUTPUT);
  pinMode(pwm4,   OUTPUT); 
  
}
 
void loop() {
   // read the input on analog pin 0:
  // For joystick on/off, fast/slow
 // int sensorValue = analogRead(A2);
 // int sensorValue = analogRead(A3);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
 // Serial.println(voltage);
  
 // if analogRead(switchfast, high) 
 //   motor_control 
  Serial.print("x-waarde:");
  Serial.println(analogRead(joystickX));
  Serial.print("Y-waarde:");
  Serial.println(analogRead(joystickY));

  xDirection = analogRead(joystickX);
  yDirection = analogRead(joystickY);

  if (xDirection <= 470){ //links draaien
    digitalWrite(pwm1, HIGH);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, LOW);
    digitalWrite(pwm4, LOW);
    Serial.println("Links");
  }
  else if (xDirection >= 540){ //rechts draaien
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, HIGH);
    digitalWrite(pwm4, LOW);
    Serial.println("Rechts");
  }
  else if (yDirection <= 470){ //achteruit
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, HIGH);
    digitalWrite(pwm3, LOW);
    digitalWrite(pwm4, HIGH);
    Serial.println("Achteruit");
  }
  else if (yDirection >= 530){
    digitalWrite(pwm1, HIGH);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, HIGH);
    digitalWrite(pwm4, LOW);
    Serial.println("Vooruit");
  }
  else {
    digitalWrite(pwm1, LOW);
    digitalWrite(pwm2, LOW);
    digitalWrite(pwm3, LOW);
    digitalWrite(pwm4, LOW);
  }
}
