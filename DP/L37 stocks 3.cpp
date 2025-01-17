#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>> &dp){
        if(cap==0 || ind==n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+solve(ind+1,0,cap,prices,n,dp),solve(ind+1,1,cap,prices,n,dp));
        }
        else{
            profit=max((prices[ind]+solve(ind+1,1,cap-1,prices,n,dp)),solve(ind+1,0,cap,prices,n,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,n,dp);
    }
    int maxProfitTab(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return solve(0,1,2,prices,n,dp);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                    if(buy){
                        dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][buy][cap]=max((prices[ind]+dp[ind+1][1][cap-1]),0+dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfitSO(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> front(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        // return solve(0,1,2,prices,n,dp);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                    if(buy){
                        curr[buy][cap]=max(-prices[ind]+front[0][cap],0+front[1][cap]);
                    }
                    else{
                        curr[buy][cap]=max((prices[ind]+front[1][cap-1]),0+front[0][cap]);
                    }
                }
            }
            front=curr;
        }
        return front[1][2];
    }
};
int main(){
    return 0;
}