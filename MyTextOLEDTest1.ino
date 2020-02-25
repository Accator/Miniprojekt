#include <U8glib.h>

U8GLIB_SSD1306_128X64 oled(U8G_12C_OPT_NONE);

String line1 = "Hello World";

void setup() {
  oled.setFont(u8g_font_helvB10);
}

void loop() {
  oled.firstPage();
  do {
    draw();
  }while(oled.nextPage());
}

void draw(void) {
  oled.drawStr(0,0,line1);
}
