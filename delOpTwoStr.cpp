// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.
    
class Solution {
public:
    vector<vector<int>> dp;
    int helper(string w1,int n1,string w2,int n2){
        if(n1==0 && n2==0){
            return 0;
        }
        if(n1 == 0 || n2 == 0){
            return max(n2-n1,n1-n2);
        }
        if(dp[n1][n2] != -1){
            return dp[n1][n2];
        }
        if(w1[0] == w2[0]){
            return dp[n1][n2] = helper(w1.substr(1),n1-1,w2.substr(1),n2-1);
        }
        
        return dp[n1][n2] = 1 + min(helper(w1.substr(1),n1-1,w2,n2),helper(w1,n1,w2.substr(1),n2-1));
        
    }
    
     int helper2(string w1,int n1,string w2,int n2){
        
        for(int i=0; i<=n1; i++){
            dp[i][0] = i;
        }
        for(int i=0; i<=n2; i++){
            dp[0][i] = i;
        }
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(w1[i-1] == w2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n1][n2];
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        
        int res = helper(word1,n1,word2,n2);
        
        return res;
    }
};
