#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};
class Solution {
public:
    void leftTraversal(Node* root,vector<int> &ans){
        if((root==NULL)|| (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            leftTraversal(root->left,ans);
        }
        else{
            leftTraversal(root->right,ans);
        }
    }
    void leafTraversal(Node* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right){
            ans.push_back(root->data);
            return;
        }
        leafTraversal(root->left,ans);
        leafTraversal(root->right,ans);
        
    }
    void rightTraversal(Node* root,vector<int> &ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right){
            rightTraversal(root->right,ans);
        }
        else{
            rightTraversal(root->left,ans);
        }
        //on return 
        ans.push_back(root->data);
        
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        //left traversal
        leftTraversal(root->left,ans);
        //leaf nodes
        //left subtree
        leafTraversal(root->left,ans);
        //right subtree
        leafTraversal(root->right,ans);
        //right nodes
        rightTraversal(root->right,ans);
        return ans;
    }
};
int main(){
    Node* root;
    root->data=1;
    root->left->data=2;
    root->right->data=3;
    Solution s;
    vector<int> ans=s.boundary(root);
    int i=0;
    for(auto i:ans){
        cout<<ans[i];
    }
    return 0;
}