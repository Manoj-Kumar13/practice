class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size(), sum =0;
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        
        if(sum&1){
            return false;
        }else{
            sum /=2;
        }
        
        bool dp[n+1][sum+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j == 0){
                    dp[i][j] = true;
                }else if(i == 0){
                    dp[i][j] = false;
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                
                if(a[i-1] <= j){
                    dp[i][j] = dp[i-1][j - a[i-1]] or dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};
