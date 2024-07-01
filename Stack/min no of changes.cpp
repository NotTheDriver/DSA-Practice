#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
#include<stack>
int findMinimumCost(string str) {
  // Write your code here
  if(str.length()%2==1){
    return -1;
  }
  stack<char> st;
  for(int i=0;i<str.length();i++){
    char ch=str[i];
    if(ch=='{'){
      st.push(ch);
    } 
    else {
      if (!st.empty() && st.top() == '{'){
        st.pop();
      }
      else{
        st.push(ch);
      }
    }
  }
  int a=0,b=0;
  while(!st.empty()){
    if(st.top()=='{'){
      b++;
    }
    else{
      a++;
    }
    st.pop();
  }
  int ans= (a+1)/2 +(b+1)/2;
  return ans;  
}

int main(){
    return 0;
}