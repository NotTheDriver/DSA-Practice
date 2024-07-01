#include<iostream>
#include<vector>
using namespace std;
void dfs(int node, vector<int> adjLs[],int vis[]){
        vis[node]=1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }
    }
int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjls[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
        }
        }
        int vis[V]={0};
        int count=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjls,vis);
            }
        }
        return count;
    }
int main(){
    return 0;
}