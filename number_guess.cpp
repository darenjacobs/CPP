#ifdef _WIN32
    #include <cstdlib>
#elif __APPLE__
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
#endif

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime> // Included to use time() function
#include <cctype> // Included to use toupper() function
#include <string>

using namespace std;

int review_guess(int, int); // function that compares the user's guess to the random number.

int main()
{
    //  Constants - change these to change the parameters of the game.
    const int MAX_NUMBER = 1000;  // This is the maximum number the user will guess. Ex: if this number is 5, the game will generate a number from 1 to 5.
    const int MAX_GUESS = 10; // This is the maximum number of guesses the user has to guess the correct random number.
    char play = 'Y'; // Changed to char to handle 'Y' or 'N' input
    string guess_tense; // string to say guess was or guesses were

    while (toupper(play) == 'Y')
    {
        srand(time(0)); // Course material C++ for Everyone page 165. Without this the random number does not change.
        int counter = 0; // Keeps count of the number of user guesses.
        int user_guess = 0; // Declare variable to store the user's guess
        int result = 1; // Holds the result of the review_guess function.
        int guess_array[MAX_GUESS]; // Declare an array of a changeable number of integers to allow a changeable number of guesses.
        int random_number = rand() % MAX_NUMBER + 1; // This creates a random number between 1 and 100. Without the +1 it would be between 0 and 99

        // Code to ask the user to guess.
        cout << "I am thinking of a number from 1 to " << MAX_NUMBER << ".  You get (" << MAX_GUESS << ") guesses.";

        // Once the user reaches the max number of guesses or guesses the correct number the program prompts the user to play again.
        while ((counter != MAX_GUESS) && (result != 0))
        {
            // Prompt the user to guess a number.
            // if counter is 0 this is the user's first guess, so I will ask "Please guess".
            // If counter is greater than 0 then the user has guessed once before so I will ask the user to "Guess again."
            if (counter == 0)
            {
                cout << endl << "Please guess: " << endl;
            }
            else
            {
                cout << endl;
            }

            cin >> user_guess;

            // Replaced guess_array[counter]; counter += 1; with the line below.
            // This serves two purposes. It increments the counter variable and fills the guess array elements with the user's current guess.
            guess_array[counter++] = user_guess;

            // Display previous guesses
            if (counter == 1)
            {
                guess_tense = "guess was";
                cout << "Your previous " << guess_tense << ": " << guess_array[0] << "." << endl;
            }
            else
            {
                guess_tense = "guesses were";
                cout << "Your previous " << guess_tense << ": ";
                for (int k = 0; k < counter; k++)
                {
                    cout << guess_array[k] << " ";  // Outputs the user guesses.
                }
                cout << endl;
            }

            // Call the function review_guess to compare the guess to the random number
            result = review_guess(user_guess, random_number);

            if (result != 0)
            {
                switch (result) // if result function returns -1 then the user's guess is too low, 1 the user's guess is too high, 0 the user's guess matches.
                {
                case -1:  cout << endl << "The number " << user_guess << " is too low, try again. Guess again: "; break;
                case  1:  cout << endl << "The number " << user_guess << " is too high, try again. Guess again: "; break;
                }
            }
            else
            {
                cout << endl << "Congratulations, you guessed the correct number!" << endl;
            }

            if (counter >= MAX_GUESS && result != 0)
            {
                cout << endl << "Sorry, the number I was thinking was " << random_number << ". Please try again." << endl;
                break;
            }
        }

        cout << "Do you want to play again? Enter Y for yes or N for no: ";
        cin >> play;
        #ifdef _WIN32
            system("cls");
        #elif __APPLE__
            system("clear");
        #endif
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
    return 0;
}
