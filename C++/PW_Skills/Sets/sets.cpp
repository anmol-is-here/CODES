#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);
    // cout<<set1.size()<<endl;
    // set1.insert(3);
    // cout<<set1.size()<<endl; // since it only accepts unique elements.

    // traversal in a set.

    // set<int>::iterator itr;  // we can also use auto keword instead.
    // for(itr = set1.begin(); itr!=set1.end(); itr++){ // auto = itr
    //     cout<<*itr<<" ";
    // }

    for(auto value:set1){
        cout<<value<<" ";
    }cout<<endl;

    // deletion elements in a set.
    // set1.erase(4);

    // auto itr = set1.begin();
    // advance(itr,3);
    // set1.erase(itr);

    // auto start_itr = set1.begin();
    // start_itr++;
    // auto end_itr = set1.begin();
    // advance(end_itr, 3);
    // set1.erase(start_itr, end_itr);

    // for(auto value:set1){
    //     cout<<value<<" ";
    // }

    // search operation.
    if(set1.find(7) != set1.end()) {
        cout<<"Element is present"<<endl;
    } else {
        cout<<"Element is not present"<<endl;
    }

    
    return 0;
}