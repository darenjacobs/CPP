#include <iostream>
#include <iomanip>
#include<math.h>

using namespace std;

double calculateMonthlyPayment(double, double, int);
void displayMonthlyPayment(double, double, int);

int main()
{
	double loanAmount = 200000;
	int term[] = {7,15,30};
	double rate[] = {5.35, 5.50, 5.75};
	char choice = 'N'; //calculate again or quit program
	double monthlyPayment = 0;

	cout<<"******** MORTGAGE PAYMENT CALCULATOR *******"<<endl<<endl;

	while (toupper(choice) != 'Q' )
	{
		cout<<endl;
		// User menu display
		cout<<"******** Selection Menu *******"<<endl;
		cout<<"(1):  7 years at 5.35% interest"<<endl;
		cout<<"(2): 15 years at 5.50% interest"<<endl;
		cout<<"(3): 30 years at 5.75% interest"<<endl;
		cout<<"(Q): Quit program"<<endl;
		//prompt for input
		cout<<"Please enter your choice:";
		cin>>choice;

		switch(choice)
		{
		case '1':
			monthlyPayment = calculateMonthlyPayment(loanAmount, rate[0], term[0]);
			cout<<"Monthly payment is :"<<monthlyPayment<<endl<<endl;
			displayMonthlyPayment(loanAmount, rate[0], term[0]);
			break;
		case '2':
			monthlyPayment = calculateMonthlyPayment(loanAmount, rate[1], term[1]);
			cout<<"Monthly payment is :"<<monthlyPayment<<endl<<endl;
			displayMonthlyPayment(loanAmount, rate[1], term[1]);
			break;
		case '3':
			monthlyPayment = calculateMonthlyPayment(loanAmount, rate[2], term[2]);
			cout<<"Monthly payment is :"<<monthlyPayment<<endl<<endl;
			displayMonthlyPayment(loanAmount, rate[2], term[2]);
			break;
		case 'Q':
		case 'q':
			break;
		default:
			cout<<"Invalid Input\nPlease try again"<<endl;

		}
	}

	cout<<endl;

	system("PAUSE");
    return (0);
}//end of main

//method to calculate monthly payment
double calculateMonthlyPayment(double amt, double rate, int year)
{
	double mrate = rate/1200.0;
	int months = year*12;
	double monthlyPayment = (amt * mrate) / (1 - pow(1+mrate,-months)); //formula to calculate mortgage payment amount

	return monthlyPayment;
}

//method to diaplay monthly payment
void displayMonthlyPayment(double amt, double rate, int year)
{
	double total = amt;
	double mrate = rate/1200.0;
	double monthlyPayment = calculateMonthlyPayment(amt, rate, year);
	int count=1;

	cout <<setw(10)<<"Payment #"<<setw(10)<<"Principle"<<setw(20)<<"Balance Paid"<<setw(19)<<"Interest Paid \n";

	for(int y=1; y<=year; y++)
	{
		for(int m=1; m<=12; m++)
		{
			// calculate interest paid
			double interest = total * mrate;
			// calculate left loan amount
			total -= (monthlyPayment - interest);

			// print loan balance and interest paid for each payment
   		cout << setw(5) <<right <<(count++);
			cout << setw(15) <<right << fixed<<setprecision(2) << total;
			cout << setw(15) <<right <<setprecision(2) <<(monthlyPayment - interest);
			cout << setw(15) <<right <<setprecision(2) <<interest;
			cout<<endl;
		}
		system("PAUSE");
	}
}
