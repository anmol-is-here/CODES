#include <iostream>
#include <vector>
using namespace std;

void heapify(int arr[7], int size, int curr){

    while(2*curr <= size){
        int leftChild = 2*curr;
        int rigthChild = 2*curr + 1;
        int minChild = leftChild;
        if(rigthChild <= size and arr[rigthChild] < arr[leftChild]){
            minChild = rigthChild;
        }
        if(arr[curr] <= arr[minChild]){
            return;
        }
        swap(arr[curr], arr[minChild]);
        curr = minChild;
    }
}

int remove(int arr[7], int &size){
    int ele = arr[0];
    arr[0] = arr[size-1];
    size--;
    heapify(arr, size, 0);
    return ele;
}

int sumOfSmallest(int arr[7], int size, int k1, int k2){
    
    // 1.min heap.
    for(int i = size/2; i >= 0; i--){
        heapify(arr, size, i);
    }

    int sum {0};
    int element = k2-k1-1;
    // 2.remove k1 elements.
    while(k1--){
        remove(arr, size);
    }

    // calculate sum by removing elements.
    while(element--){
        sum += remove(arr, size);
    }
    return sum;
}

int main() {

    int arr[7] = {20,8,22,4,12,10,14}; //{4,8,10,12,14,20,22}
    int size {7};
    int k1 {3};
    int k2 {5};

    cout<<sumOfSmallest(arr, size, k1, k2);
    
    return 0;
}