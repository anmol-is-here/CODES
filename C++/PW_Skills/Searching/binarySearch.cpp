#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector <int> &input, int target) {
    /** Time : O(log n),
     *  Space : O(1).
    */

    int lo {0};
    int hi = (input.size()-1);
    while (lo <= hi) {
        // int mid = (lo+hi)/2;
        int mid = lo + (hi-lo)/2;

        if (input[mid] == target) {
            return mid+1;
        }

        else if (input[mid] > target) {
            hi = mid-1;
        }

        else {
            lo = mid+1;
        }

    }
    return -1;
}

int binarySearchRecursive(vector <int> &input, int target, int lo, int hi) {
    /** Time : O(log n),
     *  Space : O(log n).
    */
    if (lo > hi) {
        return -2;
    }
    // int mid = (lo + hi)/2;
    int mid = lo + (hi-lo)/2;

    if (input[mid] == target) {
        return mid;
    } 
    if (input[mid] < target) {
        return binarySearchRecursive(input, target, mid+1, hi);
    }
    return binarySearchRecursive(input, target, lo, mid-1);
}

int main() {

    vector <int> num {2,3,7,9,15,17,18,20};
    int target = 18;
    // cout<<target<<" is at "<<binarySearch(num, target)<<"th position.";
    cout<<target<<" is at "<<binarySearchRecursive(num, target, 0, num.size()-1)+1<<"th position.";

    return 0;
}