class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        vector<int> a(n);
        
        for(int i=0; i<n; i++){
            a[i] = arr[i];
        }
        
        sort(a.begin(), a.end());
        int minVal = a[0];
        int maxVal = a[n-1];
        int ans = a[n-1] - a[0];
        for(int i=1; i<n; i++){
            if(a[i]-k < 0){
                continue;
            }
            minVal = min(a[0]+k, a[i]-k);
            maxVal = max(a[i-1]+k, a[n-1]- k);
            
            ans = min(ans, maxVal - minVal);
        }
        
        return ans;
    }
};
