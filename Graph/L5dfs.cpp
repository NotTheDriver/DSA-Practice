#include<iostream>
using namespace std;
#include<vector>
void dfs(int node, int vis[], vector<int> &ls, vector<int> adj[]){
      vis[node]=1;
      ls.push_back(node);
      for(auto it: adj[node]){
          if(!vis[it]){
              dfs(it,vis,ls,adj);
          }
      }
  }
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        int start=0;
        vector<int> ls;
        dfs(start, vis,ls,adj);
        return ls;
        // Code here
    }
int main(){
    return 0;
}