#include<iostream>
#include<vector>
using namespace std;

// Hello i have added this comment to check.

void bubbleSort(vector <int> &v){
    int n = v.size();
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (v[j]>v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
    return;
}

void bubbleSortOptimized(vector <int> &v){
    int n = v.size();
    for (int i=0; i<n-1; i++){
        bool flag = false;
        for (int j=0; j<n-i-1; j++){
            if (v[j]>v[j+1]){
                flag = true;
                swap(v[j], v[j+1]);
            }
        }
        if(!flag)  break;
    }
    return;
}

int main() {
    vector <int> v{50, 70, 20, 80, 40};
    // bubbleSort(v);
    bubbleSortOptimized(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

// void bubbleSort(int *arr, int &n){
//     for (int i = 0; i<n-1; i++){
//         for (int j=0; j<n-i-1; j++){
//             if (arr[j]>arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
//     return;
// }

// int main() {
//     int n = 5;
//     int arr[] = {50, 30, 10, 40, 20};
//     bubbleSort(arr ,n);
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

