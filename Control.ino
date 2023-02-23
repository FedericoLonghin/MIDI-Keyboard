void checkAnalog() {
  for (byte i = 0; i < 16; i++) {
    if (analogVal[i] > newAnalogVal[i] + ANALOG_DELTA || analogVal[i] < newAnalogVal[i] - ANALOG_DELTA) {
      int temp = istantAnalogValue(i);
      if (temp < newAnalogVal[i] + ANALOG_DELTA && temp > newAnalogVal[i] - ANALOG_DELTA) {
        byte val = newAnalogVal[i] / 8;
        switch (i) {
          case 0:  //1
            controlChange(0, 20 + 0, val);
            break;
          case 1:  //5
            controlChange(0, 20 + 4, val);
            break;
          case 2:  //computerBand slider 2
            controlChange(0, 20 + 21, val);
            break;
          case 3:  //synth tuning knob
            controlChange(0, 20 + 11, val);
            break;
          case 4:  //3
            controlChange(0, 20 + 2, val);
            break;
          case 5:  //7
            controlChange(0, 20 + 6, val);
            break;
          case 6:  //computerBand slider 4
            break;
          case 7:  // master volume knob
            controlChange(0, 7, val);
            break;
          case 8:  //slider panel 2
            controlChange(0, 20 + 1, val);
            break;
          case 9:  //6
            controlChange(0, 20 + 5, val);
            break;
          case 10:  //computerBand slider 3
            break;
          case 11:  //master tuning knob
            controlChange(0, 20 + 10, val);
            break;
          case 12:  //4
            controlChange(0, 20 + 3, val);
            break;
          case 13:  //computerBand slider 1
            break;
          case 14:  //computerBand slider 5
            break;
          case 15:
            break;
        }

        MidiUSB.flush();
        analogVal[i] = newAnalogVal[i];
      }
    }
  }
}
