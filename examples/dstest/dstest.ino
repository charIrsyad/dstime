/*
  DS1307 or DS3231 Test

  Read and Set the Time and Date on DS1307 or DS3231 RTC

  The circuit:
  - Connect VCC to 5v
  - Connect GND to GND
  - Connect SDA to SDA (A4 arduino uno) (2 Arduino leonardo) (D21 ESP32) (D2 (GPIO4) ESP8266)
  - Connect SCL to SCL (A5 arduino uno) (3 Arduino leonardo) (D22 ESP32) (D1 (GPIO5) ESP8266)

  created 2022
  by Irsyad

  This example code is in the public domain.
*/

#include <dstime.h>

DSTIME rtc; //class of rtc 

char dOW[7][15] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"}; //it start with 0 1 2 3 4...

void setup()
{
  rtc.begin();//begin the rtc
  Serial.begin(9600);
  // set the initial time here: ONLY DO THIS ONCE!
  // second, minute, hour, day of week (like Monday = 1 Tuesday = 2 etc), day of month, month, year
  // rtc.setdatetime(40,56,6,5,2,12,22);
  // here to set time only
  // second minute hour
  // rtc.settime(40,13,16);
  
}

void loop()
{
  rtc.readtime(); //reading the time from rtc

  Serial.print(rtc.dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(rtc.month, DEC);
  Serial.print("/");
  Serial.print(rtc.year, DEC);
  Serial.print(" (");
  Serial.print(dOW[rtc.dayOfWeek - 1]); 
  Serial.print(") ");
  Serial.print(rtc.hour, DEC);
  Serial.print(":");
  Serial.print(rtc.minute, DEC);
  Serial.print(":");
  Serial.print(rtc.second, DEC);
  Serial.println();
  delay(1000); // every second
}
