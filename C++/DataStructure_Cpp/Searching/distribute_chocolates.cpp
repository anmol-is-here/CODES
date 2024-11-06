#include <iostream>
#include <vector>
// #include <string>
using namespace std;

bool canDistChocolate(vector <int> &v, int mid, int s) {
    int n = v.size();
    int studntsReqd {1};
    int currSum {0};
    for (int i = 0; i < n; i++){
        if (v[i] > mid) {
            return false;
        }
        else if (currSum + v[i] > mid) {
            studntsReqd++;
            currSum = v[i];
            if (studntsReqd > s) {
                return false;
            }
        }
        else {
            currSum += v[i];
        }
    }
    return true;
}

int distChocolate(vector <int> &v, int s) {
    int n = v.size();
    int lo {v[0]};
    int hi {0};
    for (int i = 0; i < n; i++) {
        hi += v[i];
    }
    int ans {-1};
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if(canDistChocolate(v, mid, s)) {    // At most mid no. of chocolates can be distributed between 's' students or not.
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v {12,34,67,90};
    int s {2};
    cout<<distChocolate(v, s);
    return 0;
}