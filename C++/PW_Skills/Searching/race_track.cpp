#include <iostream>
#include <vector>
// #include <string>
using namespace std;

bool canPlaceStudents(vector <int> &v, int mid, int s) {
    int studentReqd {1};
    int lastPlaced {v[0]};
    for (int i = 1; i < v.size(); i++) {
        if (v[i] - lastPlaced >= mid) {
            studentReqd++;
            lastPlaced = v[i];
            if (studentReqd == s){
                return true;
            }
        }
    }
    return false;
}

int race (vector<int> &v, int s) {
    int n = v.size();
    int lo {1};
    int hi {v[n-1]-v[0]};
    int ans {-1};
    while (lo <= hi){
        int mid = lo + (hi-lo);
        if (canPlaceStudents(v, mid, s)) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans; 
}

int main() {
    vector <int> v {1,2,4,8,9};
    int s {3};
    cout<<race(v, s);    
    return 0;
}