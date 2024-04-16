#include <iostream>
#include <string>

using namespace std;

// Base class representing a Student
class Student {
    // Instance variables
    string name;
    string campus;
    string d_o_b; // date of birth
    string issue_date;
    char gender;
    int id;

public:
    // Constructor
    Student(string name, string campus, string d_o_b, string issue_date, char gender, int id) {
        setName(name);
        setCampus(campus);
        setDob(d_o_b);
        setIssueDate(issue_date);
        setGender(gender);
        setId(id);
    }

    // Destructor
    ~Student() {}

    // Getters
    string getName() { return name; }
    string getCampus() { return campus; }
    string getDob() { return d_o_b; }
    string getIssueDate() { return issue_date; }
    char getGender() { return gender; }
    int getId() { return id; }

    // Setters
    void setName(string name) { this->name = name; }
    void setCampus(string campus) { this->campus = campus; }
    void setDob(string d_o_b) { this->d_o_b = d_o_b; }
    void setIssueDate(string issue_date) { this->issue_date = issue_date; }
    void setGender(char gender) { this->gender = gender; }
    void setId(int id) { this->id = id; }

    // Methods
    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Campus: " << getCampus() << endl;
        cout << "Date of Birth: " << getDob() << endl;
        cout << "Issue Date: " << getIssueDate() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Student ID Number: " << getId() << endl;
    }

    void printAbout() {
        cout << "I am a student" << endl;
    }
};

// Derived class representing an Undergraduate student
class Undergraduate : public Student {
    // Instance variable
    string year; // Freshmen Sophomore Junior Senior

public:
    // Constructor
    Undergraduate(string year, string name, string campus, string d_o_b, string issue_date, char gender, int id)
        : Student(name, campus, d_o_b, issue_date, gender, id) {
        setYear(year);
    }

    // Setter
    void setYear(string year) { this->year = year; }

    // Getter
    string getYear() { return year; }

    // Derived class methods
    void display() {
        cout << "Year: " << getYear() << endl;
        Student::display();
    }

    void printAbout() {
        cout << "I am an Undergraduate" << endl;
    }
};

int main() {
    // Create a Student object
    Student s1("James Brown", "Busch", "10-12-2001", "02-15-2022", 'M', 100012345);

    // Create an Undergraduate object
    Undergraduate u1("Freshman", "Michael Oliver", "York", "04-22-2003", "09-02-2024", 'M', 100012346);

    // Print information about the Student object
    cout << "\n";
    s1.printAbout();
    s1.display();
    cout << "----------------\n";

    // Print information about the Undergraduate object
    u1.printAbout();
    u1.display();

    return 0;
}