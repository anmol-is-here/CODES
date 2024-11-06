#include<iostream>
#include<vector>
using namespace std;

    int bs_sorted_rotated(vector <int> &v, int target) {
        int lo {0};
        int hi = v.size()-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if (v[mid] == target) {return mid;}
            if (v[mid] >= v[lo]) {
                if (target <= v[mid] and target >= v[lo]) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }
            }
            else {
                if (target >= mid and target <= v[hi]) {
                    lo = mid+1;
                }           
                else {
                    hi =mid-1;
                }
            }
        }
        return -1; 
    }

int main() {
    vector <int> v {4,5,6,7,0,1,2,3};
    int target {7};    
    cout<<bs_sorted_rotated(v, target);
    return 0;
}