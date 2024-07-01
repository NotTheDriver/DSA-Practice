#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->val=data;
        left=NULL;
        right=NULL;
    }
};
class Solution {
public:
    pair<int,int> Diameter(TreeNode* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=Diameter(root->left);
        pair<int,int> right=Diameter(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=right.second+left.second;
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return Diameter(root).first;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int &diam){
        if(root==NULL) return 0;
        int left=solve(root->left,diam);
        int right=solve(root->right,diam);
        diam=max(diam,left+right);
        return 1+max(left,right);
    }
    int widthOfBinaryTree(TreeNode* root) {
        int diam=0;
        solve(root,diam);
        return diam;
    }
};
int main(){
    return 0;
}