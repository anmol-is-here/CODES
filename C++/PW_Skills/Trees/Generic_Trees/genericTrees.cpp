#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    char val;
    vector<Node*> children;
    Node(char data){
        this->val = data;
    }
};

void preorderTraversal(Node* root){
    if(root == NULL) return;

    cout<<root->val<<" ";
    for(Node* child:root->children){
        preorderTraversal(child);
    }
    return;
}

void inorderTraversal(Node* root){
    if(root == NULL) return;

    int childNodes = root->children.size();
    for(int i = 0; i<childNodes-1; i++){
        inorderTraversal(root->children[i]);
    }
    cout<<root->val<<" ";
    if(childNodes>0){
        inorderTraversal(root->children[childNodes-1]);
    }
    return;
}

void postorderTraversal(Node* root){
    if(root == NULL) return;

    for(Node* child:root->children){
        postorderTraversal(child);
    }
    cout<<root->val<<" ";
    return;
}

void levelOrderTraversal(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int nodesAtCurrLevel = q.size();
        while(nodesAtCurrLevel--){
            Node* curr = q.front();
            q.pop();
            cout<<curr->val<<" ";
            for(Node* child : curr->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
    return;
}

int main() {

    Node* root = new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node('D'));
    root->children[0]->children.push_back(new Node('E'));
    root->children[0]->children.push_back(new Node('F'));
    root->children[2]->children.push_back(new Node('G'));
    
    // preorderTraversal(root);
    // inorderTraversal(root);
    // postorderTraversal(root);
    // levelOrderTraversal(root);

    // cout<<root->val<<endl;
    // for(Node* child : root->children){
    //     cout<<child->val<<" ";
    // }cout<<endl;
    
    return 0;
}

/**
 *                  A
 *                / | \
 *               /  |  \
 *              /   |   \  
 *             B    C     D
 *            / \        /
 *           E   F      G
*/