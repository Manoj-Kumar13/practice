// You are given an integer n. A 0-indexed integer array nums of length n + 1 is generated in the following way:

// nums[0] = 0
// nums[1] = 1
// nums[2 * i] = nums[i] when 2 <= 2 * i <= n
// nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
// Return the maximum integer in the array nums​​​.
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0 || n == 1) return n;
        vector<int> nums(n+1);
        nums[0] = 0;
        nums[1] =1;
        int ans = 1;
        
        for(int i=1; i<=n; i++ ){
            if((2*i)>=2 && (2*i)<=n){
                nums[2*i] = nums[i];
                ans = max(ans,nums[i]);
            }
            
            if((2*i+1)>=2 && (2*i+1)<=n){
                nums[2*i+1] = nums[i]+nums[i+1];
                ans = max(ans,nums[i]+nums[i+1]);
            }
        }
        
        return ans;
    }
};
