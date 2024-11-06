#include<iostream>
#include<vector>
using namespace std;

void substring(string &str, int i, string result, vector<string> &li){
    if (i == str.length()){
        li.push_back(result);
        return;
    }
    substring(str, i+1, result+str[i], li);
    substring(str, i+1, result, li);
}

int main() {
    string st = "ab";
    vector <string> res;
    substring(st, 0, "", res);
    for (int i = 0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}