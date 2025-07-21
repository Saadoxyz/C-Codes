#include <iostream>

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

    // Function to insert a node in ascending order
    void insert(int value) {
        Node* newNode = new Node(value);

        // If the list is empty or the new node should be the new head
        if (head == nullptr || head->data > value) {
            newNode->next = head;
            head = newNode;
        } else {
            // Find the correct position to insert the new node
            Node* current = head;
            while (current->next != nullptr && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    SinglyLinkedList list;

    // Insert numbers in ascending order
    list.insert(9);
    list.insert(1);
    list.insert(5);
    list.insert(7);
    list.insert(11);
    list.insert(3);

    // Display the linked list
    std::cout << "The list in ascending order: ";
    list.display();

    return 0;
}
