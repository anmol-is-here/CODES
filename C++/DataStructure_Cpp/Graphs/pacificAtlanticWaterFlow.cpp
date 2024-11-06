// https://leetcode.com/problems/pacific-atlantic-water-flow/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    int rows;
    int cols;
    vector<vector<int> > h;

    vector<vector<int> > dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // i, j -> i+1, j -> i-1, j -> i, j-1 -> i, j+1

    vector<vector<bool> > bfs(queue<pair<int, int> > &q){
        vector<vector<bool> > visited(rows, vector<bool> (cols, false));

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            visited[i][j] = true;

            for(int d = 0; d < 4; d++){
                int newRow = i+dir[d][0];
                int newCol = j+dir[d][1];
                if(newRow < 0 or newRow >= rows or newCol < 0 or newCol >= cols) continue;
                if(visited[newRow][newCol]) continue;
                if(h[newRow][newCol] < h[i][j]) continue;
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
        return visited;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
        rows = height.size();
        cols = height[0].size();
        h = height;

        queue<pair<int, int> > pacific_q;
        queue<pair<int, int> > atlantic_q;

        for(int i = 0; i < rows; i++){
            pacific_q.push({i, 0});
            atlantic_q.push({i, cols-1});
        }

        for(int i = 1; i < cols; i++){
            pacific_q.push({0, i});
        }

        for(int i = 0; i < cols-1; i++){
            atlantic_q.push({rows-1, i});
        }

        vector<vector<bool> > pacific = bfs(pacific_q);
        vector<vector<bool> > atlantic = bfs(atlantic_q);

        vector<vector<int> > res;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacific[i][j] and atlantic[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}