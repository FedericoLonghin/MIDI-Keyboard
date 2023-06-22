#include "settings.h"
#include "MIDIUSB.h"

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);




void setup() {
  Serial.begin(115200);
  pinMode(CLK, OUTPUT);
  pinMode(LD, OUTPUT);
  pinMode(OUT, INPUT);
  pinMode(ANALOG_SELECT_0, OUTPUT);
  pinMode(ANALOG_SELECT_1, OUTPUT);
  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  // pinMode(13, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  // Serial.print("d11:");
  // Serial.print(digitalRead(11));
  // Serial.print(",d12:");
  // Serial.print(digitalRead(12));
  // Serial.print(",d13:");
  // Serial.println(digitalRead(13));

  //  printAnalogSliders();
  //printAnalogBuffer();
  // fetchAnalog();
  // checkAnalog();
  extractKeyboardStatus();
  // printRAWAalog();

  // delayMicroseconds(2000);
  getButtonPressed();
  // checkPedal();
  checkEncoder();
  printArray(keyStatus, BINARY_IN_LENGHT);
  Serial.println();
  if (showChords) {
    checkNewChord();
  }

  updateDisplay();
}