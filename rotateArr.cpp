class Solution {
public:
    void reverse(vector<int>& a, int left, int right){
        
        while(left<right){
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            left++;
            right--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k<0){
            k +=n;
        }
        
        //part 1 reverse
        reverse(nums,0,n-k-1);
        //part 2 reverse
        reverse(nums,n-k,n-1);
        //whole array reverse
        reverse(nums,0,n-1);
        
    }
};
