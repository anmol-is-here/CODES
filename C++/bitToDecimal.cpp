#include<bits/stdc++.h>
using namespace std;

int binToDecimal(int num) {
    int rem, temp, count = 0, sum = 0;
    while (num != 0)        
    {
        rem = num % 10;
        sum += rem * pow(2, count);
        num = num / 10;
        ++count;
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<binToDecimal(n);
}