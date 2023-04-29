#include<iostream>
#include<vector>
using namespace std;

int last_occurance(vector <int> &v, int target) {
    int lo {0};
    int hi = v.size()-1;
    int ans {-1};
    while (lo <= hi){
        int mid = lo +(hi-lo)/2;
        if (v[mid] <= target){
            ans = mid;
            lo = mid+1;
        }
        else if (v[mid] > target){
            hi = mid-1;
        }
        // else {
        //     lo = mid+1;
        // }
    }
    return ans;
}

int first_occurance(vector <int> &v, int target) {
    int lo {0};
    int ans{-1};
    int hi = v.size()-1;
    while (lo<=hi){
        int mid = lo + (hi-lo)/2;
        if (v[mid] >= target) {
            ans = mid;
            hi = mid-1;
        }
        // else if (v[mid] > target) {
        //     hi = mid-1;
        // }
        else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector <int> v {2,2,3,3,3,11,11};
    int target {10};
    
    int first = first_occurance(v, target);
    int last = last_occurance(v, target);

    if (v[first] != target) {
        cout<<"["<< -1<<", "<< -1<<"]"; 
    }
    else {
        cout<<"["<<first<<", "<<last<<"]"; 
    }
    return 0;
}