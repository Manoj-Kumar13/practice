class Solution{
    public:
    long long maxSubarraySum(int a[], int n){
        
        // Your code here
        long long sum = 0;
        long long ans = INT_MIN;
        for(int i=0; i<n; i++){
            sum += a[i];
            ans = max(ans,sum);
            if(sum<0){
                sum = 0;
            }
        }
        return ans;
    }
};
