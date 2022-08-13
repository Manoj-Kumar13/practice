// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long ans = LONG_MAX;
        
        long left = 1, right = n;
        
        while(left<=right){
            long mid = (left+right)/2;
            
            if(isBadVersion(mid)){
                ans = min(ans,mid);
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        return ans;
        
    }
};
