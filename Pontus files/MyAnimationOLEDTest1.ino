#include <U8glib.h>

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

int n;

void setup() {
    
}

void loop(void) {
  oled.firstPage();
  do {
    draw();
  } while(oled.nextPage());
  n++;
}

void draw(void) {
  oled.drawLine(20*cos(n/12)+63,20*sin(n/12)+31,
  -20*cos(n/12)+63,-20*sin(n/12)+31);
}
