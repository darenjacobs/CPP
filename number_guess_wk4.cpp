/*
Filename - number_guess_wk4.cpp
Author - Daren Jacobs
Class - PRG/410
Instructor - MAZEN HAJ-HUSSEIN
Date - May 30, 2012 (Week 4 assignment)

Program description
This program generates a random number and prompts the user to guess the random number.
It calls the function review_guess to compare the user guess to the random number.
If the users guess is too low the program should tell the user the guess is too low.
If the guess is too high the program should tell the user the guess is too high. If
the user guess is the correct the program should congratulate the user and prompt to
play again.

Add functionality to store the guesses the user makes in an array up to a maximum number
of guesses stored in a constant. Display a list of previous guesses before the user
guesses a new number each time. Only display the list after the first guess is made. If
the user reaches the maximum number of guesses before they guess the correct number,
display a message and end the loop. As in Week Three, allow the user to decide if he or
she wants to play another game.
*/

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <inttypes.h>
#include <stddef.h>

using namespace std;

int review_guess(int, int); // function that compares the user's guess to the random number.

int main()
{
	//  Constants - change these to change the parameters of the game.
	const int MAX_NUMBER = 100;  // This is the maximum number the user will guess. Ex: if this number is 5, the game will generate a number from 1 to 5.
	const int MAX_GUESS = 10; // This is the maximum number of guesses the user has to guess the correct random number.
	int play = 1;

	while (play == 1)
	{
		srand(time(0)); // Course material C++ for Everyone page 165. Without this the random number does not change.
		int counter = 0; // Keeps count of the number of user guesses.
		int user_guess = 0; // Declare variable to store the user's guess
		int result = 1; // Holds the result of the review_guess function.
		int guess_array [MAX_GUESS]; // Declare an array of a changeable number of integers to allow a changeable number guessses.
		int random_number = rand() % MAX_NUMBER +1; // This creates a random number between 1 and 100.  Withouth the +1 the it would be between 0 and 99

		// Code to ask the user to guess.
		cout << "I am thinking of a number from 1 to " << MAX_NUMBER << ".  You get (" << MAX_GUESS << ") guesses.";

		// Once the user reaches the max number of guesses or guesses the correct number the proogram prompts the user to play again.
		while ((counter != MAX_GUESS) && (result != 0))
		{
			// Prompt the user to guess a number.
			// if counter is 0 this is the user's first guess, so I will ask "Please guess".  If counter is greater than 0 then the user has guesses once before so I will ask the user to "Guess again."
			if (counter == 0)
			{
				cout << endl << "Please guess: " << endl;
			}
			else
			{
				cout << endl << "Guess again: " << endl;
			}

			cin >> user_guess;

			// Replaced guess_array[counter]; counter += 1; with the line below.
			guess_array[counter++] = user_guess; // This serves two purposes. It increments the counter variable and fills the guess array elements with the user's current guess.

			// Display previous guesses
			if (counter == 1) // if counter is one then the user has only made one guess so the word guess should be singular.  Thanks to my wife for pointing that out.
			{
				cout << "Your previous guess was: ";
			}
			else // Otherwise the user has made more than one guess so the word guesses should be plural.
			{
				cout << "Your previous guesses were: ";
			}

			for (int k = 0; k < counter; k++) // Loops through the user guesses. Putting 'k < MAX_GUESS' in the for-loop causes extraneous numbers in the cout line below.  Why???
			{
				cout << guess_array[k] << " ";  // Outputs the user guesses.
			}

			// Call the function review_guess to compare the guess to the random number
			result = review_guess(user_guess, random_number);

			switch (result) // if result function returns -1 then the user's guess is too low, 1 the user's guess is too high, 0 the user's guess matches.
			{
				case -1:  cout << endl << "The number is too low, try again." << endl; break;
				case  1:  cout << endl << "The number is too high, try again." << endl; break;
				case  0:  cout << endl << "Congradulations, you guessed the correct number!" << endl; break;
			}

			if (counter >= MAX_GUESS)
			{
				cout << endl << "Sorry, the number I was thinking was " << random_number << ". Please try again." << endl;
			}
		}

		cout << "Do you want to play again?  Enter 1 for yes." << endl;
		cin >> play;
	}
	cout << "Thank you for playing";
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
