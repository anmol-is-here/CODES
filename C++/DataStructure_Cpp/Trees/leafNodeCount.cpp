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

int leafCount(Node* root){
    // base case.
    if(!root){
        return 0;
    }
    if(!root->left and !root->right){
        return 1;
    }

    //recursive case.
    int left_LeafTotal = leafCount(root->left);
    int right_LeafTotal = leafCount(root->right);

    return (left_LeafTotal + right_LeafTotal);
}

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    
    cout<<leafCount(rootNode);

    return 0;
}

/**
 *        2
 *       / \
 *      4   10
 *     / \    \
 *    6   5    11
*/