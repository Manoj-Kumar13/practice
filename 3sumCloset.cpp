class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n<3){
            return 0;
        }
        int sum = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<n-2; i++){
            
            int j = i+1;
            int k = n-1;
            while(j<k){
                int temp = nums[i] + nums[j] + nums[k];
                if(abs(temp-target) < abs(sum - target)){
                sum = temp;
            }else if(temp > target){
                    k--;
                }else if(target > temp){
                    j++;
                }else{
                    return target;
                }
            }
            
        }
        return sum;
    }
};
