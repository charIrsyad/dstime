/*
  dstest.h header file

  Version: 1.0.0
  (c) 2022 Irsyad
*/

#ifndef DSTIME_H
#define DSTIME_H

#include "Arduino.h"

const long daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int feb[2] = {28,29};

class DSTIME /*The "DSTIME" class*/
{
  public:
   
void readtime(); /*reads the time*/

int second; /*second*/

int minute; /*minute*/

int hour;   /*hour*/

int dayOfWeek;  /*dayOfWeek*/

int dayOfMonth; /*dayOfMonth*/

int month; /*month*/

long year; /*year*/

String formattedDate();

String formattedTime();
  
int checkLeapyear(long yrs);

void setDS1307SQW(int sqw);

void setdatetime(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, long year); /*Sets the time and date on rtc*/

void settime(byte second, byte minute, byte hour); /*Sets the time only*/

void setdatetimestring(String sdate, String stime); /*Sets the time using string*/

int setintalarmOn(byte h, byte m, byte s); /*Sets the alarm in the arduino(internal) to turn on*/

int setintalarmOff(byte h, byte m, byte s); /*Sets the alarm in the arduino(internal) to turn off*/

float getTemp(); /*useless tempature from ds3231 (NOT WORKING)*/

void begin(); /*Begin the rtc*/

void en32K(bool onf); /*enable 32k pin*/

  unsigned long time2long(uint16_t days, uint8_t h, uint8_t m, uint8_t s); /*time to long*/

  uint16_t date2days(uint16_t y, uint8_t m, uint8_t d); /*date to days since 1/1/1970*/

  int doomsday(unsigned long t); /*weekday calc*/

  int monthc(String m); /*check month*/

  private:

  byte decToBcd(byte val); /*Decimal to Binary Coded Decimal*/

  byte bcdToDec(byte val); /*Binary Coded Decimal to Decimal*/

  byte rCB(bool values); /*read control byte of ds3231*/

  void wCB(byte ctrl, bool values); /*Write the control byte*/
};
#endif
