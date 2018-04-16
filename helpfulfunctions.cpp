//Peter Hapke 
//peterdhapke@gmail.com
//3/24/18

/* 

*/
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std; 

int randomNumber(int start_inclusive, int end_inclusive){
	int range = end_inclusive - start_inclusive + 1; 
	return ((rand() % range) + start_inclusive); 
}


string getDirection(string promptText){
	string choice = ""; 
	string junk; 
	bool validChoice = false; 
	do{

		cout << promptText << ": "; 
		cin >> choice; 
		if (choice == "up" || choice == "down"  || choice == "left" || choice == "right"){
			validChoice = true;
		}
		
		if(!validChoice){
			cin.clear();
			getline(cin, junk);
			cout << "I do not understand that heading..." << endl; 
		}
		
	}while(!validChoice); 
	cin.ignore(); //to ignore the entered whitespace
	return choice; 
} 

string getAction(){
	string choice = ""; 
	string junk; 
	bool validChoice = false; 
	do{

		cout << "What is our course of action? ";
		cin >> choice; 
		if (choice == "warp" || choice == "cargo"  || choice == "inspect" || choice == "scan"){
			validChoice = true;
		}
		
		if(!validChoice){
			cin.clear();
			getline(cin, junk);
			cout << "I am sorry I do not know how to pursue that course of action..." << endl; 
		}
		
	}while(!validChoice); 
	cin.ignore(); //to ignore the entered whitespace
	return choice; 
} 

string getAction(string choice1, string choice2){
	string choice = ""; 
	string junk; 
	bool validChoice = false; 
	do{

		cout<< endl <<  "Choose " << choice1 << " or " << choice2 << ": "; 
		cin >> choice; 
		if (choice == choice1 || choice == choice2){
			validChoice = true;
		}
		
		if(!validChoice){
			cin.clear();
			getline(cin, junk);
			cout << "I am sorry I do not know how to pursue that course of action..." << endl; 
		}
	}while(!validChoice); 
	cin.ignore(); //to ignore the entered whitespace
	return choice; 
} 

string getAction(string choice1, string choice2, string choice3){
	string choice = ""; 
	string junk; 
	bool validChoice = false; 
	do{

		cout<< endl << "Choose " << choice1 << ", " << choice2 << ", or " << choice3 << ": "; 
		cin >> choice; 
		if (choice == choice1 || choice == choice2  || choice == choice3){
			validChoice = true;
		}
		
		if(!validChoice){
			cin.clear();
			getline(cin, junk);
			cout << "I am sorry I do not know how to pursue that course of action..." << endl; 
		}
	}while(!validChoice); 
	cin.ignore(); //to ignore the entered whitespace
	return choice; 
} 


string getAction(string choice1, string choice2, string choice3, string choice4){
	string choice = ""; 
	string junk; 
	bool validChoice = false; 
	do{

		cout<< endl << "Choose " << choice1 << ", " << choice2 << ", " << choice3 << ", or" << choice4 << ": "; 
		cin >> choice; 
		if (choice == choice1 || choice == choice2  || choice == choice3 || choice == choice4){
			validChoice = true;
		}
		
		if(!validChoice){
			cin.clear();
			getline(cin, junk);
			cout << "I am sorry I do not know how to pursue that course of action..." << endl; 
		}
	}while(!validChoice); 
	cin.ignore(); //to ignore the entered whitespace
	return choice; 
} 

string getAction(vector<string> list){
	string choice = ""; 
	string junk; 
	stringstream output; 
	output << "Choose ";
	
	for (int i = 0; i < (list.size()); i++){
		output << list[i] << ", "; 
    }
    output << "or exit to go back: "; 

	bool validChoice = false; 
	do{
	cout << endl << wordWrap(output.str()); 
		getline(cin, choice);
		for(int k = 0; k < list.size(); k++){
			if (choice == (list[k])){
				validChoice = true;
			}	
		}
		
		if (choice == "exit"){
			validChoice = true; 
		}
		
		if(!validChoice){
			cin.clear();
			cout << "I am sorry I do not know how to pursue that course of action..." << endl; 
		}
	}while(!validChoice); 
	return choice; 
}

//copied from another project I wrote
string wordWrap(string given){
	stringstream output; 
	int sizeOfScreen = 90; 
	if (given.size() < sizeOfScreen){
		output << given; 
	} else {
		int start = 0;
		int length = sizeOfScreen; 
		int spaceFound = false; 
		
		while (start < given.size()){
			spaceFound = false;
			
			while(!spaceFound){
				length--; 
				if (start+length >= given.size()){
					length = given.size() - start + 1; 
					spaceFound = true; 
				} else if (length <= 0){
					length = sizeOfScreen; 
					spaceFound = true; //space not found but the word is too long to fit so it can wrap					
				} else if(given.at(start + length) == ' '){
					spaceFound = true; 
				} 
				
			}
			output << given.substr(start, length) << "\n"; 
			start = start + length +1; //to account for the space character 
			length= sizeOfScreen; 
		}
	}
	return output.str(); 
}




