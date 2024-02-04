#include <dlib/svm_threaded.h>
#include <dlib/matrix.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>

using namespace dlib;
using namespace std;

// Define a struct to represent a lottery drawing
struct LotteryDrawing {
    std::vector<int> numbers;
    int powerball;
};

// Function to read data from the Excel file
std::vector<LotteryDrawing> readLotteryData(const std::string& filename) {
    std::vector<LotteryDrawing> data;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    getline(file, line); // Skip the header line

    while (getline(file, line)) {
        std::istringstream ss(line);
        std::string date, numbersStr;
        getline(ss, date, ',');
        getline(ss, numbersStr, ',');

        LotteryDrawing drawing;

        std::istringstream numbersStream(numbersStr);
        std::string number;
        while (getline(numbersStream, number, ' ')) {
            if (number.find('/') != std::string::npos) {
                // Splitting the last number (Powerball) from the others
                drawing.powerball = stoi(number.substr(number.find('/') + 1));
            } else {
                drawing.numbers.push_back(stoi(number));
            }
        }

        data.push_back(drawing);
    }

    return data;
}

int main(int argc, char** argv) {
    // Check if the correct number of command line arguments is provided
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <lottery_data.xlsx>" << endl;
        return EXIT_FAILURE;
    }

    const std::string filename = argv[1];

    // Read the lottery data from the Excel file
    std::vector<LotteryDrawing> lotteryData = readLotteryData(filename);

    // Prepare training data
    std::vector<std::vector<double>> samples;
    std::vector<int> labels;

    for (const auto& drawing : lotteryData) {
        std::vector<double> sample;
        for (int number : drawing.numbers) {
            sample.push_back(static_cast<double>(number));
        }
        sample.push_back(static_cast<double>(drawing.powerball));

        samples.push_back(sample);
        labels.push_back(1);  // All examples are labeled as "1" (positive)
    }

    // Train a simple linear SVM model
    typedef matrix<double, 0, 1> sample_type;
    typedef linear_kernel<sample_type> kernel_type;
    svm_c_linear_trainer<kernel_type> trainer;
    decision_function<kernel_type> df = trainer.train(samples, labels);

    // Make predictions for new numbers
    sample_type new_numbers;
    // TODO: Set the new_numbers vector with your own values or use a prediction mechanism

    double prediction = df(new_numbers);

    // Output the prediction
    cout << "Predicted value: " << prediction << endl;

    return 0;
}
