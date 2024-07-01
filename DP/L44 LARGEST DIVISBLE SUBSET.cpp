#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
    int n=nums.size();
    vector<int> dp(n,1);
    vector<int> prev_id(n,-1);
    int last_ind=0;
    int max_len=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev_id[i]=j;
                }
            }
            if(dp[i]>max_len){
                max_len=dp[i];
                last_ind=i;
            }
        }
    }
    vector<int> ans;
    while(last_ind!=-1){
        ans.push_back(nums[last_ind]);
        last_ind=prev_id[last_ind];
    }
    return ans;
    }

};
int main(){
    return 0;
}