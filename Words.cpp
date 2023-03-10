/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 2/13/2023
    Instructor: Professor Silveyra
    Description: 
    Errors: 
 */
 
#include "Words.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

	// Words::Words(){
		// data = new vector<int>();
		// data -> push_back(0);	
	// }	
	
	Words::Words(){
		list = new vector<string>();
		list -> push_back("Worm");	
		list -> push_back("Dog");	
		list -> push_back("Eagle");	
		list -> push_back("Elephant");	
	}
	
	/*
	Words::Words(const Words & other) {
		// receives memeory location of object type `Words`, called other.
		// instancizaes your own copy;
		// this->data = new vector<int>();
		// Copy values of the vector `other` to this.data to make a "deep copy"
		// for (int number : other.data) {
				// data->push_back(number);
			// }
		this->data = new vector<int>();
		// for (auto i = other.data->begin(); i != other.data->end(); ++i)
		// {
			// data->push_back(other.data->at(i));
		// }
		for (int i = 0; i < other.data->size(); i++) {
			data->push_back(other.data->at(i));
		}
		
		// other->data.size();
		
	}
	*/
	
	void Words::playGame() {
		bool KeepGoing = true;
		int randPick = (rand() % list->size());
		string randWord = list->at(randPick);
		
		for (char letter : randWord) {
			cout << "_ " << randPick;
			
		}
		
		
		
		// while (KeepGoing == true) {
			// for 
		
		// }
		
	}
	
	// destructor for methods that use heaps and pointers;
	Words::~Words() {
		delete this->list;
	}