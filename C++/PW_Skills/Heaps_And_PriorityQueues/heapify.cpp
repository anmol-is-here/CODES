#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3;

// minHeap Heapify.
void minheapify(int arr[N], int &size, int curr){

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

// maxHeap Heapify.
void maxheapify(int arr[N], int &size, int curr){

    while(2*curr <= size){
        int leftChild = 2*curr;
        int rigthChild = 2*curr + 1;
        int minChild = leftChild;
        if(rigthChild <= size and arr[rigthChild] > arr[leftChild]){
            minChild = rigthChild;
        }
        if(arr[curr] >= arr[minChild]){
            return;
        }
        swap(arr[curr], arr[minChild]);
        curr = minChild;
    }
}

int main() {

    int arr[N] = {-1,60,10,80,50,5,20,70};
    int size = 7;
    for (int i = size/2; i>0; i--){
        maxheapify(arr, size, i);
    }
    for(int i = 0; i <= size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}