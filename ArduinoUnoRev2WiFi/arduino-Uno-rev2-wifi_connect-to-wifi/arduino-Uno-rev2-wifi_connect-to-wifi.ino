#include <SPI.h>
#include <WiFiNINA.h>

char ssid[] = "Rpi_zone";     // 
char pass[] = "P@$$w0rd100%"; // 

int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Connecting to WiFi...");

  // Check if WiFi module exists
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("WiFi module not found!");
    while (true);
  }

  // Connect to WiFi
  while (status != WL_CONNECTED) {
    Serial.print("Attempting connection to: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);
    delay(5000);
  }

  Serial.println("Connected to WiFi!");
  printWiFiStatus();
}

void loop() {
  // nothing here
}

void printWiFiStatus() {
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Signal strength (RSSI): ");
  Serial.println(WiFi.RSSI());

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
}