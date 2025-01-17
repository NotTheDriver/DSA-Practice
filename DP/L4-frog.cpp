#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
int solve(int index,vector<int> &heights, vector<int> &dp){
    if(index==0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int left=solve(index-1,heights,dp)+abs(heights[index]-heights[index-1]);
    int right=INT_MAX;
    if(index>1){
        right=solve(index-2,heights,dp)+abs(heights[index]-heights[index-2]);
    }
    dp[index]=min(left,right);
    return dp[index];
}
int frogJump(int n, vector<int> &heights)
{
    // vector<int> dp(n,0);
    // dp[0]=0;
    int prev2=0;
    int prev1=0;
    for(int i=1;i<n;i++){
        int fs=prev1+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1){
            ss=prev2+abs(heights[i]-heights[i-2]);
        }
        int curr=min(fs,ss);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    return 0;
}