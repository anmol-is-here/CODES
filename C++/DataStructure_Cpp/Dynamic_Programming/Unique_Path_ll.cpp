// https://leetcode.com/problems/unique-paths-ii/description/

#include <iostream>
#include <vector>
// #include <string>
using namespace std;

class Solution {
    vector<vector<int>> grid;
    vector<vector<long long int>> dp;
    int n, m;

    int f(int i, int j){
        if(i >= n or j >= m or i < 0 or j < 0) return 0;
        if(grid[i][j] == 1) return 0;
        if(i == n-1 and j == m-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i+1, j) + f(i, j+1);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        n = grid.size();
        m = grid[0].size();
        dp.clear();
        dp.resize(105, vector<long long int>(105, -1));
        if(grid[n-1][m-1] == 1) return 0;

        dp[n-1][m-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(grid[i][m-1] == 1) dp[i][m-1] = 0;
            else dp[i][m-1] = dp[i+1][m-1];
        }
        for(int i = m-2; i >= 0; i--){
            if(grid[n-1][i] == 1) dp[n-1][i] = 0;
            else dp[n-1][i] = dp[n-1][i+1];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                if(grid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];

        // return f(0, 0);
    }
};

int main() {
    
    return 0;
}