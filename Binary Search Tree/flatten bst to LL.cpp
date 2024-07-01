#include<iostream>
using namespace std;
void solve(TreeNode<int>* root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> inorder;
    solve(root,inorder);
    int n=inorder.size();
    TreeNode<int>* newRoot= new TreeNode<int>(inorder[0]);
    TreeNode<int>* curr=newRoot;
    for(int i=1;i<n;i++){
        TreeNode<int>* temp=new TreeNode<int>(inorder[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->right=NULL;
    curr->left=NULL;
    return newRoot;
}
int main(){
    return 0;
}