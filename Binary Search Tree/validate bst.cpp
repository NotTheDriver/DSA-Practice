#include<iostream>
using namespace std;
bool solve(BinaryTreeNode<int> *root, int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=min && root->data<=max){
        bool left=solve(root->left,min,root->data);
        bool right=solve(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    int min=INT_MIN;
    int max=INT_MAX;
    return solve(root,min,max);
}
int main(){
    return 0;
}