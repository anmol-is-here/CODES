#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<vector <char> > &board, int row, int column, char num) {
    for(int j = 0; j < 9; j++){
        if(board[row][j] == num){
            return false;
        }
    }
    for(int i = 0; i < 9; i++){
        if(board[i][column] == num){
            return false;
        }
    }
    int r = (row/3)*3;
    int s = (column/3)*3;
    for(int i = r; i < (r+3); i++){
        for(int j = s; j < (s+3); j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }
    return true;
}

bool sudoku(vector<vector <char> > &board, int row, int column) {
    // base case.
    if(column == 9) return sudoku(board, row+1, 0);
    if(row == 9) return true;

    if(board[row][column] == '.'){
        for(int num = 1; num <= 9; num++){
            if(canWePlace(board, row, column, '0'+num)){
                board[row][column] = '0'+num;
                bool res = sudoku(board, row, column+1);
                if(res) return true;    // we have to return true if we have solved the remaining sudoku. else
                board[row][column] = '.';     // restore to previous state.
            }
        }
        return false;
    } else {
        return sudoku(board, row, column+1);
    }
}

int main() {

    vector<vector<char>> board {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    sudoku(board, 0, 0);

    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}