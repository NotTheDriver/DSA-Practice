#include<iostream>
using namespace std;
class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int> ans=make_pair(0,0);
            return ans;
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        pair<int,int> res;
        res.first=root->data+left.second+right.second;
        res.second=max(left.first,left.second)+max(right.first,right.second);
        return res;
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans=solve(root);
        int answer=max(ans.first,ans.second);
        return answer;
    }
};
int main(){
    return 0;
}