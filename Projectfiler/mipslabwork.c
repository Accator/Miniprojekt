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


void setPixel(int x, int y) {
	int box = x/32;
	int block = y/8;
<<<<<<< HEAD
	int kollumn = x%32;
	int row = y%8;
=======
	int kollumn = x%32-1;
	int row = x%8-1;
	//Vi kommer behöva två midBox:es, annars kommer
	//pixeln kopieras in på båda


>>>>>>> b1851fe64d907516b2a6e9abbbfb8d933c7abb49
	switch (box) {
		case 0:
			startBox[block*32+kollumn] | ~(1 << row);

			break;
		case 1:
			midBoxOne[block*32+kollumn] | ~(1 << row);

			break;
		case 2:
			midBoxTwo[block*32+kollumn] | ~(1 << row);
			break;
		case 3:
			endBox[block*32+kollumn] | ~(1 << row);
			break;
<<<<<<< HEAD
		default:
			break;
=======

>>>>>>> b1851fe64d907516b2a6e9abbbfb8d933c7abb49
	}
}

void game(){
	int x = 64; //Declares x variable
	int* px; // Declares x1 pointer
	px = &x;

	int y = 16; //Declares y variable
	int* py; // Declares y1 pointer
	py = &y;

	int alive = 1; //Declares alive variable
	int* pa; // Declares alive1 pointer
	pa = &alive;


	

	while (alive) {
		//Få in knapptryck
		int btns = getbtns432();
		int btns1 = getbtns1();
		setPixel(*px,*py);
		//Kolla om spelaren ska flytta sig, om spelaren dött etc
		updateGameState(btns,btns1, px , py , pa);

		display_image(0, startBox);
		display_image(32, midBoxOne);
		display_image(64, midBoxTwo);
		display_image(96, endBox);
		delay(1000);
		
	}
}

void labwork( void )
{
  game();

}
