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
  //printAnalogBuffer();
  fetchAnalog();
  checkAnalog();
  byte note = getButtonPressed();
}


void printAnalogBuffer() {
  Serial.println("---------------");
  for (byte i = 0; i < 16; i++) {
    //Serial.print("let: ");
    //Serial.print(i);
    Serial.print(analogVal[i]);
    Serial.print(" \ti: ");
    Serial.print(istantAnalogValue(i));
    Serial.print("\t");
  }
}
