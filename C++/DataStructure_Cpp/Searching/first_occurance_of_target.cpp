#include<iostream>
#include<vector>
using namespace std;

int first_occurance(vector <int> &input, int target) {
    int lo {0};
    int hi = input.size()-1;
    int ans {-1};
    while (lo <= hi){
        int mid = lo + (hi - lo)/2;

        if (input[mid] >= target){ 
            ans = mid;
            hi = mid - 1;
        }

        // else if (input[mid] > target) {
        //     hi = mid - 1;
        // }

        else {
            lo = mid + 1;
        }

    }
    return ans;
}

int main() {

    vector <int> arr {2,5,5,5,6,6,9,9,9,9,9,9};
    int target {9};

    cout<<first_occurance(arr, target);
    
    return 0;
}