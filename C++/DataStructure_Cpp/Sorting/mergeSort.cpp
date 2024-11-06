#include<iostream>
using namespace std;



void merge(int arr[], int s, int mid, int e){
    int an = mid - s + 1;
    int bn = e - mid;   

    // create two temporary arrays
    int a[an], b[bn];

    for(int i = 0; i<an; i++){
        a[i] = arr[s+i];
    } 

    for (int j = 0; j < bn; j++){
        b[j] = arr[mid+1+j];
    }

    int i = 0, j = 0;
    int k = s;
    while(i<an and j<bn){
        if (a[i]<b[j]){
            arr[k++] = a[i++];
        }

        if (b[j]<a[i]) {
            arr[k++] = b[j++];
        }
    }

    while(i<an){
        arr[k++] = a[i++];
    }

    while(j<bn){
        arr[k++] = b[j++];
    }

}

void merge_sort(int arr[], int s, int e){
    // base case
    if (s>=e){
        return;
    }

    // recursive case
    int mid = (s+e)/2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid+1, e);
    merge(arr, s, mid, e);

}

int main() {
    int arr[] = {1,5,23,51,48,65,28,14,43,85};
    int size = sizeof(arr)/sizeof(arr[0]);

    merge_sort(arr, 0, size-1);

    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }   
    cout<<endl; 
    return 0;
}