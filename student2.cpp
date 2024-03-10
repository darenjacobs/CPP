#include <iostream>
#include <string>

using namespace std;

class Student // base class
{
    string name;
    string campus;
    string d_o_b; // date of birth
    string issue_date;
    char gender;
    int id;
public:
    Student(string name, string campus, string d_o_b, string issue_date, char gender, int id ) {
        setName(name);
        setCampus(campus);
        setDob(d_o_b);
        setIssueDate(issue_date);
        setGender(gender);
        setId(id);
    }
    ~Student(){}

    // Getters
    string getName() { return name; }
    string getCampus() { return campus; }
    string getDob() { return d_o_b; }
    string getIssueDate() { return issue_date; }
    char getGender() {return gender; }
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
        cout << "Name: "  << getName() << endl;
        cout << "Campus: "  << getCampus() << endl;
        cout << "Date of Birth: "  << getDob() << endl;
        cout << "Issue Date: "  << getIssueDate() << endl;
        cout << "Gender: "  << getGender() << endl;
        cout << "Student ID Number: "  << getId() << endl;
    }
    void printAbout()
    {
        cout << "I am a student" << endl;
    }

};

class Undergraduate : public Student  // derived class
{
private:
    string year;  // Freshmen Sophomore Junior Senior
public:
    Undergraduate(string year, string name, string campus, string d_o_b, string issue_date, char gender, int id )
    : Student(name, campus, d_o_b, issue_date, gender, id) {
        setYear(year);
    }
    void setYear(string year) { this->year = year; }
    string getYear() { return year; }

    // derived class methods
    void display() {
        cout << "Year: " << getYear() << endl;
        Student::display();
    }
    void printAbout()
    {
        cout << "I am an Undergraduate" << endl;
    }
};

int main()
{
        Student s1("James Brown","Busch","10-12-2001","02-15-2022",'M',100012345);
        Undergraduate u1("Freshman","Michael Oliver","York","04-22-2003","09-02-2024",'M',100012346);
        cout << "\n";
        s1.printAbout();
        s1.display();
        cout << "----------------\n";
        u1.printAbout();
        u1.display();
        return  0;
}
