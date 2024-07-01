#include<stack>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);

    }
    return ans;
}
int main(){
    return 0;
}
class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        st.push(0);
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            while(st.top()>curr){
                st.pop();
            }
            ans[i]=curr-st.top();
            st.push(curr);
        }
        return ans;
    }
};