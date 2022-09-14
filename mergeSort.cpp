void merge(vector<int> &arr, int left, int right){
    int mid  = left + (right-left)/2;
    int len1 = mid-left+1;
    int len2 = right - mid;
    
    int first[len1];
    int second[len2];
    
    int mr = left;
    for(int i=0; i<len1; i++){
        first[i] = arr[mr];
        mr++;
    }
    
    for(int i=0; i<len1; i++){
        second[i] = arr[mr];
        mr++;
    }
    
    int idx1=0, idx2 = 0;
    mr = left;
    while(idx1<len1 and idx2<len2){
        if(first[idx1] > second[idx2]){
            arr[mr] = second[idx2];
            idx2++;
            mr++;
        }else{
            arr[mr] = first[idx1];
            idx1++;
            mr++;
        }
    }
    
    while(idx1<len1){
        arr[mr] = first[idx1];
        idx1++;
        mr++;
    }
    
    while(idx2<len2){
         arr[mr] = second[idx2];
            idx2++;
            mr++;
    }
}

void mergeSort(vector<int> &arr,int left,int right){
    if(left>=right){
        return;
    }
    int mid = left + (right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,right);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    mergeSort(arr,0,n-1);
}
