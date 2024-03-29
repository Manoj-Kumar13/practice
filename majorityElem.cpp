class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int cnt = 1;
        
        for(int i=1; i<n; i++){
            if(ans == nums[i]){
                cnt++;
            }else if(cnt == 0){
                ans = nums[i];
                cnt++;
            }else{
                cnt--;
            }
        }
        return ans;
    }
};
