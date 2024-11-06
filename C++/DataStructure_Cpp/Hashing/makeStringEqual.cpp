#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canMakeEqual(vector<string> str){
    unordered_map<char, int> m;
    for(auto word:str){
        for(auto alpha:word){
            m[alpha]++;
        }
    }
    int n = str.size();
    for(auto ele:m){
        if(ele.second%n != 0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    vector<string> str(n);
    for(int i = 0; i < n; i++){
        cin>>str[i];
    }
    cout<<(canMakeEqual(str)?"Yes":"No")<<endl;
    
    return 0;
}