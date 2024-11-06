#include<iostream>
using namespace std;

int main() {
    int i, j;
    int n = 5;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i ; j++) {
            cout<<" ";
        }

        for (j = n-i; j > 0; j--) {
            cout<<"*";
        }

        for (j = n-i; j > 1; j--) {
            cout<<"*";
        }

        cout<<endl;
    }

    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < n; j++) {
            
    //     }
    // }
    return 0;
}