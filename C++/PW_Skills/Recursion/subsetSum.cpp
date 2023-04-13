#include<iostream>
#include<vector>
using namespace std;

void subsetSum(int *arr, int n, int i, int sum, vector<int> &result){
    if (i == n){
        result.push_back(sum);
        return;
    }
    subsetSum(arr, n, i+1, sum, result);
    subsetSum(arr, n, i+1, sum+arr[i], result);
}

int main() {
    int arr[] = {2, 4};
    int n = 2;
    vector <int> result;
    subsetSum(arr, n, 0, 0, result);
    for (int i = 0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }
    return 0;
}