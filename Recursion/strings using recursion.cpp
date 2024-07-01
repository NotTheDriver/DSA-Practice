#include<iostream>
using namespace std;
void reverse(string &str,int i){
	if(i>str.length()-i-1){
		return;
	}
	swap(str[i],str[str.length()-i-1]);
	i++;
	reverse(str,i);
}
string reverseString(string &str)
{
	// Write your code here.
	reverse(str,0);
	return str;
}
int main(){
    string str;
    cout<<"enter the string ";
    cin>>str;
    reverseString(str);
    cout<<str;
    return 0;
}