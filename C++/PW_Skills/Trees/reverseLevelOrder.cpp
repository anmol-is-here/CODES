#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    stack<Node*> st;

    while(!q.empty()){
        int nodesAtCurrentLevel = q.size();
        while(nodesAtCurrentLevel--){
            Node* currNode = q.front();
            q.pop();
            st.push(currNode);
            
            if(currNode->right){
                q.push(currNode->right);
            }
            if(currNode->left){
                q.push(currNode->left);
            }
        }
    }

    while(!st.empty()){
        ans.push_back(st.top()->data);
        st.pop();
    }
    return ans;
}

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->left->right->left = new Node(12);
    rootNode->right->right = new Node(11);
    
    vector<int> v = topView(rootNode);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}

/**
 *        2
 *       / \
 *      4   10
 *     / \    \
 *    6   5    11
 *       /
 *      12
*/