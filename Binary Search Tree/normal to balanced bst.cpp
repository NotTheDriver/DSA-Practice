#include<iostream>
#include<vector>
using namespace std;
template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
void inorder(TreeNode<int>* root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
TreeNode<int>* solve(int start, int end,vector<int> &inorder){
    if(start>end){
        return NULL;
    }
    int mid=(end+start)/2;
    TreeNode<int>* root= new TreeNode<int>(inorder[mid]);
    root->left=solve(start,mid-1,inorder);
    root->right=solve(mid+1,end,inorder);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    inorder(root,ans);
    return solve(0,ans.size()-1,ans);
}
int main(){
    return 0;
}