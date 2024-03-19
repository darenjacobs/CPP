#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    string make;
    string model;
    string color;
    int num_doors;
public:
    Vehicle(string make, string model, string color, int num_doors)
    {
        setMake(make);
        setModel(model);
        setNod(num_doors);
        setColor(color);
    }
    virtual ~Vehicle(){}

    // Getters
    string getMake() { return make; }
    string getModel() { return model; }
    string getColor() { return color; }
    int getNod() { return num_doors; }

    // Setters
    void setMake(string make) { this->make = make; }
    void setModel(string model) { this->model = model; }
    void setColor(string color) { this->color = color; }
    void setNod(int num_doors) { this->num_doors = num_doors; }

    // Methods
    void display()
    {
        cout << "Make: " << getMake() << endl;
        cout << "Model: " << getModel() << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Number of Doors: " << getNod() << endl;
    }
    virtual int getNumberOfWheels() const = 0;
};

class Motorcycle : public Vehicle // derived class
{
public:
    Motorcycle(string make, string model, string color, int num_doors)
    : Vehicle(make, model, color, num_doors)
    {
    }
    int getNumberOfWheels() const override {
        return 2;
    }

};

void aboutVehicle(const Vehicle& vehicle)
{
    cout << "This vehicle has " << vehicle.getNumberOfWheels() << " wheels" << endl;
}

int main()
{
    Motorcycle m("Honda", "Ninja", "Red", 0);
    aboutVehicle(m);
    return 0;
}
