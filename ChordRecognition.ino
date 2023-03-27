void checkNewChord() {
  String newChord = getChord(upperKeyboardStatus, UPPER_KEYBOARD_LENGTH, 5);
  if (newChord != chord) {
    if (newChord != "") {
      Serial.println(newChord);
      lcd.setCursor(7, 1);
      lcd.print(newChord);
    } else {
      lcd.setCursor(7, 1);
      lcd.print("       ");
    }
  }
  chord = newChord;
}


void extractKeyboardStatus() {
  for (byte i = 0; i < UPPER_KEYBOARD_LENGTH; i++) {
    upperKeyboardStatus[remappedKeyboard(i + 4)] = keyStatus[i + 4];
  }
}

void printUpperKeyboard() {
  for (byte i = 0; i < UPPER_KEYBOARD_LENGTH; i++) {
    Serial.print(upperKeyboardStatus[i]);
  }
}

String getChord(bool keyArray[], byte keyLength, int startNote) {
  bool shortKeyArray[12];
  String str = "";
  int i = 0;
  while (i < keyLength && !keyArray[i]) { i++; }
  for (byte j = 0; j < 12; j++) { shortKeyArray[j] = keyArray[i + j]; }

  if (i == keyLength) return str;
  // printArray(shortKeyArray, 12);


  switch (noteNumber(shortKeyArray, 12)) {
    case 1:  //simple
      break;
    case 3:
      if (shortKeyArray[4] && shortKeyArray[7]) {
        str += noteName[(i + startNote) % 12];
        str += "  ";
      }
      if (shortKeyArray[3] && shortKeyArray[7]) {
        str += noteName[(i + startNote) % 12];
        str += "m";
        str += " ";
      }
      break;
    case 4:
      if (shortKeyArray[4] && shortKeyArray[7] && shortKeyArray[10]) {
        str += noteName[(i + startNote) % 12];
        str += "7";
        str += " ";
      }
      if (shortKeyArray[3] && shortKeyArray[7] && shortKeyArray[10]) {
        str += noteName[(i + startNote) % 12];
        str += "m";
        str += "7";
      }
      break;
  }



  return str;
}

byte noteNumber(bool array[], byte size) {
  byte num = 0;
  for (byte i = 0; i < size; i++) {
    if (array[i]) num++;
  }
  return num;
}