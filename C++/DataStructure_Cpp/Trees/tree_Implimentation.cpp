#include <iostream>
#include <vector>
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

int main() {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);

    cout<<"Root Node = "<<root->data<<endl;
    cout<<"Left Node = "<<root->left->data<<endl;
    cout<<"Right Node = "<<root->right->data<<endl;

    
    return 0;
}