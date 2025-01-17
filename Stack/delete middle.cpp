#include<iostream>
using namespace std;
void solve(stack<int>& s,int count, int size){
   //base case
   if(count==size/2){
      s.pop();
      return;
   }
   int num=s.top();
   s.pop();
   solve(s,count+1,size);
   s.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count=0;
   solve(inputStack,count,N);
   
}
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;
    for(int i=0;i<expression.length();i++){
        char ch=expression[i];
        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top=s.top();
                if (top == '(' && ch == ')' || top == '{' && ch == '}' ||
                    top == '[' && ch == ']'){
                        s.pop();
                } else {
                  return false;
                }
            } 
            else {
              return false;
            }
            }
        }
    if(s.empty())
        return true;
    else
        return false;
}
int main(){
    return 0;
}