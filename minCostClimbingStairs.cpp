//memoized solution
class Solution {
public:
    int solve(vector<int>& cost,int n, vector<int>& dp){
        if(n == 0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = cost[n] + min(solve(cost,n-1,dp) , solve(cost,n-2,dp));
        
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        
        vector<int> dp(n+1,-1);
        
        return min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    }
};

//Tabulation Solution
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        
        vector<int> dp(n+1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2; i<n; i++){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        
        return min(dp[n-1],dp[n-2]);
    }
};

//space optimized solution
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        
        vector<int> dp(n+1);
        
        int p2 = cost[0];
        int p1 = cost[1];
        
        for(int i=2; i<n; i++){
            int cur = min(p1,p2) + cost[i];
            p2 = p1;
            p1 = cur;
        }
        
        return min(p1,p2);
    }
};
