#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node* right=NULL;
        node* left=NULL;
    node(int d){
        this->data=d;
        this->right=NULL;
        this->left=NULL;
    }
};
node* BuildTree(node* root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data to insert to the left "<<data<<endl;
    root->left=BuildTree(root->left);
    cout<<"Enter the data to the right of "<<data<<endl;
    root->right=BuildTree(root->right);
    return root;
}
void treeTraversal(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(root->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void buildFromlevelOrder(node* &root){
    queue<node*> q;
    cout<<"enter data for root node:";
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter the left data:";
        int left;
        cin>>left;
        if(left!=-1){
            temp->left=new node(left);
            q.push(temp->left);
        }
        cout<<"Enter the right data:";
        int right;
        cin>>right;
        if(right!=-1){
            temp->right=new node(left);
            q.push(temp->right);
        }
    }

}
int main(){
    node* root=NULL;
    //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    root=BuildTree(root);
    cout<<"Print level order transversal: "<<endl;
    preOrder(root);
    return 0;
}