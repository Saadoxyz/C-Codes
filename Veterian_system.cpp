#include <iostream>

using namespace std;

class MyArray {
private:
    int* data;
    int capacity;
    int currentSize;

public:
    MyArray() : data(nullptr), capacity(0), currentSize(0) {}

    MyArray(int initialCapacity) : capacity(initialCapacity), currentSize(0) {
        data = new int[capacity];
    }

    ~MyArray() {
        delete[] data;
    }

    int size() const {
        return currentSize;
    }

    int& operator[](int index) {
        if (index < 0 || index >= currentSize) {
            cout << "Index out of bounds\n";
            exit(1);
        }
        return data[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= currentSize) {
            cout << "Index out of bounds\n";
            exit(1);
        }
        return data[index];
    }

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    friend ostream& operator<<(ostream& os, const MyArray& arr) {
        if (arr.size() == 0) {
            os << "Empty array";
            return os;
        }

        os << arr.data[0];
        for (int i = 1; i < arr.currentSize; ++i) {
            os << ", " << arr.data[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, MyArray& arr) {
        int value;
        arr.currentSize = 0;
        while (arr.currentSize < arr.capacity && is >> value) {
            arr.data[arr.currentSize++] = value;
        }

        if (arr.currentSize == 0) {
            cerr << "Empty input\n";
        }

        return is;
    }
};

int main() {
    int initialCapacity;
    cout << "Enter initial capacity of array: ";
    cin >> initialCapacity;

    MyArray arr(initialCapacity);

    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Resize array\n"
             << "2. Input array elements\n"
             << "3. Output array elements\n"
             << "4. Access element using operator[]\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int newCapacity;
                cout << "Enter new capacity: ";
                cin >> newCapacity;
                arr.resize(newCapacity);
                break;
            }
            case 2: {
                cout << "Enter integers separated by space: ";
                cin >> arr;
                break;
            }
            case 3: {
                cout << "Array elements: " << arr << endl;
                break;
            }
            case 4: {
                int index;
                cout << "Enter index to access element: ";
                cin >> index;
                try {
                    cout << "Element at index " << index << ": " << arr[index] << endl;
                } catch (const exception& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 5: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}