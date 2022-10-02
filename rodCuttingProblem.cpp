class Solution{
  public:
  int helper(int *price, int n, int len, vector<vector<int>> &dp){
      if( n <=0 or len <= 0){
          return 0;
      }
      
      if(dp[n][len] != -1){
          return dp[n][len];
      }
        
        if(len-n >= 0){
            return dp[n][len] =  max(price[n-1] + helper(price,n,len-n,dp),helper(price,n-1,len,dp));
        }else{
            return dp[n][len] = helper(price,n-1,len,dp);
        }
  }
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(price,n,n,dp);
        
        
    }
};
