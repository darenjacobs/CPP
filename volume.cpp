#include <iostream>

using namespace std;

/*
	This program computes the volume (in liters of a six-pack of soda cans.

*/
int main()
{
	int cansPerPack = 6;
	double canVolume = 0.355; // Liters in a 12-ounce can

	cout << "A six-pack of 12-ounce cans contains "
	   << cansPerPack * canVolume << " liters." << endl;

	return 0;

}
