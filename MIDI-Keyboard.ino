#include "settings.h"
#include "MIDIUSB.h"





void setup() {
  Serial.begin(115200);
  pinMode(CLK, OUTPUT);
  pinMode(LD, OUTPUT);
  pinMode(OUT, INPUT);
  pinMode(ANALOG_SELECT_0, OUTPUT);
}

void loop() {
  pinMode(ANALOG_SELECT_1, OUTPUT);
  // printAnalogSliders();
  printAnalogBuffer();
  fetchAnalog();
  checkAnalog();
  byte note = getButtonPressed();
}
