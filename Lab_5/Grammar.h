/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 3/21/2023
    Instructor: Professor Silveyra
    Description: 
    Errors:
 */
#pragma once
#include <fstream>
#include <string>
#include <map> 
#include <vector>
using namespace std;


class Grammar {
	public:
		Grammar();
		map <string, vector<string>> hashMap;
		// ~Grammar();
		void addProduction(string nonTerm, string rhs);
		string getRandomRHS(string nonTerm);
		bool containsNonTerminal(string nonTerm);
		// bool operator<<(Grammar sentence);
		friend ostream& operator<<(ostream& os, Grammar& v);
		
};
