/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 3/21/2023
    Instructor: Professor Silveyra
    Description: 
    Errors:
 */
#include "Grammar.h"
#include <map> 
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using std::ifstream;
using std::string;
using namespace std;

	map <string, vector<string> > hashMap;

	Grammar::Grammar() {
		string finalSentence = "";
	}

	void Grammar::addProduction(string nonTerm, string rhs) {
		vector<string> vec; 
		
		if (hashMap.find(nonTerm) != hashMap.end()) {
			// vec = hashMap.at(nonTerm);
			// vec.push_back(rhs);
			hashMap.at(nonTerm).push_back(rhs);
		}
		
		else {
			vector<string> vec; 
			vec.push_back(rhs);
			hashMap.insert(make_pair(nonTerm, vec));
		}
		
		
		
		
	}

	string Grammar::getRandomRHS(string nonTerm) {
		
		vector<string> options = hashMap.at(nonTerm);
		int sizeOptions = options.size();
		int randNum = (rand() % sizeOptions);
		cout << randNum << "\n Size";
		string randSentence = options.at(randNum);
		
		return randSentence;
	}

	bool containsNonTerminal(string nonTerm) {

		istringstream iss(nonTerm);
		// Iterate the istringstream
		// using do-while loop
		do {
			string subs;
	 
			// Get the word from the istringstream
			iss >> subs;
			
			if (subs.find("<") != string::npos && subs.find(">") != string::npos) {
				// cout << "found! " << subs;
				return true;
			}
			
			else {
				subs = "";
			}
			
		} while (iss);
	 
		return false;
		
	}

	ostream& operator<<(ostream& os, Grammar& grammar){
		// return the keys and values of the map(`hashMap`)
        for (auto const& pair: grammar.hashMap) {
            os << "Key: " << pair.first << "\n";
            os << "Values: ";
            for (auto const& val: pair.second) {
                os << val << "\n";
            }
            os << "\n\n";
        }
		return os;
	}
	