#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    string make;
    string model;
    string color;
    int doors;
    int wheels;

    Vehicle(string make, string model, string color, int doors, int wheels) {
        setMake(make);
        setModel(model);
        setColor(color);
        setNod(doors);
        setNoW(wheels);
    }

    virtual ~Vehicle() {}

    // Getters
    string getMake() { return make; }
    string getModel() { return model; }
    string getColor() { return color; }
    int getNod() { return doors; }
    int getNoW() {return wheels; }

    // Setters
    void setMake(string make) { this->make = make; }
    void setModel(string model) { this->model = model; }
    void setColor(string color) { this->color = color; }
    void setNod(int doors) { this->doors = doors; }
    void setNoW(int wheels) { this->wheels = wheels; }

    // Methods
    void display() {
        cout << "Make: " << getMake() << endl;
        cout << "Model: " << getModel() << endl;
        cout << "Color: " << getColor() << endl;
        // only show Number of doors if its more than 0 so motorycles shouldn't show this sentence
        if (getNod() > 0) {
            cout << "Number of Doors: " << getNod() << endl;
        }
    }

    // Helper function to demangle the type name
    string demangle(const char* typeName) {
        while (*typeName &&!isalpha(*typeName)) {
            ++typeName;
        }
        return string(typeName);
    }

    void aboutVehicle(int wheels) {
        cout << "This vehicle is a " << demangle(typeid(*this).name()) << " and has " << wheels << " wheels" << endl;
    }
};

class Motorcycle : public Vehicle { // derived class
public:
    Motorcycle(string make, string model, string color, int doors = 0, int wheels = 2)
        : Vehicle(make, model, color, doors, wheels) {}
};

class Car : public Vehicle { // derived class
public:
    Car(string make, string model, string color, int doors, int wheels = 4)
        : Vehicle(make, model, color, doors, wheels) {}
};

class Suv : public Vehicle { // derived class
public:
    Suv(string make, string model, string color, int doors, int wheels = 4)
        : Vehicle(make, model, color, doors, wheels) {}
};

class Truck : public Vehicle { // derived class
public:
    Truck(string make, string model, string color, int doors, int wheels = 10)
        : Vehicle(make, model, color, doors, wheels) {}
};

int main() {
    Truck t("Cummins", "X15", "White", 2);
    t.aboutVehicle(t.wheels);
    t.display();
    cout << "----------------------" << endl;
    Suv s("Mazda", "CX-90", "Silver", 4);
    s.aboutVehicle(s.wheels);
    s.display();
    cout << "----------------------" << endl;
    Motorcycle m("Honda", "Ninja", "Red");
    m.aboutVehicle(m.wheels);
    m.display();
    cout << "----------------------" << endl;
    Car c("Mitsubishi", "Eclipse", "Red", 2);
    c.aboutVehicle(c.wheels);
    c.display();

    return 0;
}
