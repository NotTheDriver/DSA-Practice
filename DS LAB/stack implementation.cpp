#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int top;         // variable to keep track of the top element
    int stack[MAX_SIZE];  // array to store the stack elements

public:
    // Constructor
    Stack() {
        top = -1;  // initialize top to -1 indicating empty stack
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Function to push an element to the top of the stack
    void push(int element) {
        if (isFull()) {
            cout << "Stack Overflow: Cannot push element, stack is full." << endl;
            return;
        }

        top++;
        stack[top] = element;
        cout << "Element " << element << " pushed onto the stack." << endl;
    }

    // Function to pop an element from the top of the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop element, stack is empty." << endl;
            return;
        }

        cout << "Element " << stack[top] << " popped from the stack." << endl;
        top--;
    }

    // Function to peek at the top element of the stack
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element of the stack: " << stack[top] << endl;
    }

    // Function to display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice, element;

    while (true) {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to push: ";
                cin >> element;
                stack.push(element);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                exit(0);  // exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}