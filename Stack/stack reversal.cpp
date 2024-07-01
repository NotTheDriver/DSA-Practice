#include<iostream>
#include<stack>
using namespace std;
void insertSorted(stack<int> &stack, int num){
	if(stack.empty() || (!stack.empty()) && (stack.top()<num)){
		stack.push(num);
		return;
	}
	int num1=stack.top();
	stack.pop();

	insertSorted(stack,num);
	stack.push(num1);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	insertSorted(stack,num);
}
int main(){
    stack<char> s;
    string str="yems";
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        s.push(ch);
    }
    string ans="";
    while(!s.empty()){
        char ch=s.top();
        cout<<ch<<endl;
        ans.push_back(ch);
        s.pop();
    }
    cout<<"answer is "<<ans;
    return 0;
}