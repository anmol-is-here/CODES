#include <iostream>
#include <vector>
// #include <string>
using namespace std;

int peak_Ele(vector <int> &v) {
    int lo {0};
    int n = v.size();
    int hi = n-1;
    while(lo<=hi){
        int mid = lo +(hi-lo)/2;
        if (mid == 0){
            if(v[mid] > v[mid+1]){
                return 0;
            }
            else {
                return 1;
            }
        }
        else if (mid == n-1){
            if(v[mid]<v[mid-1]) {
                return n-2;
            }
            else {
                return n-1;
            }
        }
        else {
            if (v[mid] > v[mid-1] and v[mid] > v[mid+1]){
                return mid;
            }
            else if (v[mid]>v[mid-1]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector <int> v {2,1};
    cout<<peak_Ele(v);
    return 0;
}