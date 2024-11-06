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

int remove_duplicate(vector <int> &v) {
    int lo {0};
    int hi = v.size()-1;
    while(lo<hi){
        if(v[lo] == v[hi]){
            lo++;
            hi--;
        }
        else {
            return lo;
        }
    }
    return lo;
}

int target_in_SR(vector <int> &v, int target) {
    int lo {0};
    int hi = v.size()-1;
    if(target == v[0]) {return 1;}
    remove_duplicate(v);
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
    vector <int> v {1,1,2,2,0,0,0,0,1};
    int x = remove_duplicate(v);
    cout<<x;
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i];
    // }
    // int target = 2;
    // int result = target_in_SR(v, target);
    // if (result == -1) {
    //     cout<<result;
    // }
    // else {
    //     cout<<1;
    // }
    return 0;
}



/**
 *  I have to return a vector in above question in which the is no same element at starting and end of array.
*/