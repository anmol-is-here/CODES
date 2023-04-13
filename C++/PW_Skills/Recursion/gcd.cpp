#include<iostream>
using namespace std;

int gcd(int a, int b){
    if (b>a) return gcd(b, a);
    if (b == 0) return a;
    return gcd (b, a%b);
    // return gcd (b, a-b);
}

int main() {
    int x = gcd (32, 18);
    cout<<x;
    return 0;
}