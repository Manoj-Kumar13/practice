class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n+1, vector<long>(5, 0));
    
    int MOD = 1e9 + 7;
    
    for(int i = 0; i < 5; i++)
        dp[1][i] = 1;
    
    for(int i = 1; i < n; i++)
    {
        dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) %MOD;
        dp[i+1][1] = (dp[i][0] + dp[i][2]) % MOD;
        dp[i+1][2] = (dp[i][1] + dp[i][3]) % MOD;
        dp[i+1][3] = dp[i][2];
        dp[i+1][4] = (dp[i][2] + dp[i][3]) % MOD;
    }
    
    int res = 0;
    for(int i = 0; i < 5; i++)
        res = (res + dp[n][i]) % MOD;
    
    return res;
    }
};

/*
Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
*/
