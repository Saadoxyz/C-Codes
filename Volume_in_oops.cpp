#include <iostream>
using namespace std;
class Box {
public:
    float l, b, h;
    Box()
    {
        l = 0;
        b = 0;
        h = 0;
    }
    void set()
    {
        cout << "Enter Length" << endl;
        cin >> l;
        cout << "Enter Breadth" << endl;
        cin >> b;
        cout << "Enter hieght" << endl;
        cin >> h;
    }
    void get()
    {
        cout << "length= " << l << endl;
        cout << "breadth= " << b << endl;
        cout << "height= " << h << endl;
    }
    float volume()
    {
        cout << "The volume is " << endl;
        return l * b * h;
    }
    Box operator + (Box p)
    {
        Box temp;
        temp.l = p.l + l;
        temp.b = p.b + b;
        temp.h = p.h + h;
        return temp;
    }
    Box operator - (Box p)
    {
        Box temp;
        temp.l = p.l - l;
        temp.b = p.b - b;
        temp.h = p.h - h;
        return temp;
    }
    Box operator * (Box p)
    {
        Box temp;
        temp.l = p.l * l;
        temp.b = p.b * b;
        temp.h = p.h * h;
        return temp;
    }
    Box operator < (Box p)
    {
        if (l * b * h < p.l * p.b * p.h)
        {
            cout << l * b * h << " is lesser" << endl;
        }
        else {
            cout << p.l * p.b * p.h << " is lesser" << endl;
        }
    }
};
int main()
{
    Box a, b, c;
    a.set();
    b.set();
    c = a + b;
    a.get();
    b.get();
    c.get();
    cout << a.volume()<<endl;
    cout << b.volume()<<endl;
    cout << c.volume()<<endl;
    c = a - b;
    c.get();
    cout << c.volume() << endl;
    c = a * b;
    c.get();
    cout << c.volume() << endl;
    c = a < b;
    c.get();
    cout << c.volume() << endl;

}
