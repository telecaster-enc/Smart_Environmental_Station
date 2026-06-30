#include <Arduino.h>
#include "WiFi.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

const char* ssid = "Redmi Note 10S";
const char* pw = "z1111111";

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

String temp() {
    float t = dht.readTemperature();
    if (isnan(t)){
        return "Temp Error";
    } else {
        return String(t);
    }
}

String humid() {
    float h = dht.readHumidity();
    if (isnan(h)){
        return "Humid Error";
    } else {
        return String(h);
    }
}


void setup() {
    Serial.begin(115200);
    dht.begin();
    WiFi.begin(ssid, pw);
    while (WiFi.status()!=WL_CONNECTED){
        delay(1000);
        Serial.println("WiFi...");
    }
}

void loop() {
    Serial.println(WiFi.localIP());
    Serial.println(temp());
    Serial.println(humid());
    delay(1000);
}