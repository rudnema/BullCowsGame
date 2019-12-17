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

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{

	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	// loop throught all letters in the guess
	int32 HiddenWorldLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWorldLength; i++) {
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWorldLength; j++) {
			// if they match them
			if (Guess[i] == MyHiddenWord[i]) {
				if (i == j) { // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				} 
				else {
					BullCowCount.Cows++; // must be a cow
				}

					

			}
		}
	}
		return BullCowCount;
}
