#include <iostream>
#include <string>

using namespace std;

class Department {
private:
    int deptID;
    string deptName;
public:
    Department(int id, string name) : deptID(id), deptName(name) {}

    void display() {
        cout << "Department ID: " << deptID << endl;
        cout << "Department Name: " << deptName << endl;
    }

    // Getter and setter functions
    int getDeptID() { return deptID; }
    string getDeptName() { return deptName; }
    void setDeptID(int id) { deptID = id; }
    void setDeptName(string name) { deptName = name; }
};

class Laboratory {
private:
    int labID;
    int experimentNo;
public:
    Laboratory(int id, int expNo) : labID(id), experimentNo(expNo) {}

    // Getter and setter functions
    int getLabID() { return labID; }
    int getExperimentNo() { return experimentNo; }
    void setLabID(int id) { labID = id; }
    void setExperimentNo(int expNo) { experimentNo = expNo; }
};

class University {
private:
    string universityName;
    string location;
    Department *dept;
public:
    University(string name, string loc, Department *department) : universityName(name), location(loc), dept(department) {}

    void display() {
        cout << "University Name: " << universityName << endl;
        cout << "Location: " << location << endl;
        cout << "Department Details:" << endl;
        dept->display();
    }

    // Getter and setter functions
    string getUniversityName() { return universityName; }
    string getLocation() { return location; }
    Department* getDepartment() { return dept; }
    void setUniversityName(string name) { universityName = name; }
    void setLocation(string loc) { location = loc; }
    void setDepartment(Department *department) { dept = department; }

    // Function to update department
    void updateDepartment(Department *newDepartment) {
        if (dept != NULL)
            delete dept;
        dept = newDepartment;
    }

    // Function to delete department
    void deleteDepartment() {
        if (dept != NULL)
            delete dept;
        dept = NULL;
    }
};

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    // Getter and setter functions
    string getName() { return name; }
    int getAge() { return age; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
};

class Professor : public Person {
private:
    string profName;
    Department *dept;
public:
    Professor(string name, int age, string pName, Department *department) : Person(name, age), profName(pName), dept(department) {}

    void display() {
        Person::display();
        cout << "Professor Name: " << profName << endl;
        cout << "Department Details:" << endl;
        dept->display();
    }

    // Getter and setter functions
    string getProfName() { return profName; }
    Department* getDepartment() { return dept; }
    void setProfName(string pName) { profName = pName; }
    void setDepartment(Department *department) { dept = department; }
};

class Researcher : public Professor {
private:
    Laboratory *lab;
public:
    Researcher(string name, int age, string pName, Department *department, Laboratory *laboratory) : Professor(name, age, pName, department), lab(laboratory) {}

    void display() {
        Professor::display();
        cout << "Laboratory Details:" << endl;
        cout << "Lab ID: " << lab->getLabID() << endl;
        cout << "Experiment No: " << lab->getExperimentNo() << endl;
    }

    // Getter and setter functions
    Laboratory* getLaboratory() { return lab; }
    void setLaboratory(Laboratory *laboratory) { lab = laboratory; }
};

int main() {
    // Create Department
    Department *dept = new Department(1, "Computer Science");

    // Create University
    University uni("ABC University", "XYZ Location", dept);

    // Display University details
    cout << "University Details:" << endl;
    uni.display();
    cout << endl;

    // Update University department
    Department *newDept = new Department(2, "Electrical Engineering");
    uni.updateDepartment(newDept);

    // Display University details after updating department
    cout << "University Details after updating department:" << endl;
    uni.display();
    cout << endl;

    // Delete University department
    uni.deleteDepartment();

    // Display University details after deleting department
    cout << "University Details after deleting department:" << endl;
    uni.display();
    cout << endl;

    // Clean up dynamic memory
    delete newDept;
    delete dept;

    return 0;
}
