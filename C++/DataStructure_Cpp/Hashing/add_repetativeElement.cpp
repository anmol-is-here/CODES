#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<int> v {1,1,2,1,3,3,3};
    map<int, int> m;
    for(int i = 0; i<v.size(); i++){
        // inserting element in map.
        m[v[i]]++;
    }
    int sum {0};
    for(auto pair:m){
        if(pair.second>1){
            sum+=pair.first;
        }
    }
    
    cout<<"ANS - "<<sum<<endl;
    
    return 0;
}