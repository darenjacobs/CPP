/**  filename bonus_calc.cpp
Author - Daren Jacobs
Date - May 18, 2012
This program calculates the employee bonus based on two items, performance factor and number of years working for the company.  If the performance factor is below 5 the employee receives no bonus.  If the performance factor is 5 or above and the employee has been working fot the company for less than 5 years then the bonus is 1%.  If the performance factor is 5 or above and the employee has been working for the company for 5 or more years then the bonus is 2%.
*/
#include <iostream>

using namespace std;

int main()
{
        string employee_name;
        int years_employed, performance_factor, bonus;

        cout << "Please enter the employee's first name: ";
        cin >> employee_name;

        cout << "Please enter the employee's performance factor (0 to 100) " << endl;
        cin >> performance_factor;

        // check if the performance factor is within range

        while (performance_factor < 0 || performance_factor > 100)
        {
                cout << "The value you entered is outside of the performance factor range.  Please re-enter a value: " << endl;
                cin >> performance_factor;
        }

        if (performance_factor < 5)
                cout << "No Bonus for " << employee_name << endl;
        else
                if (performance_factor >= 5) // prompt user for number of years

                        cout << "How many years has " << employee_name << " been with the company?" << endl;
                        cin >> years_employed;

                        while (years_employed <= 0)
                        {
                                cout << "You entered too few years. re-enter the number of years employed: " << endl;
                                cin >> years_employed;
                        }

                        if (years_employed < 5)
                                cout << employee_name <<"'s bonus is 1% " << endl;
                               
                        else
                                if (years_employed >= 5)

                                        cout << employee_name <<"'s bonus is 2% " << endl;
        return 0;
}              
