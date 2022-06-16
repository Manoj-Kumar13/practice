//DP Solution
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        ans[0] = 0;
        
        for(int i=1; i<=n; i++){
            ans[i] = ans[i/2] + i%2;
        }
        
        return ans;
    }
};

//using builtIn function
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0; i<=n; i++){
            int x = __builtin_popcount(i);
            ans.push_back(x);
        }
        
        return ans;
    }
};
