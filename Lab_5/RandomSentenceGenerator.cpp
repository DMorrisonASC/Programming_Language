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
#include <algorithm>

using namespace std;

	RandomSentenceGenerator::RandomSentenceGenerator() {
		;
	}	
	RandomSentenceGenerator::RandomSentenceGenerator(const string & fileName) {
		// Create a new grammar object.
		this->grammarRule = new Grammar();

		// Open input file and create a string to store each line of the file.
		std::ifstream inputFile;
		std::string line;

		// Open the input file and check if it is open.
		inputFile.clear();
		inputFile.open(fileName.c_str());
		if (inputFile.is_open())
		{
			std::string nonTerminal;
			bool startOfProduction = false;
			bool endOfProduction = true;

			// Loop through each line of the file.
			while (getline(inputFile, line))
			{
				// Check if the line contains the start of a new production.
				if (line.find("{") != std::string::npos)
				{
					startOfProduction = true;
					endOfProduction = false;
					getline(inputFile, line);
					nonTerminal = line.c_str();
					cout << nonTerminal << "\n";
				}
				// Check if the line contains the end of a production.
				else if (line.find("}") != std::string::npos)
				{
					startOfProduction = false;
					endOfProduction = true;
				}
				// If the line is part of a production.
				else if (startOfProduction && !endOfProduction)
				{
					line = line.c_str();

					// Remove whitespace from the non-terminal.
					nonTerminal.erase(remove_if(nonTerminal.begin(), nonTerminal.end(), ::isspace), nonTerminal.end());

					// Add the production to the grammar object.
					grammarRule->addProduction(nonTerminal, line.substr(0, line.find(";")));
					cout << line << "\n";
				}
			}

			// Close the input file.
			inputFile.close();
		}		
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
	
