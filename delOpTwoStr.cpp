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
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        
        int res = helper(word1,n1,word2,n2);
        
        return res;
    }
};
