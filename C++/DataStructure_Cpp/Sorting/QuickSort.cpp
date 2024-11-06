#include<iostream>
using namespace std;

int parti(int arr[], int p, int q){
    int pivot = arr[q];
    int i = p-1;
    int j = p;
    for(; j<q; j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[q]);
    return i+1;
}

void quick_sort(int arr[], int p, int q) {

    if (p>=q){
        return;
    }

    int pi = parti(arr, p, q);
    quick_sort(arr, p, pi-1);
    quick_sort(arr, pi+1, q);
}

int main() {
    int arr[] = {45,23,15,89,75,62,15,85,49};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}