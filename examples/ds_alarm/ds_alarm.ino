/*
  DSalarm

  Make an alarm for DS1307 or DS3231

  The DS3231 has a EEPROM for storing alarms but
  this is for how to make an alarm for DS1307 or DS3231
  RTC

  maked 12 November 2022
  by Irsyad

  This example code is in the public domain.
*/

#include <dstime.h>

DSTIME rtc;

unsigned long previousMillis = 0; 
const long interval = 1000; 

const int led = 13;

void setup()
{
  rtc.begin(); //begin the rtc
  Serial.begin(9600);
  // set the initial time here: ONLY DO THIS ONCE!
  // second, minute, hour, day of week, day of month, month, year
  // rtc.setdatetime(00,42,19,5,2,12,22);
  // here to set time only
  // second minute hour
  // rtc.settime(00,41,19);
  pinMode(led,OUTPUT);
  
}

void loop()
{
  rtc.readtime();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
  previousMillis = currentMillis;
  
  if(rtc.setinalarmOn(1,2,3) == 1){ //hh:mm:ss
     digitalWrite(led, 1);
  }
  
  if(rtc.setinalarmOff(1,3,4) == 1){
     digitalWrite(led, 0);
  } 
    
  Serial.print(rtc.year, DEC);
  Serial.print("/");
  Serial.print(rtc.month, DEC);
  Serial.print("/");
  Serial.print(rtc.dayOfMonth, DEC);
  Serial.print(" (");
  Serial.print(rtc.dayOfWeek);
  Serial.print(") ");
  Serial.print(rtc.hour, DEC);
  Serial.print(":");
  Serial.print(rtc.minute, DEC);
  Serial.print(":");
  Serial.print(rtc.second, DEC);
  Serial.println();
  delay(1000); // every second
 }
}
