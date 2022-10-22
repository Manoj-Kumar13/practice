class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n = og.size(), m = og[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][1] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(!og[i-1][j-1]){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        
        return dp[n][m];
    }
};


//another approach
void solve() {
			int n;
			cin >> n;

			char grid[n+1][n+1];

			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					cin >> grid[i][j];
				}
			}

			if(grid[n][n] == '*'){
				cout << 0;
				return;
			}

			int dp[n+1][n+1];

			for (int i = n; i>=1; i--)
			{
				for (int j = n; j>=1; j--)
				{
					if(i == n and j==n){
						dp[i][j] = 1;
					}else{
						int op1 = (j == n) ? 0 : dp[i][j+1]%Mod;
						int op2 = (i == n) ? 0 : dp[i+1][j]%Mod;

						dp[i][j] = (op1+op2)%Mod;
						if(grid[i][j] == '*'){
							dp[i][j] = 0;
						}
					}

				}
			}

			cout << dp[1][1];
		}
