class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            if(s[cnt] == t[i]){
                cnt++;
            }
        }
        
        if(cnt == m){
            return true;
        }
        return false;
    }
};

//DP Solution

class Solution {
    int isSubSequence(string& s1, string& s2, int i, int j , vector<vector<int>> &dp)
{
    if (i == 0 || j == 0) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (s1[i - 1] == s2[j - 1]) {
        return dp[i][j]
               = 1 + isSubSequence(s1, s2, i - 1, j - 1,dp);
    }
    else {
        return dp[i][j] = isSubSequence(s1, s2, i, j - 1,dp);
    }
}
    
// bottom-up DP
     bool isSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }else if(a[i-1] == b[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int len = dp[n][m];
        
        return (len == n) ? true: false;
        
    }
 
public:
    bool isSubsequence(string s, string t) {
         int m = s.size();
    int n = t.size();
    if (m > n) {
        return false;
    }
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
    if (isSubSequence(s, t, m, n,dp) == m) {
        return true;
    }
    else {
        return false;
    }
    }
};
