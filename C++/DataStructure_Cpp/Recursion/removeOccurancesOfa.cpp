#include<iostream>
using namespace std;

// string removeA(string &str, int idx, int len)
string removeA(string &str, int idx){
    if (idx==str.length()) return "";

    string curr = "";
    curr += str[idx];
    return ((str[idx]=='a')? "": curr) + removeA(str, idx+1);
}

int main() {
    string s = "abcab";
    // int len = 10;
    // cout<<removeA(s, 0, len);
    cout<<removeA(s, 0);
    return 0;
}