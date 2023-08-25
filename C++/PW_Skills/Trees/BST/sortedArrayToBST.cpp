#include <iostream>
#include <vector>
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

Node* sortedArrayToBST(vector<int> v, int start, int end){
    //base case.
    if(start>end) return NULL;
    int mid = (start+end)/2;
    Node* root = new Node(v[mid]);
    // recursive case.
    root->left = sortedArrayToBST(v, start, mid-1);
    root->right = sortedArrayToBST(v, mid+1, end);
    return root;
}

void preorder(Node* root){
    if(root == NULL) return;

    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> v {1,2,3,4,5,6};
    Node* root = sortedArrayToBST(v, 0, v.size()-1);
    preorder(root);
    
    return 0;
}