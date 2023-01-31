#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
char t;

int in1 = 8;
int in2 = 7;
int in3 = 5;
int in4 = 4;
int s = 235;


void setup() {
  Serial.begin(38400); //open the serial port
  mySerial.begin(38400); // open the bluetooth serial port
  pinMode(in1,OUTPUT);   
  pinMode(in2,OUTPUT);   
  pinMode(in3,OUTPUT);   
  pinMode(in4,OUTPUT);   
}

void loop() {
  if(mySerial.available()){
    t = mySerial.read();
    Serial.println(t); // send from serial to bluetooth
  }
  //if(Serial.available()){
    //t = Serial.read();
    //mySerial.println(t); // send from bluetooth to serial
  //}
  if(t == 'h'){
    if (s > 235){
      s = 235;
    }
    else{
      s = s + 20;
    }
  }
  if(t== 'b'){
    if(s < 100){
      s = 100;
    }
    else{
      s = s - 20;
    }
  }
  Serial.println(s);
  if(t == 's'){            //move   forward(all motors rotate in forward direction)
    analogWrite(in1, s);
    //digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(in3, s);
    //digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("Vooruit");
  }
 
  if(t == 'd'){      //move reverse (all   motors rotate in reverse direction)
    digitalWrite(in1, LOW);
    analogWrite(in2, s);
    //digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    analogWrite(in4, s);
    //digitalWrite(in4, HIGH);
    Serial.println("Achteruit");
  }
   
  if(t == 'z'){      //turn right (left side motors rotate in forward direction,   right side motors doesn't rotate)
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(in3, s);
    //digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("Rechts");
  }
 
  if(t == 'q'){      //turn left (right side motors rotate in forward direction, left   side motors doesn't rotate)
    analogWrite(in1, s);
    //digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.println("Links");
  }
 
  if(t == 'e'){      //STOP (all motors stop)
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.println("Stop");
  }
}
