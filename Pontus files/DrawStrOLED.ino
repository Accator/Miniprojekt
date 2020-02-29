#include <U8glib.h>

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

void setup() {
  

}

void loop(void) {
  oled.firstPage();
  do {
    draw();
  } while(oled.nextPage());
}

void draw(void) {
  oled.drawPixel(11,44);
  oled.drawPixel(13,44);

  oled.drawLine(12,28,12,60);
  oled.drawLine(12,60,128,60);
  oled.drawLine(12,60,128,30);

  oled.setFont(u8g_font_helvB10);

  oled.drawStr(0,10, "My Arduino");
  oled.drawStr(0,23, "knowledge");
  oled.drawStr(0,60,"0");
  oled.drawStr(0,40,"1");
}
