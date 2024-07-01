#include<iostream>
using namespace std;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V);
        for(int i=0;i<V;i++) vis[i]=1e9;
        vis[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                if(dis+edgeWeight<vis[adjNode]){
                    vis[adjNode]=dis+edgeWeight;
                    pq.push({vis[adjNode],adjNode});
                }
            }
        }
        return vis;
    }
};
int main(){
    return 0;
}