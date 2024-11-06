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

void levelorder(Node* rootnode){
    //base case.
    if(rootnode == NULL){
        return;
    }
    queue<Node*> q;
    q.push(rootnode);

    while(!q.empty()){
         
        int nodesAtCurrLevel = q.size();
        while(nodesAtCurrLevel--){
            Node* currNode = q.front();
            q.pop();
            cout<<currNode->data<<" ";
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
        }
        cout<<endl;

    } 
}

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);

    levelorder(rootNode);
    
    return 0;
}

/**
 *        2
 *       / \
 *      4   10
 *     / \    \
 *    6   5    11
*/