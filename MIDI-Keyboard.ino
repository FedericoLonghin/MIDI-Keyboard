#include "settings.h"
#include "MIDIUSB.h"





void setup() {
  Serial.begin(115200);
  pinMode(CLK, OUTPUT);
  pinMode(LD, OUTPUT);
  pinMode(OUT, INPUT);
  pinMode(ANALOG_SELECT_0, OUTPUT);
  pinMode(ANALOG_SELECT_1, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  //  printAnalogSliders();
  //printAnalogBuffer();
  // fetchAnalog();
  // checkAnalog();
  getButtonPressed();
  checkPedal();
  // printRAWAalog();

  digitalWrite(13, 1);
  delayMicroseconds(2000);
  digitalWrite(13, 0);
}