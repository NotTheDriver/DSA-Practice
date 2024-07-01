#include<iostream>
using namespace std;
void convertToLinkedList(TreeNode<int> *root,TreeNode<int>* &head){
    if(root==NULL){
        return;
    }
    convertToLinkedList(root->right, head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertToLinkedList(root->left, head);
}
TreeNode<int>  mergeDLL(TreeNode<int> *head1,TreeNode<int> *head2){
    TreeNode<int> *head=NULL;
    TreeNode<int> *tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
        while(head1!=NULL){
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
        }
        while(head2!=NULL){
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
        }
    }
}
int countNodes(TreeNode<int> *head){
    int cnt=0;
    TreeNode<int> *temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
TreeNode<int> *sortedLLtoBST(TreeNode<int> *head,int n){
    //base case
    if(head==NULL || n<=0){
        return NULL;
    }
    TreeNode<int> *left=sortedLLtoBST(head, n/2);
    TreeNode<int> *root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLLtoBST(head,n-n/2-1);
    return root;
}
vector<int> mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here.

    // vector<int> bst1,bst2;
    // inorder(root1,bst1);
    // inorder(root2,bst2);
    // vector<int> merged=mergeArrays(bst1,bst2);
    // return merged;
    TreeNode<int> *head1=NULL;
    convertToLinkedList(root1,head1);
    head1->left=NULL;

    TreeNode<int> *head2=NULL;
    convertToLinkedList(root2,head2);
    head2->left=NULL;

    TreeNode<int> *head=mergeBST(head1,head2);
    return sortedLLtoBST(head, countNodes(head));
}
int main(){
    return 0;
}