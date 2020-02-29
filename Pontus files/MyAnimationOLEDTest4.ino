#include <U8glib.h>

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

int a, b;
float pi = 3.1415926535897;
float one = 12; // if datatype is float, will run smoothly,
                // if datatype is int, will severely lower framerate
float fourPi;

void setup() {
    fourPi = 4*pi;
}

void loop(void) {
  oled.firstPage();
  do {
    draw();
  } while(oled.nextPage());
  a++;
  b++;
  if (b>=20) {
    b = 0;
  }
}

void draw(void) {
  oled.drawLine(20*cos(a/one)+63,20*sin(a/one)+31,
  -20*cos(a/one)+63,-20*sin(a/one)+31);
  if (b<=20) {
    oled.drawLine(31+b,47,63+b,47);
  }
}                                          
