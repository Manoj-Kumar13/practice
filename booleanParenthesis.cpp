class Solution{
public:
int solve(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue == true){
                return s[i] == 'T';
            }else{
                return s[i] == 'F';
            }
        }
        
        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue];
        }
        
        int ans = 0;
        for(int k=i+1; k<=j-1; k+=2){
            int lt,lf,rt,rf;
            
            if(dp[i][k-1][true] != -1){
                lt = dp[i][k-1][true];
            }else{
                lt = solve(s,i,k-1,true,dp);
            }
            
            if(dp[i][k-1][false] != -1){
                lf = dp[i][k-1][false];
            }else{
                lf = solve(s,i,k-1,false,dp);
            }
            
            if(dp[k+1][j][true] != -1){
                rt = dp[k+1][j][true];
            }else{
                rt = solve(s,k+1,j,true,dp);
            }
            
            if(dp[k+1][j][false] != -1){
                rf = dp[k+1][j][false];
            }else{
                rf = solve(s,k+1,j,false,dp);
            }
            
            
            if(s[k] == '&'){
                if(isTrue == true){
                    ans += (lt*rt);
                }else{
                    ans += (lt*rf)+(lf*rt) +(lf*rf);
                }
            }else if(s[k] == '|'){
                if(isTrue == true){
                    ans += (lt*rf)+(lf*rt)+(lt*rt);
                }else{
                    ans += (lf*rf);
                }
            }else if(s[k] == '^'){
                if(isTrue == true){
                    ans += (lt*rf)+(lf*rt);
                }else{
                    ans += (lf*rf)+(lt*rt);
                }
            }
            ans = ans%1003;
        }
        
        return dp[i][j][isTrue] = ans%1003;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return solve(s, 0, n-1, true,dp);
    }
};
