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
