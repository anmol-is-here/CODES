#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<vector<int>> mat(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}