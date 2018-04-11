//Peter Hapke 
//peterdhapke@gmail.com
//3/24/18

/* 
This code lays out the sector and map classes so that a world map can be built using sector pieces in a 2-d vector
each sector piece would give all the scenario and code needed for that particular location, helping to modularize the pieces. 
This allows the pieces to be randomly distributed later (if I have time) and the vector nature allows the size of the map
to change without having to go back and change the variable type

finally the world constructor function calls the load world funtion so that different base contructors can be swapped out
later to allow for save games to be implemented. 
*/

#pragma once
#ifndef MAP_H
#define MAP_H
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "character.h"
#include "character.cpp"
#include "sector.h"
#include "sector.cpp"

using namespace std; 

/* The following website link from stack overflow was very helpful in 
creating this pseudo morphic class of objects
https://stackoverflow.com/questions/5582869/how-do-i-store-a-function-to-a-variable
*/
//this is my favorite bit of code



class Sector {
	public:
		typedef bool (*FunctionPointer)(Sector*);  //returns a bool if the function executes properly
		bool run(){return runFunction(this);};
		int currentStoryStep;
		string description;
		Sector(FunctionPointer functionToRun) {runFunction = functionToRun; currentStoryStep = 0; run(); };
	private:
		FunctionPointer runFunction; 
};

class GameMain {
	public:
		vector<vector<Sector> >  map;
		Player player; 
		bool move(string); 
		string displayMap(); 
		bool exploreSector(){return map[y][x].run();}; 
		World(){
			loadWorld();
			
		}; 
	private:
		int x; 
		int y; 
		string asciiMap;
		void loadWorld(); 	
};

#endif
