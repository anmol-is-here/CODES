// https://leetcode.com/problems/climbing-stairs

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> dp;
    int f(int i, int n){
        if(i > n) return 0;
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        return dp[i] = (f(i+1, n) + f(i+2, n));
    }
public:
    int climbStairs(int n) {
        dp.clear();
        dp.resize(46, -1);
        return f(0, n);
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}