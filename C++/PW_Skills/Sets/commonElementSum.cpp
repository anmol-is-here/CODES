#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> v1 {1,1,2,2,3};
    vector<int> v2 {6,5,1,2,3,7};
    int ans_sum {0};
    set<int> s1;

    for(auto ele:v1){
        s1.insert(ele);
    }

    for(auto ele:v2){
        if(s1.find(ele)!=s1.end())
        ans_sum += ele;
    }
    cout<<"Ans = "<<ans_sum<<endl;
    
    return 0;
}