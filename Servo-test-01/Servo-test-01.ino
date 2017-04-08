

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int sw_pin = 8; //connect a wire from digital pin 8 as a makeshift switch

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(sw_pin, INPUT_PULLUP); //make pin 8 HIGH by default
}

void loop() {
  if (digitalRead(sw_pin)) == LOW){ //if pin 8 is connected to GND, pulling it LOW
    myservo.write(90);              // set the servo to center position
  }
  else { //pin 8 is not connected to GND, leaving it HIGH
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 1ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 1ms for the servo to reach the position
  }
  }
}
