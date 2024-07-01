#include<iostream>
using namespace std;
class Solution {
public:
    int solveSpace(int m,int n,vector<vector<int>>& arr){
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(m,0);
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    curr[j]=0;
                }
                else if(i==0 && j==0){
                    curr[j]=1;
                }
                else{
                    int up=0;
                    int left=0;
                    if(i>0){
                        up=prev[j];
                    }
                    if(j>0){
                        left=curr[j-1];
                    }
                    curr[j]=up+left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
    int solveTab(int m,int n,vector<vector<int>>& arr){
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    dp[i][j]=0;
                }
                else if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                    int up=0;
                    int left=0;
                    if(i>0){
                        up=dp[i-1][j];
                    }
                    if(j>0){
                        left=dp[i][j-1];
                    }
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(i>=0 && j>=0 && arr[i][j]==1){
            return 0;
        }
        if(i==0 && i==j){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=solve(i-1,j,arr,dp);
        int left=solve(i,j-1,arr,dp);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obstacleGrid,dp);
        // return solveSpace(m,n,obstacleGrid);
    }
};
int main(){
    return 0;
}