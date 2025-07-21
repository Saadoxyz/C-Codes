#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name;
    int numSubjects;
    int* marksPerSubject;

public:
    void accept() {
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Number of Subjects: ";
        cin >> numSubjects;

        marksPerSubject = new int[numSubjects];
        cout << "Enter Marks for each Subject: ";
        for (int i = 0; i < numSubjects; ++i) {
            cin >> marksPerSubject[i];
        }
    }

    void display() {
        cout << "Student ID: " << id << "\nStudent Name: " << name << "\nMarks: ";
        for (int i = 0; i < numSubjects; ++i) {
            cout << marksPerSubject[i] << " ";
        }
        cout << endl;
    }

    ~Student() {
        delete[] marksPerSubject;
    }
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        students[i].accept();
    }

    cout << "\nMark Lists:\n";
    for (int i = 0; i < n; ++i) {
        students[i].display();
    }

    delete[] students;

    return 0;
}
