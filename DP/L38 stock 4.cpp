#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> front(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        // return solve(0,1,2,prices,n,dp);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy){
                        curr[buy][cap]=max(-prices[ind]+front[0][cap],0+front[1][cap]);
                    }
                    else{
                        curr[buy][cap]=max((prices[ind]+front[1][cap-1]),0+front[0][cap]);
                    }
                }
            }
            front=curr;
        }
        return front[1][k];
    }
};
int main(){
    return 0;
}