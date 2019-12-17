#include <iostream>
#include <string>
#include "FBullCowsGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcone to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " Letter isogram I'm thinking of \n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();  //copy
	//std::cout << MaxTries << std::endl; //??? ró¿nica

	//loop for the number of turns asking for guesses
	//TODO change drom FOR to WHILE loop once we are validating ties
	constexpr int NUMBER_OF_TURNS = 5; // inne miejsce !!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		std::string Guess = GetGuess(); // TODO make loop checking valid

		// Submit valid guess to the game
		// Print number of bulls and cows


		std::cout << "You guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
	// TODO summarise  game
}

std::string GetGuess() 
{
	int CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayGame()
{
	std::cout << "Do you want to play again ? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'y');
}

