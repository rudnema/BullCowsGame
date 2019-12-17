#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayGame();

// the enetry point of our application
int main()
{
	bool bPlayAgain = false;
	do {
	PrintIntro();
	PlayGame();
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
	constexpr int WORLD_LENGTH = 9;
	std::cout << "Welcone to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " Letter isogram I'm thinking of \n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		std::string Guess = GetGuess();
		std::cout << "You quess wa: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() 
{
	//get a guess from the player
	std::cout << "Enter your guess: ";
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

