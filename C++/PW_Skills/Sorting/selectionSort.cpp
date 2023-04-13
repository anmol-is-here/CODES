#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector <int> &v){
    int n=v.size();
    for (int i=0; i<n-1; i++){
        int min_idx = i;
        for (int j=i+1; j<n; j++){
            if(v[min_idx]>v[j]){
                min_idx = j;
            }
        }
        if(min_idx != i){
                swap(v[i], v[min_idx]);
            }
    }
    return;
}

int main() {
    vector <int> v{5, 6, 8, 2, 1};
    selectionSort(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}