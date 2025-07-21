#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int Id;
    string Name;
    int TotalSubject;
    double MarksPerSubject;
public:
    void set(int i, string n, int s, double m)
    {
        Id = i;
        Name = n;
        TotalSubject = s;
        MarksPerSubject = m;
    }

    void get()
    {
        cout << Id << endl << Name << endl << TotalSubject << endl << MarksPerSubject << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of students: " << endl;
    cin >> n;

    Student *s1 = new Student[n];

    for (int i = 0; i < n; ++i)
    {
        int id;
        string name;
        int totalsubject;
        double markspersubject;
        cout << "Enter yours id, name, total subject, and marks per subject" << endl;
        cin >> id >> name >> totalsubject >> markspersubject;
        s1[i].set(id, name, totalsubject, markspersubject);
    }

    for (int j = 0; j < n; ++j)
    {
        s1[j].get();
    }

    delete[] s1; 
    return 0;
}
