void getButtonPressed() {
  digitalWrite(LD, HIGH);
  delayMicroseconds(t);
  digitalWrite(LD, LOW);
  delayMicroseconds(t);
  digitalWrite(LD, HIGH);
  for (int i = 0; i < BINARY_IN_LENGHT; i++) {

    //UPPER KEYBOARD
    // if (i >= 0 && i < UPPER_KEYBOARD_LENGTH) {
    //   lowerKeyboardStatus[remappedIO(i)] = keyStatus[i];
    // }



    // //LOWER KEYBOARD
    // else if (i >= 52 && i < UPPER_KEYBOARD_LENGTH + 52) {
    //   //lowerKeyboardStatus[remappedIO(i)] = keyStatus[i];
    // }

    // //PEDAL KEYBORARD
    // else if (i >= 52 && i < PEDAL_KEYBOARD_LENGTH +0 ) {
    //   //lowerKeyboardStatus[remappedIO(i)] = keyStatus[i];
    // }
    // //OTHER


    if (keyStatus[i] != digitalRead(OUT)) {
      toggleAction(i, digitalRead(OUT));

      keyStatus[i] = digitalRead(OUT);
    }
    digitalWrite(CLK, LOW);
    // delayMicroseconds(t);
    digitalWrite(CLK, HIGH);
    // delayMicroseconds(t);
  }
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
          val = analogRead(ANALOG_IN_0);
          break;
        case 1:
          val = analogRead(ANALOG_IN_1);
          break;
        case 2:
          val = analogRead(ANALOG_IN_2);
          break;
        case 3:
          val = analogRead(ANALOG_IN_3);
          break;
      }

      //int val = analogRead(A0);
      newAnalogVal[i * 4 + j] = val;
    }
  }
}

int istantAnalogValue(byte add) {
  byte i = add / 4;
  // digitalWrite(ANALOG_SELECT_0, 0);
  // digitalWrite(ANALOG_SELECT_1, 1);
  digitalWrite(ANALOG_SELECT_0, i / 2);
  digitalWrite(ANALOG_SELECT_1, i % 2);
  delayMicroseconds(tAnalog);
  switch (add % 4) {
    case 0:
      return analogRead(ANALOG_IN_0);
      break;
    case 1:
      return analogRead(ANALOG_IN_1);
      break;
    case 2:
      return analogRead(ANALOG_IN_2);
      break;
    case 3:
      return analogRead(ANALOG_IN_3);
      break;
  }
  return 0;
}

void checkPedal() {
  bool OOR = false;  // out of range
  int val;
  newPedalVal = PEDAL_ANALOG_SUB_COSTANT - analogRead(A0) * PEDAL_ANALOG_MULT_COSTANT;
  if (newPedalVal >= pedalVal + ANALOG_FILTER_IGNORE_RANGE || newPedalVal <= pedalVal - ANALOG_FILTER_IGNORE_RANGE) {
    if (newPedalVal <= PEDAL_FILTER_HIGH_PASS) {
      val = 0;
      OOR = true;
    } else if (newPedalVal >= PEDAL_FILTER_LOW_PASS) {
      val = 1023;
      OOR = true;
    }
    if (!OOR) {
      val = newPedalVal;
    }
    if (pedalVal != 0 && pedalVal != 1023) {
      controlChange(0, 11, val / 16);
      MidiUSB.flush();
      // displayForceUpdate = true;
    }
    pedalVal = val;
  }
  // Serial.print("z:0,m:1023,new:");
  // Serial.print(newPedalVal);
  // Serial.print(",test:");
  // Serial.println(val * 16);
}

void checkEncoder() {

  if (!digitalRead(ENCODER_OUT_A) && digitalRead(ENCODER_OUT_B) && encoder_out_a_prev) {
    encoder_inc = true;
    encoder_dec = false;
  } else if (digitalRead(ENCODER_OUT_A) && !digitalRead(ENCODER_OUT_B) && encoder_out_b_prev) {
    encoder_inc = false;
    encoder_dec = true;
  } else {
    encoder_inc = false;
    encoder_dec = false;
  }
  encoder_out_a_prev = digitalRead(ENCODER_OUT_A);
  encoder_out_b_prev = digitalRead(ENCODER_OUT_B);
}
