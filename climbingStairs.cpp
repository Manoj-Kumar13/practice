class Solution {
public:
    int climbStairs(int n) { 
        if(n<=2){
            return n;
        }
        
        int os = 1;
        int ts = 2;
        
        int ans = 0;
        
        for(int i=3; i<=n; i++){
            ans = os+ts;
            os = ts;
            ts = ans;
        }
        
        return ans;
    }
};
