/* mipslabwork.c
   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall
   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):
   This file modified 2017-04-31 by Ture Teknolog 
   For copyright and licensing, see file COPYING */
#include <stdio.h>
#include <stdlib.h>
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

void p0(){
	display_image(0, whiteBox);
	display_image(32, blackBox);
	display_image(64, blackBox);
	display_image(96, blackBox);
}
void p1(){
	display_image(0, blackAndWhiteBox);
	display_image(32, whiteAndBlackBox);
	display_image(64, blackBox);
	display_image(96, blackBox);
}
void p2(){
	display_image(0, blackBox);
	display_image(32, whiteBox);
	display_image(64, blackBox);
	display_image(96, blackBox);
}
//mitten
void pmid(){
	display_image(0, blackBox);
	display_image(32, blackAndWhiteBox);
	display_image(64, whiteAndBlackBox);
	display_image(96, blackBox);
}
void p3(){
	display_image(0, blackBox);
	display_image(32, blackBox);
	display_image(64, whiteBox);
	display_image(96, blackBox);
}
void p4(){
	display_image(0, blackBox);
	display_image(32, blackBox);
	display_image(64, blackAndWhiteBox);
	display_image(96, whiteAndBlackBox);
}
void p5(){
	display_image(0, blackBox);
	display_image(32, blackBox);
	display_image(64, blackBox);
	display_image(96, whiteBox);
}
// Highscore list
void insertHighscore(int t){


}
//Klockan
void timer(){


}

//highscore screen
void highScoreScree(){


}




void game(){
	// 0 till 4 positione
	int x = 3; //Declares x variable
	int* px; // Declares x1 pointer
	px = &x;

	int y = 16; //Declares y variable
	int* py; // Declares y1 pointer
	py = &y;

	int alive = 1; //Declares alive variable
	int* pa; // Declares alive1 pointer
	pa = &alive;

	pmid();
	int i = 0;

	static const int array[32] = {2,1,2,2,-2,-2,-1,-1,2,1,1,2,2,1,1,-1,1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1};
	while (alive) {
		//Få in knapptryck
		int btns = getbtns432();
		int btns1 = getbtns1();
		switch (x)
		{
		case 0:
			p0();
			break;
		case 1:
			p1();
			break;
		case 2:
			p2();
			break;
		case 3:
			pmid();
			break;
		case 4:
			p3();
			break;
		case 5:
			p4();
			break;
		case 6:
			p5();
			break;
		default:
			break;
		}
	if (btns1 == 1){
		*px = *px + 1;		
	}
	if (btns == 1){
		*px = *px - 1;
	}
	if (btns == 2){
		*py = *py + 1;
	}

	if (*px > 6|| *px < 0){
		*pa = 0;
	}
	*px = *px + array[i];
	i++;
	if( i == 32)
		i = 0;
	delay(1);

}


}
void gameOver(){
	int l = 1;
	while(l){
		int btns = getbtns432();
		int btns1 = getbtns1();
		display_string(0, "GG, you died ");
		display_string(1, "Reset game ");
		display_string(2, "Press 4");
		display_string(3, "Noob");
		display_update();
		if (btns == 4)
			l = 0;	
	}
}

void labwork( void )
{

  game();
  gameOver();
}
