#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Read price per pack

	cout << "Please enter the price for a six-pack: ";
	double packPrice;
	cin >> packPrice;

	// Compute pack volume

	const double LITER_PER_OUNCE = 0.0296;
	double CAN_VOLUME = 12 * LITER_PER_OUNCE;
	double PACK_VOLUME = 6 * CAN_VOLUME;

	// Compute and print price per liter

	double pricePerLiter = packPrice / PACK_VOLUME;

	cout << fixed << setprecision(2);
	cout << "Price per liter: " << pricePerLiter << endl;

	return 0;

}
