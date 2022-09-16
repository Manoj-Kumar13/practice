#include <bits/stdc++.h> 

void heapify(vector<int> &arr, int n, int i){
    int smallest = i;
    int child1 = 2*i+1;
    int child2 = 2*i+2;
    
    if(child1 < n and arr[smallest] > arr[child1]){
        smallest = child1;
    }
    if(child2 < n and arr[smallest] > arr[child2]){
        smallest = child2;
    }
    
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for(int i = n/2-1; i>=0; i--){
        heapify(arr,n,i);
    }
    return arr;
}
