#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int n=nums.size();
        int end=n-1;
        if(n==1) return 0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid>0 && mid<n-1){
                if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                    return mid;
                }
                else if(nums[mid+1]>nums[mid]){
                    start=mid+1;
                }
                else end=mid-1;
            }
            else if(mid==0){
                if(nums[0]>nums[1]){
                    return 0;
                }
                else return 1;
            }
            else if(mid==n-1){
                if(nums[n-1]>nums[n-2]){
                    return n-1;
                }
                else return n-2;
            }
        }
        return -1;
    }
};
int main(){
    return 0;
}