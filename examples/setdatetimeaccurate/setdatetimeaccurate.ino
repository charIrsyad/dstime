#include "dstime.h"



int ss;
int mm;
int hh;
int dw;
int dm;
int md;
int yy;


long prev;
long interval = 1000;

String datetime;
DSTIME rtc;

void setup() {
  rtc.begin();
  Serial.begin(9600);
}

void loop() {
 
  unsigned long curr = millis();
  rtc.readtime();

  if(Serial.available() > 0){

    datetime = Serial.readString();
 

    String dmm = datetime.substring(0,2);
    String mmm = datetime.substring(2,4);
    String yyy = datetime.substring(4,6);

    String hhh = datetime.substring(6,8);
    String mms = datetime.substring(8,10);
    String sss = datetime.substring(10,12);



    String www = datetime.substring(13,15); 
    // How to set date time:
    //ddmmyyhhmmssww
    ss = sss.toInt();
    mm = mms.toInt();
    hh = hhh.toInt();

    dw = www.toInt();

    dm = dmm.toInt();
    md = mmm.toInt();
    yy = yyy.toInt();

    //for debugging:
//    Serial.print("SS:");
//    Serial.print(ss);
//    Serial.print(" MM:");
//    Serial.print(mm);
//    Serial.print(" HH:");
//    Serial.print(hh);
//
//    Serial.print(" WW:");
//    Serial.print(dw);
//    
//    Serial.print(" DM:");
//    Serial.print(dm);
//    Serial.print(" MN:");
//    Serial.print(md);
//    Serial.print(" YY:");
//    Serial.print(yy);
    rtc.setdatetime(ss,mm,hh,dw,dm,md,yy);
  }


  if (curr - prev >= interval) {

    prev = curr;
    Serial.println(rtc.formattedDate());
    Serial.println(rtc.formattedTime());
  }

}
