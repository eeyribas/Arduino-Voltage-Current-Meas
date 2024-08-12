#include <SoftwareSerial.h>
#include <Nextion.h>

SoftwareSerial software_serial(4, 3);
Nextion nextion(software_serial, 9600);

int analog_input = 0;
float tmp_v_out = 0.0;
float v_out = 0.0;
float v_in = 0.0;
float r_1 = 15000.0;
float r_2 = 1000.0;
int value = 0;

void setup() 
{
  pinMode(analog_input, INPUT);
  analogReference(EXTERNAL);
  
  Serial.begin(9600);
  nextion.init();
}

void loop() 
{
  value = analogRead(analog_input);
  tmp_v_out = (value * 0.76) / 1024.0;
  v_out = tmp_v_out * 1000;
  v_in = v_out / (r_2 / (r_1 + r_2));
  if (v_in < 0.09)
    v_in = 0.0;

  Serial.println(v_in);
  nextion.setComponentText("t0", String(v_in));
  nextion.setComponentText("t1", String(v_in));
  delay(1000);
}