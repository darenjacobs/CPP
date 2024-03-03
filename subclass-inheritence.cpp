// https://www.codesdope.com/cpp-subclass/
#include <iostream>
#include <string>

using namespace std;

class Student	//base class
{
	string name;
	public:
		string getName()
		{
			return name;
		}
		void setName( string n )
		{
			name = n;
		}
		void printAbout()
		{
			cout << "I am a student" << endl;
		}
};

class Undergraduate : public Student	//derived class
{
	public:
		void printAbout()
		{
			cout << "I am an Undergraduate" << endl;
		}
};

int main()
{	Student s;
	Undergraduate u;
	s.printAbout();
	u.printAbout();
	return 0;
}
