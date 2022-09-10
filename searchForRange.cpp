vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> ans(2);
    
    int left = 0;
    int right = A.size()-1;
    int pivot = -1;
    
    while(left<=right){
        int mid = left + (right-left)/2;
        
        if(A[mid] == B){
            pivot = mid;
            break;
        }
        
        if(A[mid] < B){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    if(pivot == -1){
        ans[0] = -1;
        ans[1] = -1;
    }else{
        int lp = pivot;
        int rp = pivot;
        ans[0] = lp;
        ans[1] = rp;
        while( lp > 0 and A[--lp] == B){
            ans[0] = lp;
        }
        while( rp < A.size()-1 and A[++rp] == B){
            ans[1] = rp;
        }
    }
    return ans;
    
}
