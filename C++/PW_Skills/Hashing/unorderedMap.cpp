#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> record;
    record.insert(make_pair(2, "anmol"));
    record[1] = "aditya";
    record[3] = "ansh";

    for(auto itr:record){
        cout<<itr.first<<" - "<<itr.second<<endl;
    }
    
    return 0;
}