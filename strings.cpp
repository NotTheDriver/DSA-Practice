#include <iostream>
using namespace std;
bool CheckPalindrome(char arr[],int n){
    int s=0, end=n-1;
    while(s<end){
        if(arr[s]!=arr[end]){
            return 0;
        }
        else{
            s++;end--;
        }
        return 1;
    }
}
string isPalindrome(string s) {
        string s2 ="";
        int i=0;
        while(s[i]!='\0'){
            if(s[i]>='a' && s[i]<='z'){
                s2.push_back(s[i]);
            }
            if(s[i]>='A' && s[i]<='z'){
                s2.push_back(s[i]+32);
            }
            if(s[i]>=0 && s[i<=9]){
                s2.push_back(s[i]);
            }
            i++;
        }
        int start=0;
        int end=i-1;
        while(start<=end){
            if(s2[start]!=s2[end]){
                break;
            }
            start++;
            end--;
        }
        return s2;
}
int main(){
    string s="A man, a plan, a canal: Panama";
    cout<<isPalindrome(s);
    return 0;
}
