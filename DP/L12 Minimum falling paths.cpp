#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
int solve(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(i<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int ld=matrix[i][j]+solve(i-1,j-1,matrix,dp);
    int up=matrix[i][j]+solve(i-1,j,matrix,dp);
    int rd=matrix[i][j]+solve(i-1,j+1,matrix,dp);
    return dp[i][j]=max(ld,max(up,rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxi=-1e8;
    for(int j=0;j<m;j++){
        int sum=solve(n-1,j,matrix,dp);
        maxi=max(maxi,sum);
    }
    return maxi;
}
int getMaxPathSumTabulation(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    int maxi=-1e8;
    for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int ld=matrix[i][j];
            if(j-1>=0)ld+=dp[i-1][j-1];
            else ld+=-1e8;
            int up=matrix[i][j]+dp[i-1][j];
            int rd=matrix[i][j];
            if(j+1<m) rd+=dp[i-1][j+1];
            else{
                rd+=-1e8;
            }
            dp[i][j]=max(ld,max(up,rd));
        }
    }
    for(int j=0;j<m;j++){
        int sum=dp[n-1][j];
        maxi=max(maxi,sum);
    }
    return maxi;
}
int spaceOp(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> prev(m,0),curr(m,0);
    int maxi=-1e8;
    for(int j=0;j<m;j++) prev[j]=matrix[0][j];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int ld=matrix[i][j];
            if(j-1>=0)ld+=prev[j-1];
            else ld+=-1e8;
            int up=matrix[i][j]+prev[j];
            int rd=matrix[i][j];
            if(j+1<m) rd+=prev[j+1];
            else{
                rd+=-1e8;
            }
            curr[j]=max(ld,max(up,rd));
        }
        prev=curr;
    }
    for(int j=0;j<m;j++){
        int sum=prev[j];
        maxi=max(maxi,sum);
    }
    return maxi;
}
int main(){
    return 0;
}