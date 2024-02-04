#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Function to generate 5 unique numbers from 1 to 69
std::vector<int> generateUniqueNumbers69() {
    std::vector<int> numbers69;
    for (int i = 1; i <= 69; ++i) {
        numbers69.push_back(i);
    }

    std::random_shuffle(numbers69.begin(), numbers69.end());
    std::vector<int> result(numbers69.begin(), numbers69.begin() + 5);

    return result;
}

// Function to generate 1 number from 1 to 26
int generateNumber26() {
    return (rand() % 26) + 1;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate 5 unique numbers from 1 to 69
    std::vector<int> numbers69 = generateUniqueNumbers69();

    // Generate 1 number from 1 to 26
    int number26 = generateNumber26();

    // Output the generated numbers
    std::cout << "Generated Numbers (1 to 69): ";
    for (int num : numbers69) {
        std::cout << num << " ";
    }

    std::cout << "\nGenerated Number (1 to 26): " << number26 << std::endl;

    return 0;
}
