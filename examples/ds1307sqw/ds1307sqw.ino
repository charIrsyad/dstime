/*
  DS1307 SQW Pin

  Set the SQW Pin at DS1307 RTC

  The circuit:
  - Connect VCC to 5v
  - Connect GND to GND
  - Connect SDA to SDA 
  - Connect SCL to SCL 

  created 2022
  by Irsyad

  This example code is in the public domain.
*/

#include <dstime.h>

DSTIME rtc;

void setup() {
  rtc.begin();
  Serial.begin(9600);
  Serial.print("DS1307 SQW Test");
}

void loop() {
  rtc.setDS1307SQW(0); //set the sqw pin to off
  Serial.print("DS1307 OFF");
  delay(1000);
  rtc.setDS1307SQW(1); //set the sqw pin to 1hz
  Serial.print("DS1307 1HZ");
  delay(1000);
  rtc.setDS1307SQW(2); //set the sqw pin to 4khz
  Serial.print("DS1307 4Khz");
  delay(1000);
  rtc.setDS1307SQW(3); //set the sqw pin to 8khz
  Serial.print("DS1307 8Khz");
  delay(1000);
  rtc.setDS1307SQW(4); //set the sqw pin to 32khz
  Serial.print("DS1307 32Khz");
  delay(1000);
}
