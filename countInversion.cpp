#include <bits/stdc++.h>
long long merge(long long *arr, long long left,long long right, long long &inversion){
    long long mid = left + (right - left)/2;
    long long len1 = mid - left+1;
    long long len2 = right - mid;
    
    long long first[len1];
    long long second[len2];
    
    long long mr = left;
    
    for(int i=0; i<len1; i++){
        first[i] = arr[mr++];
    }
    for(int i=0; i<len2; i++){
        second[i] = arr[mr++];
    }
    mr = left;
    long long idx1 = 0;
    long long idx2 = 0;
    while(idx1 < len1 and idx2 < len2){
        if(first[idx1]<second[idx2]){
            arr[mr++] = first[idx1++];
        }else{
            arr[mr++] = second[idx2++];
            inversion+= (len1-idx1);
        }
    }
    
    while(idx1<len1){
        arr[mr++] = first[idx1++];
    }
    while(idx2<len2){
        arr[mr++] = second[idx2++];
//         inversion++;
    }
}
long long mergeSort(long long *arr, long long left, long long right){
    long long inversion = 0;
    if(left<right){
        long long mid = left +(right - left)/2;
        
        inversion+=mergeSort(arr,left,mid);
        inversion+=mergeSort(arr,mid+1,right);
        
        merge(arr,left,right,inversion);
    }
    return inversion;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr,0,n-1);
}
