#include<iostream>
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
    int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // int n=text1.size();
        // int m=text2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,text1,text2,dp);
        return solveTab(text1,text2);
    }
};
int main(){
    return 0;
}