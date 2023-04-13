#include<iostream>
using namespace std;

bool isInArray(int *arr, int n, int i, int x){
    if(i==n) return false;
    return ((arr[i] == x) || isInArray(arr, n, i+1, x));
}

int main() {
    int arr[] = {10, 12, 14, -52, 2, 3};
    int n = 6;
    int x = 52;
    cout<<isInArray(arr, n, 0, x);
    return 0;
}