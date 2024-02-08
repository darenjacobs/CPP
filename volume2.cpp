#include <iostream>

using namespace std;

int main()
{
	const double BOTTLE_VOLUME = 2;
	const double LITER_PER_OUNCE = 0.0296;
	const double CAN_VOLUME = LITER_PER_OUNCE * 12; 
	
	double totalVolume = 0;

	// Read number of bottles

	cout << "Please enter the number of bottles: "; // Display prompt
	int bottles; 
	cin >> bottles; 

	// Start the computation of the total volume
	
	totalVolume = bottles * BOTTLE_VOLUME; 

	// Read number of cans

	cout << "Please enter the number of cans: ";
	int cans; 
	cin >> cans; 

	// Update the total volume

	totalVolume += cans * CAN_VOLUME; 

	cout << "Total volume: " << totalVolume << endl;

	return 0; 
}

