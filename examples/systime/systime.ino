#include <dstime.h>

DSTIME rtc; //class of rtc 

void setup()
{
  rtc.begin();//begin the rtc
  Serial.begin(9600);
  rtc.setdatetimestring(String(__DATE__), String(__TIME__));
  //rtc.setdatetimestring("02 Dec 2010", "00:00:00");
  
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
