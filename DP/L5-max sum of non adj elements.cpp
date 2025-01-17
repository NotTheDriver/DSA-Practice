#include<iostream>
using namespace std;
class Solution {
private:
    int solve(vector<int>& nums,int n,vector<int>& dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return nums[0];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int incl=solve(nums,n-2,dp)+nums[n];
        int excl=solve(nums,n-1,dp)+0;
        dp[n]=max(incl,excl);
        return dp[n];
    }
    //SO for space optimized
    int solveSO(vector<int>& nums){
        int n=nums.size();
        int prev2=0;
        int prev1=nums[0];
        for(int i=1;i<n;i++){
            int incl=prev2+nums[i];
            int exc=prev1+0;
            int ans=max(incl,exc);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    int solveTab(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            if((i-2)<0){
                int incl=0+nums[i];
                int exc=dp[i-1]+0;
                dp[i]=max(incl,exc);
                continue;
            }
            int incl=dp[i-2]+nums[i];
            int exc=dp[i-1]+0;
            dp[i]=max(incl,exc);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=solve(nums,n-1,dp);
        return ans;
    }
};

int main(){
    return 0;
}