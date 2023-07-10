#include <iostream>
#include <string>
using namespace std;

void permutation(string str, int i){
    // base case
    if(i == str.length()){
        cout<<str<<"  ";
        return;
    }

    for(int j = i; j < str.size(); j++){
        swap(str[i], str[j]);
        permutation(str, i+1);
        swap(str[i], str[j]);
    }
    return;
}

int main() {
    string str {"abc"};
    permutation(str, 0);

    return 0;
}