#include <bits/stdc++.h> 

void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int child1 = 2*i+1;
    int child2 = 2*i+2;
    
    if(child1< n and arr[largest]<arr[child1]){
        largest  = child1;
    }
    if(child2< n and arr[largest]<arr[child2]){
        largest  = child2;
    }
    
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr, n, largest);
    }
    
}

//0 based indexing
vector<int> heapSort(vector<int>& arr, int n) {
	// Write your code here.
    for(int i =n/2-1; i>=0; i--){
        heapify(arr,n, i);
    }
    int size = n-1;
    while(size >= 0){
        swap(arr[size],arr[0]);
        
        heapify(arr, size, 0);
        size--;
    }
    
    return arr;
}

//1 based indexing
vector<int> heapSort(vector<int>& arr, int n) {
	// Write your code here.
    vector<int> a(n+1);
    a[0] = -1;
    for(int i=1; i<=n; i++){
        a[i] = arr[i-1];
    }
    for(int i =n/2; i>0; i--){
        heapify(a,n, i);
    }
    int size = n;
    while(size > 0){
        swap(a[size],a[1]);
        size--;
        
        heapify(a, size, 1);
    }
    
    for(int i=1; i<=n; i++){
        arr[i-1] = a[i];
    }
    return arr;
}
