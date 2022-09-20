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

//bottom-up approach
 int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][w+1];
       
       for(int i=0; i<=n; i++){
           for(int j=0; j<=w; j++){
               if(i == 0 or j == 0){
                   dp[i][j] = 0;
               }
           }
       }
       
       for(int i=1; i<=n; i++){
           for(int j=1; j<=w; j++){
               
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else if(wt[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
           }
       }
       
       return dp[n][w];
       
    }
