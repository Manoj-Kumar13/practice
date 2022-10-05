	public:
	int ans = INT_MAX;
	int helper(int *coins, int n, int sum, int count,vector<vector<int>> &dp){
	    if(n <= 0 or sum <=0){
	        if(sum == 0){
	            ans = min(ans,count);
	            return ans;
	        }
	        return -1;
	    }
	    
	    if(dp[n][sum] != -1){
	        return dp[n][sum];
	    }
	    
	    return dp[n][sum] = min(helper(coins, n, sum-coins[n-1], count+1,dp),helper(coins,n-1,sum,count,dp));
	    
	}
	
	int minCoins(int coins[], int n, int sum) 
	{ 
	    // Your code goes here
	    int count  = 0;
	    vector<vector<int>> dp(n+1,vector<int>(sum+1));
	   // helper(coins,N,sum,count,dp);
	   // if(ans == INT_MAX){
	   //     return -1;
	   // }
	   // return ans;
	   
	   for(int i=0; i<=n; i++){
	       for(int j=0; j<=sum; j++){
	           if(i == 0){
	               dp[i][j] = INT_MAX-1;
	           }else if(j == 0){
	               dp[i][j] = 0;
	           }
	       }
	   }
	   dp[0][0] = 0;
	   
	   for(int i=1; i<=sum; i++){
	       if( i % coins[0] == 0){
	           dp[1][i] = i/coins[0];
	       }else{
	           dp[1][i] = INT_MAX-1;
	       }
	   }
	   
	    for(int i=1; i<=n; i++){
	       for(int j=1; j<=sum; j++){
	           if(coins[i-1] - j <= 0){
	               dp[i][j] = min(dp[i][j - coins[i-1]]+1,dp[i-1][j]);
	           }else{
	               dp[i][j] = dp[i-1][j];
	           }
	           
	       }
	    }
	    
	    return dp[n][sum] == INT_MAX-1 ? -1 : dp[n][sum];
	} 
	  
};
