/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 3/21/2023
    Instructor: Professor Silveyra
    Description: 
    Errors:
 */
using namespace std;
#include <fstream>
#include <string>


class Grammar {
	public:
		Grammar();
		// ~Grammar();
		void addProduction(string nonTerm, string rhs);
		string getRandomRHS(string nonTerm);
		bool containsNonTerminal(string nonTerm);
		// void operator<<(Grammar sentence);
};
