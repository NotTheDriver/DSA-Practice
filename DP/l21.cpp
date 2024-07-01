#include<iostream>
using namespace std;
class Solution {
public:
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
			curr[sum]=(take+not_take);
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n,target,nums);
    }
};
int main(){
    return 0;
}