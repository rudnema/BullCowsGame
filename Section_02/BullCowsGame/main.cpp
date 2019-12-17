/* This is the console executable, that makes us of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user interacion.
For game logic see the the FBullCowGame class.


*/



#include <iostream>
#include <string>
#include "FBullCowsGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayGame();
void PrintGameSummary();

FBullCowGame BCGame; //instantiate a new game

// the enetry point of our application
int main()
{
	std::cout << BCGame.GetCurrentTry(); //pokazuje próby

	bool bPlayAgain = false;
	do {
	PrintIntro();
	PlayGame();
	// TODO add a game summary
	bPlayAgain = AskToPlayGame();
	} 
	while (bPlayAgain);


	//ODPOCZYNEK z pizz¹ 
	std::cout << std::endl;
	return 0;   //exit the application
}



//introduse the game 
void PrintIntro() 
{

	//constexpr int WORD_LENGTH = 9; deleted
	std::cout << "MM                   MM                                     \n";
	std::cout << "MMM+                8MM                                     \n";
	std::cout << "MMMMMM            :MMM                        MM,     ZMM   \n";
	std::cout << "ZMMM+MMMM+       MMMM                         MMMO  MMMMM   \n";
	std::cout << "   MMM  MMMMMMMMMMMN                            MMMMMMMZ    \n";
	std::cout << "    MMMMM   MMMMMMMMM                        ZMMMZMZ, MMMMMM\n";
	std::cout << "      $MMD  MMM    MMMMMMM         MMMMMMMMMMMMM         MMM\n";
	std::cout << "777MMMMDI               I7MMM~  7MMMIIIIIII+                \n";
	std::cout << "MMM?                       MMM +MM                          \n";
	std::cout << "                           ZMM +M+                          \n";
	std::cout << "        B U L L S          MMM  MM            C O W S       \n";
	std::cout << "                     MMMMMMMO    MMMMMMM                    \n";
	std::cout << "               ZMMMMMMMM               MMMMM                \n";
	std::cout << "             MMMM                         MMMMM             \n";
	std::cout << "            MMM                               MMMMM         \n";
	std::cout << "           MMO                                   MM,        \n";
	std::cout << "\nWelcome to Bulls & Cows\n";
	std::cout << "Isogram: a word that does not have any repeating letters in it.\n";
	std::cout << "  \"planet\" is an isogram, while \"pollen\" is not.\n";
	std::cout << "  Note: for our purposes, isograms have been selected from\n  the 5000 most common English words." << std::endl;
	return;
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " Letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();  //copy
	//std::cout << MaxTries << std::endl; //??? ró¿nica

	
	
	//constexpr int32 NUMBER_OF_TURNS = 5; // inne miejsce !!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	//loop asking for guesses while the game is NOT won
	// is NOT won and there are still tries remaining
	while( ! BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess(); 

		// Submit valid guess to the game, and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}



// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		// get a guess from the player
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " latter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
		//std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //keep looping until we get no errors
	return Guess;
}

bool AskToPlayGame()
{
	std::cout << "Do you want to play again with same hidden word (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}