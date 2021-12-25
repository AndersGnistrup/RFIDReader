Project objective:
Make a RFID reader using the STM32 SPI interface to a RFID-RC522 and communicate using CAN to an external
control unit.

Design decisions.
The RFID-RC522 is part of the arduino modules but it is basicly just a brakeout board to a RF522 CHIP.
The RC522 is supported on Linux (Beagle Bone Black and other) and is cheap. So it is a good candidate.
The STM32 is selected since I am not a big fan of the Arduino operating system since it is poll/busy wait
based and AFIK not that stable. It is possible to use the AVR-studio instead but I like the STM32m since
It is a ARM based device and that makes it possible to use a standard ARM gcc compiler (no avrlib etc).

CAN is chosen since it is a rock solid interface. On top of this CANOpen is used as a protocol layer, and
the implementation wil be based on CANfestival, ttps://canfestival.org/

License: GPLv2

Code from https://github.com/Hamid-R-Tanhaei/RFID-MIFARE-RC522-ARM-STM32.git is reused in this project.
It is only the RC522 code that has been used.