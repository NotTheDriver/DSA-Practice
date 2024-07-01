#include<iostream>
using namespace std;
class Solution
{
public:
    void findPath(Node* root,int len,int &maxLen,int sum,int &maxSum){
        if(root==NULL){
            if(len>maxLen){
                maxLen=len;
                maxSum=sum;
            }
            else if(len==maxLen){
                maxSum=sum;
            }
            return;
        }
        sum+=root->data;
        findPath(root->left,len+1,maxLen,sum,maxSum);
        findPath(root->right,len+1,maxLen,sum,maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len=0;
        int maxLen=0;
        int sum=0;
        int maxSum=0;
        findPath(root,len,maxLen,sum,maxSum);
        return maxSum;
    }
};
int main(){
    return 0;
}