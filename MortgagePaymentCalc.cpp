/**  filename MortgagePaymentCalc.cpp
Author - Learn Team A: Eric Bruggerman, Jennifer Green, Daren Jacobs, Jamon Oliver
Class PRG/410
Instructor - Mazen Haj-Hussein
Date - May 27, 2012

Description:
Write the program as a procedural C++ program. Allow the user to input the amount of a mortgage and then select from a menu of mortgage loans:
•	7 year at 5.35%
•	15 year at 5.5%
•	30 year at 5.75%
Use an array for the different loans. Display the mortgage payment amount. Then, list the loan balance and interest paid for each payment over
the term of the loan. On longer-term loans, the list will scroll off the screen. Do not allow the list to scroll off the screen, but rather
display a partial list and then allow the user to continue the list. Allow the user to loop back and enter new data or quit. Insert comments
in the program to document the program.

*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void userPrompt(); // Function that prompts the user to input information.  It contains the user menu
void displayMonthlyPayment(double, double, double, int); // function that calculates the monthly payment.  It scrolls the payment number, interest paid and balance.
double calculateMonthlyPayment(double, double, int); // calculates the monthly payment.


int main()
{
	userPrompt();
		return 0;
}

void userPrompt()
{
	double loanAmount = 0.0; // initialize the loan amount to 0.
	int term[] = {7, 15, 30};  // creates an array for terms position 0 = 7, position 1 = 15, position 2 = 30
	double interestRate[] = {5.35, 5.5, 5.75};  // creates an array
	int termRate = 0;

	// Mortgage loan menu
	cout << "----------------- Mortgage Payment Calculator -----------------" << endl;

	cout << "Please enter mortgage loan amount without comas ex: 200000" << endl;
	cin >> loanAmount; // enter loan amount

	while (loanAmount < 0 ) // Validate user input
	{
		cout << "The amount you entered is too low.  Please inter a valid mortgage loan amount: " << endl;
		cin >> loanAmount; // enter loan amount if initial value was invalid
	}

	cout << "---------- Mortgage loan Rates ----------" << endl;
	cout << "1: " << term[0] << " year term at " << interestRate[0] << "% interest rate" << endl;
	cout << "2: " << term[1] << " year term at " << interestRate[1] << "% interest rate" << endl;
	cout << "3: " << term[2] << " year term at " << interestRate[2] << "% interest rate" << endl;
	cout << "0: Quit the program" << endl;
	cin >> termRate; // choose term/rate combo or exit program.

	switch (termRate)
	{
		case 1: {calculateMonthlyPayment(loanAmount, interestRate[0], term[0]);} break;
		case 2: {calculateMonthlyPayment(loanAmount, interestRate[1], term[1]);} break;
		case 3: {calculateMonthlyPayment(loanAmount, interestRate[2], term[2]);} break;
		case 0: {cout << "Have a nice day!" << endl;} break;
		default: {cout << "Please enter a valid selection" << endl;} break;
	}
}

// Calculate everything
double calculateMonthlyPayment(double loanAmount, double interestRate, int term)
{
	double monthlyInterestRate = interestRate / (100 * 12);
	int totalMonths = term * 12;
	double monthlyPayment = loanAmount * monthlyInterestRate / (1 - pow(1+ monthlyInterestRate, -totalMonths)); // borrowed from Java course.

	// display it now
	displayMonthlyPayment(monthlyPayment, loanAmount, monthlyInterestRate, totalMonths);
	return monthlyPayment;
}

void displayMonthlyPayment(double monthlyPayment, double amount, double monthlyInterestRate, int totalMonths)
{
	cout << "Monthly payment: " << monthlyPayment << endl << endl; // monthlyPayment is passed from calculateMonthlyPayment

	// Declare variables for the for loop.
	double interestPaid = 0.0;
	double principalPaid = 0.0;
	double loanBalance = 0.0;
	int tryAgain = 1; // integer to choose whether to continue or exit the program.

	for (int k = 1; k <= totalMonths; k++)
	{
		// Calculate and display new loan balance for the curent month
		interestPaid = amount * monthlyInterestRate;
		principalPaid = monthlyPayment - interestPaid;
		loanBalance = amount - principalPaid;
		amount = loanBalance;
		cout << k << " $" << setprecision(2) << fixed << interestPaid << " $" << setprecision(2) << fixed << loanBalance << endl << endl;

		if (k == 10)
		{
				system("PAUSE");
		}
	}

	cout <<"Try again?  1: Yes or 2: No" << endl;
	cin >> tryAgain;
	if (tryAgain == 1)
	{
	 	userPrompt();
	}
	else
	{
		exit(0);
	}
}
