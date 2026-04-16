#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP3XX.h>

#define SEA_LEVEL_PRESSURE_HPA 1013.25

Adafruit_BMP3XX bmp;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("BMP388 test...");

  // Initialize sensor
  if (!bmp.begin_I2C()) {
    Serial.println("Could not find BMP388!");
    while (1);
  }

  // Optional: set oversampling (better accuracy)
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);

  Serial.println("BMP388 initialized!");
}

void loop() {
  if (!bmp.performReading()) {
    Serial.println("Failed to read sensor!");
    return;
  }

  // Temperature
  Serial.print("Temperature: ");
  Serial.print(bmp.temperature);
  Serial.println(" °C");

  // Pressure
  Serial.print("Pressure: ");
  Serial.print(bmp.pressure / 100.0);
  Serial.println(" hPa");

  // Altitude
  Serial.print("Altitude: ");
  Serial.print(bmp.readAltitude(SEA_LEVEL_PRESSURE_HPA));
  Serial.println(" m");

  Serial.println("-----------------------");

  delay(1000);
}