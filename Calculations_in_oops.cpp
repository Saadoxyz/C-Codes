#include <iostream>
using namespace std;

class Shape {
private:
    int width;
    int height;
public:
    Shape(int w, int h) : width(w), height(h) {}
    float getWidth() { return width; }
    float getHeight() { return height; }
};

class Triangle : public Shape {
public:
    Triangle(int w, int h) : Shape(w, h) {}

    float area() {
        return 0.5 * getWidth() * getHeight();
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : Shape(w, h) {}

    float area() {
        return getWidth() * getHeight();
    }
};

int main() {
    Triangle triangle(3, 5);
    Rectangle rectangle(6, 4);
    cout << "Area of the triangle: " << triangle.area() << endl;
    cout << "Area of the rectangle: " << rectangle.area() << endl;
    return 0;
}