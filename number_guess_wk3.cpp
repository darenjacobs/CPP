/*
Filename - number_guess_wk3.cpp
Author - Daren Jacobs
Class - PRG/410
Instructor - MAZEN HAJ-HUSSEIN
Date - May 24, 2012 (Week 3 assignment)

Program description
This program generates a random number and prompts the user to guess the random number.
It calls the function review_guess to compare the user guess to the random number.
If the users guess is too low the program should tell the user the guess is too low.
If the guess is too high the program should tell the user the guess is too high. If
the user guess is the correct the program should congradulate the user and prompt to
play again.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int review_guess(int, int);


int main()
{
	int play_again = 1; // Holds the result of the prompt to the user to play again.

	while (play_again == 1)
	{
		srand(time(0)); // Course material C++ for Everyone page 165. Without this the random number does not change.
		int user_guess; // Declare variable to store the user's guess
		int result = 1; // Holds the result of the review_guess function.  Must be set to 1 because if it is set to 0 the while loop will not work.
		int random_number = rand() % 100 +1; // This creates a random number between 1 and 100.  Withouth the +1 the it would be between 0 and 99

		while (result != 0)
		{
			// Prompt the user to guess a number.
			cout << "Guess a number from 1 to 100: " << endl;
			cin >> user_guess;

			// Call the function review_guess to compare the guess to the random number
			result = review_guess(user_guess, random_number);

			switch (result)
			{
				case -1: cout << "The number is too low, try again." << endl; break;
				case 1:  cout << "The number is too high, try again." << endl; break;
				case 0:  cout << "Congradulations, you guessed the correct number!" << endl; break;
			}
		}

		cout << "Do you want to play again?  Enter 1 for yes" << endl;
		cin >> play_again;
	}

	cout << "Thank you for playing" << endl;

	return 0;
}

int review_guess(int user_guess, int random_number) // Function to compare user's guess to the random number
{
	if (user_guess == random_number) // if the user guess matches the random number return 0
	{
		return 0;
	}
	else if (user_guess > random_number) // if the user guess is greater than the random number return 1
	{
		return 1;
	}
	else if (user_guess < random_number) // if the user guess is less than the random number return -1
	{
		return -1;
	}
}
