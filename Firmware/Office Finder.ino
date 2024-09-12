#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#include "Arial14.h"

char b[8];
String str;
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

void ScanDMD() {
  dmd.scanDisplayBySPI();
}

int btnReader = A5;
int button = 0;
String textToScroll;

void setup() {
  //  Serial.begin(9600);
  Timer1.initialize(2000);
  Timer1.attachInterrupt(ScanDMD);
  dmd.clearScreen(true);
  pinMode(btnReader, INPUT);
}

void loop()
{

  button = analogRead(btnReader);
  //  Serial.println(button);
  if (button < 5) {
    textToScroll = "Select Office?";
    textDisplay();

  }

  if ( button > 216 && button < 236) {

    textToScroll = "HOD Elect Engr. : First Floor first office along the left passage";
    textDisplay();

  }
  if ( button > 281 && button < 301) {
    textToScroll = " HOD Welding & fabrication : First Floor Second office along the left passage";
    textDisplay();
  }
  if ( button > 378 && button < 398) {
    textToScroll = "HOD Mech Engr. : First Floor first office along the right passage";
    textDisplay();
  }
  if ( button > 557 && button < 577) {
    textToScroll = "HOD Civil Engr. : First Floor second office along the right passage";
    textDisplay();
  }
  if ( button > 1000) {
    textToScroll = "Director C.O.E. :First Floor first office immidiately after the staircase";
    textDisplay();
  }
  if ( button > 60 && button < 80) {
    textToScroll = "Exam office elect. engr. :  ground floor first office to the left";
    textDisplay();
  }
  if ( button > 100 && button < 120) {
    textToScroll = "Exam office welding & fabrication : ground floor second office to the left";
    textDisplay();
  }
  if ( button > 134 && button < 154) {
    textToScroll = "Exam office Mech. engr. : ground floor first office to the right";
    textDisplay();
  }
  if ( button >= 171 && button <= 200) {
    textToScroll = "Exam office Civil Engr. : ground floor second office to the right";
    Serial.println("Button I confirmed");
    textDisplay();
  }
}
void textDisplay() {
  int slen = 0;
  dmd.selectFont(Arial_Black_16);
  slen = textToScroll.length() + 1;
  textToScroll.toCharArray(b, slen );
  dmd.drawMarquee( b, slen, (32 * DISPLAYS_ACROSS) , 0);
  unsigned long timing  = millis();
  boolean flag = false;
  while (!flag)
  {
    if ((timing + 30) < millis())
    {
      flag = dmd.stepMarquee(-1, 0);
      timing = millis();
    }
  }
}
void textDisplay0() {
  int slen = 0;
  dmd.selectFont(Arial_Black_16);
  str = "Stem Hub Ennovation";
  slen = str.length() + 1;
  str.toCharArray(b, slen );
  dmd.drawMarquee( b, slen, (32 * DISPLAYS_ACROSS) , 0);
  unsigned long timing  = millis();
  boolean flag = false;
  while (!flag)
  {
    if ((timing + 30) < millis())
    {
      flag = dmd.stepMarquee(-1, 0);
      timing = millis();
    }
  }
}
