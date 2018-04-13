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

//complete item list
/*

Various spare parts
Warp drive
Bloody clothing sample 		> 	Contact info for Cree  >  Blood - blood sample from Cree
Lead on the Parvc 	> 	Letter of Introdocuton to Liool 	> 	Alibi -  witness statement
Terran Arms dealer passphrase >  Evidence - Terran currency
Memory crystal
Enhanced Sensors
Enhanced Shields
Beam Cannon
Precious metals
Translation Device
Recorded dark energy data

*/
string Sector::listItemsInSector(){
	stringstream output; 
	if(itemsInSector.size() != 0){
		for (int i = 0; i < itemsInSector.size(); i++){
			output << i + 1 << ".) " << itemsInSector[i] << endl; 
		}
	} else {
		output << "...nothing" << endl; 
	}
	return output.str(); 
}
bool Sector::dropItem(string item){
	itemsInSector.push_back(item);
}
bool Sector::hasItemInSector(string item){
		for (int i = 0; i < itemsInSector.size(); i++){
			if (itemsInSector[i] == item){
				return true; 
			}
	}
	return false; 
}
bool Sector::pickUpItem(string item) {
		if(hasItemInSector(item)){
			for (int i = 0; i < itemsInSector.size(); i++){
				if (itemsInSector[i] == item){
					itemsInSector.erase(itemsInSector.begin() + i);
					return true; 
				}
			}
		}
	return false; 
}

//this is the template sector function which will be used as a base for all sectors
//all functions are named with two digits so that they function list will display them in order for faster access
bool sec00RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = output.str(); 
		
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
};

//these are the used sector functions




//sector 1
bool sec01RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "This empty save for the sole commet traveling through interstellar space. Here on the edge of the charted territories there is very little in the way of life. Though peacful it is best to get back to finding evidence of Huln's innocence."; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 2
bool sec02RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 3
bool sec03RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "This sector lies on the edge of established space. Most of the worlds here are inhabited by homesteaders and farmers. Each world boasts a new and exotic commodity, usually the reason the planet was settled in the first place.";  
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			
			if(player->hasItem("Lead on the Parvc")){
				
				cout << wordWrap("Captain there are no signs of a Parvc ship, it looks like this is as far as our lead takes us.") <<endl; 
				string choice = getAction("investigate", "leave"); 
			
				if (choice == "investigate"){
					
					cout << wordWrap("Sir, there is a response from the nearby planet. It seems they have seen a Parvc ship but it left suddenly. Apparently the Captain, Looil, had a a reaction to the local flora and needed medical attention. The planet is willing to give us a letter of introduction if we make sure the Parvc captain doesn't mark the planet as inhospitable to the guilds.") << endl; 
					player->removeItem("Lead on the Parvc"); 
					player->addItem("Letter of Introdocuton to Liool");
					sec->currentStoryStep++; 
				}
			}
			
						
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
			cout << sec->description << endl; 
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 	
	}
	
	return success; 
}; 

//sector 4
bool sec04RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story";  
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 5
bool sec05RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 6
bool sec06RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	string choice;
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "This sector is known for the psychics and memory transfer devices loved by the Ulen"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			cout << wordWrap("This would be a great place to obtain a memory crystal from Private Huln, perhaps it can help in his defense. There are several communications asking if we are looking to buy. What should we do Captain?")<<endl; 			 	
				choice = getAction("buy", "leave"); 
			
				if (choice == "buy"){
					
					cout << wordWrap("A memory crystal of a possible crime? I would be happy to help! Perhaps you will even tell your friends yes? Here, here, lets get started.") << endl; 
					cout << ".."<< endl; 
					cout << "..."<< endl; 
					cout << "...."<< endl; 
					cout << wordWrap("Your crystal is ready! Thank you for the business.")<<endl; 
					 
					player->addItem("Memory crystal");
					sec->currentStoryStep++; 
				}
			 	
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
				cout << sec->description << endl; 
				cout << "--Press any key to continue--" <<endl;
				cin.get();
		break; 	
	}
	
	return success; 
}; 

//sector 7
bool sec07RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "The sector is strangely quite. It looks like any other sector but the communications traffic is absent..."; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
		//	 >  
			cout << sec->description << endl; 
			if (player->hasItem("Terran Arms dealer passphrase")){
			 	cout << wordWrap("This looks like a place an arms dealer would frequent, we have a passphrase that might draw their attention. What should we do Captain?") <<endl; 
			 	
				 string choice = getAction("broadcast", "leave"); 
			
				if (choice == "broadcast"){
					
					cout << wordWrap("Captain there is a large ship headed our direction! They are asking us what we want to purchase!") << endl; 
					cout << ".."<< endl; 
					cout << "..."<< endl; 
					cout << "...."<< endl; 
					cout << wordWrap("I see, you want to gather evidence to help your crewmate. You understand that I cannot give testimony. But I might be able to 'pay' you for information on how you came about that passphrase.")<<endl; 
					cout << ".."<< endl; 
					cout << wordWrap("The telepath world, of course. Looks like we will have to give that sector a wider area. Thanks for help captain, here, for your troubles.") <<endl; 
					player->addItem("Evidence - Terran currency");
					player->removeItem("Terran Arms dealer passphrase"); 
					
					sec->currentStoryStep++; 
				}
			 	
			 }
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
			cout << sec->description << endl; 
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 	
	}
	
	return success; 
}; 

//sector 8
bool sec08RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 9
bool sec09RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 10
bool sec10RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "There appears to be a Parvc ship floating in space here, the engines and lifesupport seem intact. It must be something else...."; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			 if (player->hasItem("Letter of Introdocuton to Liool")){
			 	cout << wordWrap("The Parvc ship might be the one we are looking for, but they are not responding. What should we do captain?") <<endl; 
			 	
				 string choice = getAction("board", "leave"); 
			
				if (choice == "board"){
					
					cout << wordWrap("Captain the entire crew is unconsious! It seems they had an alergic reaction to the foodstuffs they were trading. They almost made it back to the medical facility in the next sector before they all fell unconcious. We can wake them all with the medications we have in our clinic.") << endl; 
					cout << ".."<< endl; 
					cout << "..."<< endl; 
					cout << "...."<< endl; 
					cout << wordWrap("Thank you for saving my ship Captain! My name is Liool and you have earned the favor of the guild today...oh a letter of introduction? I see so you have been looking for me. In that case I would be happy to help you out as thanks for saving my crew. I will send you everything I know.")<<endl; 
					
					
					player->removeItem("Letter of Introdocuton to Liool"); 
					player->addItem("Alibi -  witness statement");
					sec->currentStoryStep++; 
				}
			 	
			 }
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
			cout << wordWrap("This sector contains no habitable planets and does not see many ships pass through") << endl; 
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 	
	}
	
	return success; 
}; 

//sector 11
bool sec11RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
		output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 12 
///////
//Starting space
///////
bool sec12RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "The trial will begin soon, we should gather evidence to make our case";
			output << ""; 
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
			
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 13
bool sec13RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
		output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 14
bool sec14RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 15
bool sec15RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
		output << "This sector is home to a famous medical space station. They may be able to help identify the blood on Private Hulns clothing."; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			
			if(player->hasItem("Bloody clothing sample")){
				cout << "Would you like to have a doctor take a look at the blood?" << endl;
				
				string choice = getAction("yes", "no", "exit");
				
					if(choice == "yes"){
						cout << wordWrap("You take Huln's bloody clothing to an expert in xenogenomics and wait as he inspects the blood. He seems surprised when his machines beep and reveal that the blood is in fact Ulen -which could not have come from the victim.") << endl;
						cout << endl <<wordWrap("More interesting he tells you that the sample belongs to a local individual, Cree, who is know to travel within the lowest mapped quadrent!"); 
						
						player->removeItem("Bloody clothing sample");
						player->addItem("Contact info for Cree"); 
						sec->currentStoryStep++; 
					} else {
						cout << "We should be leaving...";
					}
				
			}
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
			cout << wordWrap("Thanks to the information gathered at this medical station the last time you visited you found a lead to follow."); 
			cout << "--Press any key to continue--" <<endl << endl;
			cin.get();
		break; 	
	}
	
	return success; 
}; 

//sector 16
bool sec16RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	string choice;
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "This sector is known for the gossip found at all the local shops. It seems a world full of telepaths is terrible at keeping secrets."; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			cout << wordWrap("This might be the best place to gather information") <<endl; 
			choice = getAction("investigate", "leave"); 
			
			if (choice == "investigate"){
				cout << wordWrap("...after hours of asking around you manage to hear a rumor that might prove useful, there is a Terran arms dealer that works in an upper sector just 3 jumps from here. Using a special passphrase you can arrange a meeting.") << endl; 
				player->addItem("Terran Arms dealer passphrase"); 
				sec->currentStoryStep++; 
			}
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
			cout << sec->description << endl; 
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 	
	}
	
	return success; 
}; 
//sector 17
bool sec17RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output;
	string action;  
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "The trial is about to start..."; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:	
		case 2: //left one piece of evidence
		case 3: //left two pieces of evidence
		case 4: //left three pieces of evidence
			cout << sec->description << endl; 
			cout << "If you have any evidence to offer please do so here.": 
						
			if(player->hasItem("Memory crystal")){
				cout << "The accused is allowed a memory crystal" << endl; 
				cout << "Would you like to leave the crystal here as evidence?": 
				choice = getAction("yes", "no");
				if(choice == "yes"){
					player.removeItem("Memory crystal"); 
					sec->currentStoryStep++; 
				}
				 
			} 
			if(player->hasItem("Evidence - Terran currency")){
				cout << "This is the currency used to buy the weapon! It even has fingerprints..." << endl; 
				cout << "Would you like to leave the crystal here as evidence?": 
				choice = getAction("yes", "no");
				if(choice == "yes"){
					player.removeItem("Evidence - Terran currency"); 
					sec->currentStoryStep++; 
				}
			}
			if(player->hasItem("Blood - blood sample from Cree")){
				cout << "This blood matches what we found, and it proves the victim is alive!" << endl; 
				cout << "Would you like to leave the crystal here as evidence?": 
				choice = getAction("yes", "no");
				if(choice == "yes"){
					player.removeItem("Blood - blood sample from Cree"); 
					sec->currentStoryStep++; 
				}
			}
			if(player->hasItem("Alibi -  witness statement")){
				cout << "This alibi means Huln was not in the area..." << endl; 
				cout << "Would you like to leave the crystal here as evidence?": 
				choice = getAction("yes", "no");
				if(choice == "yes"){
					player.removeItem("Alibi -  witness statement"); 
					sec->currentStoryStep++; 
				}
			}
			if(sec->currentStoryStep >= 5){
				cout << wordWrap("The trial is starting! Please return to your ship and gather what you need to make your case") << endl; 
			}
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
	

		break; 
		default:  //run this if ths story is over and 4 pieces of evidence have been left
			cout << "As you approach the courthouse you see everyone leaving the building."
		break; 	
	}
	
	return success; 
}; 

//sector 18
bool sec18RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	string choice;
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "This sector is known for the Parvc trade guilds. Anyone that wants to trade in the empire must go through a registered guild."; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			cout << wordWrap("This might be the best place to track down the Parvc trader Private Huln was speaking to.") <<endl; 
			choice = getAction("investigate", "leave"); 
			
			if (choice == "investigate"){
				cout << wordWrap("...after hours of asking around you manage to find a lead. It seems there were only a handful of parvc traders on the planet at the time and most of them run a regular route from here to the upper sectors to trade in exotic foods from the fringe worlds.") << endl; 
				player->addItem("Lead on the Parvc"); 
				sec->currentStoryStep++; 
			}
						
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
			cout << sec->description << endl; 
			cout << "--Press any key to continue--" <<endl;
			cin.get(); 
		break; 	
	}
	
	return success; 
}; 
//sector 19
bool sec19RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 20
bool sec20RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
		
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 21
bool sec21RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
		
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();	
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 22
bool sec22RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
		
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();	
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 23
bool sec23RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
		
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();	
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 

//sector 24
bool sec24RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "This sector contains a busy shipping lane. It is best to keep moving to avoid collisons."; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			if(player->hasItem("Contact info for Cree")){
				cout << "Captain!" << endl; 
				cout << wordWrap("We are detecting the ship belonging to the Ulen named Cree. What would you like to do?");
				string choice = getAction("contact", "ignore"); 
				if (choice == "contact"){
					cout << "--We have recieved acknowledgement of our transmission --" << endl <<endl; 
					cout << wordWrap("My name is Cree, captain of the ship Qllzdrict, is there something in particular you are looking for?")<< endl; 
					cout << wordWrap("A murder? I have no idea about that! But I was just near that station. I remember tripping in the trade district, Terrans and your high gravity hrmph! I do remember leaving some blood where I fell. I would be happy to give a sample and a statement saying I am not dead.") << endl; 
				
					player->addItem("Blood - blood sample from Cree"); 
					sec->currentStoryStep++; 
				} else {
					cout << "We should leave before we interfere with the shipping lanes." << endl; 
				}
				
			}
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
			cout << wordWrap("It appears Cree is no longer in this sector. We should leave before we interfere with the shipping lanes.") << endl; 
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 	
	}
	
	return success; 
}; 

//sector 25
bool sec25RunFunction(Sector *sec, Player* player){
	bool success = true; 
	stringstream output; 
	switch(sec->currentStoryStep){
		case 0:  //case zero is called upon initialization so it contains the default text of the story and sets it accordingly
			sec->currentStoryStep++; 
			
			output << "story"; 
			
			sec->description = wordWrap(output.str());
		break; 
		case 1:
			cout << sec->description << endl; 
			
			cout << "--Press any key to continue--" <<endl;
			cin.get();
		break; 
		default:  //run this if ths story is over
		
		break; 	
	}
	
	return success; 
}; 
