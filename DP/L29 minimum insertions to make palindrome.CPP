// for the minimum number of insertions to make the string palindromic
// 1. look for the longest palindromic subsequence
//2. reverse the remaining characters to make the entire string palindromic
//3. to find the minimum number of insertions to make the string palindromic,  return (n-longest palindromic subsequence)
// where n=length of the string

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int solveTab(string &s, string &t){
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        return n-solveTab(s,t);
    }
};
int main(){
    return 0;
}