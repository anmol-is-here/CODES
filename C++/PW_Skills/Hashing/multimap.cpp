#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    multimap<string, int> directory;
    directory.insert(make_pair("anmol", 541235));
    directory.insert(make_pair("mannu", 128623));
    directory.insert(make_pair("bullah", 751852));
    directory.insert(make_pair("bullah", 852562));
    // directory["arjun"] = 4535442;                    insertion using [] is not allowed in multimap.
    for(auto itr:directory){
        cout<<itr.first<<" - "<<itr.second<<endl;
    }

    cout<<directory.count("bullah")<<endl;

    return 0;
}