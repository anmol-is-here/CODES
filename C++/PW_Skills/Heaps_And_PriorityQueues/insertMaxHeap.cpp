#include <iostream>
#include <vector>
using namespace std;

int const N = 1e3;

void insertMaxHeap(int maxHeap[N], int &size, int value){
    size++;
    maxHeap[size] = value;
    int curr = size;

    while(curr/2 > 0 and maxHeap[curr/2] < maxHeap[curr]){
        swap(maxHeap[curr/2], maxHeap[curr]);
        curr = curr/2;
    }

}

void removeMaxHeap(int maxheap[N], int &size){
    swap(maxheap[1], maxheap[size]);
    size--;
    int curr = 1;

    while(2*curr <= size){
        int leftChild = 2*curr;
        int rigthChild = 2*curr + 1;
        int maxChild = leftChild;
        if(rigthChild <= size and maxheap[rigthChild] > maxheap[leftChild]){
            maxChild = rigthChild;
        }
        if(maxheap[curr] >= maxheap[maxChild]){
            return;
        }
        swap(maxheap[curr], maxheap[maxChild]);
        curr = maxChild;
    }
}

int main() {
    int maxHeap[N] = {-1,50,40,30,20,10};
    int size = 5;
    int value = 55;
    insertMaxHeap(maxHeap, size, value);
    for(int i = 0; i<size+1; i++){
        cout<<maxHeap[i]<<" ";
    }cout<<endl;
    removeMaxHeap(maxHeap, size);
    for(int i = 0; i<size+1; i++){
        cout<<maxHeap[i]<<" ";
    }
    
    return 0;
}