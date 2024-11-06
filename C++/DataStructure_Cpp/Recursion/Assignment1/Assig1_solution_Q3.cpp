#include<iostream>
using namespace std;

int count(int n, int val){
    if(n == 1 and val >= 0) return 1;

    int sum = 0;
    
    for(int i=0; i<=val; i++){
        sum = sum + count(n-1, val-i);
    }
    return sum;
}

int main() {
    cout<<count(3, 2);
    return 0;
}