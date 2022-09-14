#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'beautifulTriplets' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */
 int firstOcc(vector<int>& A, int n, int B,int left, int right){
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

int lastOcc(vector<int>& A, int n, int B,int left,int right){
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
 int findTriplet(vector<int> arr, int d, int left, int right){
     int mid = 0;
     while(left<=right){
         mid = left  + (right-left)/2;
         
         if(arr[mid] == d){
             return mid;
         }
         if(arr[mid] < d){
             left = mid+1;
         }else{
             right = mid-1;
         }
     }
     
     return -1;
 }

int beautifulTriplets(int d, vector<int> arr) {
    int n = arr.size();
    int ans = 0;
    for(int i=0; i<n-2; i++){
        int left = i+1;
        int right = n-1;
        
        int ft = -1,st = -1;
        
        ft = findTriplet(arr,arr[i]+d,left,right);
        if(ft>i){
            st = findTriplet(arr,arr[i]+(2*d),left+1,right);   
        }
        
        
        if(ft >i and st>i){
            int frOcc = lastOcc(arr,n, arr[ft], left, right) -
                           firstOcc(arr,n,arr[ft], left, right);
            int srOcc = lastOcc(arr,n, arr[st], left, right) -
                           firstOcc(arr,n,arr[st], left, right);              
            ans = ans+1+(frOcc+srOcc);
        }
        
    }
    
    return ans;
}
