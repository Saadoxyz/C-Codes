#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int stack[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(int item) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack overflow! Cannot push item \n";
            return;
        }
        stack[++top] = item;
        cout << "Pushed item: " << item << endl;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow! Cannot pop item \n";
            return -1; // Error value
        }
        int poppedItem = stack[top--];
        cout << "Popped item: " << poppedItem << endl;
        return poppedItem;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack myStack; // Corrected from Stack to Stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << "Stack size: " << myStack.size() << endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop(); // This will demonstrate underflow

    return 0;
}
