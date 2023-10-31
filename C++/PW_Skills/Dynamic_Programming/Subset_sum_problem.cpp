/**
 * Given a set of non-negative integers and a value sum, the task is to check if there is a subset of the given set whose sum is equal to the given sum. 
 * Examples: 
 * Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
 * Output: True
 * Explanation: There is a subset (4, 5) with sum 9.
 * 
 * Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
 * Output: False
 * 
 * Explanation: There is no subset that add up to 30.
*/

// similar problem also at leetcode.

// https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    bool f(vector<int> &arr, int i, int k){
        if(k == 0) return true;
        if(i >= arr.size() and k != 0) return false;

        if(dp[i][k] != -1) return dp[i][k];
        if(arr[i] <= k){
            // we can pick or not pick element.
            return dp[i][k] = f(arr, i+1, k - arr[i]) or f(arr, i+1, k);
        } else {
            // we cannot pick element.
            return dp[i][k] = f(arr, i+1, k);
        }
    }

public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) s += nums[i];
        if((s % 2) != 0) return false;
        dp.clear();
        // dp.resize(200, vector<int>(20005, -1));
        dp.resize(205, vector<int>(20005, false));
        int k = s/2;

        for(int i = 0; i < n; i++) dp[i][0] = true;
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= k; j++){
                if(nums[i] <= j){
                    dp[i][j] = dp[i+1][j-nums[i]] or dp[i+1][j];
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][k];


        // return f(nums, 0, s/2);
    }
};

int main() {
    
    return 0;
}