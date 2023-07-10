/**
 * Consider an N*N chessboard. NQueen Problem is to accommodate N queens on the N*N chessboard such that no 2 Queens can attack each other.
*/

#include <iostream>
#include <vector>
using namespace std;

bool canPlaceQueen(int row, int col, vector<vector <char> > &grid){
    // if someone attacking from vertical up.
    for(int i = row - 1; i>=0; i--){
        if(grid[i][col] == 'Q'){
            return false;
        }
    }

    for(int i = row - 1, j = col - 1; i>=0 and j>=0; i--, j--){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }

    for(int i = row - 1, j = col + 1; i>=0 and j<grid.size(); i--, j++){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }
    
    return true;
}

void nQueen(int currRow, int n, vector<vector <char> > &grid){
    // base case
    if(currRow == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<grid[i][j]<<" ";
            }cout<<endl;
        }cout<<"****"<<endl;
    }

    for(int col = 0; col < n; col++){
        // we will go to all cols.
        // lets check if we can place queen at curr row ans cols.
        if(canPlaceQueen(currRow, col, grid)) {
            grid[currRow][col] = 'Q';
            nQueen(currRow+1, n, grid);
            grid[currRow][col] = '.';
        }
    }
    return;
}

int main() {
    int n {4};
    vector<vector <char> > grid(n, vector<char> (n, '.'));
    nQueen(0, n, grid);
    
    return 0;
}