#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

string longestPrefix(vector <string> &str) {
    sort(str.begin(), str.end());
    string s1 (str[0]);
    int i {0};
    string s2 (str[str.size()-1]);
    int j {0};
    string ans ("");

    while (i<s1.size() and j<s2.size()) {
        if (s1[i] == s2[j]) {
            ans += s1[i];
            i++; j++;
        }
        else {
            break;
        }
    }
    return ans;
}

int main() {
    vector <string> str {"ant", "anthon", "anti", "bee"};
    cout<<" longest common prefix is : "<<longestPrefix(str);
    return 0;
}