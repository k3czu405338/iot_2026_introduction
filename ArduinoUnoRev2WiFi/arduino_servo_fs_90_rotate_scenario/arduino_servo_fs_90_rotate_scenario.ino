#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(12);
}

void loop() {
  for (int angle = 0; angle <= 180; angle += 10) {
    myServo.write(angle);
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.println("°");
    delay(300);
  }

  for (int angle = 180; angle >= 0; angle -= 10) {
    myServo.write(angle);
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.println("°");
    delay(300);
  }
}