# Arduino-Voltage-Current-Meas
Contains applications of voltage and current measurement with Arduino.
The voltage measurement application reads the voltage through an analog input connected in parallel with resistors R1 and R2. The voltage value is displayed on the Nextion screen.
The current measurement application reads the current through an analog input. The current value is displayed on the Nextion screen.

Programming Language: C/C++ Programming Language

IDE: Arduino IDE Version - 2.2.0

Arduino Used: Arduino Uno

Arduino Library: To use the Nextion screen, include the nextion-master.zip library from the repository in the Arduino IDE.

Arduino Connection Diagram: The Nextion screen is connected to Arduino pins D3 and D4. To measure voltage, Arduino pin A0 is used. To measure current, Arduino pin A1 is used.