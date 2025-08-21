# DHT_ThingSpeak
## ESP8266 + DHT11/DHT22 + ThingSpeak IoT Project
This project demonstrates how to collect temperature and humidity data using a DHT sensor (DHT11/DHT22) and an ESP8266 (NodeMCU/Wemos D1 Mini), then upload it to ThingSpeak for real-time monitoring and visualization.

## Features
- Reads temperature (°C) and humidity (%) from DHT sensor.
- Connects ESP8266 to WiFi and uploads data to ThingSpeak Cloud.
- Stores and visualizes sensor data in graphs and dashboards.
- Supports DHT11 or DHT22 (just change sensor type in code).

<p align="center"> 
  <img src="https://github.com/SathvikManuka/DHT_ThingSpeak/blob/main/Temp%26Hum_Results.png" alt="Block Diagram" width="600" /> 
</p>

## Hardware Used
- ESP8266 (NodeMCU / Wemos D1 Mini)
- DHT11 / DHT22 Temperature & Humidity Sensor
- Jumper Wires & Breadboard

 ## Connections
- DHT Sensor to	ESP8266 (NodeMCU)
- VCC-3.3V
- GND-GND
- Data-D4 (GPIO2)

