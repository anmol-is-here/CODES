#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3;

void heapfy(int arr[N], int &size, int curr){

    while(2*curr <= size){

        int leftChild = 2*curr;
        int rigthChild = 2*curr + 1;
        int maxChild = leftChild;

        if(rigthChild <= size and arr[rigthChild] > arr[leftChild]){
            maxChild = rigthChild;
        }
        if(arr[curr] >= arr[maxChild]){
            return;
        }
        swap(arr[curr], arr[maxChild]);
        curr = maxChild;
    }
}

void removeMaxHeap(int arr[N], int &size){
    swap(arr[1], arr[size]);
    size--;
    int curr = 1;

    heapfy(arr, size, curr);
}

void heapSort(int arr[N], int &n){

    // 1. heapify all parent nodes into max heap.
    for(int i = n/2; i>0; i--){
        heapfy(arr, n, i);
    }
    // 2. keep deleting element untill size become 0.
    while(n!=0){
        removeMaxHeap(arr, n);
    }
}

int main() {
    int arr[N] = {-1,60,10,80,50,5,20,70};
    int n = 7;
    heapSort(arr, n);
    n = 7;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}