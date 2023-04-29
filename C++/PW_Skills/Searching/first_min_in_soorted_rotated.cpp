#include<iostream>
#include<vector>
using namespace std;

int firstSortedRotated(vector <int> &v) {
    int lo {0};
    int hi = v.size()-1;
    if (v.size() == 1) {
        return 0;
    }
    if (v[lo] < v[hi]) {
        return lo;
    }

    while (lo <= hi){
        int mid = lo + (hi-lo)/2;

        if(v[mid] > v[mid+1]) {return mid+1;}
        if(v[mid] < v[mid-1]) {return mid;}

        if (v[mid] > v[lo]) {
            lo = mid + 1;
        }
        else {
            hi = mid-1;
        }
    }
    return -1;
}
int main() {
    vector <int> v {2,3,4,5,6,7,8,1};
    cout<<firstSortedRotated(v); 
    return 0;
}