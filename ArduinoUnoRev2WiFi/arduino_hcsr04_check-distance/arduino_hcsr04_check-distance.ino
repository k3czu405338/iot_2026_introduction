// #define TRIG_PIN 9
// #define ECHO_PIN 10

// long readDistanceCM() {
//   // Clear trigger
//   digitalWrite(TRIG_PIN, LOW);
//   delayMicroseconds(5);

//   // Send pulse
//   digitalWrite(TRIG_PIN, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(TRIG_PIN, LOW);

//   // Read echo with timeout
//   long duration = pulseIn(ECHO_PIN, HIGH, 30000);

//   if (duration == 0) {
//     return -1;
//   }

//   return (duration / 2.0) * 0.0343;
// }

// // Average multiple readings (IMPORTANT improvement)
// long getStableDistance() {
//   int samples = 5;
//   long sum = 0;
//   int valid = 0;

//   for (int i = 0; i < samples; i++) {
//     long d = readDistanceCM();
//     if (d > 0) {
//       sum += d;
//       valid++;
//     }
//     delay(30);
//   }

//   if (valid == 0) return -1;
//   return sum / valid;
// }

// void setup() {
//   Serial.begin(9600);
//   pinMode(TRIG_PIN, OUTPUT);
//   pinMode(ECHO_PIN, INPUT);
// }

// void loop() {
//   long distance = getStableDistance();

//   if (distance == -1) {
//     Serial.println("Out of range");
//   } else {
//     Serial.print("Distance: ");
//     Serial.print(distance);
//     Serial.println(" cm");
//   }

//   delay(500);
// }


// /*
//  * HC-SR04 example sketch
//  *
//  * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
//  *
//  * by Isaac100
//  */

// const int trigPin = 9;
// const int echoPin = 10;

// float duration, distance;

// void setup() {
//   pinMode(trigPin, OUTPUT);
//   pinMode(echoPin, INPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   duration = pulseIn(echoPin, HIGH);
//   distance = (duration*.0343)/2;
//   Serial.print("Distance: ");
//   Serial.println(distance);
//   delay(100);
// }





#define TRIG_PIN 9
#define ECHO_PIN 10

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) return -1;

  // return float with higher precision
  return (duration / 2.0) * 0.0343;
}

float getFilteredDistance() {
  const int samples = 3;   // small number to keep 10 Hz
  float sum = 0;
  int valid = 0;

  for (int i = 0; i < samples; i++) {
    float d = readDistanceCM();
    if (d > 0) {
      sum += d;
      valid++;
    }
  }

  if (valid == 0) return -1;
  return sum / valid;
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  float distance = getFilteredDistance();

  if (distance < 0) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance, 2); // 👈 2 decimal places
    Serial.println(" cm");
  }

  delay(100); // 👈 10 times per second (100 ms)
}

