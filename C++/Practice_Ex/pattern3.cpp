#include<iostream>
using namespace std;

int main() {
    int n = 3;
    for (int i = 0; i < n*2 - 1; i++) {
        for (int j = 0; j < n ; j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}