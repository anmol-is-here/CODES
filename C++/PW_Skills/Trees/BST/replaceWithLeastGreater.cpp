/**
 * Question -> Given an array of integer , replace each element in that array with its least greter element
 *   present in its right side.
*/

#include <iostream>
#include <vector>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertNode(TreeNode* root, int element, int &sucessor){
    if(root == NULL){
        return new TreeNode(element);
    }

    if(root->val > element){
        sucessor = root->val;
        root->left = insertNode(root->left, element, sucessor);
    }
    else if(root->val < element){
        root->right  = insertNode(root->right, element, sucessor);
    }
    return root;
}

void replaceWithLeastGreterElement(vector<int> &v){
    
    TreeNode* root = NULL;
    
    for(int i = v.size()-1; i>=0; i--){
        int sucessor {-1};
        root = insertNode(root, v[i], sucessor);
        v[i] = sucessor;
    }
}

int main() {
    vector<int> v {8,3,10,15,6,9,14};
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    replaceWithLeastGreterElement(v);

    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}