#include<iostream>
using namespace std;

int sumOfNumFrom1toN(int num){
    if(num == 0) return 0;
    return (sumOfNumFrom1toN(num-1) + num);
}

int summition(int n, int m){
    if (m==1){
        return sumOfNumFrom1toN(n);
    }
    return summition(summition(n, m-1), m-1);
}

int main() {
    cout<<summition(5, 1);
    return 0;
}