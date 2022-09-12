bool isPossible(vector<int> arr, int n, int m,int mid){
    int students = 1;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        if(arr[i] + sum <= mid){
            sum+= arr[i];
        }else{
            students++;
            if(students>m || arr[i]>mid){
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.
     int left = 0;
    int right = 0;
    for(int i=0; i<n; i++){
        right+=arr[i];
    }
    
    int ans = 0;
    while(left<=right){
        int mid = left+ (right-left)/2;
        
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    
    return ans;
}
