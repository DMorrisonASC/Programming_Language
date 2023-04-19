/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 3/21/2023
    Instructor: Professor Silveyra
    Description: 
    Errors:
 */
#pragma once
#include "Grammar.h"
#include <iostream>
using namespace std;

class RandomSentenceGenerator {
	private:
		Grammar grammerRule;
	public:
		RandomSentenceGenerator();
		RandomSentenceGenerator(const string & fileName);
		string randomSentence();
		void printGrammer();
		// destructor
};

