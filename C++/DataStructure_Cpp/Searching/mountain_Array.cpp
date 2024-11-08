#include <iostream>
#include <vector>
// #include <string>
using namespace std;


// Input array must contain at least 3 elements.
int mountain_index(vector <int> &v) {
    int lo {0};
    int hi = v.size()-1;
    int ans {-1};
    while(lo<=hi) {
        int mid = lo + (hi-lo)/2;
        if (v[mid] > v[mid-1]){
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector <int> v {2,1,0};
    cout<<mountain_index(v);
    return 0;
}