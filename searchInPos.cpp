class Solution {
public:
    int binarySearch(vector<int>& a, int t,int n){
        int l = 0;
        int r = n-1;
        int mid = (l+r)/2;
        
        if(t<a[l]){
            return 0;
        }
        
        while(mid>=l && mid<=r){
            // cout << l << " " << mid << " " << r << endl; 
            if(a[mid] == t){
                return mid;
            }
            
            if(a[mid]>t){
                r = mid-1;
                mid = (l+r)/2;
            }else if(a[mid]<t){
                l = mid+1;
                mid = (l+r)/2;
            }
        }
        // cout << '\n';
        
        return mid+1;
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = binarySearch(nums,target,n);
        return ans;
    }
};
