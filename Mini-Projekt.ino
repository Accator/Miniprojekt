//Accelerometer
#include <MPU6050.h>
#include<Wire.h>
//OLED screen
#include "SoftwareSerial.h"
#include <time.h>
#include <U8glib.h>
SoftwareSerial mySerial(10, 11);
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int16_t OriginX;
int16_t OriginY;
int16_t OriginZ;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);
  oled.setFont(u8g_font_helvB10);

  //Begin accelerometer transmission
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);
  
  //Set initial position
  OriginX = Wire.read()<<8|Wire.read();
  OriginY = Wire.read()<<8|Wire.read();
  OriginZ = Wire.read()<<8|Wire.read();
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);
  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();

  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ); 
  
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");

  //Rita
  oled.firstPage();
  do {
    draw();
  } while(oled.nextPage());

  delay(1000);

}

void draw() {
  oled.drawStr(10,10,"Hej");
  oled.drawLine(10,10,20,20);
  oled.drawBox((AcX-OriginX)/1000+64,(AcY-OriginY)/1000+32,5,5);
}
