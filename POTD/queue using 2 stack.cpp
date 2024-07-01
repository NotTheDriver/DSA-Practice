#include<iostream>
using namespace std;
class MyQueue {
public:
    stack<int> input,output;
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int topElement=peek();
        output.pop();
        return topElement;
    }
    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main(){
    return 0;
}