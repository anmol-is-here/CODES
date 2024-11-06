#include<iostream>
using namespace std;

void multiple(int n, int k){
    if (k == 0) return ;
    multiple(n, k-1);
    cout<<(n*k)<<" ";
}

int main() {
    multiple(4, 9);
    return 0;
}