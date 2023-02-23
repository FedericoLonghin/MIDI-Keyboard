
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
  //Serial.print("Slid_1:");
  //Serial.print(analogVal[0]);
  //Serial.print(",");
  //Serial.print("Slid_2:");
  //Serial.print(analogVal[8]);
  //Serial.print(",");
  Serial.print("Slid_3:");
  Serial.print(analogVal[ANALOG_BASS_VOLUME]);
  Serial.print(",");
  Serial.print("Slid_4:");
  Serial.print(analogVal[ANALOG_CHORD_VOLUME]);
  Serial.print(",");
  Serial.print("Slid_5:");
  Serial.print(analogVal[ANALOG_MULTI_P_VOLUME]);
  Serial.print(",");
  Serial.print("Slid_6:");
  Serial.print(analogVal[ANALOG_RHYTHM_VOLUME]);
  Serial.print(",");
  Serial.print("Slid_7:");
  Serial.print(analogVal[ANALOG_TEMPO]);
  Serial.print(",");
  Serial.print("RAW:");
  Serial.print(analogRead(A5));
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
