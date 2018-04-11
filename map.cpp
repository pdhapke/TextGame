//Peter Hapke 
//peterdhapke@gmail.com
//3/24/18

/* 
This code fills in the details of the map and sector class definitions.
It then creates the map by building all of the sector objects and placing
them in the map 2-d vector
*/

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std; 

//this function takes a directional text and then moves a player along accordingly
//error checking for direction is done by returning a boolean value if it is a valid direction
//and the position was updated 
bool World::move(string direction){
	bool validDirection = false; 
	
	if(direction == "up"){
		if ((y - 1) < 0){
			validDirection = false; 
		} else {
			y--; 
			validDirection = true;
		}
	} else if (direction == "down"){
		if ((y + 1) >= map.size()){
			validDirection = false; 
		} else {
			y++; 
			validDirection = true;
		}
	} else if (direction == "left"){
		if ((x - 1) < 0){
			validDirection = false; 
		} else {
			x--; 
			validDirection = true;
		} 	
	} else if (direction == "right"){
	if ((x + 1) > map[0].size()){
			validDirection = false; 
		} else {
			x++; 
			validDirection = true;
		}	
	}	
	return validDirection; 
}; 

//displays the map as a an ASCII art picture for the user, with the users position marked with an x
string World::displayMap(){
	stringstream output; 
	string markedMap = asciiMap; 
	output << "# Map #" << endl; 
	
	//find the right index number to change
	int index = 8; //the first row takes 8 characters and is the boundary of the map
	index = index + 1; //the map text string starts with a border pipe
	index = index + x; //add the x coordinate of the player directly because it denotes columns
	index = index + 8*y; //add the y coordinate by adding the length of a row for each y index
	index = index - 1; //subtract one because indexes start at 0 and not 1
	
	//change the character at the proper index to an x to mark the player position
	if(index < markedMap.size() && index >= 0){
		markedMap[index] = 'x'; 
	}
	
	//add the new map to the output
	output << markedMap; 
	return output.str(); 	
}; 

//this function loads the game map
void World::loadWorld(){
	//the asciiMap that corresponds to this loaded world
	//this map is 8 characters wide and 6 tall, with an additional character 
	//added to the width by the endl command
	stringstream output; 
	
	
	//this is the base map look as ascii art, it will not work because
	//the unicode character is not recognized, the following code converts this map
	//to the proper form for the compiler
	/*
	output << " _____ " << endl; 
	output << "|'.o..|" << endl; 
	output << "|....~|" << endl; 
	output << "|Oº. .|" << endl; 
	output << "|....:|" << endl; 
	output << " ¯¯¯¯¯ " << endl; 
	*/
	output << " _____ " << endl; 
	output << "|'.o..|" << endl; 
	output << "|....~|" << endl; 
	output << "|O\u000000B0. .|" << endl; 
	output << "|....:|" << endl; 
	output << " \u0000203E\u0000203E\u0000203E\u0000203E\u0000203E " << endl;
	
	asciiMap = output.str(); 
	
	//set the starting position
	x = 1 ;
 	y = 3 ;
	
	{
		//build all 25 of the sectors
		Sector sec1(sec1RunFunction); 
	
		//TODO
	
	
		//setup the row sector vectors
		vector<Sector> row1;
		vector<Sector> row2;
		vector<Sector> row3;
		vector<Sector> row4;
		vector<Sector> row5;
	
	
		//build the row sector vectors
		//row1
		row1.push_back(sec1);
		row1.push_back(sec1);
		row1.push_back(sec1);
		row1.push_back(sec1);
		row1.push_back(sec1);
		
		//row2
		row2.push_back(sec1);
		row2.push_back(sec1);
		row2.push_back(sec1);
		row2.push_back(sec1);
		row2.push_back(sec1);
		
		//row3
		row3.push_back(sec1);
		row3.push_back(sec1);
		row3.push_back(sec1);
		row3.push_back(sec1);
		row3.push_back(sec1);
		
		//row4
		row4.push_back(sec1);
		row4.push_back(sec1);
		row4.push_back(sec1);
		row4.push_back(sec1);
		row4.push_back(sec1);
		
		//row5
		row5.push_back(sec1);
		row5.push_back(sec1);
		row5.push_back(sec1);
		row5.push_back(sec1);
		row5.push_back(sec1);
	
	
	
		//push all the row sector vectors to the total map
		map.push_back(row1);
		map.push_back(row2);
		map.push_back(row3);
		map.push_back(row4);
		map.push_back(row5);
	}
	
	
}; 	
