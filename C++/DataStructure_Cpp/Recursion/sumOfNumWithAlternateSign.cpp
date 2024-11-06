#include<iostream>
using namespace std;

int alternateSum(int num){
    if (num == 0) return 0;
    return alternateSum(num-1) + ((num%2==0)?(-num):(num));
}

int main() {
    cout<<alternateSum(10);
    return 0;
}