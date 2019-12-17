#include <iostream>
#include <string>
//
using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayGame();

// the enetry point of our application
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayGame();
	} while (bPlayAgain);
	// CZAS NA ODPOCZYNEK I PIZZE

	cout << endl;
	return 0;   //exit the application
}



//introduse the game 
void PrintIntro()
{
	constexpr int WORLD_LENGTH = 9;
	cout << "Welcone to Bulls and Cows";
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " Letter isogram I'm thinking of \n";
	cout << endl;
	return;
}

void PlayGame()
{
	//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		string Guess = GetGuess();
		cout << "You quess wa: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess()
{
	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayGame()
{
	cout << "Do you want to play again (y/n)? ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'y');
}