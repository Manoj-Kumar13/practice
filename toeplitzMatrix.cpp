class Solution {
public:
    bool checkToeplitz(vector<vector<int>>& mat, int n, int m){
        //for upper diagonal
        for(int i=1;i<n;i++){
            for(int j=1; j<m;j++){
                if(mat[i][j]!=mat[i-1][j-1]){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        if(checkToeplitz(mat,n,m)){
            return true;
        }
        return false;
    }
};
