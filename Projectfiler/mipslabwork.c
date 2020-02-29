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


void updateGameState(int btns, int btns1, int *x,int *y,int *alive){
	if (btns1 == 1){
		//display_string(2,"hej 1");
		(*x)++;
		display_update();
		
	}
	if (btns == 1){
		//display_string(2,"hej 2");
		(*x)--;
		display_update();
	}
	if (btns == 2){
		(*y)++;
		//display_string(2,"hej 3");
		display_update();

	}
	if (btns == 4){
		//display_string(2,"hej 4");
		(*y)--;
		display_update();
	}
	if (*x >= 16|| *x <= 0|| *y >= 32|| *y <= 0){
		(*alive) = 0;
	}
}


void setPixel(int x, int y) {
	int box = x/32;
	int block = y/8;
	int kollumn = x%32-1;
	int row = y%8-1;
	//Vi kommer behöva två midBox:es, annars kommer
	//pixeln kopieras in på båda
	switch (box) {
		case 0:
			startBox[block*32+kollumn] -= pow(2,row);
			break;
		case 1:
			midBoxOne[block*32+kollumn] -= pow(2,row);
			break;
		case 2:
			midBoxTwo[block*32+kollumn] -= pow(2,row);
			break;
		case 3:
			endBox[block*32+kollumn] -= pow(2,row);
			break;
	}
}

void game(){
	int x1 = 8; //Declares x variable
	int *x; // Declares x1 pointer
	x = &x1;

	int y1 = 16; //Declares y variable
	int* y; // Declares y1 pointer
	y = &y1;

	int alive1 = 1; //Declares alive variable
	int* alive; // Declares alive1 pointer
	alive = &alive1;

	while (alive) {
		//Få in knapptryck
		int btns = getbtns432();
		int btns1 = getbtns1();
		//Kolla om spelaren ska flytta sig, om spelaren dött etc
		updateGameState(btns,btns1,x ,y ,alive);
		//Rita på displayen
		draw();
		delay(100);
	}
}
int main2() {
	//Display "Are you ready?"
	game();
	//Display "Play again?"
	return 1;
}

void labwork( void )
{
  main2();

}






