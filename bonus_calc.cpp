/**  filename bonus_calc.cpp
Author - Daren Jacobs
Date - May 19, 2012
This program calculates the employee bonus based on two items, performance factor and number of years working for the company.  If the performance factor is below 5 the employee receives no bonus.  If the performance factor is 5 or above and the employee has been working fot the company for less than 5 years then the bonus is 1%.  If the performance factor is 5 or above and the employee has been working for the company for 5 or more years then the bonus is 2%.
*/
#include <iostream>

using namespace std;

int main()
{
    string employee_name;

    // Declare variables for performance factor and number of year employed at the company.
    int performance_factor, number_of_years;

    cout << "Please enter the employee's first name: ";
    cin >> employee_name;

    cout << "Please enter the employee's performance factor (0 to 100): ";
    cin >> performance_factor;

    // check if the performance factor is within range
    while (performance_factor < 0 || performance_factor > 100)
    {
        cout << "The value you entered is outside of the performance factor range.  Please re-enter a value: ";
        cin >> performance_factor;
    }

    if (performance_factor < 5)
    {
        cout << "No Bonus for " << employee_name << endl; // If the performance factor is below 5 the program should end.
    }
    else if (performance_factor >= 5) // Since peformance factor meets the criteria to receive a bonus prompt user for number of years to find out bonus percentage.
    {
        cout << "How many years has " << employee_name << " been with the company?: ";
        cin >> number_of_years;

        // Check if years employed is a valid number.
        while (number_of_years < 0)
        {
            cout << "You entered too few years. re-enter the number of years employed: ";
            cin >> number_of_years;
        }

        if (number_of_years < 5) // If the employee has worked less that 5 years the bonus is 1%.
        {
            cout << employee_name << "'s bonus is 1% " << endl;
        }
        else if (number_of_years >= 5) // If the employee has worked 5 years or more the bonus is 2%.
        {
            cout << employee_name << "'s bonus is 2% " << endl;
        }
    }

    return 0;
}