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
			string nonTerminal;
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
					nonTerminal = line;
					// cout << nonTerminal << "\n";
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
					line = line.substr(0, line.find(";"));
					// Remove Whitespace
					nonTerminal.erase(std::remove_if(nonTerminal.begin(), nonTerminal.end(), ::isspace), nonTerminal.end());
					// cout << nonTerminal << "\n";
					grammarRule->addProduction(nonTerminal, line);
					// cout << line << "\n";
				}
			}

			// Close the input file.
			inputFile.close();
		}		
	}
	
	string RandomSentenceGenerator::randomSentence() {
		// Generate a random sentence from the grammar with "<start>" as the starting non-terminal symbol.
		std::string randomSentence = grammarRule->getRandomRHS("<start>");

		// While there are still non-terminal symbols in the sentence.
		while (randomSentence.find("<") != std::string::npos)
		{
			// Get the non-terminal symbol to expand.
			std::string nonTerminalSymbol = randomSentence.substr(randomSentence.find_first_of("<"), (randomSentence.find_first_of(">") - randomSentence.find_first_of("<")) + 1);
			
			// Get a random production rule for the non-terminal symbol and append it to the rest of the sentence.
			std::string expandedGrammar = grammarRule->getRandomRHS(nonTerminalSymbol) + randomSentence.substr(randomSentence.find_first_of(">") + 1, randomSentence.size() - randomSentence.find_first_of(">"));
			
			// Replace the non-terminal symbol with the expanded grammar.
			randomSentence.replace(randomSentence.find_first_of("<"), randomSentence.size(), expandedGrammar);
		}

		// Return the fully expanded sentence.
		return randomSentence;

	}
	
	void RandomSentenceGenerator::printGrammar() {
		// Grammar * grammarObj = this->grammarRule; 
		// cout << grammarObj;
		cout << * this->grammarRule;
	}
	// Destructor
	RandomSentenceGenerator::~RandomSentenceGenerator()
	{
		delete grammarRule;
	}
	