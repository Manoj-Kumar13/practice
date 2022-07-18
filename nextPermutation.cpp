class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        
        if(i>=0){
            int j = n-1;
            while(j>=0 && nums[i]>=nums[j]){
                j--;
            }
             swap(nums,i,j);
        }
        
       
        
        reverse(nums,i+1);
    }
    
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    
    void reverse(vector<int>& nums, int start){
        int end = nums.size()-1;
        while(start < end){
            swap(nums,start,end);
            start++;
            end--;
        }
    }
};
