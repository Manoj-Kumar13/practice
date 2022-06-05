class Solution {
public:
    int maxSol = 0;
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n,string(n,'.'));
        
        helper(res,nQueens,0,n);
        return maxSol;
    }
    
     void helper(vector<vector<string> > &res, vector<string> &nQueens, int row, int &n) {
        if (row == n) {
            maxSol++;
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
