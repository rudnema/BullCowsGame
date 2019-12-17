#include "FBullCowsGames.h"

int FBullCowGame::GetMaxTries() { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	return;
}



bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::ChescGuessValidity(std::string)
{
	return false;
}
