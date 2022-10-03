class Solution {
public:
    // vector<vector<int>> dp(1001,vector<int>(1001,-1));
    int helper(string &a, string &b, int n, int m, vector<vector<int>> &dp){
        if(n == 0 or m == 0){
            return 0;
        }
        
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        if(a[n-1] == b[m-1]){
            return dp[n][m] = 1 + helper(a,b, n-1, m-1, dp);
        }else{
            return dp[n][m] = max(helper(a,b, n-1, m, dp), helper(a,b, n, m-1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();  
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(text1, text2, n , m,dp);
    }
};
