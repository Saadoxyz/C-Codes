#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }
    double calculateArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    double userRadius;
    cout << "Enter the radius of the circle: ";
    cin >> userRadius;

    
    Circle circle(userRadius);

    
    double area = circle.calculateArea();

    cout << "The area of the circle with radius " << userRadius << " is " << area << endl;

    return 0;
}
