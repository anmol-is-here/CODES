#include <iostream>
#include <vector>
using namespace std;

int const N = 1e3;

void insertMinHeap(int minHeap[N], int &size, int value){
    size++;
    minHeap[size] = value;
    int curr = size;

    while(curr/2 > 0 and minHeap[curr/2] > minHeap[curr]){
        swap(minHeap[curr/2], minHeap[curr]);
        curr = curr/2;
    }

}

void removeMinnHeap(int minheap[N], int &size){
    swap(minheap[1], minheap[size]);
    size--;
    int curr = 1;

    while(2*curr <= size){
        int leftChild = 2*curr;
        int rigthChild = 2*curr + 1;
        int minChild = leftChild;
        if(rigthChild <= size and minheap[rigthChild] < minheap[leftChild]){
            minChild = rigthChild;
        }
        if(minheap[curr] <= minheap[minChild]){
            return;
        }
        swap(minheap[curr], minheap[minChild]);
        curr = minChild;
    }
}

int main() {
    int minHeap[N] = {-1,10,20,30,40,50};
    int size = 5;
    int value = 5;
    insertMinHeap(minHeap, size, value);
    for(int i = 0; i<=size; i++){
        cout<<minHeap[i]<<" ";
    }cout<<endl;
    removeMinnHeap(minHeap, size);
    for(int i = 0; i<=size; i++){
        cout<<minHeap[i]<<" ";
    }
    
    return 0;
}