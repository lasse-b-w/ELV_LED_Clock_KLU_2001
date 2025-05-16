/*
 * show 1 of the 60 leds of the inner ring
 */
void showInnerRing(int RR) {
  if ( (RR >= 0) && (RR <= 7) ) {          // y4
   setElements(dLeds[RR]); 
   setCmd(0x13);
  delay(multiSpeed);
 }
 if ( (RR >= 8) && (RR <= 15) ) {          // y5
   setElements(dLeds[RR-8]);
   setCmd(0x12);
  delay(multiSpeed);
 }
 if ( (RR >= 16) && (RR <= 23) ) {          // y6
   setElements(dLeds[RR-16]);
   setCmd(0x11);
  delay(multiSpeed);
 }
 if ( (RR >= 24) && (RR <= 31) ) {          // y7
   setElements(dLeds[RR-24]);
   setCmd(0x10);
  delay(multiSpeed);
 }
 if ( (RR >= 32) && (RR <= 39) ) {          // y8
   setElements(dLeds[RR-32]);
   setCmd(0x27);
  delay(multiSpeed);
 }
 if ( (RR >= 40) && (RR <= 47) ) {          // y9
   setElements(dLeds[RR-40]);
   setCmd(0x26);
  delay(multiSpeed);
 }
 if ( (RR >= 48) && (RR <= 55) ) {          // y10
   setElements(dLeds[RR-48]);
   setCmd(0x25);
  delay(multiSpeed);
 }
 if ( (RR >= 56) && (RR <= 60) ) {          // y11
   setElements(dLeds[RR-56]);
   setCmd(0x24);
  delay(multiSpeed);
 }
}

/*
 * show hours on the inner ring
 */
void setHourRing(int hh, int mm) {
if (hh == 1) {
   if (mm < 15) {
     setElements(dLeds[5] | dLeds[6]); 
     setCmd(0x13);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[7]); 
     setCmd(0x13);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[0]); 
     setCmd(0x12);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[1]); 
     setCmd(0x12);
   }
  delay(multiSpeed);
 }

if (hh == 2) {
   if (mm < 15) {
     setElements(dLeds[2] | dLeds[3]); 
     setCmd(0x12);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[4]); 
     setCmd(0x12);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[5]); 
     setCmd(0x12);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[6]); 
     setCmd(0x12);
   }
  delay(multiSpeed);
 }

if (hh == 3) {
   if (mm < 15) {
     setElements(dLeds[7]); 
     setCmd(0x12);
     setElements(dLeds[0]); 
     setCmd(0x11);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[1]); 
     setCmd(0x11);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[2]); 
     setCmd(0x11);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[3]); 
     setCmd(0x11);
   }
   if (mm < 15) {
     setElements(dLeds[7]); 
     setCmd(0x12);
   }
  delay(multiSpeed);
 }

if (hh == 4) {
   if (mm < 15) {
     setElements(dLeds[4] | dLeds[5]); 
     setCmd(0x11);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[6]); 
     setCmd(0x11);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[7]); 
     setCmd(0x11);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[0]); 
     setCmd(0x10);
   }
  delay(multiSpeed);
 }

if (hh == 5) {
   if (mm < 15) {
     setElements(dLeds[1] | dLeds[2]); 
     setCmd(0x10);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[3]); 
     setCmd(0x10);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[4]); 
     setCmd(0x10);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[5]); 
     setCmd(0x10);
   }
  delay(multiSpeed);
 }

if (hh == 6) {
   if (mm < 15) {
     setElements(dLeds[6] | dLeds[7]); 
     setCmd(0x10);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[0]); 
     setCmd(0x27);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[1]); 
     setCmd(0x27);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[2]); 
     setCmd(0x27);
   }
  delay(multiSpeed);
 }

if (hh == 7) {
   if (mm < 15) {
     setElements(dLeds[3] | dLeds[4]); 
     setCmd(0x27);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[5]); 
     setCmd(0x27);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[6]); 
     setCmd(0x27);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[7]); 
     setCmd(0x27);
   }
  delay(multiSpeed);
 }

if (hh == 8) {
   if (mm < 15) {
     setElements(dLeds[0] | dLeds[1]); 
     setCmd(0x26);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[2]); 
     setCmd(0x26);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[3]); 
     setCmd(0x26);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[4]); 
     setCmd(0x26);
   }
  delay(multiSpeed);
 }

if (hh == 9) {
   if (mm < 15) {
     setElements(dLeds[5] | dLeds[6]); 
     setCmd(0x26);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[7]); 
     setCmd(0x26);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[0]); 
     setCmd(0x25);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[1]); 
     setCmd(0x25);
   }
  delay(multiSpeed);
 }

if (hh == 10) {
   if (mm < 15) {
     setElements(dLeds[2] | dLeds[3]); 
     setCmd(0x25);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[4]); 
     setCmd(0x25);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[5]); 
     setCmd(0x25);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[6]); 
     setCmd(0x25);
   }
  delay(multiSpeed);
 }

if (hh == 11) {
   if (mm < 15) {
     setElements(dLeds[7]); 
     setCmd(0x25);
     setElements(dLeds[0]); 
     setCmd(0x24);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[1]); 
     setCmd(0x24);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[2]); 
     setCmd(0x24);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[3]); 
     setCmd(0x24);
   }
   if (mm < 15) {
     setElements(dLeds[7]); 
     setCmd(0x25);
     setElements(dLeds[0]); 
     setCmd(0x24);
   }
  delay(multiSpeed);
 }

 if (hh == 12) {
   if (mm < 15) {
     setElements(dLeds[0] | dLeds[1]); 
     setCmd(0x13);
   }
   if ((mm >= 15) & (mm < 30)) {
     setElements(dLeds[2]); 
     setCmd(0x13);
   }
   if ((mm >= 30) & (mm < 45)) {
     setElements(dLeds[3]); 
     setCmd(0x13);
   }
   if ((mm >= 45) & (mm < 60)) {
     setElements(dLeds[4]); 
     setCmd(0x13);
   }
  delay(multiSpeed);
 }

}
