#include <U8glib.h>

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

char line1[] = "Do to do,";
char line2[] = "not to try!";

void setup() {
  oled.setFont(u8g_font_helvB10);
}

void loop(void) {
  oled.firstPage();
  do {
    draw();
  } while(oled.nextPage());
}

void draw(void) {
  int lineHeight = oled.getFontAscent()-oled.getFontDescent();

  int line1x = (oled.getWidth()-oled.getStrWidth(line1))/2;
  int line2x = (oled.getWidth()-oled.getStrWidth(line2))/2;
  
  oled.drawStr(line1x,lineHeight*2,line1);
  oled.drawStr(line2x,lineHeight*3,line2);
}
