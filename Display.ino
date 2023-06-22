void updateDisplay() {
  if (displayShowOnShow || displayShowDuration > 0) {
    if (!displayShowOnShow || displayForceUpdate) {  //first time
      lcd.clear();
      lcd.setCursor(2, 1);
      lcd.print(displayShowText);
      displayShowOnShow = true;
    }
    if (displayShowDuration > 0) displayShowDuration--;
    else {
      displayShowOnShow = false;
      lcd.clear();
      displayForceUpdate = true;
    }
  }
  if (displayForceUpdate && !displayShowOnShow) {
    lcd.setCursor(0, 1);
    lcd.print("Chord:");
    lcd.setCursor(7, 1);
    lcd.print(chord);
    lcd.setCursor(12, 0);
    lcd.print("Tone:");
    lcd.print(shiftTone);
    lcd.print("  ");
    lcd.setCursor(0, 3);
    lcd.print("Velocity: ");
    String intensityBar = "";
    for (byte i = 0; i < pedalVal / 100; i++) {
      intensityBar += "/";
    }
    while (intensityBar.length() < 10) intensityBar += " ";
    lcd.print(intensityBar);
  }

  displayForceUpdate = false;
}

void displayAnimation_register(String name, bool stat, int duration) {
  displayShowText = "Reg: ";
  displayShowText += name;
  displayShowText += ":";
  displayShowText += stat ? "ON" : "OFF";
  displayShowDuration = duration;
  displayForceUpdate = true;
}

void displayAnimation_pressedChord(String name, int duration) {
  displayChordDuration = duration;
}