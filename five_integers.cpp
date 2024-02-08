/**  filename five_integers_v2.cpp
Author - Daren Jacobs
Date - May 30, 2012

Description:
This program defines an array of 5 integers, has a loop that reads the values of the array from the user, has another loop that traverses
the array and displays the values on one line separating the values by a space.

For example the execution may look like this:

Enter the value of element 0 ==> 34
Enter the value of element 1 ==> 6
Enter the value of element 2==> -5
Enter the value of element 3 ==> 55
Enter the value of element 4 ==> 0

The values you entered are : 34 6 -5 55 0

Add another loop to compute and displays the smallest value in the array on a separate line. For example the execution may look like this:

The values you entered are : 34 6 -5 55 0
The smallest value you entered is : -5

*/

#include <iostream>

using namespace std;


int main()
{
	const int NUMBER_OF_ELEMENTS = 5; //  This is cleaner way of setting the number of elements in the array
	int numbers[NUMBER_OF_ELEMENTS]; // Declare an array of 5 integers since nubmer_of_elements is 5

	for (int k = 0; k < NUMBER_OF_ELEMENTS; k++)  // Loops 5 times to accept the user input. k is just a random for-loop integer
	{
		cout << "Enter the value of element " << k << " ==> "; // outputs to the screen five times asking the user for input.  The first element is 0. The last element is 4.
		cin >> numbers[k]; // accepts the user input the k is the place holder in the array.
	}

	cout << endl << "The values you entered are: ";  // Outputs to the screen the sentence "The values your entered are: "

	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)  // Loops 5 times to output the numbers the user entered.  i is just a random for-loop integer
	{
		cout << numbers[i] << " "; // i is the place holder for the element number in the array.
	}

	cout << " " << endl; // this just adds a line after the sentence " The values you entered are: "

	int smallest = numbers[0]; // I think this has to be here in order to set smallest to the FIRST value in the array.

	for ( int j = 1; j < NUMBER_OF_ELEMENTS; j++)
	{
		if (numbers[j] < smallest) // compares the current value of smallest to the array element.
		{
			smallest = numbers[j];  // if that element value is smaller than the existing value of smallest then change smallest to that element's value.
		}

	}

	cout << "The smallest value you entered is: " << smallest << endl;  // Outputs to the scren "The smallest value you entered is" + the value of smallest.

	return 0; // returns 0 if all is well.
}
