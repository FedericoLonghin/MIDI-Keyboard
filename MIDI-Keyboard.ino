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
  pinMode(13, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print("Chord:");
}

void loop() {
  Serial.println("aaa");
  //  printAnalogSliders();
  //printAnalogBuffer();
  // fetchAnalog();
  // checkAnalog();
  getButtonPressed();
  checkPedal();
  // printRAWAalog();

  // digitalWrite(13, 1);
  // delayMicroseconds(2000);
  // digitalWrite(13, 0);

  extractKeyboardStatus();
  // printUpperKeyboard();

  checkNewChord();
}