#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val = data;
        left = right = NULL;
    }
};

class BST{
public:
    Node* root;
    BST(){
        root = NULL;
    }
};

Node* insertInBST(Node* root, int value){     // Recursive Function.
    //base case.
    if(root == NULL){
        Node* newNode = new Node(value);
        return newNode;
    }

    // Recursive Case.
    if(root->val > value){
        root->left = insertInBST(root->left, value);
    }
    else if(root->val < value){
        root->right = insertInBST(root->right, value);
    }
    return root;
}

void inorderTraversal(Node* root){
    if(root == NULL) return;

    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
    return;
}

void preTraversal(Node* root){
    if(root == NULL) return;

    cout<<root->val<<" ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
    return;
}

Node* removeLeafNode(Node* root){
    if(root == NULL or (root->left == NULL and root->right == NULL)) return NULL;
    // recrsive case;
    root->left = removeLeafNode(root->left);
    root->right = removeLeafNode(root->right);
    return root;
}

int main() {
    BST bst1;
    bst1.root = insertInBST(bst1.root, 3);
    insertInBST(bst1.root, 1);
    insertInBST(bst1.root, 4);
    insertInBST(bst1.root, 2);
    insertInBST(bst1.root, 6);

    inorderTraversal(bst1.root);
    cout<<endl;
    Node* temp = removeLeafNode(bst1.root);
    inorderTraversal(temp);
    
    
    return 0;
}

/**
 *            3
 *           / \
 *          1   4
 *           \   \
 *            2   6
*/