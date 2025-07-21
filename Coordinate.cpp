#include<iostream>
#include<cmath>
using namespace std;
struct planes {
    double x, y;
};
double Distance(planes point1, planes point2)
 {
    return sqrt(pow((point2.x - point1.x), 2) + pow((point2.y - point1.y), 2));
}
int main() {
    planes point1, point2;

    cout << "Enter x and y coordinates of the 1st point:" << endl;
    cin >> point1.x >> point1.y;

    cout << "Enter x and y coordinates of the 2nd point:" << endl;
    cin >> point2.x >> point2.y;

    double distance_of_points = Distance(point1, point2)
    cout << "The Euclidean distance between the two points is: " << distance_of_points << endl;

    return 0;
}
