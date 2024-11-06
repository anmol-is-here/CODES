#include<iostream>
using namespace std;

int minJumpCost(int *h, int n, int i){
    if (i==n-1) return 0;
    if (i==n-2) return (minJumpCost(h, n, i+1) + abs(h[i]-h[i+1]));

    return min(minJumpCost(h, n, i+1) + abs(h[i]-h[i+1]), minJumpCost(h, n, i+2) + abs(h[i]-h[i+2]));
}

int main() {
    int arr[] = {10, 30, 20, 20};
    int n = 4;
    cout<<minJumpCost(arr, n, 0);
    return 0;
}