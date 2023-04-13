#include<bits/stdc++.h>
using namespace std;

int main() {
    int num, rem, sum = 0, count = 0;
    cin>>num;
     while (num != 0)        
    {
        rem = num % 2;
        sum += rem * pow(10, count);
        num = num / 2;
        count++;
    }
    cout<<sum<<endl;
}