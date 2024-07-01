void inorder(BinaryTreeNode<int> *root, int &count){
    if(root==NULL){
        return;
    }
    inorder(root->left,count);
    //leaf node ie node with no child
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder(root->right,count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count=0;
    inorder(root,count);
    return count;
}