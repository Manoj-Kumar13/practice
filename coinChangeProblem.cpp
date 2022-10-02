#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int helper(int *coins, int n, int sum, vector<vector<long long int>> &dp){
        if(n <= 0 or sum <=0){
            if(sum == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[n][sum] != -1 ){
            return dp[n][sum];
        }
        
        return dp[n][sum] = helper(coins, n, sum-coins[n-1],dp) + helper(coins,n-1,sum,dp);
        
    }
    
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,-1));
        return helper(coins, N, sum,dp);
    }
};
