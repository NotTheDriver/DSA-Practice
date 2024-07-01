#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& words) {
       int n=words.size();
        vector<int> dp(n,1),count(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i]>words[j] && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }
                else if(words[i]>words[j] && dp[j]+1==dp[i]){
                    count[i]+=count[j];
                }
            }
            maxi=max(dp[i],maxi);
        }
        int num=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) num+=count[i];
        }
        return num;
    }
};
int main(){
    return 0;
}