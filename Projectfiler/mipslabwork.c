/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

volatile int* _TRISE = (volatile int*)0xbf886100;
volatile int* _PORTE = (volatile int*)0xbf886110;

int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  *_TRISE &= ~0xff;
  TRISDSET = 0x0fe0;
 
}

/* This function is called repetitively from the main program */
void labwork( void )
{

	int btns = getbtns();

	if (btns) {
		int swt = getsw();
		if (btns & 0x1)
            mytime = (mytime & 0xff0f) | (swt << (1 * 4));
		if (btns & 0x2)
			mytime = (mytime & 0xf0ff) | (swt << (2 * 4));
		if (btns & 0x4)
			mytime = (mytime & 0x0fff) | (swt << (3 * 4));

  } 
  delay( 1000 );
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );
  display_image(96, icon);

  (*_PORTE)++;

}




int btns = getbtns();



//B1
if (btns & 0x1){

}
//B2
if (btns & 0x2){

}
//B3
if (btns & 0x3){

}
//B4
if (btns & 0x4){

}



int menu(void) {

    int game_started = 0;
    display_string(0, "Are you ready?!");
    display_string(1, "");
    display_string(2, "");
    display_string(3, "Press BTN 0 to start");
    display_update();

    for (;;) {
        int btn = getbtns();
        int sw = getsw();

        if (btns & 0x4) {
            game(); //Hoppa till spelet
        }
    }
}