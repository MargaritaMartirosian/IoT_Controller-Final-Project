#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;  // create another servo object

void setup() {
  servo1.attach(9);  // attaches the first servo on pin 9 to the servo object
  servo2.attach(10); // attaches the second servo on pin 10 to the servo object
}

void loop() {
  // Sweep servo1 from 0 to 180 degrees
  for (int pos = 0; pos <= 180; pos += 1) {
    servo1.write(pos);
    delay(15);
  }
  // And back from 180 to 0 degrees
  for (int pos = 180; pos >= 0; pos -= 1) {
    servo1.write(pos);
    delay(15);
  }

  // Sweep servo2 from 0 to 180 degrees
  for (int pos = 0; pos <= 180; pos += 1) {
    servo2.write(pos);
    delay(15);
  }
  // And back from 180 to 0 degrees
  for (int pos = 180; pos >= 0; pos -= 1) {
    servo2.write(pos);
    delay(15);
  }
}
