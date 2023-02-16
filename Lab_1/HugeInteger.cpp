#include "HugeInteger.h"
#include<vector>
#include<string>
using namespace std;

	HugeInteger::HugeInteger(){
		data = new vector<int>();
		data -> push_back(0);	

	}
	
	HugeInteger::HugeInteger(const HugeInteger & other) {
		// receives memeory location of object type `HugeInteger`, called other.
		// instancizaes your own copy;
		data = new vector<int>();
		// Copy values of the vector `other` to this.data to make a "deep copy"
		
	}
	
	HugeInteger::HugeInteger( const string & stringita ) {
		data = new vector<int>();
		// traverse through the string
		for (int i = 0; i < stringita.size(); i++) {
			data->push_back(i);
		}
	}
	
	bool HugeInteger::operator == (const HugeInteger & rightSide) {
		
	}
	const operator + (const HugeInteger & rightSide) {
		
	}
	bool HugeInteger::operator > (const HugeInteger & rightSide) {

	}
	bool HugeInteger::isZero() const {
		
	}
	string HugeInteger::toString() const {
		
	}
	
	// destructor for methods that use heaps and pointers;
	HugeInteger::~HugeInteger() {
		delete data;
	}