/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 3/21/2023
    Instructor: Professor Silveyra
    Description: Lexical analyzer
    Errors: None
 */

#include <cstdlib>
#include<iostream>
#include "Lexer.h"
using namespace std;
Lexer::Lexer( const string & fileName ): nextToken(EOF), charClass(UNKNOWN), nextChar(' ') {
  inputStream.open( fileName.c_str(), ifstream::in ); 
}

Lexer::~Lexer() {
  inputStream.close();
}

int Lexer::getNextToken() const {
  return nextToken;
}

string Lexer::getLexeme() const {
  return lexeme;
}

// lookup - a function to lookup operators and parentheses
//          and return the token
int Lexer::lookup(char ch)
{
  switch( ch )
  {
    case '(': 
      addChar(); 
      nextToken=LEFT_PAREN; 
      break;
    case ')': 
      addChar(); 
      nextToken=RIGHT_PAREN; 
      break;
    case '+': 
      addChar(); 
      nextToken=ADD_OP; 
      break;
    case '-': 
      addChar(); 
      nextToken=SUB_OP; 
      break;
    case '*': 
      addChar(); 
      nextToken=MULT_OP; 
      break;
    case '/': 
      addChar(); 
      nextToken=DIV_OP; 
      break;
	// Edited part:
    case '=': 
      addChar(); 
      nextToken=ASSIGN_OP; 
      break;    
	case '{': 
      addChar(); 
      nextToken=LEFT_CURL; 
      break;
	case '}': 
      addChar(); 
      nextToken=RIGHT_CURL; 
      break;
	case '"': 
		addChar(); 
		nextToken=DOUB_QUOTE; 
		break; // Strings
	case '.': 
		addChar(); 
		nextToken=FLOAT_DOT; 
		break;	
	case ',': 
		addChar(); 
		nextToken=COMMA; 
		break;
	case ';': 
		addChar(); 
		nextToken=SEMI_COLON; 
		break;
	  
    default:  
      addChar(); 
      nextToken=EOF; 
      break;
  }
  return nextToken;
}

// addChar() - a function to add nextChar to lexeme
void Lexer::addChar()
{
  lexeme.push_back(nextChar);
}

// getChar() - a function to get the next character of
//             input and determine its character class
void Lexer::getChar()
{
  nextChar = inputStream.get();

  if( inputStream.good() ) {
    if( isalpha(nextChar)) charClass=LETTER;
    else if( isdigit(nextChar) ) charClass=DIGIT;
    else if( nextChar == '"') charClass = DOUB_QUOTE;
	else charClass=UNKNOWN; 
  } else {
    charClass = EOF;
  }
}

// getNonBlank - a function to call getChar until it
//               returns a non-whitespace character
void Lexer::getNonBlank()
{
  while( isspace(nextChar) ) getChar();
}

// lex() - a simple lexical analyzer
int Lexer::lex()
{
  getNonBlank();
  lexeme = "";

  switch( charClass )
  {
	case DOUB_QUOTE: 
		do { // Add double quote('"') to `lexeme` and keep add chars until it reaches another one.
			addChar();
			getChar();
		} 
		while (charClass != DOUB_QUOTE);
		
		addChar(); // Add the double quote
		getChar();
		
        nextToken=DOUB_QUOTE; 
        break;
		
    case LETTER: 
        addChar(); 
        getChar(); 
		
        while( charClass == LETTER || charClass == DIGIT){ 
          addChar(); 
          getChar(); 
        } 
		// Check if the word is a reserve word in C++
		// If it is, the token is `KEY_WORDS`
		// If not, the token is `IDENT`
		isReserveWord = checkIfReserve(lexeme); 
		
		if (isReserveWord == true) {
			nextToken=KEY_WORDS; 	
		}
		
		else {
			nextToken=IDENT; 
		}
		
		isReserveWord = false;
		
        break; // identifiers
		
    case DIGIT: 
 
        do { 
          addChar(); 
          getChar(); 
        } while( charClass == DIGIT || nextChar == '.');
		// Check if the number is a floating decimal in C++
		// If it is, the token is `FLOAT_DOT`
		// If not, the token is `INT_LIT`
		isFloat = checkIfFloat(lexeme);
		
		if (isFloat == true) {
			nextToken=FLOAT_DOT;	
		}
		else {
			nextToken=INT_LIT; 
		}
        break; // integers
		
    case UNKNOWN: 
        lookup(nextChar); 
        getChar(); 
        break; // Other characters
		
    case EOF: 
        nextToken=EOF; 
        lexeme = "EOF";
        break;
  }

  return nextToken;
}

// If the word passed is a reserve word, return true. If not, return false
bool Lexer::checkIfReserve(const string word) {
	
	bool isReserve = false;
	string reserveList[11] = {"if", "else", "do", "for", "while", "switch", "case", "default", "break", "void", "return"};
	int getReserveList = sizeof(reserveList) / sizeof(string);
	
	for (int i = 0; i < getReserveList; i++) {
		if (word == reserveList[i] ) {
			return true;	
		}
	}
	return false;
}
// If the string of numbers passed is a float, return true. If not, return false
bool Lexer::checkIfFloat(const string floatingNum) {
	for (char element : floatingNum) {
		if ( element == '.') {
			return true;
		}
	}
	return false;
}
