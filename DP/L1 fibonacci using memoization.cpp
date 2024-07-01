#include<bits/stdio.h>
#include<vector>
class Solution {
private:
int series(int n, vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=series(n-1,dp)+series(n-2,dp);
    return dp[n];

}
public:
    int fib(int n) {
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++){
            dp[i]=-1;
        }
        return series(n,dp);
    }
};
//tabulation method
int fib(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

// with space optimization
int fib(int n) {
        int prev1=1;
        int prev2=0;
        if(n==0){
            return n;
        }
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }