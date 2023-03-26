
void printAnalogBuffer() {
  Serial.println("---------------");
  for (byte i = 0; i < 16; i++) {
    //Serial.print("let: ");
    //Serial.print(i);
    Serial.print(analogVal[i]);
    //Serial.print(" \ti: ");
    //Serial.print(istantAnalogValue(i));
    Serial.print("\t");
  }
}

void printAnalogSliders() {
  Serial.print("Slid_1:");
  Serial.print(analogVal[ANALOG_PEDAL_VOLUME]);
  Serial.print(",");
  Serial.print("Slid_2:");
  Serial.print(analogVal[ANALOG_UPPER_SUSTAIN]);
  Serial.print(",");
  Serial.print("Slid_3:");
  Serial.print(analogVal[ANALOG_KEYBOARD_BALANCE]);
  Serial.print(",");
  Serial.print("Slid_4:");
  Serial.print(analogVal[ANALOG_PRESET_PERCUSS_VOLUME]);
  Serial.print(",");
  Serial.print("Slid_5:");
  Serial.print(analogVal[ANALOG_VIBRATO_SPEED]);
  Serial.print(",");
  Serial.print("Slid_6:");
  Serial.print(analogVal[ANALOG_REPEAT_SPEED]);
  Serial.print(",");
  Serial.print("Slid_7:");
  Serial.print(analogVal[ANALOG_SYNT_PRESET_VOLUME]);
  //Serial.print(",");
  //Serial.print("knob_1:");
  //Serial.print(analogVal[7]);
  //Serial.print(",");
  //Serial.print("knob_2:");
  //Serial.print(analogVal[11]);
  //Serial.print(",");
  //Serial.print("knob_3:");
  //Serial.print(analogVal[3]);

  Serial.println();
}

void printRAWAalog() {
  for (int i = 0; i < 16; i++) {
    Serial.print(istantAnalogValue(i));
    Serial.print("\t");
  }
  // Serial.print(analogRead(A5));
  // Serial.print("\t");
  Serial.println();
}


void printArray(bool array[], int size) {
  for (int i = 0; i < size; i++) {
    Serial.print(array[i]);
  }
}