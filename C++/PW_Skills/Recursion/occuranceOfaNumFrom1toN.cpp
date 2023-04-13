#include<iostream>
using namespace std;

void nOccurance(int n){
    if(n<1) return ;
    
    nOccurance(n-1);
    cout<<n<<" ";
}

int main() {
    int n = 9;
    nOccurance(n);
    return 0;
}