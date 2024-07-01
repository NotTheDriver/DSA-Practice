#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //for directed graph eg: u--->v we need only one edge connection from u to v hence TC is O(Edges)
        adj[u].push_back(v);
        adj[v].push_back(u); //for undirected graph and its time complexity is O(2*Edges)
    }
    return 0;
}