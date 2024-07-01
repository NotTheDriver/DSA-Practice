#include<bits/stdc++.h>
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
Node* searchBST(Node* root, int val) {
        if(root==NULL){
            return NULL;
        }
        if(root->data==val){
            return root;
        }
        if(root->data > val){
            return searchBST(root->left, val);
        }
        else{
            return searchBST(root->right, val);
        }
    }
    //iterative approach (better time complexity o(N))
    Node* searchBST(Node* root, int val) {
        Node* temp= root;
        while(temp!=NULL){
            if(temp->data==val){
                return temp;
            }
            if(temp->data>val){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        return NULL;
    }
    
Node* insertInTree(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data > data){
        root->left=insertInTree(root->left,data);
    }
    else{
        root->right=insertInTree(root->right,data);
    }
    return root;
}
void insertData(Node* &root){
    int val;
    cin>>val;
    while(val!=-1){
        root=insertInTree(root,val);
        cin>>val;
    }
}
int minValue(Node* root){
	// Write your code here.	
	Node* temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp->data;
}
Node* deleteFromBST(Node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 child case
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL; 
        }
        //1 child case
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //2 child case
        if(root->left!=NULL && root->right!=NULL){
            int mini=minValue(root->right);
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }

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