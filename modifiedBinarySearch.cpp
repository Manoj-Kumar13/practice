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

//alternative approach
int getPivot(int *arr, int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    
    while(start<end){
        if(arr[mid]>=arr[0]){
            start = mid+1;
        }else{
            end = mid;
        }
         mid = start + (end-start)/2;
    }
    return start;
}
int binarySearch(int *arr, int left,int right, int k){
    
    while(left<=right){
        int mid = left + (right-left)/2;
        
        if(arr[mid]== k){
            return mid;
        }
        if(arr[mid] <k){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return -1;
    
}
int search(int* arr, int n, int key) {
    // Write your code here.
    int pivot = getPivot(arr,n);
    
    if(arr[pivot]<=key && arr[n-1]>=key){
        return binarySearch(arr,pivot,n-1,key);
    }else{
        return binarySearch(arr,0,pivot-1,key);
    }
}
