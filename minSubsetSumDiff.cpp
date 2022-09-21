//only for positive values
int Solution::solve(vector<int> &arr) {
    int range = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            range += arr[i];
        }
        
        bool dp[n+1][range+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=range; j++){
                if(j==0){
                    dp[i][j] = true;
                }else if( i == 0){
                    dp[i][j] = false;
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=range; j++){
                
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        vector<int> rangeArr;
        
        for(int i=0; i<=(range+1)/2; i++){
            if(dp[n][i]){
             rangeArr.push_back(i);   
            }
        }
        
        int minDif = INT_MAX;
        
        for(int i=0; i<rangeArr.size(); i++){
            minDif = min(abs(range - 2*rangeArr[i]), minDif);
        }
    
        return minDif;
}
