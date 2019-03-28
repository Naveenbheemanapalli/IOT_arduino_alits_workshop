#include <SoftwareSerial.h>
SoftwareSerial myGsm(10,11);

void setup()
{
 myGsm.begin(9600);  
 Serial.begin(9600);  
 delay(500);
 while(1)
 {
 myGsm.println("AT+CGATT=1");
 delay(200);
 printSerialData();
 
 myGsm.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR,connection type is GPRS
 delay(1000);
 printSerialData();
 
 myGsm.println("AT+SAPBR=3,1,\"APN\",\"www\"");//setting the APN,2nd parameter empty works for all networks 
 delay(5000);
 printSerialData();
 
 myGsm.println();
 myGsm.println("AT+SAPBR=1,1");
 delay(10000);
 printSerialData();
 
 myGsm.println("AT+HTTPINIT"); //init the HTTP request
 delay(2000); 
 printSerialData();

 myGsm.println("AT+HTTPPARA=\"CID\",1");// setting the httppara, 
 //the second parameter is the website from where you want to access data 
 delay(1000);
 printSerialData();
 
 
 myGsm.println("AT+HTTPPARA=\"URL\",\"http://api.thingspeak.com/apps/thinghttp/send_request?api_key=CT9B331KB5PLM1G5\"");// date 
 //  myGsm.println("AT+HTTPPARA=\"URL\",\"http://api.thingspeak.com/apps/thinghttp/send_request?api_key=OFRYILNFR4JPTSHJ\"");// time
 //myGsm.println("AT+HTTPPARA=\"URL\",\"http://api.thingspeak.com/apps/thinghttp/send_request?api_key=UQJRX09TIDG1HA12\"");// time
   
 //the second parameter is the website from where you want to access data 
 delay(1000);
 printSerialData();
 
 myGsm.println();
 myGsm.println("AT+HTTPACTION=0");//submit the GET request 
 delay(10000);//the delay is important if the return datas are very large, the time required longer.
 printSerialData();
 myGsm.println("AT+HTTPREAD=0,30");// read the data from the website you access
 delay(5000);
 printSerialData();
 delay(5000);
 myGsm.println("");
 delay(1000);
 myGsm.println("AT+HTTPTERM");// terminate HTTP service
 printSerialData();

}}

void loop()
{
}


void printSerialData()
{
 while(myGsm.available()!=0)
 Serial.write(myGsm.read());
}




