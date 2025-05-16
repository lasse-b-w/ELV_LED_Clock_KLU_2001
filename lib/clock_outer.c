/*
 * show 1 of the 60 leds of the outer ring
 */
void showOuterRing(int RR) {
 if ( (RR >= 0) && (RR <= 7) ) {            // y12
   setCmd(0x23);
   setElements(dLeds[RR]);
  delay(multiSpeed);
 }
 if ( (RR >= 8) && (RR <= 15) ) {           // y13
   setCmd(0x22);
   setElements(dLeds[RR-8]);
  delay(multiSpeed);
 }
 if ( (RR >= 16) && (RR <= 23) ) {          // y14
   setCmd(0x21);
   setElements(dLeds[RR-16]);
  delay(multiSpeed);
 }
 if ( (RR >= 24) && (RR <= 31) ) {          // y15
   setCmd(0x20);
   setElements(dLeds[RR-24]);
  delay(multiSpeed);
 }
 if ( (RR >= 32) && (RR <= 39) ) {          // y16
   setCmd(0x47);
   setElements(dLeds[RR-32]);
  delay(multiSpeed);
 }
 if ( (RR >= 40) && (RR <= 47) ) {          // y17
   setCmd(0x46);
   setElements(dLeds[RR-40]);
  delay(multiSpeed);
 }
 if ( (RR >= 48) && (RR <= 55) ) {          // y18
   setCmd(0x45);
   setElements(dLeds[RR-48]);
  delay(multiSpeed);
 }
 if ( (RR >= 56) && (RR <= 60) ) {          // y19
   setCmd(0x44);
   setElements(dLeds[RR-56]);
  delay(multiSpeed);
 }
}
