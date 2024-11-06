#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    list<int> l1 {1,2,3,4};

    // auto itr = l1.begin(); // itr will store the address of first element of our list.
    // l1.end() -> it will give me an iterator pointing to the memory location after 4.
    // cout<<*itr<<endl;

    // auto rev_itr = l1.rbegin();
    // cout<<*rev_itr<<endl
    // l1.rend() -> it will give me an iterator pointing to the memory location after 1.

    // advance(itr, 2);
    // cout<<*itr<<endl;

    // Traversal of list in STL.
    // 1. Using range based loop.
    // for(auto num:l1){
    //     cout<<num<<" ";
    // }

    // 2. using iterators.
    for(auto itr = l1.begin(); itr != l1.end(); itr++) {
        cout<<*itr<<" ";
    }
    cout<<endl;
    // reverse traversal.
    // for(auto itr = l1.rbegin(); itr != l1.rend(); itr++) {
    //     cout<<*itr<<" ";
    // }
    // cout<<endl;

    // Inserting an element in a list.
    auto itr = l1.begin();
    advance(itr,2);
    // l1.insert(itr,5);
    // l1.insert(itr, 3, 5);
    auto l = l1.begin();
    auto r = l1.begin();
    advance(r, 2);
    l1.insert(itr, l, r); // it will insert a portion of list into the position of itr.
    for(auto itr = l1.begin(); itr != l1.end(); itr++) {
        cout<<*itr<<" ";
    }
    cout<<endl;

    // deletion in list in STL.
    // 1 2 1 2 3 4. -> current list.
    auto s_itr = l1.begin();
    advance(s_itr, 2);
    auto e_itr = l1.begin();
    advance(e_itr, 4);
    l1.erase(s_itr, e_itr);
    for(auto itr = l1.begin(); itr != l1.end(); itr++) {
        cout<<*itr<<" ";
    }
    cout<<endl;
    


    return 0;
}