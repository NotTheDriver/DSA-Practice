#include <iostream>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node *left, *right;

    // Constructor
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to perform pre-order traversal
void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function to perform in-order traversal
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Function to perform post-order traversal
void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Performing pre-order traversal
    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // Performing in-order traversal
    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Performing post-order traversal
    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}