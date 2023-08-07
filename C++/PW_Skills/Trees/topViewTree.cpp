#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    map<int, int> m;

    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        int nodesAtCurrentLevel = q.size();
        while(nodesAtCurrentLevel--){
            pair<Node*, int> p = q.front();
            int currColumn = p.second;
            Node* currNode = p.first;
            q.pop();

            if(m.find(currColumn) == m.end()){
                m[currColumn] = currNode->data;
            }

            if(currNode->left){
                q.push(make_pair(currNode->left, currColumn-1));
            }
            if(currNode->right){
                q.push(make_pair(currNode->right, currColumn+1));
            }
        }
    }
    for(auto i:m){
        ans.push_back(i.second);
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