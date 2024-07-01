#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
int solve(int i,int j,vector<vector<int>>& triangle, int n,vector<vector<int>>& dp){
	if(i==n-1) return triangle[n-1][j];
	if(dp[i][j]!=-1) return dp[i][j];
	int down=triangle[i][j]+solve(i+1,j,triangle,n,dp);
	int diag=triangle[i][j]+solve(i+1,j+1,triangle,n,dp);
	return dp[i][j]=min(down,diag);
}
int minimumPathSumSO(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<int> front(n,0),curr(n,0);
	// return solve(0,0,triangle,n,dp);
	for(int j=0;j<n;j++) front[j]=triangle[n-1][j];
	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			int down=triangle[i][j]+front[j];
			int diag=triangle[i][j]+front[j+1];
			curr[j]=min(down,diag);
		}
		front=curr;
	}
	return front[0];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(n,0));
	// return solve(0,0,triangle,n,dp);
	for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];
	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			int down=triangle[i][j]+dp[i+1][j];
			int diag=triangle[i][j]+dp[i+1][j+1];
			dp[i][j]=min(down,diag);
		}
	}
	return dp[0][0];
}
int main(){
    return 0;
}