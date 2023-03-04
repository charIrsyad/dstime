#include "dstime.h"
#include "Wire.h"

//PRIVATE:

byte DSTIME::decToBcd(byte val) 
{
  return ( (val / 10 * 16) + (val % 10) );
}

byte DSTIME::bcdToDec(byte val)
{
  return ( (val / 16 * 10) + (val % 16) );
}

byte DSTIME::rCB(bool values) { //Read control byte
  Wire.beginTransmission(0x68);
  if (values) {
    
    Wire.write(0x0f);
  } else {
    
    Wire.write(0x0e);
  }
  Wire.endTransmission();
  Wire.requestFrom(0x68, 1);
  return Wire.read();
}

void DSTIME::wCB(byte control, bool values) { //Write control byte
  Wire.beginTransmission(0x68);
  if (values) {
    Wire.write(0x0f);
  } else {
    Wire.write(0x0e);
  }
  Wire.write(control);
  Wire.endTransmission();
}

uint16_t DSTIME::date2days(uint16_t y, uint8_t m, uint8_t d) {
    if (y >= 2000)
        y -= 2000;
    uint16_t days = d;
    for (uint8_t i = 1; i < m; i++)
        days += daysInMonth[i - 1];
    if (m > 2 && y % 4 == 0)
        days++;
    return days + 365 * y + (y + 3) / 4 - 1;
}

unsigned long DSTIME::time2long(uint16_t days, uint8_t h, uint8_t m, uint8_t s) {
    return ((days * 24L + h) * 60 + m) * 60 + s;
}

int DSTIME::doomsday (unsigned long t) {
   
  return ((t / 86400) + 4) % 7;
}

int DSTIME::monthc(String m){
  if(m == "Jan"){
    return 1;
    
  } else if(m == "Feb"){
    return 2;
    
  } else if(m == "Mar"){
    return 3;
    
  } else if(m == "Apr"){
    return 4;
    
  } else if(m == "May"){
    return 5;
    
  } else if(m == "Jun"){
    return 6;
    
  } else if(m == "Jul"){
    return 7;
    
  } else if(m == "Aug"){
    return 8;
    
  } else if(m == "Sep"){
    return 9;
    
  } else if(m == "Oct"){
    return 10;
    
  } else if(m == "Nov"){
    return 11;
    
  } else if(m == "Dec"){
    return 12;
    
  } 
}


//PUBLIC:

int DSTIME::checkLeapyear(long yrs) 
{                                   //check the leap year for > 2099
  
long  yr1 = yrs % 4;
long  yr2 = yrs % 100;
long  yr3 = yrs % 400;
  
    if(yr1 != 1){
    return 1;
    
  } else if(yr2 != 1){
    return 1;
    
  } else if(yr3 != 1){
    return 1;
    
  } else {
    return 0;
  }
 
}

int DSTIME::setintalarmOn(byte h, byte m, byte s){

    if (DSTIME::hour == h && DSTIME::minute == m && DSTIME::second == s) { //turn on
      return 1;
    } else {
      return 0;
    }
}

int DSTIME::setintalarmOff(byte h, byte m, byte s){

    if (DSTIME::hour == h && DSTIME::minute == m && DSTIME::second == s) { //turn off 
      return 1;
    } else {
      return 0;
    }
}

void DSTIME::readtime() //function to read the time
{
  Wire.beginTransmission(0x68); //begins the transmisson
  Wire.write(0); // set DS register pointer to 00h
  Wire.endTransmission(); //ends the transmisson
  // request seven bytes of data from DS starting from register 00h
  Wire.requestFrom(0x68, 7);
  second = bcdToDec(Wire.read() & 0x7f);
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read() & 0x3f);
  dayOfWeek = bcdToDec(Wire.read());
  dayOfMonth = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  
  //check year first
  long pyr = 2000; //might update next melenium/century
  long yr = bcdToDec(Wire.read());

  
  year = pyr + yr;

}

String DSTIME::formattedDate(){
   char ts[20];
   sprintf(ts, "%02d/%02d/%04d", DSTIME::dayOfMonth, DSTIME::month, DSTIME::year);
   return String(ts);
}

String DSTIME::formattedTime(){
   char ts[10];
   sprintf(ts, "%02d:%02d:%02d", DSTIME::hour, DSTIME::minute, DSTIME::second);
   return String(ts);
}

float DSTIME::getTemp(){

}
void DSTIME::setdatetime(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, long year) //function to set the time and date
{
  Wire.beginTransmission(0x68); //begins the transmisson
  Wire.write(0); // set next input to start at the seconds register
  if(second >= 60){
      second = 0;
  }

  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}

void DSTIME::settime(byte second, byte minute, byte hour) //function to set the time only
{
  Wire.beginTransmission(0x68); //begins transmisson
  Wire.write(0); // set next input to start at the seconds register
  if(second >= 60){
      second = 0;
  }

  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.endTransmission();
}

void DSTIME::setDS1307SQW(int sqw)
{

if(sqw == 0) {
  Wire.beginTransmission(0x68);
  Wire.write(0x07);
  Wire.write(0x00);
  Wire.endTransmission();

} else if(sqw == 1){
  Wire.beginTransmission(0x68);
  Wire.write(0x07);
  Wire.write(0x10);
  Wire.endTransmission();

} else if(sqw == 2){
  Wire.beginTransmission(0x68);
  Wire.write(0x07);
  Wire.write(0x11);
  Wire.endTransmission();

} else if(sqw == 3){
  Wire.beginTransmission(0x68);
  Wire.write(0x07);
  Wire.write(0x12);
  Wire.endTransmission();

} else if(sqw == 4){
  Wire.beginTransmission(0x68);
  Wire.write(0x07);
  Wire.write(0x13);
  Wire.endTransmission();

 }

}

void DSTIME::setdatetimestring(String sdate, String stime){

  //00:43:00
  //Dec 02 2023
  
  int hh = stime.substring(0,2).toInt();
  int mm = stime.substring(3,5).toInt();
  int ss = stime.substring(6,8).toInt();

  
  int dd = sdate.substring(4,6).toInt();
  int mn = monthc(sdate.substring(0,3));
  int yy = sdate.substring(7,11).toInt() - 2000;

  unsigned long unix = DSTIME::time2long(date2days(yy,mn,dd), hh,mm,ss);
  int wk = DSTIME::doomsday(unix+946684800);

  DSTIME::setdatetime(ss,mm,hh,wk,dd,mn,yy);
}

void DSTIME::en32K(bool onf) {
  // turn 32kHz pin on or off
  byte temp_buffer = rCB(1);
  if (onf) {
    // turn on 32kHz pin
    temp_buffer = temp_buffer | 0b00001000;
  } else {
    // turn off 32kHz pin
    temp_buffer = temp_buffer & 0b11110111;
  }
  wCB(temp_buffer, 1);
}

void DSTIME::begin(){ //function to initailize the Wire library
  Wire.begin();
}
