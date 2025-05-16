/*
 * Kreis-LED-UHR KLU2001 ELV
 * 
 * Modified: decemeber 2021 by Lasse B.
 *  
 * Arduino Nano Clone v3.0 for basic stuff and multiplexing the leds
 * ESP8266-01 with AT-Firmware (2018) for updating via NTP-Server
 * 
 * Implemented:     - changing display for date (year and day+month)
 *                  - double-led for full hours
 *                  - udpating via NTP-Server
 *                  - auto update at 8:27 am and pm 
 *                  - power down ESP8266 via CH_PD pin
 *                  
 * 
 * Ideas:           - DND mode switch
 *                  - 
 * 
 */
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "TimeLib.h"

#include "config.h"
#include "clock_digits.h"
#include "clock_grid.h"
#include "clock_inner.h"
#include "clock_outer.h"
#include "clock_ntp.h"


void showTime(int hh, int mm, int ss) {
  if (hh > 12) { hh = hh - 12; }
  setHourRing(hh, mm);
  showOuterRing(mm);
  showOuterRing(ss);
}

void setup() {
  Serial.begin(115200);
  Serial.println("*********************     LED Clock v1.0 Booting    **********************");
  mySerial.begin(9600);
  delay(200);
  upDateNTP();
  initClk();
}

void loop() {
  while (updTimer > 0) {
    showDigits(0x3E, 0x73, 0x5E, 0x00);
    updTimer--;
  }
  if (clockON == 1) {
    showGrid();
    showTime(hour(),minute(),second());
    if (dC <= (dateCounter/2)) showDate(day(),month()); 
    if (dC > (dateCounter/2))  showYear(year()); 
    dC++; if (dC > dateCounter) dC = 0;
  }
  // ******************************************************************  Update **************************************
  if ( (hour() == 12) & (minute() == 1) & (upd == 1) ) {
    setElements(0x00);
    setCmd(0x07);
    Serial.println("*********************       Auto Update        *************************");
    updTimer = 200;
    upDateNTP();
    upd = 0;
  }
  if ( (hour() == 12) & (minute() == 2 ) ) upd = 1;
}
