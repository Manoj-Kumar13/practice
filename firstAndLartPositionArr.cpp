int firstOcc(vector<int>& A, int n, int B){
    int left = 0;
    int right = A.size()-1;
    int ans = -1;
    
    while(left<=right){
        int mid = left + (right-left)/2;
        
        if(A[mid] == B){
            ans = mid;
            right = mid-1;
        }else if(A[mid] < B){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return ans;
}

int lastOcc(vector<int>& A, int n, int B){
    int left = 0;
    int right = A.size()-1;
    int ans = -1;
    
    while(left<=right){
        int mid = left + (right-left)/2;
        
        if(A[mid] == B){
            ans = mid;
            left = mid+1;
        }else if(A[mid] < B){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& A, int n, int B)
{
    // Write your code here
    pair<int,int> ans;
    
    ans.first = firstOcc(A,n,B);
    ans.second = lastOcc(A,n,B);
    
    return ans;
}
