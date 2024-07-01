#include<iostream>
#include<stack>
using namespace std;
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