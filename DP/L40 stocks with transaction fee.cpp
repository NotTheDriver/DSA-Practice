#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> front(2,0);
        vector<int> curr(2,0);

        // return solve(0,1,prices,n,dp);
        front[0]=front[1]=0;
        for(int ind=n-1;ind>=0;ind--){
                    curr[1]=max((-prices[ind]-fee+front[0]),front[1]);
                    curr[0]=max((prices[ind]+front[1]),front[0]);
                    front=curr;
        }
        return front[1];
    }
};
int main(){
    return 0;
}