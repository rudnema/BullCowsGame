#include "FBullCowsGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}



int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIIDEN_WORD = "planet";
	MyHiddenWord = HIIDEN_WORD;
	MyCurrentTry = 1;
	return;
}



bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// recieves a VALID guess, incriments turn, and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{


	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	BullCowCount BullCowCount;

	// loop throught all letters in the guess
		// compare letters against the hidden word
	
	return BullCowCount;
}
