#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    unordered_multimap<string, int> fruitCount;
    fruitCount.insert(make_pair("apple", 9));
    fruitCount.insert(make_pair("banana", 6));
    fruitCount.insert(make_pair("litchi", 3));
    fruitCount.insert(make_pair("apple", 5));
    
    for(auto itr:fruitCount){
        cout<<itr.first<<" - "<<itr.second<<endl;
    }

    return 0;
}