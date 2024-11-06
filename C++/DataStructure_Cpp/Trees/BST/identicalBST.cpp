// check weather given array has identical BST or not, without constructing the BST in actual.

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

bool checkIdenticalBSTHelper(vector<int> v1, vector<int> v2, int a1, int a2, int minValue, int maxValue) {
    // find first element in v1 within range.
    int i;
    for(i = a1; i < v1.size(); i++){
        if(v1[i] > minValue and v1[i] < maxValue) break;
    }
    // find firse element in v2 within range.
    int j;
    for(j = a2; j < v2.size(); j++){
        if(v2[j] > minValue and v2[j] < maxValue) break;
    }
    // if no element is found within range (leaf nodes).
    if(i == v1.size() and j == v2.size()){
        return true;
    }
    // if only one vector does not have element within range.
    if((i == v1.size() and j != v2.size()) and (i != v1.size() and j == v2.size())){
        return false;
    }

    // checking if both elements are equal.
    if(v1[i] != v2[j]) return false;
    // recursively check for left and right subtree.
    return checkIdenticalBSTHelper(v1, v2, a1+1, a2+1, minValue, v1[i]) and checkIdenticalBSTHelper(v1, v2, a1+1, a2+1, v2[j], maxValue);
}

bool checkIdenticalBST(vector<int> &v1, vector<int> &v2){
    return checkIdenticalBSTHelper(v1, v2, 0, 0, INT_MIN, INT_MAX);
}

int main() {
    vector<int> v1 {4,2,5,1,3};
    vector<int> v2{4,5,2,3,1};

    if(checkIdenticalBST(v1, v2)){
        cout<<"BST are Identical."<<endl;
    }
    else{
        cout<<"BST are not Identical"<<endl;
    }
    
    return 0;
}