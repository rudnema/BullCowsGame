#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// the entry point for our application
int main()
{
	PrintIntro();

	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{ 
	GetGuessAndPrintBack();
	cout << endl;
	}
	cout << endl;
	//delete
	// get a guess from player
	//cout << "Enter your guess: ";
	//(cin, Guess);
	// repeat the guess back to them
	//cout << "Your guess was:" << Guess << endl;

	// CZAS NA ODPOCZYNEK I PIZZE

	return 0;

}

// introduce the game
void PrintIntro() {
	
	constexpr int WORLD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game";
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking  of?\n";
	cout << endl;
	return;
}
// get a guess from player
string GetGuessAndPrintBack()
{
	// get a guess from player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);


	// print guess back
	cout << "Your guess was:" << Guess << endl;
	return Guess;
}
