#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    set<string> inviteList;
    int n;
    cin>>n;

    while(n--){
        string name;
        cin>>name;
        inviteList.insert(name);
    }

    for(auto name:inviteList){
        cout<<name<<endl;
    }

    return 0;
}