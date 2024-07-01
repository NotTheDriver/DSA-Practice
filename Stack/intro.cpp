#include<iostream>
using namespace std;
class Stack{
    public:
    int size;
    int top=-1;
    int *arr;

    Stack(int size){
        this->size=size;
        top=-1;
        arr=new int[size];
    }
    void push(int element){
        if((size-top)>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            cout<<"element removed: "<<arr[top]<<endl; 
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
};
int main(){
    Stack st(6);
    st.push(2);
    st.push(5);
    st.push(54);
    st.push(6);
    cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek();
    st.pop();
    cout<<st.peek()<<endl;
    st.isEmpty()?cout<<"yes":cout<<"No";


    return 0;
}