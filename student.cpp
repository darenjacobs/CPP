#include <iostream>
#include <string>

using namespace std;

class Student // base class
{
        string name;
        int age;
public:
        string getName() { return name; }
        int getAge() { return age; }
        void setName(string name) { this->name = name; }
        void setAge(int age) { this->age = age; }
        void printAbout()
        {
                cout << "I am a student" << endl;
        }

};

class Undergradutate : public Student  // derived class
{
        public:
                void printAbout()
                {
                        cout << "I am an Undergraduate" << endl;
                }

};


int main()
{
        Student s;
        Undergradutate u;
        s.printAbout();
        u.printAbout();
        return  0;
}
