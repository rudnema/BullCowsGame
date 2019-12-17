#include "FBullCowsGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20} }; //last number change plays
return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	//constexpr int32 MAX_TRIES = 3; DELETED
	const FString HIDDEN_WORD = "plane"; //isogram
	//MyMaxTries = MAX_TRIES; DELETED
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))	// if the guess isn't an isogram, return an error
	{
		return EGuessStatus::Not_Isogram; 
	}
	else if (!IsLowercase(Guess)) // if the guess isn't all lowercase. 
	{
		return EGuessStatus::Not_Lowercase; 
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// recieves a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WorldLength = MyHiddenWord.length(); // assuming same length as guess
	
	// loop throught all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WorldLength; MHWChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WorldLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				} 
				else {
					BullCowCount.Cows++; // must be a cow
				}

			}
		}
	}
	if (BullCowCount.Bulls == WorldLength) {
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
}
		return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true;  }

	TMap<char, bool> LetterSeen; //setup our map
	for (auto Letter : Word) // for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) { //if the letter is in th emap
			return false; // we do NOT have an isogram
		} else {
			LetterSeen[Letter] = true; //add the letter to the map as seen
		
		}
	}

	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		 
		if (!islower(Letter))	// if not a lowercase letter
		{
			return false;
		}
	}
	return true;
}
