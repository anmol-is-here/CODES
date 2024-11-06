/** Two strings are called anagram of each other if,
 * 1. Their length is equal and,
 * 2. the second string is made by rearranging the lwtters of first string only.
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isanagram(string s1, string s2) {
    vector <int> freq(26,0);

    if (s1.length() != s2.length()) {
        return false;
    }

    else {
        for (int i=0; i<s1.length(); i++){
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int i=0; i<26; i++){
            if(freq[i]!=0){
                return false;
            }
        }
    }
    return true;
}

int main() {
    string str1 ("anagram");
    string str2 ("nagaram");
    if (isanagram(str1, str2)) {
        cout<<"Anagram strings";
    }
    else {
        cout<<"Not Anagram strings";
    }
    return 0;
}