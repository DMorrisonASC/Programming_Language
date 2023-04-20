/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 3/21/2023
    Instructor: Professor Silveyra
    Description: 
    Errors:
 */

#include "RandomSentenceGenerator.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

	RandomSentenceGenerator::RandomSentenceGenerator() {
		;
	}	
	RandomSentenceGenerator::RandomSentenceGenerator(const string & fileName) {
		
		ifstream file(fileName);
		if (!file.is_open()) {
			cerr << "File not available" << fileName << std::endl;
		}

		string line;
		while (getline(file, line)) {
			// Parse line here
			// cout << line << endl;
		}

		file.close();
		
	
		
		
	}
	
	string RandomSentenceGenerator::randomSentence() {
		return "Up";
	}
	
	void printGrammar() {
		;
	}
	
	// Grammar getGrammar() {
		// return grammarRule;
	// }
	// Destructor
	