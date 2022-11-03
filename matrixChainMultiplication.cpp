class Solution{
public:
    int solve(int *arr, int i,int j,vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        
        int ans = INT_MAX;
        if(dp[i][j] != -1){
                return dp[i][j];
            }
        for(int k=i; k<=j-1; k++){
            int temp1 = solve(arr,i,k,dp);
            int temp2 = solve(arr,k+1,j,dp);
            
            int temp3 = arr[i-1]*arr[k]*arr[j];
            
            int tempAns = temp1+temp2+temp3;
            ans = min(ans,tempAns);
        }
        
        return dp[i][j] = ans;
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(arr, 1, n-1,dp);
    }
};
