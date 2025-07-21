#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int empId;
    string empName;
    float basicSalary;
    float da;
    float hra;
    float incomeTax;
public:
    void accept() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin>>empName;
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        da = 0.25 * basicSalary;
        hra = 800;
        incomeTax = 0.15 * basicSalary;
    }
    void display() {
        cout << "Employee ID: " << empId << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "DA (25% of basic salary): $" << da << endl;
        cout << "HRA: $" << hra << endl;
        cout << "Income Tax (15% of basic salary): $" << incomeTax << endl;
        float netSalary = basicSalary + da + hra - incomeTax;
        cout << "Net Salary: $" << netSalary << endl;
    }
};

int main() {
    Employee emp;
    emp.accept();
    emp.display();
    return 0;
}

