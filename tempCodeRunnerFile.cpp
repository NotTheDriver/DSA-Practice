#include<bits/stdc++.h>
using namespace std;
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        int m=edges[0].size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[edges[i][j]]++;
            }
        }
        int maxi=0;
        int maxFreq=0;
        for(auto it: mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        return maxi;
    }
int main(){
    vector<vector<int>> edges={{1,2},{2,3},{4,2}};
    findCenter(edges);
    return 0;
}