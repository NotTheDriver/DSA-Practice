#include<iostream>
using namespace std;
class Solution {
    private:
    int solveTab(vector<int>& nums, int target){
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
    int solveMem(vector<int>& nums, int target,vector<int> &dp){
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=solveMem(nums,target-nums[i],dp);
        }
        dp[target]=ans;
        return dp[target];
    }
    int solve(vector<int>& nums, int target){
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=solve(nums,target-nums[i]);
        }
        return ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solveTab(nums,target);
    }
};
int main(){
    return 0;
}