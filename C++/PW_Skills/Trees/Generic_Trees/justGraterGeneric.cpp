#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node(int data){
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

void justGraterNode(Node* root, int x, Node* &ans){
    if(root == NULL) {
        return;
    }

    if(root->val > x and (ans == NULL or ans->val > root->val)){
        ans = root;
    }

    for(Node* child:root->children){
        justGraterNode(child, x, ans);
    }
    return;
}

int main() {

    Node* root = new Node(20);
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(22));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(12));
    root->children[0]->children[1]->children.push_back(new Node(10));
    root->children[0]->children[1]->children.push_back(new Node(14));

    // preorderTraversal(root);

    int x {10};
    Node* ans = NULL;
    justGraterNode(root, x, ans);
    cout<<"ANS -> ";
    if(ans == NULL){ cout<<"NULL";}
    else {cout<<ans->val;}
    
    return 0;
}