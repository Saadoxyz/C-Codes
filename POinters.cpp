#include <iostream>
using namespace std;
int main() {
    char str[100];
    char *ptr;
    cout << "Enter a string: ";
    cin.getline(str, 100);
    ptr = str;
    cout << "Original string: ";
    while (*ptr != '\0') {
        cout << *ptr;
        ptr++;
    }
    cout << endl;
    int l= 0;
    ptr = str;
    while (*ptr != '\0') {
        l++;
        ptr++;
    }
    ptr = str;
    for (int i = 0; i < l / 2; i++) {
        char temp = *(ptr + i);
        *(ptr + i) = *(ptr + l - i - 1);
        *(ptr + l - i - 1) = temp;
    }
    cout << "Reversed string: " << str << endl;

    return 0;
}
