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

int btnReader = A0;
int button = 0;
String textToScroll;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(500);
  Timer1.attachInterrupt(ScanDMD);
  dmd.clearScreen(true);
  pinMode(btnReader,INPUT);
}

void loop()
{
//  textDisplay0();
  button = analogRead(btnReader);
  Serial.println(button);
  
  if ( button > 216 && button < 236) {
    textToScroll = "Electrical Engr. Exam office : first office to your left.";
    Serial.println("Button A confirmed");
  }
  else if ( button > 281 && button < 301) {
    textToScroll = "welding & fabrication Exam office : second office  to your left.";
    Serial.println("Button B confirmed");
  }
  else if ( button > 378 && button < 398) {
    textToScroll = "Mech Engr. Exam office : first office by your right.";
    Serial.println("Button C confirmed");
  }
  else if ( button > 557 && button < 577) {
    textToScroll = "Civil Engr. Exam office : second office to your right.";
    Serial.println("Button D confirmed");
  }
  else if ( button > 1000) {
    textToScroll = "Director C. O. E - immediately after the staircase";
    Serial.println("Button E confirmed");
  }
  else if ( button > 60 && button < 80) {
    textToScroll = "HOD Elect Engr - first office to the left";
    Serial.println("Button F confirmed");
  }
  else if ( button > 100 && button < 120) {
    textToScroll = "HOD weld. & fabric. - second office to the left";
    Serial.println("Button G confirmed");
  }
  else if ( button > 134 && button < 154) {
    textToScroll = "HOD Mech Engr - first office to the right";
    Serial.println("Button H confirmed");
  }
  else if ( button >= 171 && button <= 200) {
    textToScroll = "HOD Civil Engr. - second office to your left";
    Serial.println("Button I confirmed");
    }
   else if (button <= 5){
    textToScroll = "Okay Done sufvice";
    Serial.println("Else confirmed");
    textDisplay();
  }
  delay(1000);
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
