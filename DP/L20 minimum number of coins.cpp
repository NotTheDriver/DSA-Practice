#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
int solve(int ind,int target,vector<int> &num,vector<vector<int>> &dp){
    if(ind==0){
        if(target%num[0]==0) return target/num[0];
        else{
            return 1e9;
        }
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notTake=0+solve(ind-1,target,num,dp);
    int take=INT_MAX;
    if(num[ind]<=target) take=1+solve(ind,target-num[ind],num,dp);
    return dp[ind][target]=min(notTake,take);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<vector<int>> dp(num.size(),vector<int> (x+1,0));
    for(int i=0;i<=x;i++){
        if(i%num[0]==0) dp[0][i]=i/num[0];
        else dp[0][i]=1e9;
    }
    for(int ind=1;ind<num.size();ind++){
        for(int target=0;target<=x;target++){
            int notTake=0+dp[ind-1][target];
            int take=INT_MAX;
            if(num[ind]<=target) take=1+dp[ind][target-num[ind]];
            dp[ind][target]=min(take,notTake);
        }
    }
    int ans=dp[num.size()-1][x];
    if(ans>=1e9) return -1;
    else{
        return ans;
    }
}
int main(){
    return 0;
}