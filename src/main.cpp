#include <Arduino.h>
#include "WiFi.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

const char* ssid = "YOUR_SSID";
const char* pw = "YOUR_PW";

DHT dht(4, DHT11);

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

int ldr(){
    return analogRead(34);
}

int soil(){
    return analogRead(35);
}

//int rain(){ return analogRead(32); }

//int sound(){ return analogRead(35); }

int waterlev(){ return analogRead(32); }

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
    Serial.println("IP:");Serial.println(WiFi.localIP());
    Serial.println("Temp:");Serial.println(temp());
    Serial.println("Humid:");Serial.println(humid());
    Serial.println("Light:");Serial.println(ldr());
    Serial.println("Soil Moisture:");Serial.println(soil());
    //Serial.println("Rain:"); Serial.println(rain());
    //Serial.println("Sound:"); Serial.println(sound());
    Serial.println("Water:"); Serial.println(waterlev());
    delay(2000);
}