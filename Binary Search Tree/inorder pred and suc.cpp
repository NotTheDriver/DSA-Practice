#include<iostream>
using namespace std;
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int succ=-1;
    int pred=-1;
    BinaryTreeNode<int>*temp=root;
    while(temp!=NULL){
        if(temp->data<=key){
            temp=temp->right;
        }
        else{
            succ=temp->data;
            temp=temp->left;
        }
    }
    while(root!=NULL){
        if(root->data>=key){
            root=root->left;
        }
        else{
            pred=root->data;
            root=root->right;
        }
    }
    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}
int main(){
    return 0;
}