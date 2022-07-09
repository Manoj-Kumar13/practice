class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int ans = binarySearch(nums,0,n-1,target);
        
        return ans;
    }
    
    int binarySearch(vector<int> &a, int l, int r, int t){
        
        while(l<=r){
            int mid = (l+r)/2;
            
            if(a[mid] == t){
                return mid;
            }
            //left sorted 
            if(a[l]<=a[mid]){
                    if(t<a[mid] && t>=a[l]){
                        r = mid-1;
                    }else{
                        l = mid+1;
                    }
            }//right sorted
            else{
                if(t>a[mid] && t<=a[r]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        
        return -1;
    }
};
