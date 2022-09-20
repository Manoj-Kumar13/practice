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
