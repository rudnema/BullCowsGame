#pragma once
#include <string>

//notice me :D

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); //todo make a more rich return value
	bool CheckGuessValidity(std::string); // TODO make a more rich return value
	
	





	//:> ignoruj to

private:
	// see constructor for initialisation
	int MyCurrentTry;
	int MyMaxTries;

};