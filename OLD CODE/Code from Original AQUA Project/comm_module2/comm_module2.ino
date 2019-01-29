//Serial1 Serial1(18,19);
double CO = 123;
double temp = 123;
double press = 123;
double o3 = 123;
double no2 = 123;
double so2 = 123;
double pm25 = 123;
double pm10 = 123;


void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial.println("Config SIM900...");
  delay(2000);
  Serial.println("Done!...");
  Serial1.flush();
  Serial.flush();

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
}


void loop()
{
   // initialize http service
   Serial1.println("AT+HTTPINIT");
   delay(2000); 
   toSerial();

   //using SSL currently doesn't work - seems to be being blocked by O2? If we get this working, remove the http:// from the URL!
   //Serial1.println("AT+HTTPSSL=1");
   //delay(2000);
   //toSerial();

   // set http param value - change our variables and sensor data in the below code
   Serial1.println("AT+HTTPPARA=\"URL\",\"http://www.aquayork.co.uk/send?id=1&temp=" + String(temp) + "&press=" + String(press) + "&o3=" + String(o3) + "&no2=" + String(no2) + "&so2=" + String(so2) + "&co=" + String(CO) + "&pm25=" + String(pm25) + "&pm10=" + String(pm10) + "\"");
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
   delay(10000);
}

void toSerial()
{
  while(Serial1.available()!=0)
  {
    Serial.write(Serial1.read());
  }
}
