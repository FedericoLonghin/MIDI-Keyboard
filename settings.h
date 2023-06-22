#define OUT 4
#define LD 5
#define CLK 6
#define ANALOG_SELECT_0 8
#define ANALOG_SELECT_1 9
#define ENCODER_OUT_A 11
#define ENCODER_OUT_B 12
#define ENCODER_SW 13
#define BINARY_IN_LENGHT 192
#define ANALOG_LENGHT 16
#define UPPER_KEYBOARD_LENGTH 44
#define LOWER_KEYBOARD_LENGTH 44
#define PEDAL_KEYBOARD_LENGTH 13
#define midi true
#define t 1
#define tAnalog 200
#define STARTING_KEY_VAL_LOW 53  //29: middle:C2,  53:middle:C4
#define STARTING_KEY_VAL_UPP 53  //29: middle:C2,  53:middle:C4
#define STARTING_KEY_VAL_PED 40

#define ANALOG_FILTER_RANGE 5
#define ANALOG_FILTER_IGNORE_RANGE 10
#define ANALOG_DELTA 20
#define ANALOG_FILTER_TIME 100


#define PEDAL_FILTER_HIGH_PASS 35
#define PEDAL_FILTER_LOW_PASS 960
#define PEDAL_ANALOG_MULT_COSTANT 1.13
#define PEDAL_ANALOG_SUB_COSTANT 1000

#define ANALOG_IN_0 A2
#define ANALOG_IN_1 A3
#define ANALOG_IN_2 A4
#define ANALOG_IN_3 A5


bool encoder_out_a_prev;
bool encoder_out_b_prev;
bool encoder_inc,encoder_dec;
bool showChords=false;
//Display animation
bool displayForceUpdate = true;

String displayShowText = "";
int displayShowDuration = 0;
bool displayShowOnShow = false;
#define DISPLAY_ANIMATION_DURATION 200

int displayChordDuration = 0;
bool displayChordOnShow = false;
#define DISPLAY_CHORD_DURATION 200

int shiftTone = 0;

bool keyStatus[BINARY_IN_LENGHT];
bool upperKeyboardStatus[UPPER_KEYBOARD_LENGTH];
bool lowerKeyboardStatus[UPPER_KEYBOARD_LENGTH];
String noteName[] = { "DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", "SOL#", "LA", "LA#", "SI" };
String chord = "";
int analogVal[ANALOG_LENGHT];
int analogMaxVal[ANALOG_LENGHT] = { 1023, 1023, 1020, 1020, 1023, 1023, 1023, 1016, 1023, 1015, 1018, 1020, 1027, 1023, 0 };
int analogMinVal[ANALOG_LENGHT] = { 0, 0, 9, 2, 8, 0, 1, 2, 9, 2, 0, 0, 5, 9, 9, 0 };
int newAnalogVal[ANALOG_LENGHT];
bool analogInverted[ANALOG_LENGHT] = { 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0 };
unsigned long int analogFilterLastTouch[ANALOG_LENGHT];

int pedalVal;
int newPedalVal;
// ADDRESS DEFINITION

//slider panel
#define ANALOG_PEDAL_VOLUME 5
#define ANALOG_UPPER_SUSTAIN 9
#define ANALOG_KEYBOARD_BALANCE 1
#define ANALOG_PRESET_PERCUSS_VOLUME 12
#define ANALOG_VIBRATO_SPEED 4
#define ANALOG_REPEAT_SPEED 8
#define ANALOG_SYNT_PRESET_VOLUME 0

//computer Band
#define ANALOG_BASS_VOLUME 13
#define ANALOG_CHORD_VOLUME 2
#define ANALOG_MULTI_P_VOLUME 10
#define ANALOG_RHYTHM_VOLUME 6
#define ANALOG_TEMPO 14

//other
#define ANALOG_SYNT_PRESETS_TUNING 3
#define ANALOG_GENERAL_TUNING 11
#define ANALOG_GENERAL_VOLUME 7

//  DIGIAL IN INDEX

// pedal
#define DIGITAL_PEDAL_FLUTE 184
#define DIGITAL_PEDAL_BASS_GUITAR 183
#define DIGITAL_PEDAL_SUSTAIN 182

//  lower
#define DIGITAL_LOWER_FLUTE_8 181
#define DIGITAL_LOWER_CLARINET_8 180
#define DIGITAL_LOWER_FLUTE_4 179
#define DIGITAL_LOWER_STRING_4 178

//  upper
#define DIGITAL_UPPER_FLUTE_16 177
#define DIGITAL_UPPER_CELLO_16 176
#define DIGITAL_UPPER_CLARINET_16 175
#define DIGITAL_UPPER_FLUTE_8 174
#define DIGITAL_UPPER_TRUMPET_8 173
#define DIGITAL_UPPER_OBOE_8 172
#define DIGITAL_UPPER_REED_8 171
#define DIGITAL_UPPER_FLUTE_4 170
#define DIGITAL_UPPER_VIOLIN_4 169
#define DIGITAL_UPPER_FLUTE_2 168
#define DIGITAL_UPPER_CANCEL 167
#define DIGITAL_UPPER_SUSTAIN 166
#define DIGITAL_UPPER_PERCUSS 165
#define DIGITAL_UPPER_REPEAT 164

//  presets
#define DIGITAL_PRESET_PIANO 163
#define DIGITAL_PRESET_ACCORDION 162
#define DIGITAL_PRESET_BANJO 161
#define DIGITAL_PRESET_MANDOLIN 160
#define DIGITAL_PRESET_STRING_ENSEMBLE 159

//synth presets
#define DIGITAL_SYNTH_CANCEL 158
#define DIGITAL_SYNTH_PRES1 157
#define DIGITAL_SYNTH_PRES2 156
#define DIGITAL_SYNTH_PRES3 155
#define DIGITAL_SYNTH_PRES4 154
#define DIGITAL_SYNTH_PRES5 153
#define DIGITAL_SYNTH_PRES6 152
#define DIGITAL_SYNTH_SEMI_DOWN 151
#define DIGITAL_SYNTH_SEMI_UP 150
#define DIGITAL_SYNTH_KEY_DOWN 149
#define DIGITAL_SYNTH_KEY_UP 148


//  effects
#define DIGITAL_EFFECT_VIBRATO_1 190
#define DIGITAL_EFFECT_VIBRATO_2 189
#define DIGITAL_EFFECT_VIBRATO_DELAY 188
#define DIGITAL_EFFECT_REVERB 187

//  space
#define DIGITAL_SPACE_MOTION 186
#define DIGITAL_SPACE_SLOW_FAST 185
