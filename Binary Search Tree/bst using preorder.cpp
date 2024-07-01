#include<iostream>
using namespace std;
class Solution {
public:
    TreeNode* solve(vector<int> &preorder,int min, int max, int &i){
        if(i>=preorder.size()){
            return NULL;
        }
        if(preorder[i]<min || preorder[i]>max){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=solve(preorder,min,root->val,i);
        root->right=solve(preorder,root->val,max,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min=INT_MIN;
        int max=INT_MAX;
        int i=0;
        return solve(preorder,min,max,i);
    }
};
int main(){
    return 0;
}