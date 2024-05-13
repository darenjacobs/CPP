#include <iostream>
using namespace std;
class HomePet {
protected:
    string color;
    string name;
    int age;
public:
    HomePet() {
        setColor("Unknown");
        setName("Unknown");
        setAge(0);
    }
    HomePet(string color, string name, int age) {
        setColor(color);
        setName(name);
        setAge(age);
    }
    ~HomePet(){}
    void setColor(string color) {this->color = color;}
    void setName(string name) {this->name = name;}
    void setAge(int age) {this->age = age;}
    string getColor() {return this->color;}
    string getName() {return this->name;}
    int getAge() {return this->age;}
    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Age: " << getAge() << endl;
    }
    void breath() {
        cout << "Inspiration occurs when the diaphragm and the external intercostal muscles contract.  Expiration occurs when the diaphragm and the intercostal muscles relax.\n" << endl;
    }
};

class Dog:public HomePet {
private:
    string earsSize; // small, medium, large
public:
    Dog(string earsSize, string color, string name, int age) {
        setEarsSize(earsSize);
        // You can set age color and name in several ways.  See the Bird function below.
        // it looks like this: Bird(double beakLength, string color, string name, int age):HomePet(color,name,age) {

        // You can set name color and age as follows:
        this->setAge(age);
        this->setColor(color);
        this->setName(name);
    }
    ~Dog() {}
    void setEarsSize(string earsSize){this->earsSize = earsSize;}
    string getEarsSize(){return earsSize;}
    void display() {
        HomePet::display();
        cout << "Ears Size: " << getEarsSize() << endl;
    }
};

class Bird:public HomePet {
private:
    double beakLength;
public:
    Bird(double beakLength, string color, string name, int age):HomePet(color,name,age) {
        setBeakLength(beakLength);
    }
    ~Bird(){}
    void setBeakLength(double beakLength) {this->beakLength = beakLength;}
    double getBeakLength() {return beakLength;}
    void display() {
        HomePet::display();
        cout <<  "Beak Length: " << getBeakLength() << endl;
    }
};

class Fish:public HomePet {
private:
    double finLength;
public:
    Fish(double finLength, string color, string name, int age):HomePet(color,name,age) {
        setFinLength(finLength);
    }
    ~Fish(){}
    void setFinLength(double finLength) {this->finLength = finLength;}
    double getFinLength(){return finLength;}
    void display() {
        HomePet::display();
        cout <<  "Fin Length: " << getFinLength() << endl;
    }
    void breath() {
        cout << "Gills are tissues made up of feathery structures called gill filaments that provide a large surface area for gas exchange.  Fish take in oxygen-rich water through their mouths and pump it over their gills\n" << endl;
    }

};

int main() {
    // Set the animal properties
    Dog d1("small","black","Nick",7);
    Bird b1(1.02,"yellow","Snoop",3);
    Fish f1(2.25,"gold","Nemo",1);

    // display the animal properties
    d1.display();
    d1.breath();
    cout << "----------------------------\n";
    b1.display();
    b1.breath();
    cout << "----------------------------\n";
    f1.display();
    f1.breath();
    cout << "Press Enter to Exit...";
    getchar();
    return 0;
}
