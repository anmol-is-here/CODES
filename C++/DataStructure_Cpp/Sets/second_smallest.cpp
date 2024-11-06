#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> v {1,1,2,3,4};
    set<int> s1;
    for(auto ele:v){
        s1.insert(ele);
    }
    
    auto itr = s1.begin();
    itr++;
    cout<<"Second smalllest value is "<<*itr<<endl;

    return 0;
}