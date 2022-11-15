class Solution{
    public:
    int helper(string &a, string &b, int n, int m, vector<vector<int>> &dp){
        
        int len = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    len = max(len,dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return len;
        
    }
    
    int longestCommonSubstr (string a, string b, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(a,b,n,m,dp);
    }
};
