#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkAnagram(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }

    unordered_map<char, int> m;

    for(auto ele:s1){
        m[ele]++;   // storing character and their frequency in in map.
    }

    for(auto ele:s2){
        if(m.find(ele) == m.end()){
            return false;
        }
        else{
            m[ele]--;  // decreasing the stored frequency from the map of fouund character.
        }
    }

    for(auto ele:m){
        if(ele.second != 0){
            return false;
        }
    }

    return true;
}

int main() {
    string s1, s2;
    cin>>s1>>s2;

    cout<<(checkAnagram(s1, s2)?"Anagram":"Not Anagram")<<endl;
    
    return 0;
}