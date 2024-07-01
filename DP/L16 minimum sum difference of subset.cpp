#include<bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totSum=0;
	for(int i=0;i<n;i++){
		totSum+=arr[i];
	}
	int k=totSum;
	vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(arr[0]<=k) dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool not_take=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target){
                take=dp[ind-1][target-arr[ind]];
            }
            dp[ind][target]=take|not_take;
        }
    }
	int mini=1e9;
	for(int i=0;i<=totSum/2;i++){
		int s2=totSum-i;
		if(dp[n-1][i]){
			mini=min(mini,abs(s2-i));
		}
	}
	return mini;
}

int main(){
    return 0;
}