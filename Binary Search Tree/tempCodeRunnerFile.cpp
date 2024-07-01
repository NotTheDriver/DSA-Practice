#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void levelOrderTravseral(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
}
Node* insertInTree(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data > data){
        insertInTree(root->left,data);
    }
    if(root->data < data){
        insertInTree(root->right,data);
    }
    return root;
}
void insertData(Node* root){
    int val;
    cin>>val;
    while(val!=-1){
        root=insertInTree(root,val);
        cin>>val;
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter the data:";
    insertData(root);
    cout<<"printing the BST"<<endl;
    levelOrderTravseral(root);
    return 0;
}