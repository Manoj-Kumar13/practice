class Solution {
public:
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
         return dp[i][sum] =  (numberOfWays(i + 1, sum - num[i], n, num, dp) + numberOfWays(i + 1, sum, n, num, dp));
    }else{
      return dp[i][sum] = numberOfWays(i + 1, sum, n, num, dp);
    }
}
    
    int findTargetSumWays(vector<int>& a, int d) {
        int sum = 0;
        int n = a.size();
        
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        if (sum < d || (sum - d) % 2) {
            return 0;
        }
    
        int t = (sum - d)/2;
    
        vector<vector<int>> dp(n, vector<int>(t + 1, -1));
        return numberOfWays(0, t, n, a, dp);
    }
};
