#include "SPI.h"
#include "DMD.h"
#include "TimerOne.h"
#include "Arial_black_16.h"
/* you can remove the fonts if unused */
//led array variables
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS , DISPLAYS_DOWN);

//push button variables

int buttonReader = A0;
int button ;
//button text
void ScanDMD()
{
  dmd.scanDisplayBySPI();
}

//initialize and clear screen
void setup() {
  pinMode(buttonReader, INPUT);
  Timer1.initialize(5000);
  Timer1.attachInterrupt(ScanDMD);
  dmd.clearScreen(true);
  Serial.begin(9600);
}
//scroll text string
String textToScroll = "Welcome! Please Select An Office";

//draw text function
void drawText(String dispString) {
  //initialize
  dmd.clearScreen(true);
  dmd.selectFont(Arial_Black_16);
  char newString[256];

  //button button resistance
  button = analogRead(buttonReader);

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
    Serial.println("Button F confirmed");
                 }
                   else if ( button > 134 && button < 154) {
                   textToScroll = "HOD Mech Engr - first office to the right";

                 }
                   else if ( button > 171 && button < 191) {
                   textToScroll = "HOD Civil Engr. - second office to your left";
                   Serial.println("Button G confirmed");
  }
  int sLength = dispString.length();
  dispString.toCharArray(newString, sLength + 1);
  dmd.drawMarquee(newString , sLength , (32 * DISPLAYS_ACROSS) - 1 , 0);
  long start = millis();
  long timer = start;
  long timer2 = start;
  boolean flag = false;
  while (!flag) {
    if ((timer + 40) < millis()) {
      flag = dmd.stepMarquee(-1, 0);
      timer = millis();
    }
  }
}

void loop()
{
  
  drawText(textToScroll);
   button = analogRead(buttonReader);
}
