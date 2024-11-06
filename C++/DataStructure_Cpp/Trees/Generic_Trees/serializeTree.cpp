#include <iostream>
#include <unordered_map>
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

void serialize(Node* root, string &ans){
    if(root == NULL){
        return;
    }

    ans += to_string(root->val) + ":" + to_string(root->children.size()) + ":";
    for(Node* child : root->children){
        ans += to_string(child->val) + ",";
    }
    if(root->children.size()) ans.pop_back();
    ans += "\n";

    for(Node* child: root->children){
        serialize(child, ans);
    }

}

Node* deserializeStrHelper(int rootNodeVal, unordered_map<int, string> mp){
    Node* rootNode = new Node(rootNodeVal);
    string nodeStr = mp[rootNodeVal]; // 2:20,30

    if(nodeStr[0] == '0') return rootNode; // leaf node.

    int breakPos = nodeStr.find(':');
    int childsNum = stoi(nodeStr.substr(0, breakPos));
    int start = breakPos + 1;
    for(int i = 0; i<childsNum; i++){
        int end = nodeStr.find(',', start);
        if(end == string::npos)  end = nodeStr.size(); // that means ',' is not found in the string.
        int childVal = stoi(nodeStr.substr(start, end));
        rootNode->children.push_back(deserializeStrHelper(childVal, mp));
        start = end + 1;
    }
    return rootNode;
}

Node* deserializeStr(string serialisedStr){
    if(serialisedStr == ""){
        return NULL;
    }

    unordered_map<int, string> mp;
    int start {0};
    for(int i = 0; i < serialisedStr.size(); i++){
        if(serialisedStr[i] == '\n'){
            string nodeStr = serialisedStr.substr(start, i-start);  // "10:2:20,30"
            int breakPos1 = nodeStr.find(':');
            int nodeValue = stoi(nodeStr.substr(0, breakPos1)); // 10
            mp[nodeValue] = nodeStr.substr(breakPos1+1); // "2:20,30"
            start = i+1;
        }
    }
    int rootNodeVal = stoi(serialisedStr.substr(0, serialisedStr.find(':')));
    return deserializeStrHelper(rootNodeVal, mp);
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
    string ans = "";
    serialize(root, ans);
    cout<<"\n"<<ans<<endl;

    Node* root1 = deserializeStr(ans);
    levelOrderTraversal(root1);


    return 0;
}