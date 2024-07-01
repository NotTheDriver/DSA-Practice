#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
        int n=s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string ans="";
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                ans[i]=s[i];
            }
        }
        cout<<"ans string is: "<<ans<<endl;
        int j=ans.size()-1;
        int i=0;
        while(i<j){
            if(ans[i]!=ans[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
int main(){
    string s="A man, a plan, a canal: Panama";
    cout<<isPalindrome(s);
    return 0;
}