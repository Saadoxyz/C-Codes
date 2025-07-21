#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;

    node(int value) : data(value), next(nullptr) {}
};
class stack {
private:
    node* top;
    int count;
public:
    stack() : top(nullptr), count(0) {}
    bool is_empty() {
        return top == nullptr;
    }
    void push(int item) {
        node* new_node = new node(item);
        new_node->next = top;
        top = new_node;
        count++;
        cout << "pushed item: " << item << endl;
    }
    int pop() {
        if (is_empty()) {
            cout << "stack underflow! cannot pop item." << endl;
            return -1;
        }
        node* temp = top;
        int popped_item = temp->data;
        top = top->next;
        delete temp;
        count--;
        cout << "popped item: " << popped_item << endl;
        return popped_item;
    }
    int sum() {
        int total = 0;
        node* current = top;
        while (current != nullptr) {
            total += current->data;
            current = current->next;
        }
        return total;
    }
    int size() {
        return count;
    }
    void display() {
        if (is_empty()) {
            cout << "stack is empty." << endl;
            return;
        }
        node* current = top;
        cout << "stack contents: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
void display_menu() {
    cout << "\nmenu:\n";
    cout << "1. add value to even stack\n";
    cout << "2. add value to odd stack\n";
    cout << "3. pop value from even stack\n";
    cout << "4. pop value from odd stack\n";
    cout << "5. display sum of even stack\n";
    cout << "6. display sum of odd stack\n";
    cout << "7. display even stack\n";
    cout << "8. display odd stack\n";
    cout << "9. exit\n";
    cout << "choose an option: ";
}
int main() {
    stack even_stack, odd_stack;
    int choice, value;
    do {
        display_menu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "enter a value to add to the even stack: ";
                cin >> value;
                if (value % 2 == 0) {
                    even_stack.push(value);
                } else {
                    cout << "please enter an even number." << endl;
                }
                break;
            case 2:
                cout << "enter a value to add to the odd stack: ";
                cin >> value;
                if (value % 2 != 0) {
                    odd_stack.push(value);
                } else {
                    cout << "please enter an odd number." << endl;
                }
                break;
            case 3:
                even_stack.pop();
                break;
            case 4:
                odd_stack.pop();
                break;
            case 5:
                cout << "sum of even stack: " << even_stack.sum() << endl;
                break;
            case 6:
                cout << "sum of odd stack: " << odd_stack.sum() << endl;
                break;
            case 7:
                even_stack.display();
                break;
            case 8:
                odd_stack.display();
                break;
            case 9:
                cout << "exiting program..." << endl;
                break;
            default:
                cout << "invalid option! please try again." << endl;
        }
    } while (choice != 9);
    return 0;
}
