#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    unordered_multiset<int> ms1;
    ms1.insert(4);
    ms1.insert(8);
    ms1.insert(4);
    ms1.insert(1);
    ms1.insert(3);

    for(auto ele:ms1){
        cout<<ele<<" ";
    }cout<<endl;
    
    return 0;
}