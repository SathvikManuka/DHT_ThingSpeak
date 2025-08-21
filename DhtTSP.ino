#include <ESP8266WiFi.h>
#include "DHT.h"
#include "ThingSpeak.h"

// WiFi credentials
const char* ssid = "Jayanth";
const char* password = "12345678";

// ThingSpeak credentials
unsigned long myChannelNumber = 3042437;   // Replace with your ThingSpeak Channel ID
const char* myWriteAPIKey = "XLNDEAO0AHWTIUAB";  // Replace with your Write API Key

// DHT setup
#define DHTPIN D4       // GPIO2 (D4 on NodeMCU)
#define DHTTYPE DHT11   // Change to DHT22 if using that sensor
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read DHT values
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C, Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  // Send data to ThingSpeak
  ThingSpeak.setField(1, t);  // Field1 = Temperature
  ThingSpeak.setField(2, h);  // Field2 = Humidity

  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (x == 200) {
    Serial.println("Data sent to ThingSpeak successfully!");
  } else {
    Serial.print("Failed to send data. HTTP error code: ");
    Serial.println(x);
  }

  delay(20000); // ThingSpeak allows updates every 15 seconds (safe: 20s)
}
