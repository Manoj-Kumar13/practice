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


//another appraoch
class Solution {
public:
    int helper(int n, vector<int> &cost, vector<int> &dp){
        if(n == 2){
            return min(cost[n-1],cost[n-2]);
        }
        
        if(n < 2){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] =  min(cost[n-1] + helper(n-1,cost,dp),cost[n-2] + helper(n-2,cost,dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        
        vector<int> dp(n+1,-1);
        
        // return helper(n,cost,dp);
        
        vector<int> dp2(n+1);
        
        for(int i=0; i<2; i++){
            dp2[i] = 0;
        }
        dp2[2] = min(cost[1],cost[0]);
        
        for(int i=3; i<=n; i++){
            dp2[i] = min(cost[i-1] + dp2[i-1],cost[i-2] + dp2[i-2]);
        }
        return dp2[n];

    }
};

//space optimized
int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        if( n < 2){
            return 0;
        }

        int p1 = min(cost[1],cost[0]);
        int p2 = 0;
        
        for(int i=3; i<=n; i++){
            int temp = min(cost[i-1] + p1,cost[i-2] + p2);
            p2 = p1;
            p1 = temp;
        }
        return p1;

    }
