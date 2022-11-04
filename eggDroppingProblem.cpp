int dp[201][201];
class Solution
{
    public:
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int e, int n) 
    {
        // your code here
        if(n<=1){
            return n;
        }
        
        if(e == 1){
            return n;
        }
        
        if(dp[e][n] != -1){
            return dp[e][n];
        }
        
        int ans = INT_MAX;
        
        for(int i=1; i<=n; i++){
            int temp = 1 + max(eggDrop(e,n-i), eggDrop(e-1,i-1));
            
            ans = min(ans,temp);
        }
        
        return dp[e][n] = ans;
    }
};
