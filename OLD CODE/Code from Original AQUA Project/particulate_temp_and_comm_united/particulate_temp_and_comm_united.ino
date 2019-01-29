#include <hpma115S0.h>
#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
/* WIRING INSTRUCTIONS
 * PARTICLATE: PIN 2 (green) to 5V; PIN 6 (yellow #1) to RX; PIN 7 (orange) to TX; PIN 8 (yellow #2) to GND [USES SERIAL2]
 * PRESS/TEMP: 3V to 3V; GND to GND; SCK to SCL (21); SDI to SDA (20)
 * COMM MOD: 5V to 5V; GND to GND; PWR to 9; TX to RX1; RX to TX1 [USES SERIAL1]
 */
HPMA115S0 hpma115S0(Serial2);
Adafruit_BMP280 bmp; 

int seconds;
float total2_5 = 0;
float average2_5 = 0;
float total10 = 0;
float average10 = 0;
float temp = 0; 
float tempTotal = 0;
float pressure = 0;
float pressTotal = 0;
float pressAverage = 0;
float tempAverage = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  //if (!bmp.begin()) {  //this starts the sensor off
   // Serial.println(F("Could not find BMP280 sensor, check wiring!")); //gives a warning message if it can't find the sensor
   // while (1);
  //}
  bmp.begin();
  delay(1000);
  Serial.println("Starting...");
  hpma115S0.Init();
}

// the loop function runs over and over again forever
void loop() {
  if (seconds == 0) {
    hpma115S0.StartParticleMeasurement();
    delay(3000);
  }
  while (seconds < 60) {
    unsigned int pm2_5, pm10;
    if (hpma115S0.ReadParticleMeasurement(&pm2_5, &pm10)) {
      total2_5 = total2_5 + pm2_5;
      total10 = total10 + pm10;
      Serial.println("PARTICULATE 2.5: " + String(pm2_5) + " ug/m3" );
      Serial.println("PARTICULATE 10: " + String(pm10) + " ug/m3" );
      delay(1000);
    }
    Serial.print(F("TEMPERATURE = "));
    temp = bmp.readTemperature();
    Serial.print(temp);
    Serial.println(" *C");
    tempTotal = tempTotal + temp;
    Serial.print(F("PRESSURE = "));
    pressure = bmp.readPressure();
    Serial.print(pressure);
    Serial.println(" Pa");
    pressTotal = pressTotal + pressure;
    seconds++;
  }
  if (seconds == 60) {
    hpma115S0.StopParticleMeasurement();
    Serial.println("Reading stopped!");
    Serial.println("");
    average2_5 = total2_5 / (seconds / 2);
    average10 = total10 / (seconds / 2);
    pressAverage = (pressTotal / seconds) / 100;
    tempAverage = tempTotal / seconds;
    Serial.println("PM 2.5 average: " + String(average2_5) + " ug/m3");
    Serial.println("PM 10 average: " + String(average10) +  " ug/m3");
    Serial.println("Temp average: " + String(tempAverage) + " *C");
    Serial.println("Pressure average: " + String(pressAverage) + " mbar");
    delay(1000);
    
    Serial.println("Now powering on comm module...");
    commPower(); //turn on the communication module
    delay(60000); //give it time to connect to network
    Serial.println("Comm module should now be powered & connected!");
    
    // attach or detach from GPRS service 
    Serial1.println("AT+CGATT?");
    delay(100);
    toSerial();

    // bearer settings
    Serial1.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
    delay(2000);
    toSerial();

    // bearer settings
    Serial1.println("AT+SAPBR=3,1,\"APN\",\"m2mkit.telefonica.com\"");
    delay(2000);
    toSerial();

    // bearer settings
    Serial1.println("AT+SAPBR=1,1");
    delay(2000);
    toSerial();
  
    // initialize http service
    Serial1.println("AT+HTTPINIT");
    delay(2000); 
    toSerial();

    // set http param value - change our variables and sensor data in the below code
    Serial1.println("AT+HTTPPARA=\"URL\",\"http://www.aquayork.co.uk/send?id=1&temp=" + String(tempAverage) + "&press=" + String(pressAverage) + "&o3=4&no2=7&so2=2&co=15&pm25=" + String(average2_5) + "&pm10=" + String(average10) + "\"");
    delay(2000);
    toSerial();

    // set http action type 0 = GET, 1 = POST, 2 = HEAD
    Serial1.println("AT+HTTPACTION=0");
    delay(6000);
    toSerial();

    // read server response
    Serial1.println("AT+HTTPREAD"); 
    delay(1000);
    toSerial();

    Serial1.println("");
    Serial1.println("AT+HTTPTERM");
    toSerial();
    delay(300);

    Serial1.println("");
    delay(1000);
    
    commPower(); //power off comm mod
    Serial.println("CommMod off!"); 
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

void commPower() //software equivalent of pressing the power button!
{
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(9, HIGH);
  delay(3000);
  digitalWrite(9, LOW);
  delay(1000);
}

void toSerial() //writing what the comm module recieves to the serial monitor
{
  while(Serial1.available()!=0)
  {
    Serial.write(Serial1.read());
  }
}
