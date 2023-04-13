#include<iostream>
using namespace std;

int power(int base, int raise){
    if (raise == 0) return 1;

    if (raise == 1) return base;

    return (power(base, (raise-1)) * base);
}


int armstrong(int n, int d){
    if (n == 0) return 0;

    return power(n%10, d) + armstrong(n/10, d);
}


int main() {
    int n = 153;
    int temp = n;
    int noOfDigits = 0;
    while (temp!=0) {
        temp = temp/10;
        noOfDigits++;
    }
    int res = armstrong(n, noOfDigits);
    if (n == res) {
        cout<<"Yes.";
    } else {
       cout<<"No"; 
    }
    
    return 0;
}