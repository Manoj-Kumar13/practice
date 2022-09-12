bool isPossible(vector<int> &stalls,int n, int k, int mid){
    int cows =1;
    int lastCow = stalls[0];
    
    for(int i=0; i<n; i++){
        if(stalls[i]-lastCow >=mid){
            cows++;
            if(cows == k){
                return true;
            }
            lastCow = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    int left = 0;
    int right = 0;
    for(int i =0; i<n; i++){
        right = max(right,stalls[i]);
    }
    sort(stalls.begin(),stalls.end());
    int ans = 0;
    while(left<=right){
        int mid  = left + (right-left)/2;
        if(isPossible(stalls,n,k,mid)){
            ans = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return ans;
}
