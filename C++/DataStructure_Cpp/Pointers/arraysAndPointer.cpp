#include<iostream>
using namespace std;

void process (int *arr, int n) {
    for (int i = 0; i<n; i++) {
        cout<<*(arr+i)<<"\n";
    }
    *(arr+1) = 54;
    return;
}

int main() {
    int arr[] = {1, 5, 8};
    process(arr, 3);

    for(int i = 0; i<3; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}