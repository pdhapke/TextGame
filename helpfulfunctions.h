
#pragma once
#ifndef HELPFULFUNCTIONS_H
#define HELPFULFUNCTIONS_H
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std; 

int randomNumber(int start_inclusive, int end_inclusive);
string getDirection(string promptText);
string getAction();
string getAction(string, string);
string getAction(string, string, string);
string getAction(string, string, string, string);
string getAction(vector<string>);
string wordWrap(string given); 


#endif
