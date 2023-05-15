#include <iostream>
#include <vector>
#include <string>
using namespace std;

string countSort(string str){
    vector <int> freq(26,0);

    for (int i {0}; i < str.length(); i++){
        int index = str[i] - 'a';
        freq[index]++;

    }

    int j {0};
    for(int i=0; i<26; i++) {
        while(freq[i]--){
            str[j++] = i + 'a';
        }
    }
    return str;
}

int main() {
    string str ("college");
    cout<<countSort(str);    
    return 0;
}