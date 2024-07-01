#include<iostream>
using namespace std;
class Solution
{
    pair<bool,int> isSum(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        if(root!=NULL && root->left==NULL && root->right==NULL){
          pair<bool,int> p=make_pair(true,root->data);
          return p;
        }
        pair<bool,int> leftAns=isSum(root->left);
        pair<bool,int> rightAns=isSum(root->right);
        bool left=leftAns.first;
        bool right=rightAns.first;
        bool cond=root->data==leftAns.second+rightAns.second;
        pair<bool,int> ans;
        if(left && right && cond){
            ans.first=true;
            ans.second=2*root->data;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         return isSum(root).first;
    }
};
int main(){
    return 0;
}