#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

class Stack {
private:
    int stack[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int item) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push item " << item << endl;
            return;
        }
        stack[++top] = item;
    }

    int sum() {
        int total = 0;
        for (int i = 0; i <= top; i++) {
            total += stack[i];
        }
        return total;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack evenStack, oddStack;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add value to even stack\n";
        cout << "2. Add value to odd stack\n";
        cout << "3. Sum of even stack\n";
        cout << "4. Sum of odd stack\n";
        cout << "5. Display even stack\n";
        cout << "6. Display odd stack\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to add to the even stack: ";
                cin >> value;
                if (value % 2 == 0) {
                    evenStack.push(value);
                } else {
                    cout << "Please enter an even number." << endl;
                }
                break;

            case 2:
                cout << "Enter a value to add to the odd stack: ";
                cin >> value;
                if (value % 2 != 0) {
                    oddStack.push(value);
                } else {
                    cout << "Please enter an odd number." << endl;
                }
                break;

            case 3:
                cout << "Sum of even stack: " << evenStack.sum() << endl;
                break;

            case 4:
                cout << "Sum of odd stack: " << oddStack.sum() << endl;
                break;

            case 5:
                evenStack.display();
                break;

            case 6:
                oddStack.display();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }
}
