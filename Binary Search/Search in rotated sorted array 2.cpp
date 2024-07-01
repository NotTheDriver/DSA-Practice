#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int n=nums.size();
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target==nums[mid]) return true;
            if(nums[start]==nums[mid] && nums[mid]==nums[end]){
                start++;
                end--;
                continue;
            }
            if(nums[start]<=nums[mid]){
                if(target<=nums[mid] && target>=nums[start]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(target>=nums[mid] && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};
int main(){
    return 0;
}