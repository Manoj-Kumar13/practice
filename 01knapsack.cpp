class Solution
{
    public:
    
    int helper(int w, int wt[], int val[], int n, int dp[1001][1001]){
        if(n == 0 or w == 0){
           return 0;
       }
       
       if(dp[n][w] != -1){
           return dp[n][w];
       }
       
       if(wt[n-1] <= w){
           return dp[n][w] = max(val[n-1] + helper(w-wt[n-1], wt, val, n-1,dp),helper(w, wt, val, n-1,dp));
       }else{
           return dp[n][w] = helper(w, wt, val, n-1,dp);
       }
    }
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[1001][1001];
       memset(dp,-1,sizeof(dp));
       
       return helper(w,wt,val,n,dp);
       
    }
};
