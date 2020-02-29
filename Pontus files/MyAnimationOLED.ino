#include <U8glib.h>

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

int n;
float pi = 3.1415926535897;
float fourPi;

void setup() {
    fourPi = 4*pi;
}

void loop(void) {
  oled.firstPage();
  do {
    draw();
  } while(oled.nextPage());
  n++;
}

void draw(void) {
  oled.drawLine(20*cos(n/fourPi)+63,20*sin(n/fourPi)+31,
  -20*cos(n/fourPi)+63,-20*sin(n/fourPi)+31);
}
