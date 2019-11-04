#ifndef datamidi_h
#define datamidi_h

int freeRam () {
   extern int __heap_start, *__brkval;
   int v;
   return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
const char textIN1[] PROGMEM = "FEG  ";
const char textIN2[] PROGMEM = "AEG  ";
const char textIN3[] PROGMEM = "Lfo1 ";
const char textIN4[] PROGMEM = "Lfo2 ";
const char textIN5[] PROGMEM = "Velo ";
const char textIN6[] PROGMEM = "KbTr ";
const char textIN7[] PROGMEM = "MOD  ";
const char textIN8[] PROGMEM = "Pitch";
const char *const textIN[] PROGMEM  = {textIN1, textIN2, textIN3, textIN4, textIN5, textIN6, textIN7, textIN8};

const char textOUT1[] PROGMEM = "Pitch";
const char textOUT2[] PROGMEM = "Osc2 ";
const char textOUT3[] PROGMEM = "Osc1 ";
const char textOUT4[] PROGMEM = "Noise";
const char textOUT5[] PROGMEM = "Cut  ";
const char textOUT6[] PROGMEM = "AMP  ";
const char textOUT7[] PROGMEM = "PAN  ";
const char textOUT8[] PROGMEM = "Lfo2 ";
const char *const textOUT[] PROGMEM  = {textOUT1, textOUT2, textOUT3, textOUT4, textOUT5, textOUT6, textOUT7, textOUT8};

const char textOUT2_1[] PROGMEM = "     ";
const char textOUT2_2[] PROGMEM = "Ctrl1";
const char textOUT2_3[] PROGMEM = "Ctrl1";
const char textOUT2_4[] PROGMEM = "Level";
const char textOUT2_5[] PROGMEM = "Off  ";
const char textOUT2_6[] PROGMEM = "     ";
const char textOUT2_7[] PROGMEM = "     ";
const char textOUT2_8[] PROGMEM = "Freq ";
const char *const textOUT_2[] PROGMEM  = {textOUT2_1, textOUT2_2, textOUT2_3, textOUT2_4, textOUT2_5, textOUT2_6, textOUT2_7, textOUT2_8};


const char SynSine1[] PROGMEM = "SynSine1";
const char SynSine2[] PROGMEM = "SynSine2";
const char SynSine3[] PROGMEM = "SynSine3";
const char SynSine4[] PROGMEM = "SynSine4";
const char SynSine5[] PROGMEM = "SynSine5";
const char SynSine6[] PROGMEM = "SynSine6";
const char SynSine7[] PROGMEM = "SynSine7";
const char SynBass1[] PROGMEM = "SynBass1";
const char SynBass2[] PROGMEM = "SynBass2";
const char SynBass3[] PROGMEM = "SynBass3";
const char SynBass4[] PROGMEM = "SynBass4";
const char SynBass5[] PROGMEM = "SynBass5";
const char SynBass6[] PROGMEM = "SynBass6";
const char SynBass7[] PROGMEM = "SynBass7";
const char SynWave1[] PROGMEM = "SynWave1";
const char SynWave2[] PROGMEM = "SynWave2";
const char SynWave3[] PROGMEM = "SynWave3";
const char SynWave4[] PROGMEM = "SynWave4";
const char SynWave5[] PROGMEM = "SynWave5";
const char SynWave6[] PROGMEM = "SynWave6";
const char SynWave7[] PROGMEM = "SynWave7";
const char SynWave8[] PROGMEM = "SynWave8";
const char SynWave9[] PROGMEM = "SynWave9";
const char thWave1[] PROGMEM = "5thWave1";
const char thWave2[] PROGMEM = "5thWave2";
const char thWave3[] PROGMEM = "5thWave3";
const char Digi1[] PROGMEM = "Digi1";
const char Digi2[] PROGMEM = "Digi2";
const char Digi3[] PROGMEM = "Digi3";
const char Digi4[] PROGMEM = "Digi4";
const char Digi5[] PROGMEM = "Digi5";
const char Digi6[] PROGMEM = "Digi6";
const char Digi7[] PROGMEM = "Digi7";
const char Digi8[] PROGMEM = "Digi8";
const char Endless[] PROGMEM = "Endless*";
const char EPiano1[] PROGMEM = "E.Piano1";
const char EPiano2[] PROGMEM = "E.Piano2";
const char EPiano3[] PROGMEM = "E.Piano3";
const char EPiano4[] PROGMEM = "E.Piano4";
const char Organ1[] PROGMEM = "Organ1";
const char Organ2[] PROGMEM = "Organ2";
const char Organ3[] PROGMEM = "Organ3";
const char Organ4[] PROGMEM = "Organ4";
const char Organ5[] PROGMEM = "Organ5";
const char Organ6[] PROGMEM = "Organ6";
const char Organ7[] PROGMEM = "Organ7";
const char Clav1[] PROGMEM = "Clav1";
const char Clav2[] PROGMEM = "Clav2";
const char Guitar1[] PROGMEM = "Guitar1";
const char Guitar2[] PROGMEM = "Guitar2";
const char Guitar3[] PROGMEM = "Guitar3";
const char Bass1[] PROGMEM = "Bass1";
const char Bass2[] PROGMEM = "Bass2";
const char Bass3[] PROGMEM = "Bass3";
const char Bass4[] PROGMEM = "Bass4";
const char Bass5[] PROGMEM = "Bass5";
const char Bell1[] PROGMEM = "Bell1";
const char Bell2[] PROGMEM = "Bell2";
const char Bell3[] PROGMEM = "Bell3";
const char Bell4[] PROGMEM = "Bell4";
const char Voice1[] PROGMEM = "Voice1";
const char Voice2[] PROGMEM = "Voice2";
const char Voice3[] PROGMEM = "Voice3";
const char Voice4[] PROGMEM = "Voice4";

const char *const textOLED[] PROGMEM  = {
  SynSine1,
  SynSine2,
  SynSine3,
  SynSine4,
  SynSine5,
  SynSine6,
  SynSine7,
  SynBass1,
  SynBass2,
  SynBass3,
  SynBass4,
  SynBass5,
  SynBass6,
  SynBass7,
  SynWave1,
  SynWave2,
  SynWave3,
  SynWave4,
  SynWave5,
  SynWave6,
  SynWave7,
  SynWave8,
  SynWave9,
  thWave1,
  thWave2,
  thWave3,
  Digi1,
  Digi2,
  Digi3,
  Digi4,
  Digi5,
  Digi6,
  Digi7,
  Digi8,
  Endless,
  EPiano1,
  EPiano2,
  EPiano3,
  EPiano4,
  Organ1,
  Organ2,
  Organ3,
  Organ4,
  Organ5,
  Organ6,
  Organ7,
  Clav1,
  Clav2,
  Guitar1,
  Guitar2,
  Guitar3,
  Bass1,
  Bass2,
  Bass3,
  Bass4,
  Bass5,
  Bell1,
  Bell2,
  Bell3,
  Bell4,
  Voice1,
  Voice2,
  Voice3,
  Voice4
};

#endif
