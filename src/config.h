/*
 * Pin-Register
 */
#define pinA          14
#define pinB          15
#define pinC          16
#define icD5          17    //  (green)
#define icD4          18    //  (orange)
#define icD3          19    //  (white)

#define pinSegA       2
#define pinSegB       3
#define pinSegC       4
#define pinSegD       5
#define pinSegE       6
#define pinSegF       7
#define pinSegG       8
#define pinSegH       9

#define pinTX         11    //  (yellow)
#define pinRX         10    //  (gren)

#define pinPowerESP   12    //  (blue)
/*
 * define the ssid and password for WLAN
 */
#define ssid         ""
#define password     ""
#define deviceName   "LEDClock"
/*
 * Variables
 * 
 *          - multiSpeed:       sets the delay for multiplexing (e.g. 2 for best results)
 *          - dDgits:           contains numbers for the middle display
 *          - dLeds:            contains Leds for using with decimalvalues
 */
int multiSpeed = 2; 
const byte dDigit[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
const byte dLeds[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
int clockON         = 0;        // 0 = clock off, 1 = clock on
int updTimer        = 200;      // shows Upd on display
int dateCounter     = 500;      // duration of date on display
int dC              = 0;        // dateCounter
int upd             = 1;        // ready for one update?
/*
 * Choose the IC (BCD 74LS145) and sets the command and the right register
 */
void setCmd(byte cmds) {
  if (cmds & 0x01) digitalWrite(pinA, 0); else digitalWrite(pinA, 1);   // A
  if (cmds & 0x02) digitalWrite(pinB, 0); else digitalWrite(pinB, 1);   // B
  if (cmds & 0x04) digitalWrite(pinC, 0); else digitalWrite(pinC, 1);   // C 
  if (cmds & 0x10) digitalWrite(icD3, 0); else digitalWrite(icD3, 1);   // IC 3  7-digit + 1. hours
  if (cmds & 0x20) digitalWrite(icD5, 0); else digitalWrite(icD5, 1);   // IC 5  2. hour + 1. minute
  if (cmds & 0x40) digitalWrite(icD4, 0); else digitalWrite(icD4, 1);   // IC 4  2. minute + grid  
}
/*
 * Sets the elements of the clock
 */
void setElements(byte elements) {
  if (elements & 0x01) digitalWrite(pinSegA, 1); else digitalWrite(pinSegA, 0);
  if (elements & 0x02) digitalWrite(pinSegB, 1); else digitalWrite(pinSegB, 0);
  if (elements & 0x04) digitalWrite(pinSegC, 1); else digitalWrite(pinSegC, 0);
  if (elements & 0x08) digitalWrite(pinSegD, 1); else digitalWrite(pinSegD, 0);
  if (elements & 0x10) digitalWrite(pinSegE, 1); else digitalWrite(pinSegE, 0);
  if (elements & 0x20) digitalWrite(pinSegF, 1); else digitalWrite(pinSegF, 0);
  if (elements & 0x40) digitalWrite(pinSegG, 1); else digitalWrite(pinSegG, 0);
  if (elements & 0x80) digitalWrite(pinSegH, 1); else digitalWrite(pinSegH, 0);
}
/*
 * inits the clock and turns off all leds
 */
void initClk() {
  pinMode(pinSegA, OUTPUT);
  pinMode(pinSegB, OUTPUT);
  pinMode(pinSegC, OUTPUT);
  pinMode(pinSegD, OUTPUT);
  pinMode(pinSegE, OUTPUT);
  pinMode(pinSegF, OUTPUT);
  pinMode(pinSegG, OUTPUT);
  pinMode(pinSegH, OUTPUT);
  
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);

  pinMode(icD3, OUTPUT);
  pinMode(icD5, OUTPUT);
  pinMode(icD4, OUTPUT);
  
  setCmd(0x07);
}
