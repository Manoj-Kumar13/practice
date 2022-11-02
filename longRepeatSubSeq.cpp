class Solution {
	public:
		int LongestRepeatingSubsequence(string a){
		    // Code here
		    int n = a.size();
		    
		    string b = a;
		    vector<vector<int>> dp(n+1,vector<int>(n+1));
		    
		    for(int i=0; i<=n; i++){
		        for(int j=0; j<=n; j++){
		            if(i==0 or j==0){
		                dp[i][j] = 0;
		            }else if(a[i-1] == b[j-1] and i != j){
		                dp[i][j] = 1+dp[i-1][j-1];
		            }else{
		                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    
		    return dp[n][n];
		}

};
