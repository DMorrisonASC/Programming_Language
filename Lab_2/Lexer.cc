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
        addChar(); 
        getChar(); 
		
        while( charClass == LETTER || charClass == DIGIT ){ 
          addChar(); 
          getChar(); 
        }         
		// while( charClass == UNKNOWN){ 
          // addChar(); 
          // getChar(); 
        // } 
        nextToken=DOUB_QUOTE; 
        break;
		
    case LETTER: 
        addChar(); 
        getChar(); 
		
        while( charClass == LETTER || charClass == DIGIT){ 
          addChar(); 
          getChar(); 
        } 
		
		isReserveWord = checkIfReserve(lexeme);
		
		if (isReserveWord == true) {
			nextToken=KEY_WORDS; 	
		}
		
		else {
			nextToken=IDENT; 
		}
		
		isReserveWord = false;
		
		// nextToken=IDENT; 
        break; // identifiers
		
    case DIGIT: 
        addChar(); 
        getChar(); 
        while( charClass == DIGIT ){ 
          addChar(); 
          getChar(); 
        } 
        nextToken=INT_LIT; 
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

bool Lexer::checkIfReserve(const string word) {
	
	bool isReserve = false;
	string reserveList[11] = {"if", "else", "for", "do", "while", "switch", "case", "default", "break", "void", "return"};
	int getReserveList = sizeof(reserveList) / sizeof(string);
	
	for (int i = 0; i < getReserveList; i++) {
		if (word.compare(reserveList[i]) == true) {
			return true;	
		}
	}
}
