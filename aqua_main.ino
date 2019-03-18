/* PROJECT AQUA ARDUINO UNIT CODE : ADAPTED FROM PREVIOUS DESIGN BY BEN GLADDERS
 * WIRING INSTRUCTIONS
 * PARTICULATE: PIN 2 (green) to 3V (breadboad); PIN 6 (yellow #1) to RX; PIN 7 (orange) to TX; PIN 8 (yellow #2) to GND [USES SERIAL2]
 * PRESS/TEMP: 3V to 3V (breadboard); GND to GND; SCK to SCL (21); SDI to SDA (20)
 * COMM MOD: 5V to 5V (Arduino); GND to GND; PWR to 9; TX to RX1; RX to TX1 [USES SERIAL1]
 * DSG SENSORS: CO Sensor - rx:46 tx:47, NO2 Sensor - rx:48 tx:49, O3 Sensor - rx:50 tx:51, SO2 Sensor - rx:52 tx:53
 */

#include <hpma115S0.h> //libraries required for the code (can be found in shared folder)
#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include "soft_uart.h"
using namespace arduino_due;

#define SOFT_UART_BIT_RATE 9600 // 57600 38400 1200 19200 9600 115200 115200
#define RX_BUF_LENGTH 64 // software serial port's reception buffer length
#define TX_BUF_LENGTH 64 // software serial port's transmision buffer length
#define RECEPTION_TIMEOUT 100 // milliseconds

HPMA115S0 hpma115S0(Serial2); //defines particulare connection & name required for library
Adafruit_BMP280 bmp;  //defines temp & pressure sensor name required for library
serial_tc0_declaration(RX_BUF_LENGTH,TX_BUF_LENGTH);  //tc0 - CO Sensor - rx:46 tx:47 
serial_tc1_declaration(RX_BUF_LENGTH,TX_BUF_LENGTH);  //tc1 - NO2 Sensor - rx:48 tx:49
serial_tc2_declaration(RX_BUF_LENGTH,TX_BUF_LENGTH);  //tc2 - O3 Sensor - rx:50 tx:51
serial_tc3_declaration(RX_BUF_LENGTH,TX_BUF_LENGTH);  //tc3 - SO2 Sensor - rx:52 tx:53


int seconds; //set to 60 for 1 min of readings
int pm2_5Count; //counter for particulate 2.5 average
int pm10Count; 
int tempCount; 
int pressureCount; 

float total2_5 = 0; //added to by each reading to get the total for 2.5
float average2_5 = 0; //holds the average when total is divided by count
float total10 = 0;
float average10 = 0;
float temp = 0; //holds readings as they come in
float tempTotal = 0;
float pressure = 0;
float pressTotal = 0;
float pressAverage = 0;
float tempAverage = 0;

float CO, NO2, O3, SO2 =0;  //DGS VALUES
int countCO, countNO2, countO3, countSO2 =0; //NUMBER OF SEPERATE SENSOR'S READINGS IN 60 SECOND PERIOD
const unsigned char hexCR=0xD, hexLowerC=0x63;
  
unsigned int pm2_5;
unsigned int pm10;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); //start connecting with computer dialogue
  Serial1.begin(19200); //start connection with comm module
  Serial2.begin(9600); //start connection with particulate sensor
  if (!bmp.begin()) {  //starts the temp & press sensor off
    Serial.println(F("Could not find BMP280 sensor, check wiring!")); //gives a warning message if it can't find the sensor
    while (1);
  }
  delay(1000);
  Serial.println("Starting...");
  hpma115S0.Init(); //start the particulate sensor

  Serial.println("Setting up DGS sensors..");
  serial_tc0.begin(46, 47, SOFT_UART_BIT_RATE, soft_uart::data_bit_codes::EIGHT_BITS, soft_uart::parity_codes::NO_PARITY, soft_uart::stop_bit_codes::ONE_STOP_BIT);
  serial_tc1.begin(48, 49, SOFT_UART_BIT_RATE, soft_uart::data_bit_codes::EIGHT_BITS, soft_uart::parity_codes::NO_PARITY, soft_uart::stop_bit_codes::ONE_STOP_BIT);
  serial_tc2.begin(50, 51, SOFT_UART_BIT_RATE, soft_uart::data_bit_codes::EIGHT_BITS, soft_uart::parity_codes::NO_PARITY, soft_uart::stop_bit_codes::ONE_STOP_BIT);
  serial_tc3.begin(52, 53, SOFT_UART_BIT_RATE, soft_uart::data_bit_codes::EIGHT_BITS, soft_uart::parity_codes::NO_PARITY, soft_uart::stop_bit_codes::ONE_STOP_BIT);
 //serial_tcx.begin(RXPORT, TXPORT, BITRATE, DATA-PACKET SIZE IN BITS, PARITY BIT, STOP BIT SIZE);
  
  delay(2000);
}

// the loop function runs over and over again forever
void loop() {

  //HONEYWELL PARTICLE MEASUREMENT CODE
  Serial.println("STARTING NEW READING SET");
  if (seconds == 0) {
    hpma115S0.StartParticleMeasurement(); //start taking particle readings
    delay(100);
  }
  while (seconds < 60) {
    if (hpma115S0.ReadParticleMeasurement(&pm2_5, &pm10)) { //if readings are available, add to the reading variable
      if (pm2_5 > 0) {
        pm2_5Count++; //increase counter if a reading occured
      }
      if (pm10 > 0) {
        pm10Count++;
      }
      total2_5 = total2_5 + pm2_5; //add reading to the total
      total10 = total10 + pm10;
      Serial.println("PARTICULATE 2.5: " + String(pm2_5) + " ug/m3" ); //print readings
      Serial.println("PARTICULATE 10: " + String(pm10) + " ug/m3" );
      delay(1000);
    }

    //BMP280 CODE
    Serial.print(F("TEMPERATURE = "));
    temp = bmp.readTemperature(); //take temperature reading
    if (temp > 0) {
      tempCount++;
    }
    Serial.print(temp);
    Serial.println(" *C");
    tempTotal = tempTotal + temp;
    Serial.print(F("PRESSURE = "));
    pressure = bmp.readPressure()/100; //take pressure reading
    if (pressure > 0) {
      pressureCount++;
    }
    Serial.print(pressure);
    Serial.println(" mbar");
    pressTotal = pressTotal + pressure;
    
    //SPEC SENSORS DGS CODE
    readSoftUart();
    
    seconds++; //increase seconds counter by 1 (should total 60 before moving on)
  }

  
  if (seconds == 60) { //when seconds reach this, readings stop
    hpma115S0.StopParticleMeasurement(); //stop the particulate sensor from doing measurements
    Serial.println("Reading stopped!");
    Serial.println("");
    average2_5 = total2_5 / pm2_5Count; //average the readings (reading / number of readings)
    average10 = total10 / pm10Count;
    pressAverage = pressTotal / pressureCount;
    tempAverage = tempTotal / tempCount;
    Serial.println("PM 2.5 average: " + String(average2_5) + " ug/m3"); //print the averages
    Serial.println("PM 10 average: " + String(average10) +  " ug/m3");
    Serial.println("Temp average: " + String(tempAverage) + " *C");
    Serial.println("Pressure average: " + String(pressAverage) + " mbar");
    Serial.print("CO readings: ");
    Serial.println(countCO);
    Serial.print("NO2 readings: ");
    Serial.println(countNO2);
    Serial.print("O3 readings: ");
    Serial.println(countO3);
    Serial.print("SO2 readings: ");
    Serial.println(countSO2);
    Serial.print("CO average: ");
    Serial.println(CO/countCO);
    Serial.print("NO2 average: ");
    Serial.println(NO2/countNO2);
    Serial.print("O3 average: ");
    Serial.println(O3/countO3);
    Serial.print("SO2 average: ");
    Serial.println(SO2/countSO2);
    delay(1000);
    
    Serial.println("Now powering on comm module...");
    commPower(); //turn on the communication module
    
    // attach or detach from GPRS service
    Serial1.flush();
    delay(1000);
    while (toSerialNew().indexOf("1") == -1) { //checks for GPRS connection - specificall, a 1 being returned
      Serial.println("Still waiting...");
      Serial1.println("AT+CGATT?"); //repeats the connection query
      delay(1000);
    }
    Serial.println("Connected!");

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

    // send the averages to the website
    Serial1.print("AT+HTTPPARA=\"URL\",\"http://www.aquayork.co.uk/send?id=1&temp=");
    Serial1.print(String(tempAverage));
    Serial1.print("&press=");
    Serial1.print(String(pressAverage));
    Serial1.print("&o3=");
    Serial1.print(String(O3/countO3));
    Serial1.print("&no2=");
    Serial1.print(String(NO2/countNO2));
    Serial1.print("&so2=");
    Serial1.print(String(SO2/countSO2));
    Serial1.print("&co=");
    Serial1.print(String(CO/countCO));
    Serial1.print("&pm25=");
    Serial1.print(String(average2_5));
    Serial1.print("&pm10=");
    Serial1.print(String(average10));
    Serial1.println("\"");
    
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
    average2_5 = 0; //set everything back to zero ready for the next reading set
    average10 = 0;
    total10 = 0;
    total2_5 = 0;
    tempTotal = 0;
    tempAverage = 0;
    pressTotal = 0;
    pressAverage = 0;
    pm2_5Count = 0;
    pm10Count = 0;
    tempCount = 0;
    pressureCount = 0;

    CO, NO2, O3, SO2 =0;
    countCO, countNO2, countO3, countSO2 =0;
    
    seconds = 0;
    Serial.flush();    
    delay(10000);
  }
}

void commPower() //software equivalent of pressing the power button on comm module!
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

String toSerialNew()
{
  String lovelyNewString = "";
  while(Serial1.available()!=0)
  {
    char lovelyNewChar = Serial1.read();
    lovelyNewString.concat(lovelyNewChar);
    //Serial.write(lovelyNewChar);
  }

  return lovelyNewString;
}

float getConc(String sensorOutput){ //When passed the entire sensor output string, will single out the concentration reading and return as a float.
    String firstSub, finalSub;
    float fValue;
    firstSub = sensorOutput.substring(sensorOutput.indexOf(',')+1);
    finalSub = firstSub.substring(0,firstSub.indexOf(','));
    return finalSub.toFloat();
  }

void readSoftUart(){  //writes a carriage return to each sensor then reads the data sent back, passing through getConc() to single out the concentration. If valid reading then store it and up the data count, ready for averaging.

  float tempCO, tempNO2, tempO3, tempSO2 =0;
     
  Serial.println("\n-----------------------Starting readings from DGS's------------------------\n\nWriting \"Carriage return\" to soft_uart ports.\n");
  serial_tc0.write(hexCR);
  serial_tc1.write(hexCR);
  serial_tc2.write(hexCR);
  serial_tc3.write(hexCR);
  /*serial_tc0.write(hexLowerC);
  serial_tc1.write(hexLowerC);
  serial_tc2.write(hexLowerC);
  serial_tc3.write(hexLowerC);
*/
  delay(1000);

  tempCO = getConc(serial_tc0.readStringUntil('\n'));
  if (tempCO!=0){
    CO+=(float)tempCO;
    Serial.print("Data from CO Sensor: ");
    Serial.println(tempCO);
    countCO++;
    }

  tempNO2 = getConc(serial_tc1.readStringUntil('\n'));
  if (tempNO2!=0){
    NO2+=(float)tempNO2;
    Serial.print("Data from NO2 Sensor: ");
    Serial.println(tempNO2);
    countNO2++;
    }

    tempO3 = getConc(serial_tc2.readStringUntil('\n'));
  if (tempO3!=0){
    O3+=(float)tempO3;
    Serial.print("Data from O3 Sensor: ");
    Serial.println(tempO3);
    countO3++;
    }

    tempSO2 = getConc(serial_tc3.readStringUntil('\n'));
  if (tempSO2!=0){
    SO2+=(float)tempSO2;
    Serial.print("Data from SO2 Sensor: ");
    Serial.println(tempSO2);
    countSO2++;
    }

  Serial.println("\n-----------------------End of DGS readings------------------------\n");
  } 
