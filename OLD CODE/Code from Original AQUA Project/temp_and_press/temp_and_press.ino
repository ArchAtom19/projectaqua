/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMEP280 Breakout 
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required 
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/
//TEMPERATURE (Celsius) & PRESSURE (Pascals)
//!!This code requries the 'Adafruit Sensor' and 'Adafruit BMP280' libraries!
//!!Wire the BMP280 as follows: VIN = 5V power; GND = ground; SCK = 21; SDI = 20

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

float temp = 0; 
float tempTotal = 0;
float pressure = 0;
float pressTotal = 0;
float average = 0;


Adafruit_BMP280 bmp; 

void setup() {
  Serial.begin(9600);
  
  if (!bmp.begin()) {  //this starts the sensor off
    Serial.println(F("Could not find BMP280 sensor, check wiring!")); //gives a warning message if it can't find the sensor
    while (1);
  }
}

void loop() {
    Serial.print(F("Temperature = "));
    temp = bmp.readTemperature(); //takes temperature reading
    Serial.print(temp); //prints it
    Serial.println(" *C");
    tempTotal = tempTotal + temp; //adds this reading to the temperature total
    
    Serial.print(F("Pressure = "));
    pressure = bmp.readPressure(); //takes pressure reading
    Serial.print(pressure); //prints it
    Serial.println(" Pa");
    pressTotal = pressTotal + pressure; //adds this reading to the pressure total
    Serial.println(); //empty space between this reading and next
    average++; //adds to the counter for number of readings taken
   
    if (average == 10) { // once set number needed for an average is met; change as needed
      Serial.print(F("TEMPERATURE AVERAGE = "));
      Serial.print(tempTotal / average); //divide total by the number of readings taken & print it
      Serial.println(" *C");
      Serial.print(F("PRESSURE AVERAGE = "));
      Serial.print(pressTotal / average);
      Serial.println(" Pa");
      average = 0; //resets average so that it can be repeated again
      tempTotal = 0; //resets total
      pressTotal = 0;
      Serial.println();
    }
    
    delay(5000); //delays 5 secs before taking next reading

    
}
