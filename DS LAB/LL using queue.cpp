#include <iostream>
#include <queue>
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
    queue<Node*> q;

public:
    LinkedList() {
        q = queue<Node*>();
    }

    // Insertion at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (q.empty()) {
            q.push(newNode);
        } else {
            Node* frontNode = q.front();
            frontNode->next = newNode;
            q.push(newNode);
        }
        cout << "Element " << value << " inserted." << endl;
    }

    // Deletion of an element from the beginning of the list
    void remove() {
        if (q.empty()) {
            cout << "List is empty. Deletion failed." << endl;
            return;
        }

        Node* frontNode = q.front();
        q.pop();
        if (!q.empty()) {
            Node* nextNode = q.front();
            frontNode->next = nextNode;
        }

        cout << "Element " << frontNode->data << " deleted." << endl;
        delete frontNode;
    }

    // Display the elements in the list
    void display() {
        if (q.empty()) {
            cout << "List is empty." << endl;
            return;
        }

        queue<Node*> tempQ = q;
        cout << "Elements in the list: ";
        while (!tempQ.empty()) {
            Node* node = tempQ.front();
            cout << node->data << " ";
            tempQ.pop();
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.insert(40);

    myList.display();

    myList.remove();

    myList.display();

    return 0;
}