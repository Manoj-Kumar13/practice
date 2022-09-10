int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int left = 0,right=A.size()-1;
    
    while(left<=right){
        int mid = left + (right-left)/2;
        
        if(A[mid] == B){
            return mid;
        }
        
        if(A[mid]<B){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return left;
    
}
