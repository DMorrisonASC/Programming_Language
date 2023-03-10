#include "HugeInteger.h"
#include <vector>
// #include <string>
#include <iostream>
#include <sstream>
using namespace std;

	HugeInteger::HugeInteger(){
		data = new vector<int>();
		data -> push_back(0);	

	}
	
	HugeInteger::HugeInteger(const HugeInteger & other) {
		// receives memeory location of object type `HugeInteger`, called other.
		// instancizaes your own copy;
		this->data = new vector<int>();
		// Copy values of the vector `other` to this.data to make a "deep copy"
		// for (int number : other.data) {
				// data->push_back(number);
			// }
		this->data = new vector<int>();
		for (auto i = other.data->begin(); i != other.data->end(); ++i)
		{
			data->push_back(*i);
		}
		
	}
	
	HugeInteger::HugeInteger( const string & stringita ) {
		data = new vector<int>();
		// traverse through the string
		for (char letter : stringita) {
			int asciiNum = int(letter);
			if ( 48 <= asciiNum <= 57) {
				data->push_back(letter);
			}
		}
	}
	
	bool HugeInteger::operator == (const HugeInteger & rightSide) {
		if (this->data->size() != rightSide.data->size()) {
			return false;
		}
		
		for (int i = 0; i < this->data->size(); i++)
		{
			if (this->data[i] != rightSide.data[i]) {
				return false;
			}
		}
		return true;
	}
	
	// const HugeInteger HugeInteger::operator + (const HugeInteger & rightSide) {
		// long calculation = atoi(rightSide.toString()) + atoi(toString());
		// string output = to_string(calculation);
		// return HugeInteger(output);	
	// }

	
	bool HugeInteger::operator > (const HugeInteger & rightSide) {		
		
		int biggestSize = 0;
		if ( this->data->size() > rightSide.data->size() ) {
			biggestSize = this->data->size();
		}
		else if ( this->data->size() < rightSide.data->size() ){
			biggestSize = rightSide.data->size();
		}
		
		else {
			biggestSize = this->data->size();
		}
		
		for (int i = biggestSize - 1; i >= 0; i--)
		{
			if (i < rightSide.data->size() && i < this->data->size())
				if (this->data->at(i) > rightSide.data->at(i))
					return true;
		}
		return false;
		
	}
	
	bool HugeInteger::isZero() const {
		// Note: the auto keyword is used to automatically identify the type of elements in range-expression
		for (auto i = data->begin(); i < data->end(); i++) {
			if (*i != 0)
				return false;
		}
		return true;
	}
	
	string HugeInteger::toString() const {
		// string finalString = "";
		
		// for(int i = 0; i < this->data->size(); i++)
		// {
			// string numberString = to_string(data[i]);
			// finalString.append(numberString);
		// }
		// return finalString;
		std::stringstream numberString;
		for(auto i = data->begin(); i < data->end(); i++) {
		  numberString << *i;
		}
		std::string finalString = numberString.str();
		
		return finalString;
	}
	
	// destructor for methods that use heaps and pointers;
	HugeInteger::~HugeInteger() {
		delete this->data;
	}
