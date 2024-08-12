#include <SoftwareSerial.h>
#include <Nextion.h>

SoftwareSerial software_serial(4, 3);
Nextion nextion(software_serial, 9600);

const int analog_input = A1;
int mv_per_amp = 185;
int raw_value = 0;
int ac_soff_set = 1650;
double voltage = 0;
double amps = 0;

void setup() 
{
  pinMode(analog_input, INPUT);
  analogReference(EXTERNAL);
  
  Serial.begin(9600);
  nextion.init();
}

void loop() 
{
  raw_value = analogRead(analog_input);
  voltage = (raw_value / 1024.0) * 3300;
  amps = ((voltage - ac_soff_set) / mv_per_amp);

  Serial.print("Current = ");
  Serial.println(amps, 3);
  nextion.setComponentText("t0", String(amps));
  nextion.setComponentText("t1", String(amps));
  delay(1000);
}