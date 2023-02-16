/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 2/13/2023
    Instructor: Professor Silveyra
    Description: 
    Errors: 
 */

#include<vector>
#include<string>
using namespace std;

class HugeInteger {
	private:
		vector<int> * data;
	public:
		HugeInteger();
		HugeInteger(const HugeInteger & other);
		HugeInteger( const string & stringita );
		bool operator == (const HugeInteger & rightSide);
		const HugeInteger operator + (const HugeInteger & rightSide);
		bool operator > (const HugeInteger & rightSide);
		bool isZero() const;
		string toString() const;
		// destructor for methods that use heaps and pointers;
		~HugeInteger();
};
