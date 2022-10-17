class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n,string(n,'.'));
        
        helper(res,nQueens,0,n);
        return res;
    }
    
    void helper(vector<vector<string> > &res, vector<string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isSafe(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                helper(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    
    bool isSafe(vector<string> &nQueens, int row, int col, int &n) {
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};

//another approach
#include <bits/stdc++.h> 
void addAns(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
    
    vector<int> temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row,int col, vector<vector<int>> &board, int n){
    int x = row;
    int y = col;
    //same row
    while(y>=0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }
    
    x = row;
    y = col;
    //check diagonal
    while(x>=0 and y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    
    x = row;
    y = col;
    //check diagonal
    while(x<n and y>=0 ){
        if(board[x][y] == 1){
            return false;
        }    
        y--;
        x++;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    if(col == n){
        addAns(board, ans,n);
        return;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board,n)){
            board[row][col] = 1;
            solve(col+1,ans,board,n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
	// Write your code here
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    
    solve(0, ans, board, n);
    
    return ans;
	
}
