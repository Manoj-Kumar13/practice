bool isPossible(vector<int> &boards, int n, int k,int mid){
    int painters= 1;
    int time = 0;
    for(int i=0; i<n; i++){
        if(time + boards[i] <= mid ){
            time +=boards[i];
        }else{
            painters++;
            if(painters>k || boards[i] > mid){
                return false;
            }
            time = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n = boards.size();
    int left = 0;
    int right = 0;
    for(int i=0; i<n; i++){
        right += boards[i];
    }
    int ans = 0;
    while(left <= right){
        int mid = left+(right-left)/2;
        
        if(isPossible(boards,n,k,mid)){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return ans;
}
