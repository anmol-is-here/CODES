// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int len = points.size();
        int lastEndTime = points[0][1];
        int ans = 0;
        for(int i = 1; i < len; i++){
            if(points[i][0] <= lastEndTime){
                // overlapping case.
                lastEndTime = min(points[i][1], lastEndTime);
                ans++;
            }
            else{
                lastEndTime = points[i][1];
            }
        }
        return points.size() - ans;
    }
};

int main() {
    
    return 0;
}