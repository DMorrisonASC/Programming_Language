/*
    Author: Daeshaun Morrison, Muhlenberg College class of 2024(daeshaunkmorrison@gmail.com)
    Date: 2/13/2023
    Instructor: Professor Silveyra
    Description: 
    Errors: 
 */

#include "Player.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

	Player::Player(){
		score = 0;
		loses = 0;
	}
	
	// Player::getScore () {
		// cout << "Score: \n" << Words.score << "Win(s)\n" << Words.lose << "Loss(es)\n";   
	// }
	int Player::getScore () {
		return score;
	}	
	int Player::getLoses () {
		return loses;
	}