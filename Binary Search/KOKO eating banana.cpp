#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long check(vector<int>& piles, int h,int mid){
        int n=piles.size();
        long target=0;
        for(int i=0;i<n;i++){
            target+=ceil((double)piles[i]/(double)mid);
        }
        return target;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int end=INT_MIN;
        for(auto it:piles){
            end=max(end,it);
        }
        int ans=0;
        int start=1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(piles,h,mid)<=h){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}