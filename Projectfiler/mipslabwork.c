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
#define ORIGINX 8
#define ORIGINY 16

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
  main2();

}


int main2(argc, const char *argv[]) {
	//Display "Are you ready?"
	game();
	//Display "Play again?"
	return 1;
}
void game(){
	//Om spelaren lever 1, om inte 0
	int *alive;
	*alive = 1;
	//Spelarens position i x-led
	int *x;
	*x = ORIGINX;
	//Spelarens position i y-led
	int *y;
	*y = ORIGINY;
	int btns;

	while (alive) {
		//Få in knapptryck
		btns = getbtns();
		//Kolla om spelaren ska flytta sig, om spelaren dött etc
		updateGameState(btns);
		//Rita på displayen
		draw();
		delay(200);
	}
}
void updateGameState(int btns){
	if (btns == 1){
		*x++;
	}
	if (btns == 2){
		*x--;
	}
	if (btns == 3){
		*y++;
	}
	if (btns == 4){
		*y--;
	}
	if (*x >= 16|| *x <= 0|| *y >= 32|| *y <= 0){
		*alive = 0;
	}
}
void draw(){
	
}






