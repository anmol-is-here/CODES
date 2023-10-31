//  https://leetcode.com/problems/triangle/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> grid;
    vector<vector<int>> dp;

    int f(int r, int c){
        if(r == grid.size()-1){
            return grid[r][c];
        }
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = grid[r][c] + min(f(r+1, c), f(r+1, c+1));
    }

    void fbu(){
        int r = grid.size();
        for(int i = 0; i < grid[r-1].size(); i++){
            dp[r-1][i] = grid[r-1][i];
        }

        for(int i = r - 2; i >= 0; i--){
            for(int c = 0; c < grid[i].size(); c++){
                dp[i][c] = grid[i][c] + min(dp[i+1][c], dp[i+1][c+1]);
            }
        }
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        grid = triangle;
        dp.clear();
        dp.resize(205, vector<int>(205, -1));
        fbu();
        return dp[0][0];
    }
};

int main() {
    
    return 0;
}