// https://leetcode.com/problems/non-overlapping-intervals/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int len = intervals.size();
        int lastEndTime = intervals[0][1];
        int ans = 0;
        for(int i = 1; i < len; i++){
            // vector<int> ans;
            if(intervals[i][0] < lastEndTime){
                // overlapping case.
                lastEndTime = min(intervals[i][1], lastEndTime);
                ans++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int len = intervals.size();
        int lastEndTime = intervals[0][1];
        int ans = 0;
        for(int i = 1; i < len; i++){
            if(intervals[i][0] < lastEndTime){
                // overlapping case.
                ans++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}