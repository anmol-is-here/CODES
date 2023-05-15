/**Isomorphic strings,
 * => the string which are one-one mapped by each other are called isomorphic strings.
 * eg:- if we take example of two strings [egg] and [add]
 * here e<->a;
 * and g<->d;
 * so above two strings are example of isomorphic strings.
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isIsomorphic(string s1, string s2) {
    vector <int> v1(128,-1);
    vector <int> v2(128,-1);

    if(s1.length() != s2.length()) {
        return false;
    }

    else {
        for (int i=0; i<s1.length(); i++){
            if (v1[s1[i]] != v2[s2[i]]) {
                return false;
            }
            else {
                v1[s1[i]] = v2[s2[i]] = i;
            }
        }
    }
    return true;
}

int main() {
    string str1 ("aabba");
    string str2 ("bbaaa");
    if (isIsomorphic(str1, str2)) {
        cout<<"Isomorphic strings";
    }
    else {
        cout<<"Not Isomorphic strings";
    }
    return 0;
}