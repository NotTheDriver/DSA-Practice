#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int ind,int prev,vector<int>& nums,vector<vector<int>> dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev]) take=1+solve(ind+1,ind,nums,dp);
        int not_take=0+solve(ind+1,prev,nums,dp);
        return dp[ind][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // return solve(0,-1,nums,dp);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || nums[ind]>nums[prev]) take=1+dp[ind+1][ind+1];
                int not_take=0+dp[ind+1][prev+1];
                dp[ind][prev+1]=max(take,not_take);
            }
        }
        return dp[0][0];
    }
};
int main(){
    return 0;
}