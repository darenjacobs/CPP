/**
filename number_guess.cpp
Author - Daren Jacobs
Date - May 18, 2012

This program generates a random number and prompts the user to guess the random number. The user gets to guess until guessing the correct number.  If the users guess is too low the program should tell the user the guess is too low.  If the guess is too high the program should tell the user the guess is too high.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int user_guess; // Declare variable to store the user's guess
	srand(time(0)); // Course material C++ for Everyone page 165. Without this the random number does not change.
	int random_number = rand() % 100 +1; // This creates a random number between 1 and 100.  Withouth the +1 the it would be between 0 and 99

	do
	{
		// Prompt the user to guess a number.
		cout << "Guess a number from 1 to 100: " << endl;
		cin >> user_guess;

		if (user_guess < random_number) // The user's guess is lower than the random number.
		{
			cout << "The number is too low, try again." << endl; // Tell the user the guess is too low
		}
		else if (user_guess > random_number) // The user's guess is higher than the random number.
		{
			cout << "The number is too high, try again." << endl;
		}
		else if (user_guess == random_number) // The user's guess is correct.  This should theorhetically come after the do-while loop.
		{
			cout << "Congradulations, you guessed the correct number!" << endl;
		}
	}
	while (random_number != user_guess);

	return 0;
}
