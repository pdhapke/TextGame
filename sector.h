//Peter Hapke 
//peterdhapke@gmail.com
//3/24/18
 
/* 
This code lays out the sector function declarations which will be a part of each individual sector. 
These functions run a different section of the story based on the step the story is on
*/

#pragma once
#ifndef SECTOR_H
#define SECTOR_H
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std; 
/* The following website link from stack overflow was very helpful in 
creating this pseudo morphic class of objects
https://stackoverflow.com/questions/5582869/how-do-i-store-a-function-to-a-variable
*/
//this is my favorite bit of code
class Sector {
	public:
		typedef bool (*FunctionPointer)(Sector*, Player*);  //returns a bool if the function executes properly
		bool run(Player *player){return runFunction(this, player);};
		int currentStoryStep;
		string description;
		Sector(FunctionPointer functionToRun) {runFunction = functionToRun; currentStoryStep = 0; run(new Player(true)); };
		vector<string> itemsInSector; 
		string listItemsInSector(); 
		bool dropItem(string); 
		bool pickUpItem(string); 
		bool hasItemInSector(string); 
		string eventItem; 
		
	private:
		FunctionPointer runFunction; 
};

//this is the template sector function which will be used as a base for all sectors
bool sec0RunFunction(Sector *sec, Player*);

//these are the used sector functions
bool sec1RunFunction(Sector *sec, Player*); 




#endif
