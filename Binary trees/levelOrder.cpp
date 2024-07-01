#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> input;
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            input.push_back(temp->val);
        }
        ans.push_back(input);
    }
    return ans;
}
int main(){
    return 0;
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            root=s.top();
            s.pop();
            ans.push_back(root->val);
            if(root->right!=NULL){
                s.push(root->right);
            }
            if(root->left!=NULL){
                s.push(root->left);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> s;
        TreeNode* temp=root;
        while(true){
            if(temp!=NULL){
                s.push(temp);
                temp=temp->left;
            }
            else{
                if(s.empty()){
                    break;
                }
                temp=s.top();
                s.pop();
                inorder.push_back(temp->val);
                temp=temp->right;
            }
        }
        return inorder;
}};
//TC O(N) 
//SC O(N)