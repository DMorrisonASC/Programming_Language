/*
    Author: Daeshaun Morrison
    Date: 
    Instructor: Professor Silverya
    Description: Work with a partner to write a program in C that prompts the user for a filename. It then opens the file, reads its contents, spits out a table of letter frequencies, then closes the file.
    Errors: 
 */
 
#include <iostream>
#include <fstream>
#include <string>
#pragma once
using namespace std;

void freqCount();

int main() {
	freqCount();
	
	
	
	
}

void freqCount() {
	// Create a text string that stores the output(each line).
	string eachLine;

	// Read from the text file
	ifstream MyReadFile("kira_jojo_sample.txt");
	int numSentences = 0;
	// Use a while loop together, read the file line by line
	while (getline (MyReadFile, eachLine)) {
		string eachLineStr = eachLine;

		// cout << eachLineStr; 
		// Add 1 for every sentence
		numSentences += 1;
		for (int x : arr) {
			cout<<x<<" ";
		}
		

	}

	cout << numSentences;

	// Close the file
	MyReadFile.close();
}