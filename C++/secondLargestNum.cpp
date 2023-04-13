#include<iostream>
using namespace std;

int largestElementIndex(int arr[], int size) {
    int max = INT16_MIN;
    int  index = -1;
    for(int i=0; i<size; i++) {
        if(arr[i]>max) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

int secondLargestElement(int arr[], int size) {
    int max = INT16_MIN;
    int second_max = INT16_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }
    return second_max;
}

int main() {
    int arr[] = {1,5,8,6,8};
    int n = 5;
    // int largestEleIndex = largestElementIndex(arr,size);
    // cout<<arr[largestEleIndex]<<endl;
    // int x = arr[largestEleIndex];
    // //arr[largestEleIndex] = -1;
    // for(int i=0; i<size; i++) {
    //     if (arr[i] == x) {
    //         arr[i] = -1;
    //     }
    // }
    // int secondLargestEleIndex = largestElementIndex(arr,size);
    // cout<<arr[secondLargestEleIndex]<<endl;

    cout<<secondLargestElement(arr, n);
    return 0;
}
