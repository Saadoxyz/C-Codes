#include <iostream>
#include <string>
using namespace std;

class Member {
protected:
    string name;
    int age;
    string phoneNumber;
    string address;
    float salary;

public:
    void printSalary() {
        cout << "Salary: $" << salary << endl;
    }
};

class Employee : public Member {
private:
    string specialization;

public:
    void setData(string n, int a, string ph, string addr, float sal, string spec) {
        name = n;
        age = a;
        phoneNumber = ph;
        address = addr;
        salary = sal;
        specialization = spec;
    }

    void display() {
        cout << "Employee Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

class Manager : public Member {
private:
    string department;

public:
    void setData(string n, int a, string ph, string addr, float sal, string dept) {
        name = n;
        age = a;
        phoneNumber = ph;
        address = addr;
        salary = sal;
        department = dept;
    }

    void display() {
        cout << "Manager Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    Employee emp;
    emp.setData("John Doe", 30, "1234567890", "123 Main St", 5000.0, "Software Engineering");
    emp.display();
    emp.printSalary();

    cout << endl;

    Manager manager;
    manager.setData("Jane Smith", 40, "9876543210", "456 Oak St", 8000.0, "Human Resources");
    manager.display();
    manager.printSalary();

    return 0;
}