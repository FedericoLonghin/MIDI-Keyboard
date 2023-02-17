int getButtonPressed() {
  digitalWrite(LD, HIGH);
  delayMicroseconds(t);
  digitalWrite(LD, LOW);
  delayMicroseconds(t);
  digitalWrite(LD, HIGH);

  for (int i = 0; i < KEYBOARD_LENGHT; i++) {

    if (keyStatus[i] != digitalRead(OUT)) {
      if (!keyStatus[i]) {
        noteOn(0, 50 + i, 64);
      } else {
        noteOff(0, 50 + i, 64);
      }
      keyStatus[i] = digitalRead(OUT);
      MidiUSB.flush();
    }
    digitalWrite(CLK, LOW);
    delayMicroseconds(t);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(t);
  }

  return -1;
}

void fetchAnalog() {

  for (byte i = 0; i < 4; i++) {
    digitalWrite(ANALOG_SELECT_0, i / 2);
    digitalWrite(ANALOG_SELECT_1, i % 2);
    delayMicroseconds(tAnalog);

    for (byte j = 0; j < 4; j++) {
      int val;
      switch (j) {
        case 0:
          val = analogRead(A0);
          break;
        case 1:
          val = analogRead(A1);
          break;
        case 2:
          val = analogRead(A2);
          break;
        case 3:
          val = analogRead(A3);
          break;
      }

      //int val = analogRead(A0);
      newAnalogVal[i * 4 + j] = val;
    }
  }
}

int istantAnalogValue(byte add) {
  byte i = add / 4;
  digitalWrite(ANALOG_SELECT_0, i / 2);
  digitalWrite(ANALOG_SELECT_1, i % 2);
  delayMicroseconds(tAnalog);
  switch (add % 4) {
    case 0:
      return analogRead(A0);
      break;
    case 1:
      return analogRead(A1);
      break;
    case 2:
      return analogRead(A2);
      break;
    case 3:
      return analogRead(A3);
      break;
  }
  return 0;
}
