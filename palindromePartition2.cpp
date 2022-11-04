//first approach(top down dp)
class Solution{
public:
bool isPalindrome(string &a, int i, int j){
        while(i<j){
            if(a[i] != a[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    int solve(string &a, int i, int j,vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(isPalindrome(a,i,j)){
            return 0;
        }
        
        int ans = INT_MAX;
        for(int k=i; k<=j-1; k++){
            int temp1 = solve(a,i,k,dp);
            int temp2 = solve(a,k+1,j,dp);
            
            int tempAns = temp1 + temp2 + 1;
            
            ans = min(ans,tempAns);
        }
        
        return dp[i][j] = ans;
    }
    int palindromicPartition(string s)
    {
        // code here
         int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1,dp);
    }
};

//second approach(space optimized)
bool isPalindrome(string &a, int i, int j){
        while(i<j){
            if(a[i] != a[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    int solve(string &a, int i, int j,vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(isPalindrome(a,i,j)){
            return 0;
        }
        
        int ans = INT_MAX;
        for(int k=i; k<=j-1; k++){
            
            int temp1;
            if(dp[i][k] != -1){
                temp1 = dp[i][k];
            }else{
                temp1 = solve(a,i,k,dp);
                dp[i][k] = temp1;
            }
            int temp2;
            if(dp[k+1][j] != -1){
                temp2 = dp[k+1][j];
            }else{
                temp2 = solve(a,k+1,j,dp);
                dp[k+1][j] = temp2;
            }
            
            int tempAns = temp1 + temp2 + 1;
            
            ans = min(ans,tempAns);
        }
        
        return dp[i][j] = ans;
    }
int Solution::minCut(string s) {
    int n = s.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(s,0,n-1,dp);
}

//Third approach(most optimized: using 1-D DP)
class Solution {
public:
    bool isPalindrome(string &a, int i, int j){
        while(i<j){
            if(a[i] != a[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    int solve(string &a, int i, int j,vector<int> &dp){
        if(i>=j){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        if(isPalindrome(a,i,j)){
            return 0;
        }
        
        int ans = INT_MAX;
        for(int k=i; k<=j-1; k++){
            if(isPalindrome(a,i,k)){
                int temp = solve(a,k+1,j,dp) + 1;
                ans = min(ans,temp);
            }
        }
        
        return dp[i] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return solve(s,0,n-1,dp);
    }
};
