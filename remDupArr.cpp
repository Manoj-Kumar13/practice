class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int dupCount = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) dupCount++;
            else nums[i-dupCount] = nums[i];
        }
        return n-dupCount;
    }
};
