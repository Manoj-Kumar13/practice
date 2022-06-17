class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> grid(n,vector<int>(m,-1));
        int ans = helper(grid,n,m,0,0);
        return ans;
    }
    
    int helper(vector<vector<int>>& grid,int n,int m, int i, int j){
        if(i == n-1 && j== m-1){
            return 1;
        }
        
        if(i>=n || j>=m){
            return 0;
        }
        
        if(grid[i][j] != -1){
            return grid[i][j];
        }
        
        grid[i][j] = helper(grid,n,m,i+1,j) + helper(grid,n,m,i,j+1);
        
        return grid[i][j];
        
        
    }
};
