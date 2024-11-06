#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(1);
    ms.insert(3);
    ms.insert(2);
    ms.insert(3);

    for(auto ele:ms){
        cout<<ele<<" ";
    }cout<<endl;
    
    return 0;
}