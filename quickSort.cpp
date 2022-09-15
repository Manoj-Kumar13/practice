#include <bits/stdc++.h>

int partition(vector<int> &arr, int left, int right){
    int pivot = arr[left];
    int cnt=0;
    
    for(int i=left+1; i<=right; i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    
    int pivotIndex = left + cnt;
    swap(arr[pivotIndex],arr[left]);
    
    int i=left,j=right;
    
    while(i<pivotIndex and j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        
        if(i<pivotIndex and j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    
    return pivotIndex;
}
void quickSort(vector<int> &arr, int left, int right){
    
    if(left<right){
        int p = partition(arr,left,right);
    
        quickSort(arr,left,p-1);
        quickSort(arr,p+1,right);
    }
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    quickSort(arr,0,arr.size()-1);
    return arr;
}
