#include <dstime.h>

DSTIME rtc;

void setup() {
  rtc.begin();
  Serial.begin(9600);
  Serial.println("DS3231 32k test");
}

void loop() {
  rtc.en32K(1);
  Serial.println("Turn ON 32K");
  delay(1000);
  rtc.en32K(0);
  Serial.println("Turn OFF 32K");
  delay(1000);
}
