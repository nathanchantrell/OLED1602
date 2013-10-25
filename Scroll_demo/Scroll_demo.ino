/*
Scrolling demo on the OLED 1602 display from Wide.HK. 
Uses Library by Phil Grant http://www.gadjet.co.uk
Scrolling by Nathan Chantrell http://nathan.chantrell.net
*/

#include  <Wire.h>
#include  <OLedI2C.h> // http://www.gadjetsblog.blogspot.co.uk/2013/09/oled-1602-display-and-library-for.html

OLedI2C LCD;

void setup() {
  Serial.begin(9600); 
  Wire.begin();   
  LCD.init();  
  LCD.clearLcd();
}

void loop() { 
  scrollString("Slowly scrolling text on line one...",0,200);
  scrollString("and faster on line two...",1,100);
}

void scrollString(char* message, byte row, unsigned int time) {
 char buffer[16];
 for (byte i=0;i<strlen(message)+16;i++) {
  byte pos = i+1;
  for (byte j=0;j<16;j++) {
   if ((pos<16)||(pos>strlen(message)+15)) { // pad and trail with blank spaces
     buffer[j]=' ';
   }
   else buffer[j]=message[pos-16];
   pos++;
  }
  LCD.cursPos(0,row);
  LCD.sendString(buffer);
  delay(time);
 }
}


