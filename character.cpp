//Peter Hapke 
//peterdhapke@gmail.com
//3/24/18

/* 
This section complete the class definition of the player object  and adds the 
functions which access and display the player inventory
*/

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std; 
bool Player::hasItem(string item){
	for (int i = 0; i < inventory.size(); i++){
		if (inventory[i] == item){
			return true; 
		}
	}
	return false; 
}

bool Player::addItem(string item){
	inventory.push_back(item);
} 
bool Player::removeItem(string item){
	if(hasItem(item)){
		for (int i = 0; i < inventory.size(); i++){
		if (inventory[i] == item){
			inventory.erase(inventory.begin() + i);
			return true; 
		}
	}
	}
	return false; 
}
string Player::viewInventory(){
	stringstream output; 
	for (int i = 0; i < inventory.size(); i++){
		output << i + 1 << ".) " << inventory[i] << endl; 
	}
	return output.str(); 	
}

Player::Player(){
	string confirm; 
	bool isName = false; 
	
	inventory.push_back("Starting Equipment");
	inventory.push_back("pick");
	
		cout << "What is your name? : ";
	
	do{
		getline(cin, name); 
		
		cout << "Is your name " << name << "? Enter yes to confirm: ";
		getline(cin, confirm); 
		
		if (confirm == "yes"){
			cout << "Great then we can get started" << endl; 
			isName = true; 
		} else {
			cout << "Okay....I will ask again then." << endl; 
			cout << "What is REALLY your name? : "; 
		}
		
		
		
	}while(!isName);
	
	
}
Player::Player(bool emptyplayer){
}; 
