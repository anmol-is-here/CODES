#include<iostream>
using namespace std;

int sqrt_bs(int num) {
    int lo {1};
    int hi {num};
    int ans {-1};
    while (lo < hi){
        int mid = lo + (hi-lo)/2;
        if (mid*mid <= num){
            ans = mid;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return ans;
}

int main() {
    int num {49};

    cout<<sqrt_bs(num);

    return 0;
}