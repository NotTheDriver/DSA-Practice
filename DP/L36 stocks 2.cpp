#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind,int buy,vector<int>& prices,int n,vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        int profit=0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit=max((-prices[ind]+solve(ind+1,0,prices,n,dp)),solve(ind+1,1,prices,n,dp));
        }
        else{
            profit=max((prices[ind]+solve(ind+1,1,prices,n,dp)),solve(ind+1,0,prices,n,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        // return solve(0,1,prices,n,dp);
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            int profit=0;
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    profit=max((-prices[ind]+dp[ind+1][0]),dp[ind+1][1]);
                }
                else{
                    profit=max((prices[ind]+dp[ind+1][1]),dp[ind+1][0]);
                }
                dp[ind][buy]=profit;

            }
        }
        return dp[0][1];
    }
};
int main(){
    return 0;
}