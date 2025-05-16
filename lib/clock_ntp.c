SoftwareSerial mySerial(pinRX, pinTX); // RX, TX

void powerESP(int po) {
  digitalWrite(pinPowerESP, po);
}

void initESP() {
  pinMode(pinPowerESP, OUTPUT);
  powerESP(0);
  delay(10);
  // Power Up ESP via BD136
  powerESP(1);
  delay(2000);
  String cmd="AT+CWQAP";
  mySerial.println(cmd);
  while ( !mySerial.find((char*)"OK") ); 
  Serial.println("ESP8266 initialized!");
}

void shutDnESP() {
  String cmd="AT+CWQAP";
  mySerial.println(cmd);
  while ( !mySerial.find((char*)"OK") ); 
  Serial.println("ESP8266 shut down!");
  powerESP(0);
}

void connectESP() {
  // SSID and Password set up connection to AP
  Serial.println("Connect to AP...");
  String cmd="AT+CWJAP=\"";
  cmd+=ssid;
  cmd+="\",\"";
  cmd+=password;
  cmd+="\"";
  mySerial.println(cmd);
  while ( !mySerial.find((char*)"OK") ); 
  Serial.println("AP connected!");
  // NTP Server
  Serial.println("Setting up NTP Server...");
  cmd="AT+CIPSNTPCFG=1,1,\"192.53.103.108\"";
  mySerial.println(cmd);
  while ( !mySerial.find((char*)"OK") );
  Serial.println("Set up!");
}

void getNTPTime() {
  Serial.println("Getting Time from Server...");
  String cmd="AT+CIPSNTPTIME?";
  mySerial.println(cmd);

  String inComing   = mySerial.readString();
  String NTime      = inComing.substring(32);
  String NcorrTime  = NTime.substring(4,24);
  String Nmonth     = NcorrTime.substring(0, 3);
  String Nday       = NcorrTime.substring(6, 4);
  String Nhour      = NcorrTime.substring(9, 7);
  String Nminute    = NcorrTime.substring(12, 10);
  String Nsecond    = NcorrTime.substring(15, 13);
  String Nyear      = NcorrTime.substring(20, 16);
 
  Serial.println( NcorrTime );
  int monthInt = 1;
  int hourInt = Nhour.toInt();

  if (Nmonth == "Dec") monthInt = 12;
  if (Nmonth == "Nov") monthInt = 11;
  if (Nmonth == "Oct") monthInt = 10;
  if (Nmonth == "Sep") monthInt = 9;
  if (Nmonth == "Aug") monthInt = 8;
  if (Nmonth == "Jul") monthInt = 7;
  if (Nmonth == "Jun") monthInt = 6;
  if (Nmonth == "May") monthInt = 5;
  if (Nmonth == "Apr") monthInt = 4;
  if (Nmonth == "Mar") monthInt = 3;
  if (Nmonth == "Feb") monthInt = 2;
  if (Nmonth == "Jan") monthInt = 1;

  if (hourInt > 12) {
    hourInt = hourInt - 12;
  }

  setTime(hourInt+1, Nminute.toInt(), Nsecond.toInt(), Nday.toInt(), monthInt, Nyear.toInt());
  clockON = 1;
}

void upDateNTP() {
  initESP();
  connectESP();
  getNTPTime();
  shutDnESP();
}
