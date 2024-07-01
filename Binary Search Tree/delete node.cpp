#include<iostream>
using namespace std;
class TreeNode{
    public:
        int val;
        TreeNode* right;
        TreeNode* left;
        TreeNode(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
};
class Solution {
public:
    TreeNode* miniVal(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            //0 child case
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //1 child case
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            //2 child case
            if(root->left!=NULL && root->right!=NULL){
                int mini=miniVal(root->right)->val;
                root->val=mini;
                root->right=deleteNode(root->right,key);
                return root;
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else{
            root->right=deleteNode(root->right,key);
            return root;
        }
    }
};
int main(){
    return 0;
}