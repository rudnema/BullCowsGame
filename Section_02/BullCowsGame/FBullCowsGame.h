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
	// provide a method for counting bulls % cows, and increasing try #
	
	





	//ignorowaæ

private:
	// see constructor for initialisation
	int MyCurrentTry;
	int MyMaxTries;

};