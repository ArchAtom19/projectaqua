#include <hpma115S0.h>
#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

HPMA115S0 hpma115S0(Serial1);
Adafruit_BMP280 bmp; 

int seconds;
float total2_5;
float average2_5;
float total10;
float average10;
float temp; 
float tempTotal;
float pressure;
float pressTotal;
float pressAverage;
float tempAverage;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  if (!bmp.begin()) {  //this starts the sensor off
    Serial.println(F("Could not find BMP280 sensor, check wiring!")); //gives a warning message if it can't find the sensor
    while (1);
  }
  delay(1000);
  Serial.println("Starting...");
  hpma115S0.Init();
}

// the loop function runs over and over again forever
void loop() {
  while (seconds < 60) {
    hpma115S0.StartParticleMeasurement();
    unsigned int pm2_5, pm10;
    if (hpma115S0.ReadParticleMeasurement(&pm2_5, &pm10)) {
      total2_5 = total2_5 + pm2_5;
      total10 = total10 + pm10;
      Serial.println("PM 2.5: " + String(pm2_5) + " ug/m3" );
      Serial.println("PM 10: " + String(pm10) + " ug/m3" );
    }
    temp = bmp.readTemperature();
    Serial.println(temp + " *C");
    tempTotal = tempTotal + temp;
    pressure = bmp.readPressure();
    Serial.println(pressure + (" Pa");
    pressTotal = pressTotal + pressure;
    seconds++;
    delay(1000);
  }
  if (seconds == 60) {
    hpma115S0.StopParticleMeasurement();
    Serial.println("Reading stopped!");
    delay(3000);
    average2_5 = total2_5 / seconds;
    average10 = total10 / seconds;
    pressAverage = pressTotal / seconds;
    tempAverage = tempTotal / seconds;
    Serial.println("PM 2.5 average: " + String(average2_5));
    Serial.println("PM 10 average: " + String(average10));
    Serial.println("Temp average: " + tempAverage + " *C");
    Serial.println("Pressure average: " + pressAverage + " Pa"); 
    average2_5 = 0;
    average10 = 0;
    total10 = 0;
    total2_5 = 0;
    tempTotal = 0;
    tempAverage = 0;
    pressTotal = 0;
    pressAverage = 0;
    seconds = 0;    
    delay(5000);
  }
}
