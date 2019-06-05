/*
 * code to control custom made cat feeder. uses a tilt switch on a lever that the cat
 * can press down to open the treat door using a servo
 * 
 * 06/05/2019
 * gbolatto
 */


#include <Servo.h>

Servo servo;
int servoPos;

void setup() {
  servo.attach(8);
  servoPos = 150;  // 60 is up   150 is down for door
  servo.write(servoPos);
  
  pinMode(2, INPUT); // tilt switch
  digitalWrite(2, HIGH); // tilt switch

  Serial.begin(9600);
  
}

int input;
void loop() {
  if(HIGH == digitalRead(2)) {
    Serial.println("off");
  } else {  // if tilt switch turns on open the door and then close after 150ms
    Serial.println("on");
    servo.write(60);  // opens the door
    delay(150);
    servo.write(150); // closes the door after 150ms
    delay(5000);  // delay 5 seconds so nothing happens upon repeatedly pressing
  }
}
