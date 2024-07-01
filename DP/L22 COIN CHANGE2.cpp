#include<iostream>
using namespace std;
class Solution {
public:
    int solve(vector<int> &coins,int ind,int amount,vector<vector<int>> &dp){
        if(ind==0){
            return (amount%coins[0]==0);
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int not_take=solve(coins,ind-1,amount,dp);
        int take=0;
        if(coins[ind]<=amount) take=solve(coins,ind,amount-coins[ind],dp);
        return dp[ind][amount]=take+not_take;
    }
    int solveTab(int amount, vector<int>& coins){
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            dp[0][t]=(t%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=amount;t++){
                int not_take=dp[ind-1][t];
                int take=0;
                if(coins[ind]<=t) take=dp[ind][t-coins[ind]];
                dp[ind][t]=take+not_take;
            }
        }
        return dp[n-1][amount];
    }
    int change(int amount, vector<int>& coins) {
        // int n=coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return solve(coins,n-1,amount,dp);
        return solveTab(amount,coins);
    }
};
int main(){
    return 0;
}