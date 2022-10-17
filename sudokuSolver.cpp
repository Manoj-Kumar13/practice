#include <bits/stdc++.h>
bool isSafe(int row,int col, int val, vector<vector<int>> &sudoku, int n){
    for(int i=0; i<n; i++){
        //row check
        if(sudoku[row][i] == val){
            return false;
        }
        // column check
        if(sudoku[i][col] == val){
            return false;
        }
        
        //3*3 matrix check
        if(sudoku[3*(row/3)+i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    
    return true;
}

bool solve(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    int n = sudoku[0].size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n ;j++){
            
            if(sudoku[i][j] == 0){
                for(int val=1; val<=9; val++){
                    if(isSafe(i,j,val,sudoku,n)){
                        sudoku[i][j] = val;
                        bool possible = solve(sudoku);
                        if(possible){
                            return true;
                        }else{
                        sudoku[i][j] = 0;
                        }
                    }
                }
            return false;
            }
        }
    }
    
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku){
    solve(sudoku);
    return;
}
