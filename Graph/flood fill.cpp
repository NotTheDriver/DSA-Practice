#include<iostream>
#include<vector>
using namespace std;
void dfs(int row, int col,int newColor, vector<vector<int>>& image,vector<vector<int>>& ans, int delRow[], int delCol[],int init_color){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int newRow=row+delRow[i];
            int newCol=col+delCol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol]==init_color && ans[newRow][newCol]!=newColor){
                dfs(newRow,newCol,newColor,image,ans,delRow,delCol,init_color);
            }
        }
    }
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans=image;
        int init_color=image[sr][sc];
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        dfs(sr,sc,newColor,image,ans,delRow,delCol,init_color);
        return ans;
    }
int main(){
    return 0;
}