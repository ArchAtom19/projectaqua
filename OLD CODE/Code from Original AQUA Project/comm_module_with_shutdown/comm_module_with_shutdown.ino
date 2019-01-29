//Requires 5V, Ground, TX1, RX1, 9

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600); //comm mod connection (currently TX1,RX1)
  Serial.println("Starting!");
}


void loop()
{
  commPower(); //power on comm mod
  delay(20000); //give it time to connect to network (adjust as necessary)
  Serial.println("CommMod powered!");

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
   Serial1.println("AT+HTTPPARA=\"URL\",\"http://www.aquayork.co.uk/send?sensor=1&temp=500&press=500&o3=500&no2=500&so2=500&co=500&pm25=500&pm10=500\"");
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

   commPower(); //power off comm mod
   Serial.println("CommMod off!");
   delay(5000); //give it time to connect to network (adjust as necessary)
   
   //delay(10000);
}

void toSerial() //writing what the comm module recieves to the serial monitor
{
  while(Serial1.available()!=0)
  {
    Serial.write(Serial1.read());
  }
}

void commPower() //software equivalent of pressing the power button!
{
  //digitalWrite(9, LOW);
  //delay(1000);
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(5000);
}

