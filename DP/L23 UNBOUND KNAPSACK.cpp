#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int solve(int ind, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp){
    if(ind==0)return (int(w/weight[0]))*profit[0];
    if(dp[ind][w]!=-1) return dp[ind][w];
    int not_take=0+solve(ind-1,w,profit,weight,dp);
    int take=0;
    if(weight[ind]<=w) take=profit[ind]+solve(ind,w-weight[ind],profit,weight,dp);
    return dp[ind][w]=max(take,not_take);
}
int solveTab(int n, int W, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int wt=0;wt<=W;wt++){
        dp[0][wt]=(int(W/weight[0]))*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=W;w++){
            int not_take=0+dp[ind-1][w];
            int take=0;
            if(weight[ind]<=w) take=profit[ind]+dp[ind][w-weight[ind]];
            dp[ind][w]=max(take,not_take);
        }
    }
    return dp[n-1][W];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return solveTab(n,w,profit,weight);
}
int main(){
    return 0;
}