#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    string make;
    string model;
    string color;
    int num_of_wheels;
    int num_of_doors;
public:
    Vehicle(string make, string model, string color, int num_of_wheels, int num_of_doors) {
        setMake(make);
        setModel(model);
        setNow(num_of_wheels);
        setNod(num_of_doors);
        setColor(color);
    }
    ~Vehicle(){}

    // Getters
    string getMake(){ return make; }
    string getModel(){ return model; }
    string getColor(){ return color; }
    int getNow() { return num_of_wheels; }
    int getNod() { return num_of_doors; }
};

int main()
{
    return 0;
}
