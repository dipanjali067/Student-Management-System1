#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    int age;
    string course;

public:
    void input()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Course: ";
        getline(cin, course);
    }

    void display() const
    {
        cout << left << setw(10) << rollNo
             << setw(25) << name
             << setw(10) << age
             << setw(20) << course << endl;
    }

    int getRollNo() const
    {
        return rollNo;
    }

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    string getCourse() const
    {
        return course;
    }
};

void addStudent()
{
    Student s;

    ofstream file("students.txt", ios::app);

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    s.input();

    file << s.getRollNo() << "|"
         << s.getName() << "|"
         << s.getAge() << "|"
         << s.getCourse() << endl;

    file.close();

    cout << "\nStudent record added successfully!\n";
}

void displayStudents()
{
    ifstream file("students.txt");

    if (!file)
    {
        cout << "No records found!\n";
        return;
    }

    string line;

    cout << "\n-------------------------------------------------------------\n";
    cout << left << setw(10) << "RollNo"
         << setw(25) << "Name"
         << setw(10) << "Age"
         << setw(20) << "Course" << endl;
    cout << "-------------------------------------------------------------\n";

    while (getline(file, line))
    {
        string roll, name, age, course;

        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);

        roll = line.substr(0, pos1);
        name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        age = line.substr(pos2 + 1, pos3 - pos2 - 1);
        course = line.substr(pos3 + 1);

        cout << left << setw(10) << roll
             << setw(25) << name
             << setw(10) << age
             << setw(20) << course << endl;
    }

    file.close();
}

int main()
{
    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n   STUDENT MANAGEMENT SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Exit";
        cout << "\n====================================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            cout << "\nThank you for using the system!\n";
            break;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
