#include<iostream>
using namespace std;

int numOfPath(int i, int j, int m, int n){
    if (i == m-1 and j == n-1) return 1;
    if (i >= m or j >= n) return 0;
    return numOfPath(i, j+1,m , n) + numOfPath(i+1, j, m, n); 
}

int main() {
    cout<<numOfPath(0, 0, 2, 3);
    return 0;
}