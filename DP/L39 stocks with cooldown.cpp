#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        // return solve(0,1,prices,n,dp);
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            int profit=0;
                    dp[ind][1]=max((-prices[ind]+dp[ind+1][0]),dp[ind+1][1]);
                    dp[ind][0]=max((prices[ind]+dp[ind+2][1]),dp[ind+1][0]);
        }
        return dp[0][1];
    }
};
int main(){
    return 0;
}