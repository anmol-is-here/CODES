#include <bits/stdc++.h>
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

void encode(Node* root, string& data) {
    if(!root) {
        data += 'x';
        return;
    }
    data += 'n';
    char* buffer = (char*)&root->val;
    for(int i = 0; i < 4; ++i)
        data += buffer[i];
    encode(root->left, data);
    encode(root->right, data);
}

// string serialize(Node* root) {
//         string s="";
//         if(!root){
//             return s;
//         }
//         queue<Node*>q;
//         q.push(root);
//         while(!q.empty()){
//             Node* node=q.front();
//             q.pop();
//             if(!node){
//                 s+="#,";
//             }
//             else{
//                 s+=to_string(node->val)+',';
//                 q.push(node->left);
//                 q.push(node->right);
//             }
//         }
//         return s;
//     }

// string serialize(Node* root) {
//     string data;
//     encode(root, data);
//     return data;
// }

void serializeHelper(Node* root, string &str){
    if(root == NULL) return;
    str += to_string(root->val) + ':';
    serializeHelper(root->left, str);
    serializeHelper(root->right, str);
}
// Encodes a tree to a single string.
string serialize(Node* root) {
    string str = "";
    if(root == NULL){
        return str;
    }
    serializeHelper(root, str);
    return str;
}

Node* deserializeHelper(string &data, int &index, int upper_bound){
        if(index >= data.size()){
            return NULL;
        }

        int value = stoi(data.substr(0, data.find(':')));


        if(value >= upper_bound){
            return NULL;
        }

        Node* root = new Node(value);
        data = data.substr(data.find(':'));
        // index++;

        root->left = deserializeHelper(data, index, root->val);
        root->right = deserializeHelper(data, index, upper_bound);

        return root;
}
// Decodes your encoded data to tree.
Node* deserialize(string data) {
    int index = 0;
    return deserializeHelper(data, index, INT_MAX);
}

int main() {
    BST bst1;
    bst1.root = insertInBST(bst1.root, 2);
    insertInBST(bst1.root, 1);
    insertInBST(bst1.root, 3);
    // insertInBST(bst1.root, 2);
    // insertInBST(bst1.root, 6);

    string data = serialize(bst1.root);

    Node* root2 = deserialize(data);
    
    inorderTraversal(root2);

    return 0;
}

/**
 *            3
 *           / \
 *          1   4
 *           \   \
 *            2   6
*/