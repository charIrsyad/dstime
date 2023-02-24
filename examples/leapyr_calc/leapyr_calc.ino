/*
  RTC check leap year

  Check the leap year for > 2099

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

void setup()
{
  rtc.begin();//begin the rtc
  Serial.begin(9600);
  delay(200);
  rtc.readtime();
  long yr = rtc.year();
  int leapyear = rtc.checkLeapyear(yr);
  if(leapyear == 1){
    Serial.println("Its a Leap Year");
  } else {
    Serial.println("Its not a Leap Year");
  }
  
}

void loop()
{
   
}
