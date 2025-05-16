/*
 * Shows the middle digits 
 */
void showDigits(byte c1, byte c2, byte c3, byte c4) {
  setElements(c1);
  setCmd(0x17);
 delay(multiSpeed);
  setElements(c2);
  setCmd(0x16);
 delay(multiSpeed);
  setElements(c3);
  setCmd(0x15);
 delay(multiSpeed);
  setElements(c4);
  setCmd(0x14);
 delay(multiSpeed);
}
/*
 * show date
 */
void showDate(int dd, int mm) {
  showDigits(dDigit[dd/10], dDigit[dd%10] | 0x80, dDigit[mm/10], dDigit[mm%10] | 0x80);
}
void showYear(int yy) {
  showDigits(dDigit[(yy%10000)/1000], dDigit[(yy%1000)/100], dDigit[(yy%100)/10], dDigit[yy%10]);
}
