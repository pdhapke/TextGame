//Peter Hapke 
//peterdhapke@gmail.com
//3/24/18

/* 
This code is the main code for the game and details the story for each sector
of the map individually. 
*/

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std; 

//this is the template sector function which will be used as a base for all sectors
bool sec0RunFunction(Sector *sec, Player* player){
	bool success = true; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			sec->description = "Default Story";
		
		break; 
		case 1:
			cout << sec->description; 
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
};

//these are the used sector functions
bool sec1RunFunction(Sector *sec, Player* player){
	bool success = true; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			sec->description = "Default Story";
			
		break; 
		case 1:
			cout << sec->description << endl; 
			cout << "The current player name is: " << player->name; 
			
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

