#include <stint.h>
#include <pic32mx.h>
#include <"mipslab.h">

#define ORIGINX 8
#define ORIGINY 16

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