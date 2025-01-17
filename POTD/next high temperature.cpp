#include<iostream>
using namespace std;
class Solution {
public:
vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        int hottest=-1;
        for(int i=n-1;i>=0;i--){
            if(temperatures[i]>=hottest){
                hottest=temperatures[i];
                continue;
            }
            int days=1;
            while(temperatures[i+days]<=temperatures[i]){
                days+=ans[i+days];
            }
            ans[i]=days;
        }
        return ans;
}
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first<=temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top().second-i;
            }
            s.push({temperatures[i],i});
        }
        return ans;
    }
};
int main(){
    return 0;
}