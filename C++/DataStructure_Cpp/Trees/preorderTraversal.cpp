#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void preorderTraversal(Node* rootNode){
    // base case.
    if(rootNode == NULL){
        return;
    }

    cout<<rootNode->data<<" ";
    //recursive call for left subtree.
    preorderTraversal(rootNode->left);
    //recursive call for right subtree.
    preorderTraversal(rootNode->right);
    return;
}

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);

    preorderTraversal(rootNode);
    
    return 0;
}

/**
 *        2
 *       / \
 *      4   10
 *     / \    \
 *    6   5    11
*/