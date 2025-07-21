#include <iostream>
using namespace std;
int f(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * f(n - 1);
    }
}
int fi(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;
    cout << "Factorial (Recursive): " << f(n) << endl;
    cout << "Factorial (Iterative): " << fi(n) << endl;

    return 0;8
}
