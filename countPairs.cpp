class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        sort(arr, arr + n);
        int ans = 0;
        for(int i=0; i<n-1; i++){
            int t = k - arr[i];
            
            int start = lower_bound(arr+i+1, arr+n, t) - arr;
            int end =   upper_bound(arr+i+1, arr+n, t) - arr;
            ans += end - start;
        }
        
        return ans;
    }
};
