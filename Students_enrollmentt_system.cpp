#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int year_of_birth;
public:
    Person(string n, int yob) : name(n), year_of_birth(yob) {}
};

class Student : public Person {
private:
    string studentID;
    string enrolledSemester;
public:
    Student(string n, int yob, string id, string semester) : Person(n, yob), studentID(id), enrolledSemester(semester) {}
    void display() {
        cout << "Name: " << name << ", Year of Birth: " << year_of_birth << endl;
        cout << "Student ID: " << studentID << ", Enrolled Semester: " << enrolledSemester << endl;
    }
};

class Employee {
private:
    string employeeID;
    int joiningYear;
public:
    Employee(string id, int year) : employeeID(id), joiningYear(year) {}
    string getEmployeeID() const {
        return employeeID;
    }
    int getJoiningYear() const {
        return joiningYear;
    }
};

class Administrator : public Employee {
private:
    string jobTitle;
    string courseID;
    string courseTitle;
public:
    Administrator(string id, int year, string title, string courseId, string courseTitle) : Employee(id, year), jobTitle(title), courseID(courseId), courseTitle(courseTitle) {}
    void setJobTitle(string title) {
        jobTitle = title;
    }
    string getJobTitle() const {
        return jobTitle;
    }
    string getCourseID() const {
        return courseID;
    }
    string getCourseTitle() const {
        return courseTitle;
    }
};

class Academic : public Employee {
private:
    string courseID;
    string courseTitle;
public:
    Academic(string id, int year, string courseId, string courseTitle) : Employee(id, year), courseID(courseId), courseTitle(courseTitle) {}
    void setCourseID(string courseId) {
        courseID = courseId;
    }
    void setCourseTitle(string title) {
        courseTitle = title;
    }
    string getCourseID() const {
        return courseID;
    }
    string getCourseTitle() const {
        return courseTitle;
    }
};

int main() {
    cout << "Testing Student class:" << endl;
    Student student1("John Doe", 2000, "S12345", "Spring 2024");
    student1.display();
    cout << endl;
    cout << "Testing Administrator class:" << endl;
    Administrator admin("A456", 2018, "Admin Officer", "C123", "Introduction to Administration");
    cout << "Before setting job title: " << admin.getJobTitle() << endl;
    admin.setJobTitle("Senior Admin Officer");
    cout << "After setting job title: " << admin.getJobTitle() << endl;
    cout << "Course ID: " << admin.getCourseID() << ", Course Title: " << admin.getCourseTitle() << endl;
    cout << endl;
    cout << "Testing Academic class:" << endl;
    Academic academic("E789", 2015, "C456", "Advanced Mathematics");
    academic.setCourseID("C789");
    academic.setCourseTitle("Computer Science Fundamentals");
    cout << "Course ID: " << academic.getCourseID() << ", Course Title: " << academic.getCourseTitle() << endl;
    cout << endl;

    return 0;
}