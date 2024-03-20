#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
public:
    string make;
    string model;
    string color;
    int num_doors;
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
    void aboutVehicle(int wheels)
    {
        cout << "This vehicle has " << wheels << " wheels" << endl;
    }
};

class Motorcycle : public Vehicle // derived class
{
public:
    int wheels = 2;
    Motorcycle(string make, string model, string color, int num_doors)
    : Vehicle(make, model, color, num_doors) { }
};


class Car : public Vehicle // derived class
{
public:
    int wheels = 2;
    Car(string make, string model, string color, int num_doors)
    : Vehicle(make, model, color, num_doors) { }
};


int main()
{
    Motorcycle m("Honda", "Ninja", "Red", 0);
    m.aboutVehicle(m.wheels);
    m.display();
    cout << "----------------------" << endl;
    Car c("Mitsubishi", "Eclipse", "Red", 2);
    c.aboutVehicle(c.wheels);
    c.display();


    return 0;
}
