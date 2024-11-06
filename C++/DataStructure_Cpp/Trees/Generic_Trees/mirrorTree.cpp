#include <iostream>
#include <algorithm>
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

void mirrorTree(Node* root){
    if(root == NULL){
        return;
    }

    if(root->children.size()<2){
        return;
    }

    reverse(root->children.begin(), root->children.end());

    for(Node* child:root->children){
        mirrorTree(child);
    }
    return;
}

int main(){
    
    Node* root = new Node(10);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(34));
    root->children.push_back(new Node(56));
    root->children.push_back(new Node(100));
    root->children[1]->children.push_back(new Node(1));
    root->children[3]->children.push_back(new Node(7));
    root->children[3]->children.push_back(new Node(8));
    root->children[3]->children.push_back(new Node(9));
    levelOrderTraversal(root);
    mirrorTree(root);
    levelOrderTraversal(root);


    return 0;
}