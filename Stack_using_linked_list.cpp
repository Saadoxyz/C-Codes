#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        cout << "Pushed item: " << item << endl;
    }
    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! Cannot pop item.\n";
            return -1;
        }
        Node* temp = top;
        int poppedItem = temp->data;
        top = top->next;
        delete temp;
        cout << "Popped item: " << poppedItem << endl;
        return poppedItem;
    }
};
int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    return 0;
}
