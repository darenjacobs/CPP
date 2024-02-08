#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "Please enter a number between 0 and 100: " ;
	cin >> number;

	while (number < 0 || number > 100)
	{
		cout << "The value you entered is outside the range.  Please re-enter a new value." << endl;
		cin >> number;
	}

	cout << "The value you entered is: " << number << endl;

	return 0;
}
