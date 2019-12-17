#pragma once
#include <string>

//notice me :D

using FString = std::string;
using int32 = int;

//all values initialised to zero
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EwordStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};



class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;


	bool IsGameWon() const;
	EwordStatus CheckGuessValidity(FString) const;

	void Reset(); //todo make a more rich return value
	FBullCowCount SubmitGuess(FString);
	
	

	//ban

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};