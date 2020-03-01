/* mipslabwork.c
   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall
   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):
   This file modified 2017-04-31 by Ture Teknolog 
   For copyright and licensing, see file COPYING */
#include <stdio.h>
#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
#include <math.h>
//#define ORIGINX 8
//#define ORIGINY 16



/*
int *alive;
&alive = 1;
int *x;
&x = ORIGINX;
int *y;
&y = ORIGINY;
*/

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

void draw(){
	
}


void updateGameState(int btns, int btns1, int* px,int* py,int* pa){
	if (btns1 == 1){
		*px = *px + 1;		
	}
	if (btns == 1){
		*px = *px - 1;
	}
	if (btns == 2){
		*py = *py + 1;
	}
	if (btns == 4){
		*py = *py - 1;

	}
	if (*px >= 128|| *px <= 0|| *py >= 32|| *py <= 0){
		*pa = 0;
	}
}





void game(){
	// 0 till 4 positioner
	int x = 2; //Declares x variable
	int* px; // Declares x1 pointer
	px = &x;

	int y = 16; //Declares y variable
	int* py; // Declares y1 pointer
	py = &y;

	int alive = 1; //Declares alive variable
	int* pa; // Declares alive1 pointer
	pa = &alive;

	display_image(0, whiteBox);
	display_image(32, blackAndWhiteBox);
	display_image(64, whiteAndBlackBox);
	display_image(96, blackBox);

	

	while (alive) {
		//Få in knapptryck
		int btns = getbtns432();
		int btns1 = getbtns1();
	}
}

void labwork( void )
{
  game();

}
