
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

//SoftwareSerial mySerial(8, 9); // RX, TX

int data=0,count=0;
String a;
char ch ,data1[61],rcv;
 LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 const int sensor1 = 10;
  const int sensor2 = 11;
  int buttonState1 = 0;
  int buttonState2 = 0;
void okcheck();
void setup()
{
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);  
  lcd.begin(16, 2);
  Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
   // mySerial.begin(9600);
 // mySerial.println("Hello, world?");
}

void loop()
{
  
  lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);


while(1)
{
 buttonState1 = digitalRead(sensor1);
 buttonState2 = digitalRead(sensor2);
  if (buttonState1 == LOW)
  {     
Serial.print("AT+SAPBR=3,1,");Serial.print('"');Serial.print("Contype");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("GPRS");Serial.print('"');Serial.print("\r\n");delay(1000);
Serial.print("AT+SAPBR=3,1,");Serial.print('"');Serial.print("APN");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("WWW");Serial.print('"');Serial.print("\r\n");delay(1000);
Serial.print("AT+SAPBR=1,1\r\n");delay(10000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);
Serial.print("AT+SAPBR=2,1\r\n");delay(1000);
Serial.print("AT+HTTPINIT\r\n");delay(1000);
Serial.print("AT+HTTPPARA=");Serial.print('"');Serial.print("URL");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("http://api.thingspeak.com/update?key=154V2WPYDD17XH9S&field1=SOME ONE AT PLACE 1");Serial.print('"');Serial.print("\r\n");delay(3000);
Serial.print("AT+HTTPACTION=0\r\n"); delay(1000);
Serial.print("AT+HTTPACTION=0\r\n"); delay(1000);
  
  } 
  if (buttonState1 == HIGH)
  {   
   // Serial.print("sensor1 deactivated\r\n");  
  }
   if (buttonState2 == LOW)
  { 
        
lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);

Serial.print("AT+SAPBR=3,1,");Serial.print('"');Serial.print("Contype");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("GPRS");Serial.print('"');Serial.print("\r\n");delay(1000);
Serial.print("AT+SAPBR=3,1,");Serial.print('"');Serial.print("APN");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("WWW");Serial.print('"');Serial.print("\r\n");delay(1000);
Serial.print("AT+SAPBR=1,1\r\n");delay(10000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);
Serial.print("AT+SAPBR=2,1\r\n");delay(1000);
Serial.print("AT+HTTPINIT\r\n");delay(1000);
Serial.print("AT+HTTPPARA=");Serial.print('"');Serial.print("URL");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("http://api.thingspeak.com/update?key=154V2WPYDD17XH9S&field1=SOME ONE AT PLACE 2");Serial.print('"');Serial.print("\r\n");delay(3000);
Serial.print("AT+HTTPACTION=0\r\n"); delay(1000);
Serial.print("AT+HTTPACTION=0\r\n"); delay(1000);
 
  } 
  if (buttonState2 == HIGH)
  {    
    //Serial.print("sensor2 deactivated\r\n"); 
  }

}
}
void okcheck()
{
  if(Serial.available()>0)

  {
    digitalWrite(LED_BUILTIN, HIGH);
  
  do
  {
    ch=Serial.read();
    }while(ch!='K');
  digitalWrite(LED_BUILTIN, LOW);
}  
}
