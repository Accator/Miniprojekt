#include <U8glib.h>

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

int frame, startFrame, endFrame;
const int spinnerSize = 8;
const int spinnerX = 32;
const int spinnerY = 16;
const int frameSkip = 3; // The speed of animation
const int frameSkipSpinner = 2; //
const float pi = 3.1415926535897;

void setup() {
    startFrame = 0; // What frame to start the animation on, will be considered 0 if above 127
    frame = startFrame;
    endFrame = 127+startFrame;
}

void loop(void) {
  oled.firstPage();
  do {
    draw();
  } while(oled.nextPage());
  frame = frame + frameSkip;
  if (frame>=endFrame) {
    frame = startFrame;
  }
}

void draw() {
  //Spinner
  oled.drawLine(spinnerSize*cos(frame/pi)+spinnerX,spinnerSize*sin(frame/pi)+spinnerY,
  -spinnerSize*cos(frame/pi)+spinnerX,-spinnerSize*sin(frame/pi)+spinnerY);
  oled.drawLine(frame,48,frame+32,48);
  
  //Line
  if (frame>96&&frame<=128) {
    oled.drawLine(0,48,frame-96,48);
  }
  if (frame>128&&frame<=128+startFrame) {
    oled.drawLine(frame-128,48,frame-96,48);
  }
  
  //Long diagonal line above
  oled.drawLine(frame,32,frame+16,48);
  if (frame>112&&frame<=128) {
    oled.drawLine(0,48+112-frame,frame-112,48);
  }
  if (frame>128) {
    oled.drawLine(frame-128,32,frame-112,48);
  }
  
  //Long diagonal line below
  oled.drawLine(frame,64,frame+16,48);
  if (frame>112&&frame<=128) {
    oled.drawLine(0,48-112+frame,frame-112,48);
  }
  if (frame>128) {
    oled.drawLine(frame-128,64,frame-112,48);
  }
  
  //Short diagonal line above
  oled.drawLine(frame+24,40,frame+32,48);
  if (frame>96&&frame<=104) {
    oled.drawLine(0,48+96-frame,frame-96,48);
  }
  if (frame>104&&frame<=128+startFrame) {
    oled.drawLine(-104+frame,40,-104+8+frame,48);
  }
  
  //Short diagonal line below
  oled.drawLine(frame+24,56,frame+32,48);
  if (frame>96&&frame<=104) {
    oled.drawLine(0,48-96+frame,frame-96,48);
  }
  if (frame>104&&frame<=128+startFrame) {
    oled.drawLine(-104+frame,56,-104+8+frame,48);
  }
}
