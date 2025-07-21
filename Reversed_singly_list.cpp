#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insert(int d) {
        Node* newNode = new Node(d);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse() {
        Node* back = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            current->next = back;
            back = current;
            current = nextNode;
        }
        head = back;
    }
};

int main() {
    SinglyLinkedList list;
    list.insert(1);
    list.insert(3);
    list.insert(5);
    list.insert(7);
    list.insert(9);
    list.insert(11);
    cout << "Original list: ";
    list.display();
    list.reverse();
    cout << "Reversed list: ";
    list.display();
    return 0;
}
