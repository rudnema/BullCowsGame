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

FBullCowGame BCGame; //instantiate a new game

// the enetry point of our application
int main()
{
	std::cout << BCGame.GetCurrentTry();

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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " Letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();  //copy
	//std::cout << MaxTries << std::endl; //??? ró¿nica

	//loop for the number of turns asking for guesses
	//TODO change drom FOR to WHILE loop once we are validating ties
	//constexpr int32 NUMBER_OF_TURNS = 5; // inne miejsce !!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetValidGuess(); 

		// Submit valid guess to the game, and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	// TODO summarise  game
}



// loop continually until the user gives a valid guess
FText GetValidGuess()
{

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " latter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //keep looping until we get no errors
}

bool AskToPlayGame()
{
	std::cout << "Do you want to play again ? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'y');
}

