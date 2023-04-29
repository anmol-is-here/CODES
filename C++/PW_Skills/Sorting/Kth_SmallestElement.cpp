#include<iostream>
using namespace std;

int partition(int arr[], int l, int r){

    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j]<pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;

}

int Kth_Small(int arr[], int l, int r, int k){

    if (k>0 and k<=(r-l+1)) {
    
        int pos = partition(arr, l, r);

        if (pos-l == k-1){
            return arr[pos];
        }

        else if (pos-l > k-1){
            return Kth_Small(arr, l, pos-1, k);
        }

        else {
            return Kth_Small(arr, pos+1, r, k-(pos-l+1));
        }
    }
return INT16_MAX;
}

int main() {
    int arr[] {5,3,1,7,9,8,2,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k{5};

    cout<<Kth_Small(arr, 0, n-1, k)<<endl;
    return 0;
}