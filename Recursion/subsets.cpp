#include<iostream>
using namespace std;
class Solution {
    void solve(vector<int> num, vector<vector<int>>& ans, int index, vector<int> output){
        if(index>=num.size()){
            ans.push_back(output);
            return;
        }
        //exclude
        solve(num,ans,index+1,output);
        //inclusion
        int element=num[index];
        output.push_back(element);
        solve(num,ans,index+1,output);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums,ans,index,output);
        return ans;
    }
};

int main(){
    return 0;
}

