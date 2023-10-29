// https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

// variation 1 when arry is sorted from back index.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int len = intervals.size();
        res.push_back(intervals[len-1]);
        for(int i = len-2; i >=0; i--){
            // vector<int> ans;
            if(intervals[i][1] >= res[res.size()-1][0]){
                // overlapping case.
                res[res.size()-1][0] = min(intervals[i][0], res[res.size()-1][0]);
                res[res.size()-1][1] = max(intervals[i][1], res[res.size()-1][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};


// variation 2 when array is sorted from starting index.
bool cmp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}


class Solution1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int len = intervals.size();
        res.push_back(intervals[0]);
        for(int i = 1; i < len; i++){
            // vector<int> ans;
            if(intervals[i][0] <= res[res.size()-1][1]){
                // overlapping case.
                res[res.size()-1][0] = min(intervals[i][0], res[res.size()-1][0]);
                res[res.size()-1][1] = max(intervals[i][1], res[res.size()-1][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}