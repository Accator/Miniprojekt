#include <MPU6050.h>
#include <Wire.h>
#include "SoftwareSerial.h"
#include <time.h>
#include <U8glib.h>
SoftwareSerial mySerial(10, 11);
# define Start_Byte 0x7E
# define Version_Byte 0xFF
# define Command_Length 0x06
# define End_Byte 0xEF
# define Acknowledge 0x00 //Returns info with command 0x41 [0x01: info, 0x00: no info]
# define Track 0x03
# define ACTIVATED LOW
# define DEACTIVATED HIGH

U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

const int MPU=0x68;
int16_t AcX1,AcY1,AcZ1,GyX1,GyY1,GyZ1;
int16_t AcX2,AcY2,AcZ2,GyX2,GyY2,GyZ2;

int volume = 15;
int r;

bool doneRandomOnce, doneMP3Once = false;

String line1 = "This is my";
String line2 = "personal";
String line3 = "user interface";

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  mySerial.begin(9600);
  setVolume(volume);
  srand(time(NULL));
  oled.setFont(u8g_font_helvB10);
}

void loop(){
  oled.firstPage();
  do {
    draw();
  } while(oled.nextPage());
  
  AcX2=AcX1;
  AcY2=AcY1;
  AcZ2=AcZ1;
  GyX2=GyX1;
  GyY2=GyY1;
  GyZ2=GyZ1;
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);
  AcX1=Wire.read()<<8|Wire.read();
  AcY1=Wire.read()<<8|Wire.read();
  AcZ1=Wire.read()<<8|Wire.read();
  GyX1=Wire.read()<<8|Wire.read();
  GyY1=Wire.read()<<8|Wire.read();
  GyZ1=Wire.read()<<8|Wire.read();
  if (digitalRead(4)==DEACTIVATED) {
    if ((abs(AcX1-AcX2)>5000 || abs(AcY1-AcY2)>5000 || abs(AcZ1-AcZ2)>5000)&&(AcX2!=0&&AcY2!=0&&AcZ2!=0) || doneRandomOnce==false) {
      /*if (doneRandomOnce=false) {
        r = rand() % 13;
      }
      doneRandomOnce=true;
      if (AcX2!=0&&AcY2!=0&&AcZ2!=0) {
        execute_CMD(Track,0,r);
        do {
          delay(500);
        } while (digitalRead(4)==ACTIVATED);
        r = rand() % 13;
      }*/
      if (doneRandomOnce==true) {
        execute_CMD(Track,0,r);            //MP3
        r = rand() % 13;
      }
      while (digitalRead(4)==ACTIVATED) {  //Wait MP3 Done
        line2="";
        line3="";
        switch (r) {
          case 1:
            line1="I was pure once";
            break;
          case 2:
            line1="Fought for";
            line2="righteousness";
            break;
          case 3:
            line1="I was called";
            line2="Ashbringer";
            break;
          case 4:
            line1="Betrayed by my";
            line2="order";
            break;
          case 5:
            line1="Destroyed by";
            line2="Kel'Thuzad";
            break;
          case 6:
            line1="Made to server";
            break;
          case 7:
            line1="My son watched";
            line2="me die";
            break;
          case 8:
            line1="Crusade felt";
            line2="his rage";
            break;
          case 9:
            line1="Truth is unknown";
            line2="to him";
            break;
          case 10:
            line1="Scarlet crusade";
            line2="is pure no longer";
            break;
          case 11:
            line1="Balnazzar's";
            line2="crusade";
            line3="corrupted my son";
            break;
          case 12:
            line1="KILL THEM ALL";
            break;
          default:
            line1="This should never";
            line2="be displayed";
            break;
        }
        delay(500);
      }
      if (doneRandomOnce==false) {         //r
        r = rand();
        r = rand() % 13;
        doneRandomOnce=true;
      }
      line2="";
      line3="";
      switch (r) {
        case 1:
          line1="I was pure once";
          break;
        case 2:
          line1="Fought for";
          line2="righteousness";
          break;
        case 3:
          line1="I was called";
          line2="Ashbringer";
          break;
        case 4:
          line1="Betrayed by my";
          line2="order";
          break;
        case 5:
          line1="Destroyed by";
          line2="Kel'Thuzad";
          break;
        case 6:
          line1="Made to server";
          break;
        case 7:
          line1="My son watched";
          line2="me die";
          break;
        case 8:
          line1="Crusade felt";
          line2="his rage";
          break;
        case 9:
          line1="Truth is unknown";
          line2="to him";
          break;
        case 10:
          line1="Scarlet crusade";
          line2="is pure no longer";
          break;
        case 11:
          line1="Balnazzar's";
          line2="crusade";
          line3="corrupted my son";
          break;
        case 12:
          line1="KILL THEM ALL";
          break;
        default:
          line1="This should never";
          line2="be displayed";
          break;
      }
    }
  }
  delay(500);
}

void draw() {
  int lineHeight = oled.getFontAscent()-oled.getFontDescent();
  int line1x = (oled.getWidth()-oled.getStrWidth(line1.c_str()))/2;
  int line2x = (oled.getWidth()-oled.getStrWidth(line2.c_str()))/2;
  int line3x = (oled.getWidth()-oled.getStrWidth(line3.c_str()))/2;
  oled.drawStr(line1x,lineHeight*2,line1.c_str());
  oled.drawStr(line2x,lineHeight*3,line2.c_str());
  oled.drawStr(line3x,lineHeight*4,line3.c_str());
  oled.drawLine(10,10,20,20);
}

void setVolume(int volume)
{
  execute_CMD(0x06, 0, volume); // Set the volume (0x00~0x30)
  delay(500);
}

void execute_CMD(byte CMD, byte Par1, byte Par2)
// Excecute the command and parameters
{
  // Calculate the checksum (2 bytes)
  word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
  // Build the command line
  byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge,
  Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte};

  //Send the command line to the module
  for (byte k=0; k<10; k++) {
    mySerial.write(Command_line[k]);
  }
}
