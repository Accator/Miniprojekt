#include <U8glib.h>

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

int a, c, d, frame,totalFrames;
float pi = 3.1415926535897;
float one = 12; // if datatype is float, will run smoothly,
                // if datatype is int, will severely lower framerate

void setup() {
    frame = 0;
    totalFrames = 128;
}

void loop(void) {
  oled.firstPage();
  do {
    draw();
  } while(oled.nextPage());
  a++;
  frame++;
  if (frame>96&&frame<=160) {
    d++;
    if (frame>128&&frame<=160) {
      c++;
    }
  }
  if (frame>127) {
    c, d = 0;
  }
  if (frame>127) {
    //For whatever reason frame has to be assigned 0 after c and d
    frame = 0;
  }
}

void draw(void) {
  oled.drawLine(20*cos(a/one)+63,20*sin(a/one)+31,
  -20*cos(a/one)+63,-20*sin(a/one)+31);
  oled.drawLine(frame,48,frame+32,48);
  if (frame>96) {
    oled.drawLine(c,48,d,48);
  }
}
