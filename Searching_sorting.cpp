#include <iostream>
using namespace std;

int linearSearch(int myarray[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (myarray[i] == key) {
            return i + 1;
        }
    }
    return -1;
}

int binarySearch(int myarray[], int beg, int end, int key) {
    if (end >= beg) {
        int mid = (beg + end) / 2;
        if (myarray[mid] == key) {
            return mid + 1;
        } else if (myarray[mid] < key) {
            return binarySearch(myarray, mid + 1, end, key);
        } else {
            return binarySearch(myarray, beg, mid - 1, key);
        }
    }
    return -1;
}

void bubbleSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int myarray[], int size) {
    for (int k = 1; k < size; k++) {
        int temp = myarray[k];
        int j = k - 1;
        while (j >= 0 && temp < myarray[j]) {
            myarray[j + 1] = myarray[j];
            j = j - 1;
        }
        myarray[j + 1] = temp;
    }
}

int main() {
    int choice, size, key, location;
    char repeat;

    do {
        cout << "Enter the size of the array: ";
        cin >> size;

        int myarray[size];

        cout << "Enter elements of the array: ";
        for (int i = 0; i < size; i++) {
            cin >> myarray[i];
        }

        cout << "\nMenu:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Insertion Sort\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to be searched: ";
                cin >> key;
                location = linearSearch(myarray, size, key);
                if (location != -1) {
                    cout << "Key found at position " << location << " in the array\n";
                } else {
                    cout << "Could not find the given key in the array\n";
                }
                break;

            case 2:
                cout << "Enter the key to be searched: ";
                cin >> key;
                location = binarySearch(myarray, 0, size - 1, key);
                if (location != -1) {
                    cout << "Key found at location " << location << endl;
                } else {
                    cout << "Could not find the given key in the array\n";
                }
                break;

            case 3:
                bubbleSort(myarray, size);
                cout << "Sorted array using Bubble Sort:\n";
                for (int i = 0; i < size; i++) {
                    cout << myarray[i] << "\t";
                }
                cout << endl;
                break;

            case 4:
                insertionSort(myarray, size);
                cout << "Sorted array using Insertion Sort:\n";
                for (int i = 0; i < size; i++) {
                    cout << myarray[i] << "\t";
                }
                cout << endl;
                break;

            default:
                cout << "Invalid choice!\n";
                break;
        }

        cout << "Do you want to perform another operation? (Y/N): ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    cout << "Exiting the program. Goodbye!\n";

    return 0;
}
