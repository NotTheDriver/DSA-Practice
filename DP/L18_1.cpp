#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
const int mod=1000000007;
int solve(vector<int>& arr,int ind, int k,vector<vector<int>> &dp){
	if(k==0) return 1;
	if(ind==0){
		if(k==0 && arr[0]==0) return 2;
		if(k==0 || arr[0]==k) return 1;
		return 0;
	}
	if(dp[ind][k]!=-1){
		return dp[ind][k];
	}
	int not_take=solve(arr,ind-1,k,dp);
	int take=0;
    if (arr[ind] <= k) {
        take = solve(arr, ind - 1, k - arr[ind], dp);
    }
    return dp[ind][k]=(take+not_take)%mod;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	// vector<vector<int>>dp(n,vector<int>(k+1,-0));
    vector<int> prev(k+1,0),curr(k+1,0);
	if(arr[0]==0) prev[0]=2;
	else{
		prev[0]=1;
	}
	// for(int i=1;i<n;i++){
	// 	dp[i][0]=1;
	// }
	if(arr[0]!=0 && arr[0]<=k) prev[arr[0]]=1;
	for(int i=1;i<n;i++){
		for(int sum=0;sum<=k;sum++){
			int not_take=prev[sum];
			int take=0;
    		if (arr[i] <= sum) {
        		take = prev[sum-arr[i]];
    		}
			curr[sum]=(take+not_take)%mod;
		}
        prev=curr;
	}
	return prev[k];
	// return solve(arr,n-1,k,dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalSum=0;
    for(auto it:arr){
        totalSum+=it;
    }
    if(totalSum-d<0 || (totalSum-d)%2) return false;
    return findWays(arr,(totalSum-d)/2);
}



int main(){
    return 0;
}