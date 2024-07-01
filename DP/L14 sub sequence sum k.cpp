#include<iostream>
using namespace std;
#include <bits/stdc++.h> 

bool solveTab(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool not_take=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target){
                take=dp[ind-1][target-arr[ind]];
            }
            dp[ind][target]=take|not_take;
        }
    }
    return dp[n-1][k];
}
bool solve(int ind,int target,vector<int> &arr,vector<vector<int>>&dp){
    if(target==0){
        return true;
    }
    if(ind==0){
        return (arr[0]==target);
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    bool not_take=solve(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target){
        take=solve(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]=take|not_take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // return solve(n-1,k,arr,dp);
    return solveTab(n,k,arr);
}
int main(){
    return 0;
}