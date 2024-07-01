#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int solveSpace(vector<vector<int>>& triangle,int n){
        vector<int> curr(n,0),front(n,0);
        for(int j=0;j<n;j++){
            front[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d=triangle[i][j]+front[j];
                int dg=triangle[i][j]+front[j+1];
                curr[j]=min(d,dg);
            }
            front=curr;
        }
        return front[0];
    }
    int solveTab(vector<vector<int>>& triangle,int n){
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d=triangle[i][j]+dp[i+1][j];
                int dg=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d,dg);
            }
        }
        return dp[0][0];
    }
    int solveMem(int i,int j, vector<vector<int>>& a,vector<vector<int>>& dp,int n){
        if(i==n-1){
            return a[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int d=a[i][j]+solveMem(i+1,j,a,dp,n);
        int dg=a[i][j]+solveMem(i+1,j+1,a,dp,n);
        return dp[i][j]=min(d,dg);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solveMem(0,0,triangle,dp,n);
        return solveSpace(triangle,n);
    }
};
int main(){
    return 0;
}