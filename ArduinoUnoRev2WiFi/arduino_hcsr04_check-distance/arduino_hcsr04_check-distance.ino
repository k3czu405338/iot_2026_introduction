#define TRIG_PIN 9
#define ECHO_PIN 10

long readDistanceCM() {
  // Clear trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);

  // Send trigger pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo with timeout (important!)
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout

  // If no signal
  if (duration == 0) {
    return -1; // error
  }

  // Convert to distance (cm)
  return duration * 0.0343 / 2;
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long distance = readDistanceCM();

  if (distance == -1) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(300); // stable reading
}