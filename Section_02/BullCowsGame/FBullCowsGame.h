#pragma once
#include <string>

//notice me :D

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); //todo make a more rich return value
	bool CheckGuessValidity(FString); // TODO make a more rich return value
	// provide a method for counting bulls % cows, and increasing try #
	
	





	//ignorowaæ

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;

};