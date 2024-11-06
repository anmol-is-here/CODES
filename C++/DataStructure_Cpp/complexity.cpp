#include<iostream>
// #include<vector>
using namespace std;

int sum_in_range(int x, int y) {
    int sum = 0;
    for(int i = x; i < y; i++) {
        sum += i;
    }
    return sum;
}

int sum_in_range_optimized(int x, int y) {
    int sum = 0;
    int n = (y-x+1);
    sum = ((n/2)*((2*x)+(n-1)*1));
    return sum;
}
int main() {
    cout<<sum_in_range(2,1000000);
    // cout<<sum_in_range_optimized(2,1000000);
    return 0;
}