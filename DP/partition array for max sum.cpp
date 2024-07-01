#include<iostream>
using namespace std;
class Solution {
public:
    int solveTab(vector<int> &arr, int k){
        int n=arr.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int ind=n-1;ind>=0;ind--){
            int len=0;
            int maxi=INT_MIN;
            int maxAns=INT_MIN;
            for(int j=ind;j<min(n,ind+k);j++){
                len++;
                maxi=max(maxi,arr[j]);
                int sum=len*maxi+dp[j+1];
                maxAns=max(sum,maxAns);
            }
            dp[ind]=maxAns;
        }
        return dp[0];
    }
    int solve(int ind,vector<int> &arr, int k,vector<int> &dp){
        int n=arr.size();
        if(ind==n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        for(int j=ind;j<min(n,ind+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+solve(j+1,arr,k,dp);
            maxAns=max(sum,maxAns);
        }
        return dp[ind]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solveTab(arr,k);
    }
};
int main(){
    return 0;
}