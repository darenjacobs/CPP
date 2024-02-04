/**  filename calculate_bonus.cpp
Author - Daren Jacobs
Date - May 24, 2012
Using the function calculate_bonus this program calculates the employee bonus based on two items, performance factor and number of years working for the company.  If the performance factor is below 5 the employee receives no bonus.  If the performance factor is 5 or above and the employee has been working fot the company for less than 5 years then the bonus is 1%.  If the performance factor is 5 or above and the employee has been working for the company for 5 or more years then the bonus is 2%.
*/

#include <iostream>

using namespace std;

int calculate_bonus(int performance_factor, int number_of_years) // function that returns the employee bonus 0, 1%, or 2% 
{
	int bonus; // variable for the bonus amount. 
	if (performance_factor < 5) // No bonus if it's less than 5
	{  
		bonus = 0; 
	} 
	
	else if (performance_factor >= 5)
	{
		if (number_of_years < 5)
		{
			bonus = 1;	
		}
		else if (number_of_years >= 5) 
		{
			bonus = 2;
		} 		

	}
	
	return bonus; 

}


int main()
{
        string employee_name; // This was not requested for the assignment but whatever. :) 
        int performance_factor, number_of_years, bonus; // Declare variables for performance factor and number of year employed at the company and bonus.

        cout << "Please enter the employee's first name: ";
        cin >> employee_name;

        cout << "Please enter the employee's performance factor (0 to 100) " << endl;
        cin >> performance_factor;

        while (performance_factor < 0 || performance_factor > 100) // Validate the input - check if performance factor is within range.
        {
                cout << "The value you entered is outside of the performance factor range.  Please re-enter a value: " << endl;
                cin >> performance_factor;
        }


      	cout << "How many years has " << employee_name << " been with the company?" << endl;
      	cin >> number_of_years;

      	while (number_of_years < 0) // Validate the input - check if the years employed is a valid number. 
       	{
       		cout << "You entered too few years. re-enter the number of years employed: " << endl;
                cin >> number_of_years;
       	}                  
      

	bonus = calculate_bonus(performance_factor, number_of_years);  
	if (bonus > 0)
	{
		cout << employee_name <<  "'s bonus is " << calculate_bonus(performance_factor, number_of_years) <<  "%" << endl;
	}

	else
	{
		cout << "No bonus for " << employee_name << endl; // This is just being fancy.  I could state this as employee_name's bonus is 0%.  
	}
	

        return 0;
}
