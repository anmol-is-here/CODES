#include <iostream>
#include <vector>
#include <queue>
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

int maxDepth(Node* root){
    // base case.
    if(!root){
        return 0;
    }

    // recursive case.
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return (max(leftDepth, rightDepth) +1);
}

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    rootNode->right->right->left = new Node(12);
    
    cout<<maxDepth(rootNode);

    return 0;
}

/**
 *        2
 *       / \
 *      4   10
 *     / \    \
 *    6   5    11
 *             /
 *            12  
*/             