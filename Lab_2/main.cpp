/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 2/13/2023
    Instructor: Professor Silveyra
    Description: 
    Errors: Does not print integers contained in `HugeInteger` and comparing `HugeInteger` does not work;
 */
#include<iostream>
#include<string>
#include "HugeInteger.h"
 int main() {
	HugeInteger h1;
	string num = "123deez321";
	HugeInteger h2(num);
	HugeInteger h3(h2);

    cout<<h2.toString();
	
	bool isGreater = h3 > h2;
	cout << isGreater;
 }