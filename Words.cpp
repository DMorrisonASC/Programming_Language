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
		list -> push_back("worm");	
		list -> push_back("dog");	
		list -> push_back("eagle");	
		list -> push_back("elephant");	
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
		int guesses = 7;
		bool KeepGoing = true;
		int randPick = (rand() % list->size());
		string randWord = list->at(0);
		string incompleteWord = "";
		
		
		for (char letter : randWord) {
			cout << "_ ";
			incompleteWord.push_back('_');
		}
		
		while (KeepGoing == true) {
			cout << "Guess a letter: ";
			char input;
			cin>>input;
			
			if (randWord.find(input) != std::string::npos) {
				for (int i = 0; i < randWord.length(); i++ ) {
					if (randWord.at(i) == input) {
						incompleteWord = editWord(incompleteWord, i, input);
					}
				}
				
				cout << incompleteWord;
			}
			else {
				cout << "\"" << input << "\"" << " is not in the word";
				guesses = guesses - 1;
				cout << "Guesses ramaining: " << guesses << "\n";
			}	
		
		}
		
		
	}
	
	string Words::editWord(string s, int index, char new_char) {
	   // replace new_char with the existing character at s[index]
	   if( index >= 0 && index < s.length() ) {
		  s[ index ] = new_char;
		  return s;
	   } else {
		  return s;
	   }
	}
	
	// destructor for methods that use heaps and pointers;
	Words::~Words() {
		delete this->list;
	}
