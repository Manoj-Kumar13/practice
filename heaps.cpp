#include<bits/stdc++.h>
using namespace std;

class heap{
    int arr[100];
    int size;

    public:
    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int data){
        size += 1;
        int index = size;
        arr[index] = data;
        
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void pop(){
        if(size==0){
            cout<< "nothing to delete"<<endl;
            return;
        }
        arr[1] = arr[size];
        size -= 1;
        int index = 1;
        while(index < size){
            int children1 = 2*index;
            int children2 = 2*index+1;
            if(children1 < size and arr[index] < arr[children1]){
                swap(arr[index],arr[children1]);
                index= children1;
            }else if(children2 < size and arr[index] < arr[children2]){
                swap(arr[index],arr[children2]);
                index= children2;
            }else{
                return;
            }
        }

    }


    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};

void heapify(int *arr, int n, int i){
    int largest = i;
    int child1 = 2*i;
    int child2 = 2*i+1;

    if(child1 <= n and arr[largest] < arr[child1]){
        largest  = child1;
    }
    if(child2 <= n and arr[largest] < arr[child2]){
        largest  = child2;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int *arr, int n) {
	// Write your code here.
    for(int i =n/2; i>0; i--){
        heapify(arr,n, i);
    }
    int size = n;
    while(size > 0){
        swap(arr[size],arr[1]);
        size--;
        
        heapify(arr, size, 1);
    }
}

int main(){

    heap h;
    // h.insert(5);
    // h.insert(2);
    // h.insert(4);
    // h.insert(6);
    // h.insert(9);
    // h.insert(8);
    // h.insert(7);
    // h.insert(1);
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print(); 
    h.pop();
    // h.pop();
    h.print();

    int arr[7] = {-1,54,53,55,52,50,94};
    int n = 6;
    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }

    heapSort(arr,n);

    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
