#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        int countFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    countFresh+=1;
                }
            }
        }
        int tm=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,1,0,-1};
        int count=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            
            q.pop();
            for(int i=0;i<4;i++){
                    int row=r+drow[i];
                    int col=c+dcol[i];
                    if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && grid[row][col]==1 ){
                        q.push({{row,col},t+1});
                        vis[row][col]=2;
                        count++;
                    }
            }
        }
        if(count!=countFresh){
            return -1;
        }
        return tm;
    }
};
int main(){
    return 0;
}