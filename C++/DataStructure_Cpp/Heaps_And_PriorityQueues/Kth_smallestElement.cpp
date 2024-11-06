/**
 * Question -> Given an array and an integer K where K issmaller than size of array, the task is to find the Kth smallest 
 *             element in the given array. It is given that all array element are distinct.
*/


#include <iostream>
using namespace std;
const int N = 1e3;

void heapify(int arr[N], int size, int curr){

    while(2*curr+1 <= size){
        int leftChild = 2*curr + 1;
        int rightChild = 2*curr + 2;
        int minChild = leftChild;
        if(rightChild <= size and arr[rightChild] < arr[leftChild]){
            minChild = rightChild;
        }

        if(arr[minChild] >= arr[curr]){
            return;
        }
        swap(arr[minChild], arr[curr]);
        curr = minChild;
    }
    return;
}

void remove(int arr[N], int &size){
    
    arr[0] = arr[size-1];
    size--;
    heapify(arr, size, 0);

}

int KthSmallestElement(int arr[N], int size, int k){

    // 1.create min heap.
    for(int i = size/2-1; i>=0; i--){
        heapify(arr, size, i);
    }

    // 2. remove k-1 element.
    k -= 1;
    while(k--){
        remove(arr, size);
    }

    return arr[0];

}

int main() {

    int arr[N] = {60,10,80,50,5,20,70};
    int size {7};

    cout<<KthSmallestElement(arr, size, 6);
    
    return 0;
}