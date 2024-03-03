// clang++ -std=c++11 destructors.cpp -o destructors
// https://www.codesdope.com/cpp-subclass/
#include <iostream>
#include <string>
using namespace std;

class HomePet {
protected:
    string* color; // Let's say we now allocate color dynamically
    string name;
    int age;
public:
    HomePet() : color(new string("Unknown")), name("Unknown"), age(0) {}
    HomePet(string color, string name, int age) : color(new string(color)), name(name), age(age) {}
    virtual ~HomePet() {
        cout << "Destroying HomePet " << name << endl;
        delete color; // Free dynamically allocated memory
    }
    void setColor(string color) { *(this->color) = color; }
    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    string getColor() { return *color; }
    string getName() { return name; }
    int getAge() { return age; }
    virtual void display() {
        cout << "Name: " << getName() << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Age: " << getAge() << endl;
    }
    virtual void breath() {
        cout << "Inspiration and expiration occur." << endl;
    }
};

class Dog : public HomePet {
private:
    string* earsSize; // Assume this is also dynamically allocated
public:
    Dog(string earsSize, string color, string name, int age) : HomePet(color, name, age), earsSize(new string(earsSize)) {}
    ~Dog() {
        cout << "Destroying Dog " << name << endl;
        delete earsSize; // Free dynamically allocated memory
    }
    void setEarsSize(string earsSize) { *(this->earsSize) = earsSize; }
    string getEarsSize() { return *earsSize; }
    void display() override {
        HomePet::display();
        cout << "Ears Size: " << getEarsSize() << endl;
    }
};

int main() {
    Dog d("small", "black", "Nick", 7);
    d.display();
    d.breath();
    // Dog 'd' will be automatically destroyed when it goes out of scope
    // This will trigger the Dog destructor, then the HomePet destructor
    return 0;
}
