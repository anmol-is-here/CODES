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


Node* lowestCommonAncestor(Node* root, Node* node1, Node* node2){
    // base case.
    if(root == NULL) return NULL;
    // recursive case.
    if(root->val > node1->val and root->val > node2->val){
        // ancestor is in left subtree.
        return lowestCommonAncestor(root->left, node1, node2);
    }
    if(root->val < node1->val and root->val < node2->val){
        // ancestor is in right subtree.
        return lowestCommonAncestor(root->right, node1, node2);
    }
    /**
     * if root value is lying between node1 and node2 value or,
     * if root value is equal to the node value
    */
    return root;
}

int main() {
    BST bst1;
    bst1.root = insertInBST(bst1.root, 3);
    insertInBST(bst1.root, 1);
    insertInBST(bst1.root, 4);
    insertInBST(bst1.root, 2);
    insertInBST(bst1.root, 6);

    Node* node1 = new Node(2);
    Node* node2 = new Node(3);
    Node* temp = lowestCommonAncestor(bst1.root, node1, node2);
    cout<<temp->val;

    return 0;
}

/**
 *            3
 *           / \
 *          1   4
 *           \   \
 *            2   6
*/