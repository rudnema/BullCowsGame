#pragma once
#include <string>

//notice me :D

using FString = std::string;
using int32 = int;

//all values initialised to zero
struct BullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); //todo make a more rich return value
	bool CheckGuessValidity(FString); // TODO make a more rich return value


	// counts bulls % cows, and increasses try # assuming valid guess
	BullCowCount SubmitGuess(FString);
	





	//ignorowaæ

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};