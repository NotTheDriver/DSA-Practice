#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(vector<int>& bloomDay, int mid, int k){
        int consecutive=0;
        int count=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                consecutive++;
            }
            else{
                consecutive=0;
            }
            if(consecutive==k){
                count++;
                consecutive=0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int ans=-1;
        int start=0;
        int end=INT_MIN;
        for(auto it:bloomDay){
            end=max(it,end);
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(bloomDay,mid,k)>=m){
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