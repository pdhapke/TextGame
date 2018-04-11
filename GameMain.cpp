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
bool GameMain::move(string direction){
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
string GameMain::displayMap(){
	stringstream output; 
	string markedMap = asciiMap; 
	output << "# Map #" << endl; 
	
	//find the right index number to change
	int index = 8; //the first row takes 8 characters and is the boundary of the map
	index = index + 1; //the map text string starts with a border pipe so add one
	index = index + x; //add the x coordinate of the player directly because it denotes columns
	index = index + 8*y; //add the y coordinate by adding the length of a row for each y index
	
	
	//change the character at the proper index to an x to mark the player position
	if(index < markedMap.size() && index >= 0){
		markedMap[index] = 'x'; 
	}
	
	//add the new map to the output
	output << markedMap; 
	return output.str(); 	
}; 

//this function loads the game map
void GameMain::loadWorld(){
	//the asciiMap that corresponds to this loaded world
	//this map is 8 characters wide and 6 tall, with an additional character 
	//added to the width by the endl command
	stringstream output; 
	
	//setup the story here so that the brief time the player is reading the computer can run a few lines and prepare the game
	cout << "Captain on the bridge!" << endl; 
	cout << "It seems we have a problem Captain " << player.name << ". " endl; 
	cout << "One of our crew, Private Huln, has been arrested for the murder of a Jovin trader." << endl; 
	cout << "It appears he was seen at the crime scence, the victims blood was found on his clothes,"
	cout << "and the weapon was bought with Terran currency." << endl
	cout << endl;
	cout << "If we are to mount a defense we will need to gather out own evidence." << endl;  
	cout << "Speaking with Private Huln it appears that he may have been set up. He can recall" << endl;		
	cout << "colliding with a Jovin, but says it was not the same one who was killed." << endl;  			//blood breadcrumb
	cout << "As a matter of fact he was speaking with a a Reon when the alleged attack too place." << endl; //alibi breadcrumb
	cout << "From the reports of the rest of the crew, it seems only three used Terran currency to" << endl; //payment breadcrumb
	cout << "make purchases during our shore leave. The items purchased were a transfer capacitor " << endl; //payment breadcrumb
	cout << "from a local Ulen, a subspace modulator from a nearby Jovin, and a phase columnator  " << endl; //payment breadcrumb
	cout << "from a passing Reon." << endl; 
		//give some space 
	cout << endl; 
	
	
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
	output << "|O*. .|" << endl; 
	output << "|....:|" << endl; 
	output << " ----- " << endl;

	asciiMap = output.str(); 
	
	//set the starting position
	x = 1 ;
 	y = 3 ;
	
	{
		//build all 25 of the sectors
		Sector sec1(sec1RunFunction); 
		Sector sec2(sec1RunFunction); 
		Sector sec3(sec1RunFunction); 
		Sector sec4(sec1RunFunction); 
		Sector sec5(sec1RunFunction); 
		Sector sec6(sec1RunFunction); 
		Sector sec7(sec1RunFunction); 
		Sector sec8(sec1RunFunction); 
		Sector sec9(sec1RunFunction); 
		Sector sec10(sec1RunFunction); 
		Sector sec11(sec1RunFunction); 
		Sector sec12(sec12RunFunction); 
		Sector sec13(sec1RunFunction); 
		Sector sec14(sec1RunFunction); 
		Sector sec15(sec1RunFunction); 
		Sector sec16(sec1RunFunction); 
		Sector sec17(sec1RunFunction); 
		Sector sec18(sec1RunFunction); 
		Sector sec19(sec1RunFunction); 
		Sector sec20(sec1RunFunction); 
		Sector sec21(sec1RunFunction); 
		Sector sec22(sec1RunFunction); 
		Sector sec23(sec1RunFunction); 
		Sector sec24(sec1RunFunction); 
		Sector sec25(sec1RunFunction); 
	
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
		row1.push_back(sec2);
		row1.push_back(sec3);
		row1.push_back(sec4);
		row1.push_back(sec5);
		
		//row2
		row2.push_back(sec6);
		row2.push_back(sec7);
		row2.push_back(sec8);
		row2.push_back(sec9);
		row2.push_back(sec10);
		
		//row3
		row3.push_back(sec11);
		row3.push_back(sec12); //this is the starting location
		row3.push_back(sec13);
		row3.push_back(sec14);
		row3.push_back(sec15);
		
		//row4
		row4.push_back(sec16);
		row4.push_back(sec17);
		row4.push_back(sec18);
		row4.push_back(sec19);
		row4.push_back(sec20);
		
		//row5
		row5.push_back(sec21);
		row5.push_back(sec22);
		row5.push_back(sec23);
		row5.push_back(sec24);
		row5.push_back(sec25);
	
		//push all the row sector vectors to the total map
		map.push_back(row1);
		map.push_back(row2);
		map.push_back(row3);
		map.push_back(row4);
		map.push_back(row5);
	}
	
	
}; 	
void GameMain::begin(){
	//run the game loop until the game is over
	while(!player.gameOver){
		displayMap(); 
		cout << "How would you like to proceed Captain?" << endl; 
		cout << "You can inspect the ships stores by typing- cargo" << endl; 
		cout << "You can revisit the current location by typing - land" << endl; 
		cout << "You can visit another sector of space by typing - warp" << endl; 
		cout << endl; 
		string courseOfAction = getAction(); 
		
		if (courseOfAction == "warp"){		
			cout << "Let the know helm which direction you want to travel by typing";		
			do(!move(getDirection("up, down, left, or right: "))){
				cout << "The sector in that direction is uncharted:" << endl; 
			}
			exploreSector(); 
		} else if(courseOfAction == "land"){
			exploreSector();
		} else if(courseOfAction == "cargo"){
			cout << player.viewInventory(); 
		}
	
		
	}


			

}


