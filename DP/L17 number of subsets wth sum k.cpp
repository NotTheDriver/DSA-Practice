#include<bits/stdc++.h>
using namespace std;
int solve(int i,int sum,vector<int>& nums,vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(i==0) return(sum==nums[0]);
        if(dp[i][sum]!=-1) return dp[i][sum];
        int not_take=solve(i-1,sum,nums,dp);
        int take=0;
        if(sum>=nums[i]) take=solve(i-1,sum-nums[i],nums,dp);
        return dp[i][sum]=not_take+take;
    }


int findWays(vector<int>& nums, int target)
{
	// Write your code here.
	    int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
}

    

int main(){
    return 0;
}