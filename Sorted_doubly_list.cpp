#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(string d) {
        Node* newNode = new Node(d);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void displayForward() {
        if (!head) return;
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    void displayReverse() {
        if (!head) return;
        Node* current = head->prev;
        do {
            cout << current->data << " ";
            current = current->prev;
        } while (current != head->prev);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insert("Red");
    list.insert("Green");
    list.insert("Blue");
    list.insert("Yellow");

    cout << "Forward traversal: ";
    list.displayForward();

    cout << "Reverse traversal: ";
    list.displayReverse();

    return 0;
}
