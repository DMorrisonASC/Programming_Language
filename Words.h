/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 2/13/2023
    Instructor: Professor Silveyra
    Description: 
    Errors: 
 */
#pragma once
#include<vector>
#include<string>
using namespace std;

class Words {
	private:
		vector<string> * list;
	public:
		Words();
		Words( const string & fileName );
		void playGame();
		void getScore();
		
		// destructor for methods that use heaps and pointers;
		~Words();
};