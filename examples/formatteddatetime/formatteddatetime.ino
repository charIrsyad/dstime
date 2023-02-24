#include <dstime.h>

DSTIME rtc; //class of rtc 

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
  Serial.println(rtc.formattedDate());
  Serial.println(rtc.formattedTime());
  delay(1000); // every second
}
