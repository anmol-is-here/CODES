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

// void insertInBST(Node* &root, int value){       // Iterative Function.
//     Node* newNode = new Node(value);
//     if(root == NULL){
//         root = newNode;
//         return;
//     }
//     Node* current = root;
//     while(true){
//         if(current->val > value){
//             if(current->left == NULL){
//                 current->left = newNode;
//                 return;
//             }
//             current = current->left;
//         }
//         else{
//             if(current->right == NULL){
//                 current->right = newNode;
//                 return;
//             }
//             current = current->right;
//         }
//     }
//     return;
// }

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

bool searchKey(Node* root, int key){
    //base case.
    if(root == NULL) return false;
    if(root->val == key) return true;
    //Recursive case.
    if(root->val > key){
        return searchKey(root->left, key);
    }
    if(root->val < key){
        return searchKey(root->right, key);
    }
    return false;
}

Node* largestNodeBST(Node* root){
    Node* curr = root;
    while(curr and curr->right){
        curr = curr->right;
    }
    return curr;
}

Node* deleteInBST(Node* root, int key){
    if(root == NULL) return root;
    if(root->val < key){
        root->right = deleteInBST(root->right, key);
    }
    else if(root->val > key){
        root->left = deleteInBST(root->left, key);
    }
    else{
        if(root->left == NULL and root->right == NULL){   // to delete node with 0 child.
            delete root;
            return NULL;
        }
        // to delete node with 1 child.
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // to delete node with 2 or more childs.
        else{
            Node* justSmallerNode = largestNodeBST(root->left);
            root->val = justSmallerNode->val;
            root->left = deleteInBST(root->left, justSmallerNode->val);
        }
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

int main() {
    BST bst1;
    bst1.root = insertInBST(bst1.root, 3);
    insertInBST(bst1.root, 1);
    insertInBST(bst1.root, 4);
    insertInBST(bst1.root, 2);
    insertInBST(bst1.root, 6);
    inorderTraversal(bst1.root);
    cout<<endl;
    // cout<<endl<<searchKey(bst1.root, 4);
    bst1.root = deleteInBST(bst1.root, 3);
    inorderTraversal(bst1.root);
    cout<<"\n"<<bst1.root->val;

    return 0;
}

/**
 *            3
 *           / \
 *          1   4
 *           \   \
 *            2   6
*/