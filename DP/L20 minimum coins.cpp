#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
int solve(int ind,int target, vector<int> &num,vector<vector<int>> &dp){
    if(ind==0){
        if(target%num[0]==0) return target/num[0];
        return 1e9;
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    int not_take=0+solve(ind-1,target,num,dp);
    int take=INT_MAX;
    if(num[ind]<=target) take=1+solve(ind,target-num[ind],num,dp);
    return dp[ind][target]=min(take,not_take);
}

// int minimumElements(vector<int> &num, int x)
// {
//     int n =num.size();
//     // Write your code here.
//     vector<vector<int>> dp(n,vector<int>(x+1,0));
//     for(int t=0;t<=x;t++){
//         if(t%num[0]==0) dp[0][t]=t/num[0];
//         else dp[0][t]=1e9;
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int target=0;target<=x;target++){
//             int not_take=0+dp[ind-1][target];
//             int take=INT_MAX;
//             if(num[ind]<=target) take=1+dp[ind][target-num[ind]];
//             dp[ind][target]=min(take,not_take);
//         }
//     }
//     int ans=dp[n-1][x];
//     if(ans>=1e9){
//         return -1;
//     }
//     return ans;
// }
int minimumElements(vector<int> &num, int x)
{
    int n =num.size();
    // Write your code here.
    vector<int> prev(x+1,0),curr(x+1,0);
    for(int t=0;t<=x;t++){
        if(t%num[0]==0) prev[t]=t/num[0];
        else prev[t]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=x;target++){
            int not_take=0+prev[target];
            int take=INT_MAX;
            if(num[ind]<=target) take=1+curr[target-num[ind]];
            curr[target]=min(take,not_take);
        }
        prev=curr;
    }
    int ans=prev[x];
    if(ans>=1e9){
        return -1;
    }
    return ans;
}
int main(){
    return 0;
}