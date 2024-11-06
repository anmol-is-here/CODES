#include <iostream>
#include <vector>
// #include <string>
using namespace std;

int binary_search(vector <int> &v, int lo, int hi, int target) {
    while (lo<=hi) {
        int mid = lo + (hi-lo)/2;
        if(v[mid] == target) {
            return mid;
        }
        else if(v[mid] < target) {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return -1;
}

int first_min_SR(vector <int> &v) {
    int lo {0};
    int hi = v.size()-1;
    if (v.size() == 1){
        return 0;
    }
    if (v[lo]<v[hi]){
        return lo;
    }
    while (lo<hi){

        int mid = lo+(hi-lo)/2;
        if (v[mid] > v[mid+1])  {return mid+1;}
        if (v[mid-1] > v[mid]) {return mid;}

        if (v[mid] > v[lo]){
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return -1;
}

int target_in_SR(vector <int> &v, int target) {
    int lo {0};
    int hi = v.size()-1;
    int first_min = first_min_SR(v);
    if (target >= v[lo] and target <= v[first_min-1]) {
        hi = first_min - 1;
        return binary_search(v, lo, hi, target);
    }
    else {
        lo = first_min;
        return binary_search(v, lo, hi, target); 
    }
    return -1;
}


int main() {
    vector <int> v {7,8,9,10,2,3,4,5,6};
    int target = 10;
    cout<<target_in_SR(v, target);
    return 0;
}