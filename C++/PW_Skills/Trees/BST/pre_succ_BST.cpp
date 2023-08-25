// Inorder predecessor and successor of BST.

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

void inorderPreSucc_BST(Node* root, Node* &pre, Node* &succ, int key){
    if(root == NULL){
        return;
    }
    if(root->val == key){
        // pre -> rightmost value in left subtree.
        if(root->left){
            Node* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            pre = temp;
        }
        // succ -> leftmost value in right subtree.
        if(root->right){
            Node* temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }

    if(root->val > key){
        succ = root;
        inorderPreSucc_BST(root->left, pre, succ, key);
    }
    if(root->val < key){
        pre = root;
        inorderPreSucc_BST(root->right, pre, succ, key);
    }
}

int main() {
    BST bst1;
    bst1.root = insertInBST(bst1.root, 3);
    insertInBST(bst1.root, 1);
    insertInBST(bst1.root, 4);
    insertInBST(bst1.root, 2);
    insertInBST(bst1.root, 6);
    Node* succ = NULL;
    Node* pre = NULL;
    inorderPreSucc_BST(bst1.root, pre, succ, 3);
    if(succ!=NULL){
        cout<<"Sucessor - "<<succ->val<<endl;
    }
    else{
        cout<<"Sucessor - NULL"<<endl;
    }
    if(pre!=NULL){
        cout<<"Predecessor - "<<pre->val<<endl;
    }
    else{
        cout<<"Predecessor - NULL"<<endl;
    }
    
    return 0;
}