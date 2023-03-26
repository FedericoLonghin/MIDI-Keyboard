
void checkAnalog() {
  for (byte i = 0; i < 16; i++) {
    if (analogVal[i] >= newAnalogVal[i] + ANALOG_FILTER_IGNORE_RANGE || analogVal[i] <= newAnalogVal[i] - ANALOG_FILTER_IGNORE_RANGE) {
      if (millis() > analogFilterLastTouch[i] + ANALOG_FILTER_TIME || (analogVal[i] >= newAnalogVal[i] + ANALOG_FILTER_RANGE || analogVal[i] <= newAnalogVal[i] - ANALOG_FILTER_RANGE)) {
        analogFilterLastTouch[i] = millis();
        //   int temp = istantAnalogValue(i);
        //   if (temp < newAnalogVal[i] + ANALOG_DELTA && temp > newAnalogVal[i] - ANALOG_DELTA) {
        // byte val = newAnalogVal[i] / 8;
        byte val = remapAnalog(newAnalogVal[i], 0, 1024, 0);
        switch (i) {
          // Slider Panel
          case ANALOG_PEDAL_VOLUME:
            controlChange(0, 20 + 0, val);
            break;
          case ANALOG_UPPER_SUSTAIN:
            controlChange(0, 20 + 1, val);
            break;
          case ANALOG_KEYBOARD_BALANCE:
            controlChange(0, 20 + 2, val);
            break;
          case ANALOG_PRESET_PERCUSS_VOLUME:
            controlChange(0, 20 + 3, val);
            break;
          case ANALOG_VIBRATO_SPEED:
            controlChange(0, 20 + 4, val);
            break;
          case ANALOG_REPEAT_SPEED:
            controlChange(0, 20 + 5, val);
            break;
          case ANALOG_SYNT_PRESET_VOLUME:
            controlChange(0, 20 + 6, val);
            break;

          // Computer Band Panel
          case ANALOG_BASS_VOLUME:
            controlChange(0, 20 + 7, val);
            break;
          case ANALOG_CHORD_VOLUME:
            controlChange(0, 20 + 8, val);
            break;
          case ANALOG_MULTI_P_VOLUME:
            controlChange(0, 20 + 9, val);
            break;
          case ANALOG_RHYTHM_VOLUME:
            controlChange(0, 20 + 10, val);
            break;
          case ANALOG_TEMPO:
            controlChange(0, 20 + 11, val);
            break;

          // other
          case ANALOG_SYNT_PRESETS_TUNING:
            controlChange(0, 20 + 12, val);
            break;
          case ANALOG_GENERAL_TUNING:
            controlChange(0, 20 + 13, val);
            break;
          case ANALOG_GENERAL_VOLUME:
            controlChange(0, 20 + 14, val);
            break;
        }

        MidiUSB.flush();
        analogVal[i] = newAnalogVal[i];
      }
    }
  }
}

byte remapAnalog(int val, int min, int max, bool inverted) {
  int newVal = (val - min) / ((max - min) / 127);
  if (inverted)
    newVal = 127 - newVal;
  return newVal;
}

void toggleAction(int index, bool val) {
  // Serial.println(index);
  switch (index) {
    case 100 ... 112:
      if (val)
        noteOn(0, remappedKeyboard(index) + STARTING_KEY_VAL_PED, 64);
      else
        noteOff(0, remappedKeyboard(index) + STARTING_KEY_VAL_PED, 64);
      break;
    case 52 ... 95:
      if (val)
        noteOn(1, remappedKeyboard(index) + STARTING_KEY_VAL_LOW, 64);
      else
        noteOff(1, remappedKeyboard(index) + STARTING_KEY_VAL_LOW, 64);
      break;
    case 4 ... 47:
      if (val)
        noteOn(2, remappedKeyboard(index) + STARTING_KEY_VAL_UPP, 64);
      else
        noteOff(2, remappedKeyboard(index) + STARTING_KEY_VAL_UPP, 64);
      break;

    // Registers

    // Pedal
    case DIGITAL_PEDAL_FLUTE:
      controlChange(0, 20, val * 64);
      break;
    case DIGITAL_PEDAL_BASS_GUITAR:
      controlChange(0, 21, val * 64);
      break;
    case DIGITAL_PEDAL_SUSTAIN:
      controlChange(0, 22, val * 64);
      break;


    // Lower
    case DIGITAL_LOWER_FLUTE_8:
      controlChange(1, 20, val * 64);
      break;
    case DIGITAL_LOWER_CLARINET_8:
      controlChange(1, 21, val * 64);
      break;
    case DIGITAL_LOWER_FLUTE_4:
      controlChange(1, 22, val * 64);
      break;
    case DIGITAL_LOWER_STRING_4:
      controlChange(1, 23, val * 64);
      break;

      // Upper
    case DIGITAL_UPPER_FLUTE_16:
      controlChange(2, 20, val * 64);
      break;
    case DIGITAL_UPPER_CELLO_16:
      controlChange(2, 21, val * 64);
      break;
    case DIGITAL_UPPER_CLARINET_16:
      controlChange(2, 22, val * 64);
      break;
    case DIGITAL_UPPER_FLUTE_8:
      controlChange(2, 23, val * 64);
      break;
    case DIGITAL_UPPER_TRUMPET_8:
      controlChange(2, 24, val * 64);
      break;
    case DIGITAL_UPPER_OBOE_8:
      controlChange(2, 25, val * 64);
      break;
    case DIGITAL_UPPER_REED_8:
      controlChange(2, 26, val * 64);
      break;
    case DIGITAL_UPPER_FLUTE_4:
      controlChange(2, 27, val * 64);
      break;
    case DIGITAL_UPPER_VIOLIN_4:
      controlChange(2, 28, val * 64);
      break;
    case DIGITAL_UPPER_FLUTE_2:
      controlChange(2, 29, val * 64);
      break;
    case DIGITAL_UPPER_CANCEL:
      controlChange(2, 30, val * 64);
      break;
    case DIGITAL_UPPER_SUSTAIN:
      controlChange(2, 31, val * 64);
      break;
    case DIGITAL_UPPER_PERCUSS:
      controlChange(2, 32, val * 64);
      break;
    case DIGITAL_UPPER_REPEAT:
      controlChange(2, 33, val * 64);
      break;

      // Presets
    case DIGITAL_PRESET_PIANO:
      controlChange(3, 20, val * 64);
      break;
    case DIGITAL_PRESET_ACCORDION:
      controlChange(3, 21, val * 64);
      break;
    case DIGITAL_PRESET_BANJO:
      controlChange(3, 22, val * 64);
      break;
    case DIGITAL_PRESET_MANDOLIN:
      controlChange(3, 23, val * 64);
      break;
    case DIGITAL_PRESET_STRING_ENSEMBLE:
      controlChange(3, 24, val * 64);
      break;
      // Effects
    case DIGITAL_EFFECT_VIBRATO_1:
      controlChange(3, 25, val * 64);
      break;
    case DIGITAL_EFFECT_VIBRATO_2:
      controlChange(3, 26, val * 64);
      break;
    case DIGITAL_EFFECT_VIBRATO_DELAY:
      controlChange(3, 27, val * 64);
      break;
    case DIGITAL_EFFECT_REVERB:
      controlChange(3, 28, val * 64);
      break;
      // Space
    case DIGITAL_SPACE_MOTION:
      controlChange(3, 29, val * 64);
      break;
    case DIGITAL_SPACE_SLOW_FAST:
      controlChange(3, 30, val * 64);
      break;
  }
  MidiUSB.flush();
}

byte remappedKeyboard(byte val) {
  switch (val) {
    //  Pedal Keyboard
    case 100 ... 112:
      return -112 - val;
      break;
    //  Lower Keyboard
    case 89 ... 95:
      return -89 + val;
      break;
    case 77 ... 88:
      return -77 + 7 + val;
      break;
    case 65 ... 76:
      return -65 + 19 + val;
      break;
    case 52 ... 64:
      return -52 + 31 + val;
      break;

    //  Upper Keyboard
    case 41 ... 47:
      return -41 + val;
      break;
    case 29 ... 40:
      return -22 + val;
      break;
    case 17 ... 28:
      return +2 + val;
      break;
    case 4 ... 16:
      return +27 + val;
      break;
  }
  return -1;
}
