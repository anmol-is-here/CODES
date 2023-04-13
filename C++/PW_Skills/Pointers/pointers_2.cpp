#include<iostream>
using namespace std;

void swapq(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    // return;
}

int main() {
    int x = 18, y = 26;
    int *p1 = &x;
    int *p2 = &y;
     
    swapq(p1, p2);
    cout<<x<<" "<<y;
    return 0;
}