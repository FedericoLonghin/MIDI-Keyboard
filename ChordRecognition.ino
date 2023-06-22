void checkNewChord() {
  String newChord = getChord(lowerKeyboardStatus, LOWER_KEYBOARD_LENGTH, 5);
  if (newChord != chord) {

    Serial.println(newChord);
    displayForceUpdate = true;
  }
  chord = newChord;
}


void extractKeyboardStatus() {  //deprecated
  for (byte i = 0; i < UPPER_KEYBOARD_LENGTH; i++) {
    upperKeyboardStatus[remappedIO(i + 4)] = keyStatus[i + 4];
    lowerKeyboardStatus[remappedIO(i + 52)] = keyStatus[i + 52];
  }
}



String getChord(bool keyArray[], byte keyLength, int startNote) {
  bool shortKeyArray[12];
  String str = "       ";
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
        str = noteName[(i + startNote) % 12];
        str += "  ";
      } else if (shortKeyArray[3] && shortKeyArray[7]) {
        str = noteName[(i + startNote) % 12];
        str += "m";
        str += " ";
      } else if (shortKeyArray[3] && shortKeyArray[8]) {
        str = noteName[(i + startNote + 8) % 12];
        str += "/";
        str += noteName[(i + startNote) % 12];
        str += " ";
      } else if (shortKeyArray[5] && shortKeyArray[9]) {
        str = noteName[(i + startNote + 5) % 12];
        str += "/";
        str += noteName[(i + startNote) % 12];
        str += " ";
      } else if (shortKeyArray[5] && shortKeyArray[8]) {
        str = noteName[(i + startNote + 5) % 12];
        str += "m/";
        str += noteName[(i + startNote) % 12];
        str += " ";
      } else if (shortKeyArray[3] && shortKeyArray[9]) {
        str = noteName[(i + startNote + 3) % 12];
        str += "m/";
        str += noteName[(i + startNote) % 12];
        str += " ";
      }
      break;
    case 4:
      if (shortKeyArray[4] && shortKeyArray[7] && shortKeyArray[10]) {
        str = noteName[(i + startNote) % 12];
        str += "7";
        str += " ";
      } else if (shortKeyArray[3] && shortKeyArray[7] && shortKeyArray[10]) {
        str = noteName[(i + startNote) % 12];
        str += "m";
        str += "7";
      }

      break;
  }



  return str;
}

byte noteNumber(bool array[], byte size) {  //return how many key is pressed
  byte num = 0;
  for (byte i = 0; i < size; i++) {
    if (array[i]) num++;
  }
  return num;
}