#include <iostream>
using namespace std;

struct Student {
    string name;
    int roll;
    float marks;
};

int main() {
   
    Student student;

 
    cout << "Enter student name: ";
    cin >>student.name;

    cout << "Enter roll number: ";
    cin >> student.roll;

    cout << "Enter marks: ";
    cin >> student.marks;

  
    cout << "\nStudent Information:" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.roll<<endl;
    cout<<"Marks:"<<student.marks<<endl;
    return 0;
}

