bool isPossible(vector<int>arr, int sum, int n){
        if(n == 0){
            if(sum == 0){
                return true;
            }
            return false;
        }
        
        if(arr[n-1] <= sum){
            return isPossible(arr,sum-arr[n-1], n-1) or isPossible(arr,sum, n-1);
        }else{
            return isPossible(arr,sum, n-1);
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        bool dp[n+1][sum+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j==0){
                    dp[i][j] = true;
                }else if( i == 0){
                    dp[i][j] = false;
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
        // return isPossible(arr,sum, n);
    }

//memoized solution
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
  public:
  bool isPossible(int *arr, int sum, int n, vector<vector<int>> &dp){
        if(n == 0){
            if(sum == 0){
                return true;
            }
            return false;
        }
        
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        if(arr[n-1] <= sum){
            return dp[n][sum] = isPossible(arr,sum-arr[n-1], n-1,dp) or isPossible(arr,sum, n-1,dp);
        }else{
            return dp[n][sum] = isPossible(arr,sum, n-1,dp);
        }
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range = 0;
	    for(int i=0; i<n; i++){
	        range += arr[i];
	    }
	    vector<vector<int>> dp(n+1,vector<int>(range+1,-1));
	    vector<int> rangeArr;
	    for(int i=1; i<=range; i++){
	        if(isPossible(arr,i,n,dp)){
	            rangeArr.push_back(i);
	        }
	    }
	    
	    int ans = INT_MAX;
	    
	    for(int i=0; i<rangeArr.size(); i++){
	        ans  = min(ans, abs(rangeArr[i] - (range - rangeArr[i])));
	    }
	    
	    return ans;
	}
};
