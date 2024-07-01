#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
class Queue {
    public:
    int *arr;
    int qfront;
    int rear;
    int size;
    Queue() {
        // Implement the Constructor
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==size){
            cout<<"The Queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront==rear){
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements in the queue: ";
        for (int i = qfront; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
Queue myQueue;
    int choice, element;

    do {
        cout << "-------------------------" << endl;
        cout << "Queue Operations:" << endl;
        cout << "-------------------------" << endl;
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