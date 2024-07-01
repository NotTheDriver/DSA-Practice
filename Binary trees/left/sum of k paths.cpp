#include<iostream>
using namespace std;
class Solution{
  public:
    void solve(Node* root, int &count,int k,vector<int> ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->data);
        solve(root->left,count,k,ans);
        solve(root->right,count,k,ans);
        int size=ans.size();
        int sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=ans[i];
            if(sum==k){
                count++;
            }
        }
        ans.pop_back();
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> ans;
        int count=0;
        solve(root,count,k,ans);
        return count;
    }
};
int main(){
    return 0;
}