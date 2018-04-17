//Peter Hapke 
//peterdhapke@gmail.com
//3/24/18

/* 
This is the main program for a simple text based game 

it contains two functions, one that runs tests and the other that actually runs the game
I did this so I could gradually test pieces and switch out the code the main function runs
more easily
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <string>


#include <fstream>
#include <ctime>
#include <math.h>
#include "helpfulfunctions.h"
#include "character.h"
#include "character.cpp"
#include "sector.h"
#include "sector.cpp"
#include "helpfulfunctions.cpp"
#include "GameMain.h"
#include "GameMain.cpp"

using namespace std; 

void testGame(); 
void runGame();


int main(int argc, char** argv) {
	runGame(); 
	return 0; 
}

//testing main
void testGame(){
//used while I was testing granular functions and interfaces
	
}

void runGame(){
	mainScreen(); 
	GameMain game; 
	game.begin();
	
}

