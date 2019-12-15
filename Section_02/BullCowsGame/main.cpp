#include <iostream>
#include <string>

using namespace std;

void PrintIntro();

// the entry point for our application
int main()
{
	PrintIntro();
	

	// get a guess from player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);


	// repeat the guess back to them
	cout << "Your guess was:" << Guess << endl;
	


	// get a guess from player
	cout << "Enter your guess: ";

	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was:" << Guess << endl;





	cout << endl;
	
	// CZAS NA ODPOCZYNEK I PIZZE



	return 0;

}
void PrintIntro() {
	// introduce the game
	constexpr int WORLD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game";
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking  of?\n";
	cout << endl;
	return;
}