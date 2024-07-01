#include <iostream>
using namespace std;
#define MAX_SIZE 5

class CircularQueue {
private:
    int queue[MAX_SIZE];
    int front, rear;

public:
    // Constructor
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    // Insert an element into the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue Overflow. Unable to enqueue element." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE; // Circularly wrap index
        }
        queue[rear] = element;
        cout << "Element " << element << " enqueued successfully." << endl;
    }

    // Delete an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow. Unable to dequeue element." << endl;
            return;
        }
        int element = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE; // Circularly wrap index
        }
        cout << "Element " << element << " dequeued successfully." << endl;
    }

    // Display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements in the queue: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE; // Circularly wrap index
        }
        cout << queue[rear] << endl;
    }
};

int main() {
    CircularQueue myQueue;
    int choice, element;

    do {
        cout << "------------------------" << endl;
        cout << "Circular Queue Operations:" << endl;
        cout << "------------------------" << endl;
        cout << "1. Enqueue an element" << endl;
        cout << "2. Dequeue an element" << endl;
        cout << "3. Display elements" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                myQueue.enqueue(element);
                break;
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                myQueue.display();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}