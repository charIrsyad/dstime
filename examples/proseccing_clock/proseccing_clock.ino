//Proseccing Clock

//Code for arduino

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
  if (curr - prev >= interval) {

    prev = curr;
    Serial.print(rtc.formattedDate());
    Serial.print(" ");
    Serial.println(rtc.formattedTime());
  }

}

/* The clock for proseccing
   import processing.serial.*;

Serial serial;  // Create object from Serial class

String time;

void setup()
{
   size(1500,400);
   
   serial = new Serial(this, "COM3", 9600);
}

void draw()
{  
 
   while(serial.available() > 0){
     time = serial.readStringUntil(10);
  

     if(time != null){
           
   background(196);
   fill(0,0,255);
   textSize(128);
   text(time,200,200);
   
     }
   }
}

 */
