#include <iostream>
#include <vector>
using namespace std;

bool canWeGo(int i, int j, vector<vector <int> > &grid){
    int n = grid.size();
    return ((i<n and j<n and i>=0 and j>=0) and grid[i][j] == 1);
}

int f(int i, int j, vector<vector <int> > &grid){
    int n = grid.size();
    // base case
    if(i == n-1 and j == n-1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<grid[i][j]<<" ";
            }cout<<endl;
        }cout<<"****"<<endl;
        return 1;
    }

    int ans {0};
    grid[i][j] = 2;
    if(canWeGo(i, j+1, grid)){  // right side
        ans += f(i, j+1, grid);
    }
    
    if(canWeGo(i+1, j, grid)){  // down side
        ans += f(i+1, j, grid);
    }

    if(canWeGo(i, j-1, grid)){  // left side
        ans += f(i, j-1, grid);
    }

    if(canWeGo(i-1, j, grid)){  // up side
        ans += f(i-1, j, grid);
    }

    grid[i][j] = 1;

    return ans;

}

int main() {

    vector<vector <int> > grid {
        {1,1,1,1},
        {0,1,0,1},
        {0,1,1,1},
        {0,1,1,1}
    };
    int res = f(0 ,0 ,grid);
    cout<<res<<endl;
    
    return 0;
}