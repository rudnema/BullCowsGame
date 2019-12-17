#pragma once
#include <string>

//notice me :D

class FBullCowGame {
public:
	void Reset(); //todo make a more rich return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool ChescGuessValidity(std::string); // -- || --


	//:> ignoruj to

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;

};