class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        int ans = 0;
        int n = a.size();
        
        for(int i=0; i<k; i++){
            ans = ans + a[i];
        }
        int sum = ans;
        for(int i=k; i<n; i++){
            sum  = sum + a[i] - a[i-k];
            
            ans = max(sum,ans);
        }
        
        return double  (ans/double(k));
    }
};
