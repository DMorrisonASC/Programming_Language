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
		
		this->grammarRule = new Grammar();
		
		ifstream file(fileName);
		if (!file.is_open()) {
			cerr << "File not available" << fileName << std::endl;
		}
		
		string hashKey = "";
		string vecData = "";
		string line;
		
		bool startProduction = false;
        bool endProduction = true;
		
		while (getline(file, line)) {
			// Parse line here
			cout << line << endl;
			if (line.find("{") != std::string::npos) {
				startProduction = true;
                endProduction = false;
                getline(file, line);
                hashKey = line.c_str();
				cout << hashKey << "\n";
			}
			
			else if (line.find("}") != std::string::npos) {
                startProduction = false;
                endProduction = true;
			}
			
			else if (startProduction && !endProduction) {
				vecData = line.c_str();
				cout << vecData << "\n";
				grammarRule->addProduction(hashKey, vecData);
				
			}
			
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
	
