#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a,int b){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(M,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int ans=s.top();
        int countZero=0;
        for(int i=0;i<n;i++){
            if(M[ans][i]==0){
                countZero++;
            }
        }
        if(countZero!=n){
            return -1;
        }
        int countOne=0;
        for(int i=0;i<n;i++){
            if(M[i][ans]==1){
                countOne++;
            }
        }
        if(countOne!=n-1){
            return -1;
        }
        return ans;
    }
};
int main(){
    return 0;
}