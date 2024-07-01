#include<iostream>
using namespace std;

void inorder(TreeNode<int> *root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> mergeArrays(vector<int> &bst1,vector<int> &bst2){
    int i=0,j=0,k=0;
    int size=bst1.size()+bst2.size();
    vector<int> merged(size);
    while(i<bst1.size() && j<bst2.size()){
        if(bst1[i]<bst2[j]){
            merged[k++]=bst1[i];
            i++;
        }
        else{
            merged[k++]=bst2[j];
            j++;
        }
    }
    while(i<bst1.size()){
        merged[k++]=bst1[i];
        i++;
    }
    while(j<bst2.size()){
        merged[k++]=bst2[j];
        j++;
    }
    return merged;
}

vector<int> mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here.
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    vector<int> merged=mergeArrays(bst1,bst2);
    return merged;

}
int main(){
    return 0;
}