class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int sz = n-k;
        int sum = 0;
        for(int i=sz; i<n; i++){
            sum += cp[i];
        }
        int ans = sum;
        
        for(int i=0; i<k; i++){
            sum += cp[i];
            sum -= cp[i+sz];
            ans = max(ans,sum);
        }
        
        return ans;
    }
};
