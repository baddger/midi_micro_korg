#include "Controller.h"
#include "dataMidi.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <avr/pgmspace.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <MIDI.h>

/// OLED
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define CHANNEL_MIDI   1
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/// LCD
// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 20, 4); //LiquidCrystal_I2C lcd(0x3F,20,4);

MIDI_CREATE_DEFAULT_INSTANCE();

//************************************************************
//***SET THE NUMBER OF CONTROLS USED**************************
//************************************************************

//Mux M0(10, 16, false); //Digital multiplexer on Arduino pin 10
Mux M1(A0, 16, true); //Analog multiplexer on Arduino analog pin A1
Mux M2(A1, 16, true); //Analog multiplexer on Arduino analog pin A2
Mux M3(A2, 16, true); //Analog multiplexer on Arduino analog pin A3
//*******************************************************************


Pot MPO1(M1, 0, 0, 77, 1);
Pot MPO2(M1, 1, 0, 14, 1);
Pot MPO3(M1, 2, 0, 15, 1);
Pot MPO4(M1, 3, 0, 05, 1);
Pot MPO5(M1, 4, 0, 78, 1);
Pot MPO6(M1, 5, 0, 82, 1);
Pot MPO7(M1, 6, 0, 18, 1);
Pot MPO8(M1, 7, 0, 19, 1);
Pot MPO9(M1, 8, 0, 12, 1);
Pot MPO10(M1, 9, 0, 22, 1);
Pot MPO11(M1, 10, 0, 21, 1);
Pot MPO12(M1, 11, 0, 20, 1);
Pot MPO13(M1, 12, 0, 72, 1);
Pot MPO14(M1, 13, 0, 70, 1);
Pot MPO15(M1, 14, 0, 75, 1);
Pot MPO16(M1, 15, 0, 73, 1);
//
Pot MPO17(M2, 0, 0, 74, 1);
Pot MPO18(M2, 1, 0, 71, 1);
Pot MPO19(M2, 2, 0, 83, 1);
Pot MPO20(M2, 3, 0, 79, 1);
Pot MPO21(M2, 4, 0, 28, 1); // ce potar semble avoir du bruit
Pot MPO22(M2, 5, 0, 29, 1);
Pot MPO23(M2, 6, 0, 30, 1);
Pot MPO24(M2, 7, 0, 31, 1);
Pot MPO25(M2, 8, 0, 85, 1);
Pot MPO26(M2, 9, 0, 94, 1);
Pot MPO27(M2, 10, 0, 13, 1);
Pot MPO28(M2, 11, 0, 93, 1);
Pot MPO29(M2, 12, 0, 26, 1);
Pot MPO30(M2, 13, 0, 25, 1);
Pot MPO31(M2, 14, 0, 24, 1);
Pot MPO32(M2, 15, 0, 23, 1);

Pot MPO33(M3, 0, 0, 27, 1);
Pot MPO34(M3, 1, 0, 76, 1);
Pot MPO35(M3, 2, 0, 92, 1);
Pot MPO36(M3, 3, 0, 90, 1);
Pot MPO37(M3, 4, 0, 87, 1);
Pot MPO38(M3, 5, 0, 95, 1);
Pot MPO39(M3, 6, 0, 10, 1);
Pot MPO40(M3, 7, 0, 88, 1);

//---How many buttons are connected directly to pins?---------
byte NUMBER_BUTTONS = 0;
//---How many potentiometers are connected directly to pins?--
byte NUMBER_POTS = 1;


//---How many buttons are connected to a multiplexer?---------
byte NUMBER_MUX_BUTTONS = 0;
//---How many potentiometers are connected to a multiplexer?--
byte NUMBER_MUX_POTS = 40; //

//Add buttons used to array below like this->  Button *BUTTONS[] {&BU1, &BU2, &BU3, &BU4, &BU5, &BU6, &BU7, &BU8};
Button *BUTTONS[] {};
//*******************************************************************
Button *MUXBUTTONS[] {};
Pot PotVolume( A6, 0x07, 0x07, 1);

Pot *POTS[] {&PotVolume};

//*******************************************************************
//Add multiplexed pots used to array below like this->  Pot *MUXPOTS[] {&MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6.....};
Pot *MUXPOTS[] {&MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6, &MPO7, &MPO8, &MPO9, &MPO10, &MPO11, &MPO12, &MPO13, &MPO14, &MPO15,
  &MPO16, &MPO17, &MPO18, &MPO19, &MPO20, &MPO21, &MPO22, &MPO23, &MPO24, &MPO25,
&MPO26, &MPO27, &MPO28, &MPO29, &MPO30, &MPO31, &MPO32, &MPO33, &MPO34, &MPO35,
&MPO36, &MPO37, &MPO38, &MPO39, &MPO40 };
//*******************************************************************

//**************************NRPN**********************
byte NUMBER_MUX_POTS_NPRN = 8;
Pot POTNPRN1(M3, 8, 0, 0, 1); //PATCH 1 SOURCE
Pot POTNPRN2(M3, 9, 0, 1, 1); //PATCH 2 SOURCE
Pot POTNPRN3(M3, 10, 0, 2, 1); //PATCH 3 SOURCE
Pot POTNPRN4(M3, 11, 0, 3, 1); //PATCH 4 SOURCE
Pot POTNPRN5(M3, 12, 0, 8, 1); //PATCH 1 DEST
Pot POTNPRN6(M3, 13, 0, 9, 1); //PATCH 2 DEST
Pot POTNPRN7(M3, 14, 0, 10, 1); //PATCH 3 DEST
Pot POTNPRN8(M3, 15, 0, 11, 1); //PATCH 4 DEST
Pot *MUXPOTSNPRN[] {&POTNPRN1, &POTNPRN2, &POTNPRN3, &POTNPRN4, &POTNPRN5, &POTNPRN6, &POTNPRN7, &POTNPRN8 };

//**************************NRPN**********************
Pot POTWAVE(M1, 0, 0, 0, 0);
Pot POTDWGS(M1, 2, 0, 0, 0);

//**************************LCD**********************
void setup() {
  ////Serial.begin(9600);

  // initialize the LCD
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  updatePatchInOutOnLCD(true);
  updatePatchPowerOnLCD(true);
  MIDI.begin(MIDI_CHANNEL_OFF);

  // initialize OLED
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    //Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  //display.setFont(&FreeSerif9pt7b);
  display.setTextSize(2);                  // setTextSize applique est facteur d'échelle qui permet d'agrandir ou réduire la font
  display.setTextColor(WHITE);             // La couleur du texte
  display.setRotation(2);
}

void loop() {
  if (NUMBER_BUTTONS != 0) updateButtons();
  if (NUMBER_POTS != 0) updatePots();
  if (NUMBER_MUX_BUTTONS != 0) updateMuxButtons();
  if (NUMBER_MUX_POTS != 0) updateMuxPots();
  if (NUMBER_MUX_POTS != 0) updateMuxPotsNprn();

  updatePatchInOutOnLCD(true);
  updatePatchPowerOnLCD(true);
  updateOLED(&POTWAVE, &POTDWGS);
}

/*******************************************************************/
//                              LCD IN  / OUT
/*******************************************************************/char buffer5[5];
byte NUMBER_MUX_POTS_LCD_IN = 4;
byte NUMBER_MUX_POTS_LCD_OUT = 4;

Pot *MUXPOTS_LCD_IN[]  {&POTNPRN1, &POTNPRN2, &POTNPRN3, &POTNPRN4};
Pot *MUXPOTS_LCD_OUT[] {&POTNPRN5, &POTNPRN6, &POTNPRN7, &POTNPRN8};
byte oldin[4] = {255,255,255,255};
byte oldout[4] = {255,255,255,255};
void updatePatchInOutOnLCD(bool forceRead) {

  for (int i = 0; i < NUMBER_MUX_POTS_LCD_IN; i++) {

    MUXPOTS_LCD_IN[i]->muxUpdate();
    byte potmessage;
    if ((forceRead)) {
      potmessage = MUXPOTS_LCD_IN[i]->getCurrentValue();
    }
    else
    {
      potmessage = MUXPOTS_LCD_IN[i]->getValue();
      if (potmessage == 255) continue; // if same value do nothing;
    }
    if(potmessage == oldin[i])
    {
      continue;
    }
    oldin[i] = potmessage;
    int colone = i * 5;
    int val = potmessage >> 4; // Val => 0 -> 7


    lcd.setCursor(colone, 0);
    strcpy_P(buffer5, (char *)pgm_read_word(&(textIN[val])));  // Necessary casts and dereferencing, just copy.
    lcd.print(buffer5);

  }

  for (int i = 0; i < NUMBER_MUX_POTS_LCD_OUT; i++) {

    MUXPOTS_LCD_OUT[i]->muxUpdate();
    byte potmessage;
    if ((forceRead)) {
      potmessage = MUXPOTS_LCD_OUT[i]->getCurrentValue();
    }
    else
    {
      potmessage = MUXPOTS_LCD_OUT[i]->getValue();
      if (potmessage == 255) continue; // if same value do nothing;
    }
    if(potmessage == oldout[i])
    {
      continue;
    }
    oldout[i] = potmessage;
    int colone = i * 5;
    int val = potmessage >> 4; // Val => 0 -> 7

    lcd.setCursor(colone, 2);
    strcpy_P(buffer5, (char *)pgm_read_word(&(textOUT[val])));  // Necessary casts and dereferencing, just copy.
    lcd.print(buffer5);
    lcd.setCursor(colone, 3);
    strcpy_P(buffer5, (char *)pgm_read_word(&(textOUT_2[val])));  // Necessary casts and dereferencing, just copy.
    lcd.print(buffer5);
  }
}

/*******************************************************************/
//                              LCD POWER
/*******************************************************************/
byte NUMBER_POT_LCD_POWER = 4;
Pot *POT_LCD_POWER[] { &MPO21, &MPO22, &MPO23, &MPO24};

byte old[4] = {255,255,255,255};
void updatePatchPowerOnLCD(bool forceRead) {

  for (int i = 0; i < NUMBER_POT_LCD_POWER; i++) {

    POT_LCD_POWER[i]->muxUpdate();
    byte potmessage;
    if ((forceRead)) {
      potmessage = POT_LCD_POWER[i]->getCurrentValue();
    }
    else {
      potmessage = POT_LCD_POWER[i]->getValue();
      // if same value do nothing;
      if (potmessage == 255) continue;
    }
    if(potmessage == old[i])
    {
      continue;
    }
    old[i] = potmessage;
    int colone = i * 5;
    lcd.setCursor(colone, 1);
    lcd.print(F(" "));
    if(potmessage > 99) {} // value use 3 char
    else if(potmessage > 9) { lcd.print(F("0")); }// value use 2 char
    else { lcd.print(F("00")); } // value use 1 char
    lcd.print(potmessage);
    lcd.print(F(" "));
  }
}

/*******************************************************************/
//                              OLED
/*******************************************************************/
byte saveWave = 0;
byte saveDWGS = 0;
char buffer[10];  // make sure this is large enough for the largest string it must hold
void updateOLED(Pot * potWave, Pot * potDWGS)
{
  potWave->muxUpdate();
  byte potmessageWave = potWave->getValue();
  potDWGS->muxUpdate();
  byte potmessageDWGS = potDWGS->getValue();
  if (potmessageWave != 255)
  {
    saveWave = potmessageWave;
  }
  if (potmessageDWGS != 255)
  {
    saveDWGS = potmessageDWGS;
  }
  if (!( 79 < saveWave &&  saveWave < 96))
  {
    display.clearDisplay();
    display.setCursor(5,5);                  // On va écrire en x=0, y=0
    display.println(F("NO DWGS"));
    display.display();
    return;
  }

  int value = saveDWGS >> 1;
  strcpy_P(buffer, (char *)pgm_read_word(&(textOLED[value])));  // Necessary casts and dereferencing, just copy.
  display.clearDisplay();
  display.setCursor(5,5);                  // On va écrire en x=0, y=0
  display.println(buffer);        // un println comme pour écrire sur le port série
  //display.println(freeRam());        // un println comme pour écrire sur le port série
  display.display();
}



//*****************************************************************
void updateButtons() {

  // Cycle through Button array
  for (int i = 0; i < NUMBER_BUTTONS; i = i + 1) {
    byte message = BUTTONS[i]->getValue();

    //  Button is pressed
    if (message == 0) {
      switch (BUTTONS[i]->Bcommand) {
        case 0: //Note
        MIDI.sendNoteOn(BUTTONS[i]->Bvalue, 127, BUTTONS[i]->Bchannel);
        break;
        case 1: //CC
        MIDI.sendControlChange(BUTTONS[i]->Bvalue, 127, BUTTONS[i]->Bchannel);
        break;
        case 2: //Toggle
        if (BUTTONS[i]->Btoggle == 0) {
          MIDI.sendControlChange(BUTTONS[i]->Bvalue, 127, BUTTONS[i]->Bchannel);
          BUTTONS[i]->Btoggle = 1;
        }
        else if (BUTTONS[i]->Btoggle == 1) {
          MIDI.sendControlChange(BUTTONS[i]->Bvalue, 0, BUTTONS[i]->Bchannel);
          BUTTONS[i]->Btoggle = 0;
        }
        break;
      }
    }

    //  Button is not pressed
    if (message == 1) {
      switch (BUTTONS[i]->Bcommand) {
        case 0:
        MIDI.sendNoteOff(BUTTONS[i]->Bvalue, 0, BUTTONS[i]->Bchannel);
        break;
        case 1:
        MIDI.sendControlChange(BUTTONS[i]->Bvalue, 0, BUTTONS[i]->Bchannel);
        break;
      }
    }
  }
}
//*******************************************************************
void updateMuxButtons() {

  // Cycle through Mux Button array
  for (int i = 0; i < NUMBER_MUX_BUTTONS; i = i + 1) {

    MUXBUTTONS[i]->muxUpdate();
    byte message = MUXBUTTONS[i]->getValue();

    //  Button is pressed
    if (message == 0) {
      switch (MUXBUTTONS[i]->Bcommand) {
        case 0: //Note
        MIDI.sendNoteOn(MUXBUTTONS[i]->Bvalue, 127, MUXBUTTONS[i]->Bchannel);
        break;
        case 1: //CC
        MIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 127, MUXBUTTONS[i]->Bchannel);
        break;
        case 2: //Toggle
        if (MUXBUTTONS[i]->Btoggle == 0) {
          MIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 127, MUXBUTTONS[i]->Bchannel);
          MUXBUTTONS[i]->Btoggle = 1;
        }
        else if (MUXBUTTONS[i]->Btoggle == 1) {
          MIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 0, MUXBUTTONS[i]->Bchannel);
          MUXBUTTONS[i]->Btoggle = 0;
        }
        break;
      }
    }
    //  Button is not pressed
    if (message == 1) {
      switch (MUXBUTTONS[i]->Bcommand) {
        case 0:
        MIDI.sendNoteOff(MUXBUTTONS[i]->Bvalue, 0, MUXBUTTONS[i]->Bchannel);
        break;
        case 1:
        MIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 0, MUXBUTTONS[i]->Bchannel);
        break;
      }
    }
  }
}
//***********************************************************************
void updatePots() {
  for (int i = 0; i < NUMBER_POTS; i = i + 1) {
    byte potmessage = POTS[i]->getValue();
    if (potmessage != 255) MIDI.sendControlChange(POTS[i]->Pcontrol, potmessage, CHANNEL_MIDI);//POTS[i]->Pchannel);
  }
}
//***********************************************************************
void updateMuxPots() {
  for (int i = 0; i < NUMBER_MUX_POTS; i = i + 1) {
    MUXPOTS[i]->muxUpdate();
    byte potmessage = MUXPOTS[i]->getValue();
    if (potmessage != 255) MIDI.sendControlChange(MUXPOTS[i]->Pcontrol, potmessage, CHANNEL_MIDI);//MUXPOTS[i]->Pchannel);
    //  if (potmessage != 255) //Serial.println(String(potmessage));
  }
}

//***********************************************************************
void updateMuxPotsNprn() {
  for (int i = 0; i < NUMBER_MUX_POTS_NPRN; i = i + 1) {
    MUXPOTSNPRN[i]->muxUpdate();
    byte potmessage = MUXPOTSNPRN[i]->getValue();
    if (potmessage != 255)
    {

      //MIDI.sendNrpnValue(byte inMsb, byte inLsb, Channel inChannel);
      MIDI.sendControlChange(0x63, 0x04, CHANNEL_MIDI);//MUXPOTS[i]->Pchannel);
      MIDI.sendControlChange(0x62, MUXPOTSNPRN[i]->Pcontrol, CHANNEL_MIDI);//MUXPOTS[i]->Pchannel);
      MIDI.sendControlChange(0x06, potmessage, CHANNEL_MIDI);//MUXPOTS[i]->Pchannel);
    }
  }
}
