
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

//SoftwareSerial mySerial(8, 9); // RX, TX

int data=0,count=0;
String a;
char ch ,rcv;
 LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 const int sensor1 = 10;
  int buttonState1 = 0;
void okcheck();
void setup()
{
  pinMode(sensor1, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
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
 
  delay(1000);
 int y = analogRead(A0);Serial.print("temp:");Serial.print(y);Serial.print("\r\n");
 int z = analogRead(A1);Serial.print("light:");Serial.print(z);Serial.print("\r\n");
  
  
  if (y>=130)
  { 
    digitalWrite(8, HIGH); 
Serial.print("AT+SAPBR=3,1,");Serial.print('"');Serial.print("Contype");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("GPRS");Serial.print('"');Serial.print("\r\n");delay(1000);
Serial.print("AT+SAPBR=3,1,");Serial.print('"');Serial.print("APN");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("WWW");Serial.print('"');Serial.print("\r\n");delay(1000);
Serial.print("AT+SAPBR=1,1\r\n");delay(10000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);
Serial.print("AT+SAPBR=2,1\r\n");delay(1000);
Serial.print("AT+HTTPINIT\r\n");delay(1000);
int y = analogRead(A0);
Serial.print("AT+HTTPPARA=");Serial.print('"');Serial.print("URL");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("http://api.thingspeak.com/update?key=154V2WPYDD17XH9S&field2=High Temprature:");Serial.print(y);Serial.print('"');Serial.print("\r\n");delay(3000);
Serial.print("AT+HTTPACTION=0\r\n"); delay(1000);
Serial.print("AT+HTTPACTION=0\r\n"); delay(1000);
  
  }
  else
  {
    digitalWrite(8, LOW);
  }
  
  if (z<700)
  {  
    digitalWrite(9, LOW);
Serial.print("AT+SAPBR=3,1,");Serial.print('"');Serial.print("Contype");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("GPRS");Serial.print('"');Serial.print("\r\n");delay(1000);
Serial.print("AT+SAPBR=3,1,");Serial.print('"');Serial.print("APN");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("WWW");Serial.print('"');Serial.print("\r\n");delay(1000);
Serial.print("AT+SAPBR=1,1\r\n");delay(10000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);Serial.print("AT+SAPBR=1,1\r\n");delay(1000);
Serial.print("AT+SAPBR=2,1\r\n");delay(1000);
Serial.print("AT+HTTPINIT\r\n");delay(1000);
Serial.print("AT+HTTPPARA=");Serial.print('"');Serial.print("URL");Serial.print('"');Serial.print(',');Serial.print('"');Serial.print("http://api.thingspeak.com/update?key=154V2WPYDD17XH9S&field2=light");Serial.print('"');Serial.print("\r\n");delay(3000);
Serial.print("AT+HTTPACTION=0\r\n"); delay(1000);
Serial.print("AT+HTTPACTION=0\r\n"); delay(1000);
  
  }
  else
  {
    digitalWrite(9, HIGH);
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
