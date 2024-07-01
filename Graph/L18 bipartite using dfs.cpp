#include<iostream>
using namespace std;
class Solution {
public:
    // bool check(int i,vector<vector<int>>& graph,vector<int> &color){
    //     queue<int> q;
    //     q.push(i);
    //     color[i]=0;
    //     while(!q.empty()){
    //         int node=q.front();
    //         q.pop();
    //         for(auto it:graph[node]){
    //             if(color[it]==-1) {   
    //                 color[it]=!color[node];
    //                 q.push(it);
    //             }
    //             else if(color[it]==color[node]) return false;
    //         }
    //     }
    //     return true;
    // }
    bool check(int node,int col,vector<vector<int>>& graph,vector<int> &color){
        color[node]=col;
        for(auto it: graph[node]){
            if(color[it]==-1){
                if(check(it,!col,graph,color)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i,0,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    return 0;
}