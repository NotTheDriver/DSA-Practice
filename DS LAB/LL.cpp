#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insertion at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Element " << value << " inserted at the beginning." << endl;
    }

    // Insertion at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Element " << value << " inserted at the end." << endl;
    }

    // Deletion of an element from the list
    void deleteElement(int value) {
        if (head == nullptr) {
            cout << "List is empty. Deletion failed." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Element " << value << " deleted." << endl;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Element " << value << " not found in the list. Deletion failed." << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Element " << value << " deleted." << endl;
    }

    // Display the elements in the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Elements in the list: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    myList.insertAtBeginning(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);
    myList.insertAtBeginning(5);

    myList.display();

    myList.deleteElement(20);

    myList.display();

    return 0;
}