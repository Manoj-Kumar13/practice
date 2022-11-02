#include <bits/stdc++.h>

using namespace std;

void helper(vector<int> &a, vector<int> &b, int n, int m, vector<vector<int>> &dp){
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i == 0 || j == 0){
               dp[i][j] = 0; 
            }else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    helper(a,b,n,m,dp);
    vector<int> ans;
    
    int i = n, j=m;
    while(i>0 and j>0){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
