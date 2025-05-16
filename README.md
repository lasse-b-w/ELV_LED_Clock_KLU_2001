# ELV LED Clock  "KLU 2001"

Re-building this wonderful led-clock. \
Someday it stopped working and i found out, that the mikrocontroller had an issue. \
So, i devided to give this beauty a new life :-) 

Quick and dirty. For some further questions you can email me.

Stay tuned...

[Kreis-LED-Uhr.pdf](https://github.com/user-attachments/files/20258449/Kreis-LED-Uhr.pdf)

Arduino Nano Clone v3.0 for basic stuff and multiplexing the leds.\
ESP8266-01 with AT-Firmware (2018) for updating via NTP-Server.

Implemented:
- changing display for date (year and day+month)\
- double-led for full hours\
- udpating via NTP-Server\
- auto update at 8:27 am and pm\
- power down ESP8266 via CH_PD pin

Front:  
![IMG_1337](https://github.com/user-attachments/assets/6c58cd1e-52a3-48fd-a524-0390be4d8d39)
Backside (with ULN2803 for driving LEDs and Arduino):
![IMG_1338](https://github.com/user-attachments/assets/4115926b-7b51-419c-8cb3-2af19db7487a)
Backside with hotglue to fix connections:
![IMG_1339](https://github.com/user-attachments/assets/a4be771d-f1f2-4b4b-9a37-6ab948207495)
Side-view with plugable ESP8266:
![IMG_1342](https://github.com/user-attachments/assets/e987ec36-ede5-4306-b3e0-9c52d8d4892f)

