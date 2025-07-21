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
    void display() {
        if (!head) return;
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
    void split(DoublyLinkedList& list1, DoublyLinkedList& list2) {
        if (!head) return;
        Node* slow = head;
        Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        list1.head = head;
        list2.head = slow->next;
        slow->next = list1.head;
        list1.head->prev = slow;
        list2.head->prev = fast;
        fast->next = list2.head;
        if (list2.head == list1.head) {
            list2.head = nullptr;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.insert("Apple");
    list.insert("Banana");
    list.insert("Orange");
    list.insert("Grapes");
    list.insert("Peach");
    cout << "Original list: ";
    list.display();
    DoublyLinkedList list1, list2;
    list.split(list1, list2);
    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();
    return 0;
}
