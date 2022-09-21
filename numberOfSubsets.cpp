//fails on 12 testcase on coding ninjas
#include <bits/stdc++.h> 
int findWays(vector<int> &a, int t)
{
        // Write your code here..
        int n = a.size();
        int dp[n+1][t+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=t; j++){
                if(j==0){
                    dp[i][j] = 1;
                }else if(i == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=t; j++){
                if(a[i-1] <= j){
                    dp[i][j] = dp[i-1][j - a[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][t];
    }

//passes all testcases
int numberOfWays(int i, int sum, int n, vector<int> &num, vector<vector<int>> &dp)
{

    if (sum < 0)
    {
        return 0;
    }

    if (i == n)
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }

    if(num[i] <= sum){
         return dp[i][sum] =  numberOfWays(i + 1, sum - num[i], n, num, dp) + numberOfWays(i + 1, sum, n, num, dp);
    }else{
      return dp[i][sum] = numberOfWays(i + 1, sum, n, num, dp);
    }
}

int findWays(vector<int> &num, int tar)
{

    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return numberOfWays(0, tar, n, num, dp);
}
