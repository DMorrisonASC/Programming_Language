/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 3/21/2023
    Instructor: Professor Silveyra
    Description: 
    Errors:
 */
#include <iostream>
#include "RandomSentenceGenerator.h"

using namespace std;

int main() {
    cout << "Hello, world!\n";
	string fileName = "Trump.g";
	string * ptrName = &fileName;
	//
	RandomSentenceGenerator sentenceGenerator(fileName);
    
}
