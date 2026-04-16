#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(12);
}

void loop() {
  Serial.print("30 Angle rotation: ");
  for (int angle = 0; angle <= 180; angle += 30) {
    myServo.write(angle);
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.println("°");
    delay(400);
  }

  Serial.print("45 Angle rotation: ");
  for (int angle = 0; angle <= 180; angle += 45) {
    myServo.write(angle);
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.println("°");
    delay(400);
  }

  Serial.print("90 Angle rotation: ");
  for (int angle = 0; angle <= 180; angle += 90) {
    myServo.write(angle);
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.println("°");
    delay(500);
  }

  Serial.print("180 Angle rotation: ");
  for (int angle = 0; angle <= 180; angle += 180) {
    myServo.write(angle);
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.println("°");
    delay(600);
  }

}